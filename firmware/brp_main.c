/* 
 * Tyler Anderson Wed Jan 20 17:37:14 EST 2016
 * This is the main function for the USB firmware 
 */

#define DEBUG
#define BAUDRATE 9600

// FX2LIB headers
#include <fx2regs.h>
#include <fx2macros.h>
#include <delay.h>
#include <gpif.h>
#include <serial.h>
#include <stdio.h>

static void Initialize(void)
{
  CPUCS=0x10;      SYNCDELAY4;  // 48 MHz, CLKOUT output disabled.
  IFCONFIG=0xcb;   SYNCDELAY4;  // Internal IFCLK, 48MHz, Asynchronous slave FIFO 
#ifdef DEBUG
  sio0_init(BAUDRATE);
  printf("serial port initialized\n");
#endif
  EP2CFG=0xa0;      SYNCDELAY4;    // 1010 0010 (bulk OUT, 512 bytes, quad-buffered)
  EP4CFG=0x20;      SYNCDELAY4;    // Disabled
  EP6CFG=0x60;      SYNCDELAY4;    // Disabled
  EP8CFG=0x60;      SYNCDELAY4;    // Disabled
  FIFORESET = 0x80; SYNCDELAY4;    // activate NAK-ALL to avoid race conditions
  FIFORESET = 0x02; SYNCDELAY4;    // reset, FIFO 2
  FIFORESET = 0x04; SYNCDELAY4;    // reset, FIFO 4
  FIFORESET = 0x06; SYNCDELAY4;    // reset, FIFO 6
  FIFORESET = 0x08; SYNCDELAY4;    // reset, FIFO 8
  FIFORESET = 0x00; SYNCDELAY4;    // deactivate NAK-ALL
  EP2FIFOCFG=0x00; SYNCDELAY4;     // Make sure AUTOOUT=0. (Need to see 0->1 transition)
  EP2FIFOCFG=0x11; SYNCDELAY4;     // Make sure AUTOOUT=1.
  FIFOPINPOLAR = 0x0c; SYNCDELAY4; // Set SLRD and SLWR for active high
  PORTACFG = 0x00; SYNCDELAY4;
  OEA = 0x02; 
  IOA = 0x02;
#ifdef DEBUG
  printf("gpio initialized\n");
#endif

}

void main(void)
{
  __xdata unsigned char wait_count = 0;
    
  Initialize();
    
  for(;;)
    {
      // This was tuned up to give roughly the correct pulse width/duty cycle
      IOA = IOA | 0x02;
      IOA = IOA | 0x02;
      IOA = IOA | 0x02;
      IOA = IOA | 0x02;
      IOA = IOA & 0xFD;
      for( wait_count = 0; wait_count < 11; wait_count++);
      
      // Wait for input on EP2 (EP2 non-empty).
      // if(!(EP2CS & (1<<2)))
      if(!(EP2468STAT & 0x01))
	
	{
/* #ifdef DEBUG */
/* 	  printf("Received on EP2\n"); */
/* #endif */
/* 	  IOA = IOA | 0x02; */
/* 	  IOA = IOA | 0x02; */
/* 	  IOA = IOA | 0x02; */
/* 	  IOA = IOA | 0x02; */
/* 	  IOA = IOA & 0xFD; */
	}
    }
}
