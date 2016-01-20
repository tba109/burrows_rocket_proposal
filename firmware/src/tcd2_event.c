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
  const WORD MAX_WAIT_COUNT0 = 50; // about 100 us
  //const WORD MAX_WAIT_COUNT1 = 25; // about 50 us
  const WORD MAX_WAIT_COUNT1 = 75; // about 150 us

  waitcount = 0;
  if( evt_pendn() == 0 ) // active low, so a zero executes this routine
    {
      ///////////////////////////////////////////////////////////////
      // Tyler Anderson Thu Mar 15 15:42:01 EDT 2012
      // After I integrated the TCD, we found that the 
      // TCD was always reading one event behind the other
      // instruments. It occurred to me that this might be because
      // somewhere in the TCD CDAQ, we might be clearing without a
      // read, such that the next event that the next time we get
      // a trigger, the USB fifo still has the previous event's data
      // in it. So, when we generate a new trigger, if the old data
      // is still in the USB fifo, we need to clear it before refilling
      // with the new data
      ////////////////////////////////////////////////////////////////
      if( !(EP6CS &  0x04) ) 
	{
#ifdef DEBUG
	  printf("No SFC Read. Resetting fifo!\n");
#endif
	  FIFORESET = 0x06;
	  FIFORESET = 0x00;
	 
	}
      
      change_evt_collectn(0);
      
      while ( !(GPIFTRIG & bmBIT7) ); // wait until things are finished
      GPIFADRL = 0x00; SYNCDELAY4;
      GPIFADRH = 0x00; SYNCDELAY4;
      GPIFTCB1 = 0;
      GPIFTCB0 = NEVTS;
      // GPIFTCB0 = ;
      GPIFTRIG = 6; // R/W=0, E[1:0] = ep_num

      // Timeout if the FPGA does not respond 
      // A timeout here is probably because one of the stacks didn't readout 
      // so you aren't getting an evt_rdyn
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

      // Timeout if the FPGA does not respond. This would be a strange error, probably
      // meaning there is something wrong with the FPGAs hardware or firmware, since
      // setting evt_timeoutn low should make the overlord FPGA autoread
      for(waitcount = 0; waitcount < MAX_WAIT_COUNT1; waitcount++)
	{ 
	  if( !(GPIFTRIG & bmBIT7) ) // Still busy
	    continue;
	  else
	    break;
	}
      if( waitcount == MAX_WAIT_COUNT1 )
	{
#ifdef DEBUG 
	  printf("Autoread not exiting. Aborting event read!\n");
#endif
	  GPIFABORT = 0xFF;
	}
      
      change_evt_timeoutn(1);
      change_evt_collectn(1);
      // master_trigger_clear();
      return 1;
      
    }
  else
    // TBA Thu Feb  9 09:22:54 EST 2012
    // I changed this from return 0 to return 1 because it seems I need to flush no
    // matter what or else when I'm in event mode, if I don't get an event, the next
    // command I send returns an error
    return 1;
}
