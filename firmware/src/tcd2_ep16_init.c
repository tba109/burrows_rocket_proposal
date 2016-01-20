/*
 * Tyler Anderson Wed Nov 24 12:02:17 EST 2010
 * Moved EP1 and EP6 initalization out of tcd2_main_ifc2.c
 * just to make things a little less cluttered.
 */

#include "tcd2_ep16_init.h"

void ep16_init(void)
{
  CPUCS=0x10; // 0001 0000
              // b7b6 = 00
              // b5   = 0, No RDn WRn strobe with PORTC
              // b4b3 = 10, 48MHz
              // b2   = 0, CLKOUT not inverted
              // b1   = 0, CLKOUT pin disabled
              // b0   = 0, Run the 8051
              // TRM 15-13

  //IFCONFIG = 0xEE;
  IFCONFIG=0xA6; // 1110 1110
                 // b7   = 1, IFCLK source is internal
                 // b6   = 0, 30 MHz
                 // b5   = 1, Do not tri-state IFCLK
                 // b4   = 0, IFCLK not inverted
                 // b3   = 0, synchronous GPIF
                 // b2   = 1, Show current GPIF state on PortE[2..0]
                 // b1b0 = 10, GPIF master mode
                 // TRM 15-16
  // Tyler Anderson Thu Jan 26 13:42:34 EST 2012
  // Changed to a 24 MHz bus speed for all FPGAs
  //IFCONFIG=0x06; // 0000 0110
                 // b7   = 0, IFCLK source is external
                 // b6   = 0, NA for external clock
                 // b5   = 0, tri-state IFCLK out
                 // b4   = 0, IFCLK not inverted
                 // b3   = 0, synchronous GPIF
                 // b2   = 1, Show current GPIF state on PortE[2..0]
                 // b1b0 = 10, GPIF master mode
                 // TRM 15-16

  // Tyler Anderson Fri Jan 27 12:41:23 EST 2012
  // Use a 30 MHz internal bus instead
  IFCONFIG=0xA6; // 1110 1110
                 // b7   = 1, IFCLK source is internal
                 // b6   = 0, 30 MHz
                 // b5   = 1, Do not tri-state IFCLK
                 // b4   = 0, IFCLK not inverted
                 // b3   = 0, synchronous GPIF
                 // b2   = 1, Show current GPIF state on PortE[2..0]
                 // b1b0 = 10, GPIF master mode
                 // TRM 15-16
  

  SYNCDELAY4;
  
  
  REVCTL=0x03;  // Boiler plate, as far as I can tell...
  SYNCDELAY4;
   
  EP1OUTCFG=0xA0; // 1010 0000
                  // b7   = 1, valid
                  // b6   = 0
                  // b5b4 = 10, bulk
                  // b3b2 = 00
                  // b1b0 = 00
                  // TRM 15-26
                  //
  SYNCDELAY4;
  
  EP1INCFG= 0xA0; // 1010 0000 (valid and bulk)
                  // b7   = 1, valid
                  // b6   = 0
                  // b5b4 = 10, bulk
                  // b3b2 = 00
                  // b1b0 = 00
                  // TRM 15-26
                  //
  SYNCDELAY4;
  
  EP1OUTBC = 0;  // Arm the OUT endpoint so that the
  SYNCDELAY4;     // SFC can write to us. This resets 
                 // EP1OUTBC.BUSY=1
  ///////////////////////////////////////////////////
  // Now perform the setup stuff for EP6OUT
  //////////////////////////////////////////////////
  EP6CFG=0xE2;  // 1010 0010 (bulk IN, 512 bytes, double-buffered)
                // b7 = 1, valid
                // b6 = 1, IN
                // b5 = 1, bulk
                // b4 = 0, SIZE
                // b3 = 0
                // b2 = 0
                // b1 = 1 // Double buffer
                // b0 = 0
  SYNCDELAY4;
   
  FIFORESET = 0x80;  SYNCDELAY4;  // NAK all requests from host. 
  FIFORESET = 0x82;  SYNCDELAY4;  // Reset individual EP (2,4,6,8)
  FIFORESET = 0x84;  SYNCDELAY4;
  FIFORESET = 0x86;  SYNCDELAY4;
  FIFORESET = 0x88;  SYNCDELAY4;
  FIFORESET = 0x00;  SYNCDELAY4;  // Resume normal operation. 
  OUTPKTEND = 0x82;  SYNCDELAY4;
  OUTPKTEND = 0x82;  SYNCDELAY4;

  EP6FIFOCFG = 0x0D; SYNCDELAY4; // EP6 AUTOIN, 16 bit wide bus
  
  // USB packet is committed. Use 440B to be sure.
  EP6AUTOINLENH = 0x01; SYNCDELAY4; // MSB 
  EP6AUTOINLENL = 0xB8; SYNCDELAY4; // LSB

  IE |= 0x80;
}
