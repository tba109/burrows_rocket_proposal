/*
 * TBA Thu Oct  7 15:11:55 EDT 2010
 * These are the functions for the TCD2 commanding.
 */
// TCD2 headers
#include "tcd2_config.h"
#include "tcd2_command.h"
#include "tcd2_event.h"
#include "tcd2_flags.h"

// FX2LIB headers
#include <fx2regs.h>
#include <fx2macros.h>
#include <serial.h>
#include <delay.h>
#include <usbjt.h>
#include <lights.h>
#include <setupdat.h>
#include <eputils.h>
#include <gpif.h>

// Global memory space to point at with local pointers
WORD datstuff;

unsigned char get_action(unsigned char trg)
{
  return (trg & ACTIONMASK);
}

unsigned char get_action_shifted(unsigned char trg)
{
  return ( (trg & ACTIONMASK) >> ACTIONOFFSET);
}

unsigned char get_node(unsigned char trg)
{
  return ( trg & NODEMASK );
}

void set_action(tcd2_command * cmd, unsigned char act)
{
  cmd->target = ( (act & ACTIONMASK) | (get_node(cmd->target) & NODEMASK) );
}

void set_action_shifted(tcd2_command * cmd, unsigned char act)
{
  cmd->target = ( ((act << ACTIONOFFSET) & ACTIONMASK) | (get_node(cmd->target) & NODEMASK) );
}

void set_node(tcd2_command * cmd, unsigned char nde)
{
  cmd->target = ( (cmd->target & ACTIONMASK) | (nde & NODEMASK) );
}

void command_buffer_clear(cmd_buffer * buf)
{
  unsigned char i;
  for(i=0; i < MAXNCMD; i++)
    {
      buf->cmdbuf[i].target = 0x00;
      buf->cmdbuf[i].param = 0x00;
      buf->cmdbuf[i].datarg = 0x00;
    }
  buf->Ncmd = MAXNCMD;
} 

void command_buffer_print(cmd_buffer * buf)
{
  __xdata unsigned char i;
  for(i = 0; i < buf->Ncmd; i++)
    {
#ifdef DEBUG
      printf("buf->cmdbuf[%d].target = 0x%02X, ",i,buf->cmdbuf[i].target);
      printf("buf->cmdbuf[%d].param = 0x%02X, ",i,buf->cmdbuf[i].param);
      printf("buf->cmdbuf[%d].datarg = 0x%04X, ",i,buf->cmdbuf[i].datarg);
      printf("\n");
#endif
    }
#ifdef DEBUG
  printf("Ncmd = %d\n",buf->Ncmd);
  printf("mode = %d\n",buf->mode);
  printf("tuner = %d\n",buf->tuner);
  printf("clev = %d\n",buf->clev);
  printf("stkmsk = %d\n",buf->stkmsk);
  printf("\n");
#endif
}

void command_rostack_send(cmd_buffer * buf, tcd2_command * cmd)
{
  __xdata unsigned char *dest = (__xdata unsigned char *)0xE400;
  __xdata WORD * dat;
  __xdata WORD datval;
  //printf("Inside command_rostack_send\n");
  if( (cmd->target & ACTIONMASK) == SET )
    {
      if( cmd->param == MODE )
	{
	  if( cmd->datarg == EVT_MODE )
	    {
	      buf->mode = EVT_MODE;
	      return;
	    }
	  else if( cmd->datarg == CMD_MODE )
	    {
	      buf->mode = CMD_MODE;
	      return;
	    }
	  else
	    {
	      cmd->target = cmd->target & ERRORMASK;
	      return;
	    }
	}
      if( cmd->param == CLEV )
	{ 
	  GPIFADRH = 0x00;
	  GPIFADRL = 0x01;
	  buf->clev = cmd->datarg;
	}
      else if( cmd->param == STKMSK )
	{
	  GPIFADRH = 0x00;
	  GPIFADRL = 0x02;
	  buf->stkmsk = cmd->datarg;
	}
      else
	{
	  cmd->target = cmd->target & ERRORMASK;
	  return;
	}
      // Change the GPIF engine to olpwrn 
      dest[50] = 0x07;
      // Write to the fpga
      datval = cmd->datarg;
      dat = &datval;
      while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
      gpif_single_write16(dat,1);  
      // Change the GPIF engine back to cmdwen
      dest[50] = 0x16;
    }
  else if( (cmd->target & ACTIONMASK) == GET ) 
    {
      if( cmd->param == MODE )
	cmd->datarg = buf->mode;
      else if( cmd->param == CLEV )
	cmd->datarg = buf->clev;
      else if( cmd->param == STKMSK )
	cmd->datarg = buf->stkmsk;
      else
	{
	  //printf("Unrecognized get\n");
	  cmd->target = cmd-> target & ERRORMASK;
	  return;
	}
    }
  else
    {
      //printf("Unrecognized action\n");
      cmd->target = cmd->target & ERRORMASK;
      return;
    }
  return;
  
}

