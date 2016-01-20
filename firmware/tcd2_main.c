/* 
 * Tyler Anderson Wed Apr 20 11:01:20 EDT 2011
 * This is the final TCD2 firmware for the FX2LP
 */
// TCD2 headers
#include "tcd2_config.h"
#include "tcd2_command.h"
#include "tcd2_event.h"
#include "tcd2_ep16_init.h"
#include "tcd2_flags.h"

// FX2LIB headers
#include <fx2regs.h>
#include <fx2macros.h>
#include <delay.h>
#include <gpif.h>

__xdata cmd_buffer CMDbuffer;
__xdata cmd_buffer * CMDbufptr;

void wait_one_second()
{
  __xdata unsigned char wait_12x_count = 0;
  __xdata unsigned int wait_100ms_count = 0;
  const unsigned int WAIT_100ms = 0xFFFF;

  for( wait_12x_count = 0; wait_12x_count < 12; wait_12x_count++)
    for( wait_100ms_count = 0; wait_100ms_count < WAIT_100ms; wait_100ms_count++);
}

///////////////////////////////////////////////////////////////////////////
// Tyler Anderson Wed Nov 24 13:09:48 EST 2010
// The main event program, which does the following:
//   Initialize serial port (for debugging)
//   Setup the EP1IN/OUT, EP6, GPIO's, etc
//   Setup the GPIF engine
//   Initialize the TCD DACs to "safe" values
//   Calibrate the ADCs
//   Loop:
//      Check if we received a command on EP1OUT
//      Check is we received setup data token on EP0, and handle it
////////////////////////////////////////////////////////////////////////////
void main(void)
{
  __xdata unsigned char i = 0;
  __xdata unsigned char j = 0;
  
#ifdef DEBUG // If debugging is enabled, set up the serial port
  sio0_init(BAUDRATE);
  printf("\n-------------------------------------\n");
  printf("TCD2 USB Board is alive!\n");
  printf("This is TCD2 ROSTACK firmware version %d.%d\n",MAJREVNO,MINREVNO);
#endif
  // printf("About to wait for one second\n");
  // Wait for the stacks to finish their initialization
  // wait_one_second();
  //printf("Done waiting for one second\n");

  // Initialize globals
  CMDbufptr = &CMDbuffer;
  command_buffer_clear(CMDbufptr);
  CMDbufptr->mode = INIT_MODE; // we're currently in initialization, which is mode 0
  // debug 
  CMDbufptr->clev = 3; // default FPGA irqn coicidence level
  CMDbufptr->stkmsk = 0x03FF; // All stacks active
  //printf("CMDbuffer initialized\n");
  ep16_init(); // set up the endpoints
  //printf("Endpoints initialized\n");
  
  gpif_init(WaveData,InitData); // set up the GPIF
  
  //printf("gpif engine intialized\n");
  
  // Initialize interface flags
  init_flags();
  //printf("Flags initialized\n");
  
#ifdef DEBUG 
  printf("Initializations finished!\n");
#endif
  
  // Main event loop
  CMDbufptr->mode = CMD_MODE; // Now we're in command mode
  // Flush the FPGAs
  soft_resetn();
  wait_one_second();
  flushn();
  wait_one_second();
  ol_flushn();
  wait_one_second();
  stack_initialize();
  wait_one_second();
  wait_one_second();
  for(;;)
    {
      // flushn();
      // Check if there's a command pending and handle it
      if( command_receive(CMDbufptr) )
	{
	  flushn();
	}
      
      if( CMDbufptr->mode == EVT_MODE )
	if( event_receive() )
	  {
	    flushn();
	  }
    }
    
}
