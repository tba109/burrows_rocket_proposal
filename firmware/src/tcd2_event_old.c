/*
 * Tyler Anderson Tue Nov 16 17:43:04 EST 2010
 * Read TCD event data into buffer and autocommit it
 */
#include "tcd2_command.h"
#include "tcd2_event.h"
#include "tcd2_config.h"
#include "tcd2_flags.h"

#include <fx2regs.h>
#include <fx2types.h>
#include <delay.h>
#include <gpif.h>

unsigned char event_receive()
{
  WORD waitcount;
  const WORD MAX_WAIT_COUNT0 = 75; // about 150 us
  const WORD MAX_WAIT_COUNT1 = 25; // about 50 us
  waitcount = 0;
  if( 1 /*evt_pendn() == 0*/ ) // active low, so a zero executes this routine
    {
      change_evt_collectn(0);
      
      while ( !(GPIFTRIG & bmBIT7) ); // wait until things are finished
      GPIFADRL = 0x00; SYNCDELAY4;
      GPIFADRH = 0x00; SYNCDELAY4;
      GPIFTCB1 = 0;
      GPIFTCB0 = NEVTS;
      GPIFTRIG = 6; // R/W=0, E[1:0] = ep_num

      // Timeout if the FPGA does not respond
      for(waitcount = 0; waitcount < MAX_WAIT_COUNT0; waitcount++)
	{ 
	  if( !(GPIFTRIG & bmBIT7) ) // Still busy
	    continue;
	  else
	    break;
	}
      
      if( waitcount == MAX_WAIT_COUNT0 ) // Timeout! Set the timeout flag and wait again
	{
#ifdef DEBUG
	  printf("event_receive: Timeout! Autoreading the rest\n");
#endif
	  change_evt_timeoutn(0);
	}
      
      
      // Timeout if the FPGA does not respond
      for(waitcount = 0; waitcount < MAX_WAIT_COUNT1; waitcount++)
	{ 
	  if( !(GPIFTRIG & bmBIT7) ) // Still busy
	    continue;
	  else
	    break;
	}
      if( waitcount == MAX_WAIT_COUNT1 ) 
	printf("Aborting event read!\n");
      GPIFABORT = 0xFF;
      change_evt_collectn(1);
      change_evt_timeoutn(1);
            
      // If the data hasn't been readout after a certain amount of time, reset
      // the FIFO so that we don't get stuck here
      while(waitcount < DTIMEOUT) 
	{
	  if(EP6CS &  0x04) // If EP6IN is empty
	    break;
	  else
	    waitcount++;
	}
      if( !(EP6CS &  0x04) && waitcount == DTIMEOUT) 
	{
	  FIFORESET = 0x06;
	  FIFORESET = 0x00;
	}
      
      return 1;
      
    }
  else
    return 0;
}