void command_response(cmd_buffer * buf)
{
  __xdata unsigned char *dest=EP1INBUF;
  __xdata unsigned char len = 4 * buf->Ncmd;
  __xdata unsigned char i;
  unsigned int wait = 0;

  for(i=0; i < buf->Ncmd; i++)
    {
      dest[4*i] = buf->cmdbuf[i].target;
      dest[4*i+1] = buf->cmdbuf[i].param;
      dest[4*i+2] = MSB(buf->cmdbuf[i].datarg);
      dest[4*i+3] = LSB(buf->cmdbuf[i].datarg);
    } 
  SYNCDELAY4; EP1INBC=len; // Set the number of bytes to 
                           // xfer to arm EP1IN

  SYNCDELAY4; EP1OUTBC=0; // This re-arms EP1OUT, which means
                         // data contained in it thus far
                         // will be over written.
  while(wait < CTIMEOUT) 
    {
      if(!(EP1INCS & bmBIT1)) // If EP1IN is not busy
	break;
      else
	wait++;
    }
  if(EP1INCS &  bmBIT1)  // If EP1IN is still busy after ~20ms, clear it
    EP1INCS &= ~bmBIT1;
}

unsigned char command_mode(tcd2_command * cmd)
{
  if(cmd->datarg == EVT_MODE)
    return EVT_MODE;
  else 
    return CMD_MODE; 
}

void command_fpga_receive(tcd2_command * cmd, unsigned char adr)
{      
  // Tyler Anderson Fri Mar  4 16:03:30 EST 2011
  // The gpif_single_read16 function from fx2lib won't work here, because
  // I want to also be able to timeout if bus doesn't respond, and that
  // function always waits for the GPIF to not be busy
  // I'll manually do this here
  
  WORD waitcount;
  WORD dummy;
  const WORD MAX_WAIT_COUNT = 100; // about 200 us
  //printf("Inside command_fpga_receive\n");
  // Read in the data
  while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be non busy
  GPIFADRH = 0x00; SYNCDELAY4;
  GPIFADRL = adr; SYNCDELAY4;
  // printf("GPIF reading command\n");
  // dummy read to trigger real read
  dummy = XGPIFSGLDATLX;
  // printf("GPIF reading command started\n");
  
  // Timeout if the FPGA does not respond
  for(waitcount = 0; waitcount < MAX_WAIT_COUNT; waitcount++)
    { 
      if( !(GPIFTRIG & bmBIT7) ) // Still busy
	continue;
      else
	break;
    }
  
  if( waitcount == MAX_WAIT_COUNT ) // Timeout! Abort
    {
#ifdef DEBUG
      //printf("command_fpga_receive: Timeout! GPIF Aborting\n");
#endif
      GPIFABORT = 0xFF;
      cmd->target = cmd->target | ERRORMASK;
    }
  else // GPIF read completed successfully
    {
      //printf("Datarg read okay!\n");
      cmd->datarg = (GPIFSGLDATH << 8) | GPIFSGLDATLNOX;
    }
  return; 
}

void command_fpga_send(tcd2_command * cmd)
{
  __xdata WORD * dat;
  __xdata WORD datval;
  //printf("Inside command_fpga_send\n");
  // If you're here, this must be a command for the FPGA 
  //   Set the the address to the target values
  GPIFADRH = 0x00; SYNCDELAY4;
  GPIFADRL = 0x00; SYNCDELAY4;
  //printf("assigned addresses\n");
  datval = (((short)cmd->target << 8) & 0xFF00) | (0x00FF & (short)cmd->param ) ;
  dat = &datval;
  //printf("assigned pointers\n");
  while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
  //printf("GPIF done being busy\n");
  gpif_single_write16(dat,1);
  //printf("Wrote command part\n");
  //   Write the datarg part on the data lines
  while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
  datval = cmd->datarg;
  dat = &datval;
  while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
  gpif_single_write16(dat,1);  
  //printf("Wrote data part\n");
}

void command_dispatch(cmd_buffer * buf)
{
  unsigned char i;
  unsigned char nrostack_cmds;
  tcd2_command * cmd;
  nrostack_cmds = 0;
  //printf("Inside command_dispatch\n");
  //////////////////////////////////////////////////////////////////////////////
  // Write the commands. Handle commands for the FX2LP separately than
  // commands for the for the stacks
  //////////////////////////////////////////////////////////////////////////////
  for(i=0; i < buf->Ncmd; i++)
    {
      // Check if there are errors from parsing
      if(buf->cmdbuf[i].target & ERROR)
	continue;
      
      cmd = &buf->cmdbuf[i];

      if( (buf->cmdbuf[i].target & NODEMASK) == ROSTACK)
	command_rostack_send(buf,cmd); 
      else
	command_fpga_send(cmd-nrostack_cmds);
    }
 
  //////////////////////////////////////////////////////////////////////////////
  // Handle the response
  //////////////////////////////////////////////////////////////////////////////
  
  for(i=0; i < buf->Ncmd; i++)
    {
      if(buf->cmdbuf[i].target & ERROR)
	continue;
      
      cmd = &buf->cmdbuf[i];
      
      if( (buf->cmdbuf[i].target & NODEMASK) == ROSTACK )
	nrostack_cmds++;
      else
	command_fpga_receive(cmd,i-nrostack_cmds);
    }
}

unsigned char command_parse(cmd_buffer * buf)
{
  __xdata const unsigned char *src=EP1OUTBUF;
  __xdata unsigned char *dest=EP1INBUF;
  unsigned char Ncmd;
  unsigned char i;
  
  // Does EP1OUT have a number of bytes
  // comensurate with an integral number of
  // commands? (N.B. 4B / command)
  Ncmd = (unsigned char) EP1OUTBC / 4;
  if((unsigned char) EP1OUTBC % 4)
    {
#ifdef DEBUG
      printf("command_parse_NR: Wrong length, %d\n",EP1OUTBC);
#endif
      return 1;
    }
  
  // Is there a target command every four blocks
  // starting at the first block?
  for(i = 0; i < Ncmd; i++)
    {
      switch(src[4*i] & (ACTIONMASK))
	{
	case TCDNOP :
	  continue;
	case GET : 
	  continue;
	case SET : 
	  continue;
	case EVENT : 
	  continue;
	default :
#ifdef DEBUG
	  printf("command_parse_NR: illegitimate action token: %X\n",src[4*i]);
#endif
	  return 1;
	}
    }

  // No NR errors. Copy the data into the command
  // buffer.
  for(i = 0; i < Ncmd; i++)
    {
      buf->cmdbuf[i].target = src[4*i];
      buf->cmdbuf[i].param = src[4*i+1];
      buf->cmdbuf[i].datarg = MAKEWORD(src[4*i+2],src[4*i+3]);
    }
  buf->Ncmd = Ncmd;
  return 0;
}

unsigned char command_receive(cmd_buffer * buf)
{
  __xdata const unsigned char *src=EP1OUTBUF;
  if(!(EP1OUTCS & bmBIT1)) // Check when data appears
    {
      //command_buffer_print(buf);
      // First, make sure we remove the pending stuff
      // change_evt_collectn(1);
      
#ifdef DEBUG
      //printf("Command(s) received\n");
#endif
      /////////////////////////////////////////////////////////////////
      // Thu Dec 29 17:40:35 EST 2011
      // Start of changes 
      // first check the special commands which require no response
      
      // Check if its a softreset
      // Tue Jan 10 11:48:15 EST 2012
      // This is subtle. If you INIT the stacks and then send a flush
      // before they've been allowed to finish initializing the DACs and
      // calibrating the ADCs, then not all DACs will get initilaized. 
      // So, return 0 here instead of 1.
      if( (src[0] & ACTIONMASK) == INIT )
	{
	  stack_initialize();
	  SYNCDELAY4; EP1OUTBC = 0; // This re-arms EP1OUT
	  return 0;
	}
      
      if( (src[0] & ACTIONMASK) == SOFTRESET )
	{
	  soft_resetn();
	  SYNCDELAY4; EP1OUTBC=0; // This re-arms EP1OUT
	  return 0;
	}
      
      // Check if its a flush command
      if( (src[0] & ACTIONMASK) == FLUSH )
	{
	  SYNCDELAY4; EP1OUTBC=0; // This re-arms EP1OUT
	  return 1;
	}
      // Check if we're clearing the Master Trigger and do it
      if( (src[1] == CLEAR_MT) )
	{
	  master_trigger_clear();
	  SYNCDELAY4; EP1OUTBC=0; // This re-arms EP1OUT
	  return 0;
	}
      // Check if we're clearing the Local Trigger and do it
      if( ( (src[0] & ACTIONMASK) == CLEAR ) && 
	  ( (src[1] == CLEAR_LT)  ) && 
	  ( (src[0] & NODEMASK) <= CD ) )
	{
	  local_trigger_clear(src[0] & NODEMASK);
	  SYNCDELAY4; EP1OUTBC=0; // This re-arms EP1OUT
	  return 0;
	}
      ///////////////////////////////////////////////////////////////////////////
      if(!command_parse(buf))
	{
	  //command_buffer_print(buf);
	  command_dispatch(buf);
	}
      command_response(buf);
      //command_buffer_print(buf);
      command_buffer_clear(buf);
      
      return 1;      
     
    }
  return 0;
}

void master_trigger_clear()
{
  __xdata WORD * dat;
  __xdata WORD datval;
  //printf("Inside master_trigger_clear\n");
  // If you're here, this must be a command for the FPGA 
  //   Set the the address to the target values
  GPIFADRH = 0x00; SYNCDELAY4;
  GPIFADRL = 0x00; SYNCDELAY4;
  //printf("assigned addresses\n");
  datval = ((unsigned short)(CLEAR & TCDMT) << 8) | (CLEAR_MT & 0x00FF);
  datval = (((short)(CLEAR | TCDMT) << 8) & 0xFF00) | (0x00FF & CLEAR_MT ) ;
  dat = &datval;
  //printf("assigned pointers\n");
  while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
  //printf("GPIF done being busy\n");
  gpif_single_write16(dat,1);
  //printf("Wrote command part\n");
  //   Write the datarg part on the data lines
  while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
  datval = 0;
  dat = &datval;
  while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
  gpif_single_write16(dat,1);  
  //printf("Wrote data part\n");
}

void local_trigger_clear(unsigned char node)
{
  __xdata WORD * dat;
  __xdata WORD datval;
  // printf("Inside local_trigger_clear\n");
  // If you're here, this must be a command for the FPGA 
  //   Set the the address to the target values
  GPIFADRH = 0x00; SYNCDELAY4;
  GPIFADRL = 0x00; SYNCDELAY4;
  //printf("assigned addresses\n");
  datval = (((short)(CLEAR | node) << 8) & 0xFF00) | (0x00FF & CLEAR_LT ) ;
  //datval = (((short)(CLEAR & node)) << 8) | (CLEAR_LT & 0x00FF);
  dat = &datval;
  //printf("assigned pointers\n");
  while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
  //printf("GPIF done being busy\n");
  gpif_single_write16(dat,1);
  //printf("Wrote command part\n");
  //   Write the datarg part on the data lines
  while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
  datval = 0;
  dat = &datval;
  while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
  gpif_single_write16(dat,1);  
  //printf("Wrote data part\n");
}

void stack_initialize()
{
  __xdata WORD * dat;
  __xdata WORD datval;
  unsigned char i = 0;
  //printf("Inside stack_initialize\n");
  // If you're here, this must be a command for the FPGA 
  //   Set the the address to the target values
  GPIFADRH = 0x00; SYNCDELAY4;
  GPIFADRL = 0x00; SYNCDELAY4;
  //printf("assigned addresses\n");
  
  for( i = 0; i < 10; i++ )
    {
      datval = ((unsigned short)(INIT | i) << 8);
      dat = &datval;
      //printf("assigned pointers\n");
      while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
      //printf("GPIF done being busy\n");
      gpif_single_write16(dat,1);
      //printf("Wrote command part\n");
      //   Write the datarg part on the data lines
      while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
      datval = 0;
      dat = &datval;
      while(!(GPIFTRIG & bmBIT7)); // Wait for GPIF to be not busy
      gpif_single_write16(dat,1);  
    }

    //printf("Wrote data part\n");
}