/* 
 * Tyler Anderson Tue Oct 19 13:37:59 EDT 2010
 * This is the TCD2 main firmware program
 */
// TCD2 headers
#include "tcd2_config.h"
#include "tcd2_command.h"

#include <fx2regs.h>
#include <fx2macros.h>
#include <serial.h>
#include <delay.h>
#include <usbjt.h>
#include <lights.h>
#include <setupdat.h>
#include <eputils.h>
#include <gpif.h>

#define SYNCDELAY() SYNCDELAY4
#define REARMVAL 0x80
#define REARM() EP2BCL=REARMVAL

volatile WORD bytes;
volatile bit gotbuf;
volatile BYTE icount;
volatile bit got_sud;
DWORD lcount;
bit on;
__xdata cmd_buffer CMDbuffer;
__xdata cmd_buffer * CMDbufptr;

static void ep_init(void)
{
  CPUCS=0x10; // 0001 0000
              // b7b6 = 00
              // b5   = 0, No RDn WRn strobe with PORTC
              // b4b3 = 10, 48MHz
              // b2   = 0, CLKOUT not inverted
              // b1   = 0, CLKOUT pin disabled
              // b0   = 0, Run the 8051
              // TRM 15-13
  
  IFCONFIG=0xCE; // 1100 1110
                 // b7   = 1, IFCLK source is internal
                 // b6   = 1, 48 MHz
                 // b5   = 0, Tri-state IFCLK
                 // b4   = 0, IFCLK not inverted
                 // b3   = 1, Asynchronous GPIF
                 // b2   = 1, Show current GPIF state on PortE[2..0]
                 // b1b0 = 10, GPIF master mode
                 // TRM 15-16
  SYNCDELAY4;
 

  REVCTL=0x03;  // Boiler plate, as far as I can tell...
  SYNCDELAY4;
  
  //mygpif_init();
 
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
                // b6 = 0, OUT
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
  
  OEA = 0xFF; // set PORTA as all outputs
  IOA = 0x00;
  printf("EPs inited!\n");

}

void main() 
{
  on=0;
  lcount=0;
  got_sud=FALSE;
  icount=0;
  gotbuf=FALSE;
  bytes=0;
  
  // renumerate
  RENUMERATE(); 
  
  SETCPUFREQ(CLK_48M);
  SETIF48MHZ();
  sio0_init(57600);
  
  USE_USB_INTS(); 
  ENABLE_SUDAV();
  ENABLE_SOF();
  ENABLE_HISPEED();
  ENABLE_USBRESET();
   
  // make it so we enumberate
  ep_init();
  EA=1; // global interrupt enable 
#ifdef DEBUG
  printf ( "Done initializing stuff\n" );
#endif  

  CMDbufptr = &CMDbuffer;
  command_buffer_clear(CMDbufptr);
  command_buffer_print(CMDbufptr);

  while(TRUE) 
    {
      if ( got_sud ) 
	{
#ifdef DEBUG
	  printf ( "Handle setupdata\n" );
#endif
	  handle_setupdata(); 
	  got_sud=FALSE;
	}
    }
}

// copied routines from setupdat.h
// value (low byte) = ep
#define VC_EPSTAT 0xB1

BOOL handle_vendorcommand(BYTE cmd)
{
  switch ( cmd ) 
    {
    case VC_EPSTAT:
      {         
	__xdata BYTE* pep= ep_addr(SETUPDAT[2]);
#ifdef DEBUG
	printf ( "ep %02x\n" , *pep );
#endif
	if (pep) 
	  {
	    EP0BUF[0] = *pep;
	    EP0BCH=0;
	    EP0BCL=1;
	    return TRUE;
	  } 
      }
    default:
#ifdef DEBUG
      printf ( "Need to implement vendor command: %02x\n", cmd );
#endif
    }
  return FALSE;
}

// this firmware only supports 0,0
BOOL handle_get_interface(BYTE ifc, BYTE* alt_ifc) 
{
#ifdef DEBUG
  printf ( "Get Interface\n" );
#endif
  if (ifc==0) {*alt_ifc=0; return TRUE;} else { return FALSE;}
}

BOOL handle_set_interface(BYTE ifc, BYTE alt_ifc) 
{ 
#ifdef DEBUG
  printf ( "Set interface %d to alt: %d\n" , ifc, alt_ifc );
#endif 
  
  if (ifc==0&&alt_ifc==0) 
    {
      // SEE TRM 2.3.7
      // reset toggles
      RESETTOGGLE(0x02);
      RESETTOGGLE(0x86);
      // restore endpoints to default condition
      RESETFIFO(0x02);
      EP2BCL=0x80;
      SYNCDELAY();
      EP2BCL=0X80;
      SYNCDELAY();
      RESETFIFO(0x86);
      return TRUE;
    } 
  else 
    return FALSE;
}

// get/set configuration
BYTE handle_get_configuration() 
{
  return 1; 
}

BOOL handle_set_configuration(BYTE cfg)
{ 
  return cfg==1 ? TRUE : FALSE; // we only handle cfg 1
}

// copied usb jt routines from usbjt.h
void sudav_isr() interrupt SUDAV_ISR 
{
  got_sud=TRUE;
  CLEAR_SUDAV();
}

bit on5;
__xdata WORD sofct=0;
void sof_isr () interrupt SOF_ISR using 1 
{
  ++sofct;
  if(sofct==8000) 
    { 
      // about 8000 sof interrupts per second at high speed
      on5=!on5;
      if (on5) d5on(); else d5off();
      sofct=0;
    }
  CLEAR_SOF();
}

void sutok_isr() interrupt SUTOK_ISR {}
void suspend_isr() interrupt SUSPEND_ISR {}
void usbreset_isr() interrupt USBRESET_ISR { CLEAR_USBRESET(); }
void hispeed_isr() interrupt HISPEED_ISR { handle_hispeed(); CLEAR_HISPEED(); }
void ep0ack_isr() interrupt EP0ACK_ISR {}
void ep0in_isr() interrupt EP0IN_ISR {}
void ep0out_isr() interrupt EP0OUT_ISR {}
void ep1in_isr() interrupt EP1IN_ISR {}
void ep1out_isr() interrupt EP1OUT_ISR {}
void ep2_isr() interrupt EP2_ISR {}
void ep4_isr() interrupt EP4_ISR {}
void ep6_isr() interrupt EP6_ISR {}
void ep8_isr() interrupt EP8_ISR {}
void ibn_isr() interrupt IBN_ISR {}
void ep0ping_isr() interrupt EP0PING_ISR {}
void ep1ping_isr() interrupt EP1PING_ISR {}
void ep2ping_isr() interrupt EP2PING_ISR {}
void ep4ping_isr() interrupt EP4PING_ISR {}
void ep6ping_isr() interrupt EP6PING_ISR {}
void ep8ping_isr() interrupt EP8PING_ISR {}
void errlimit_isr() interrupt ERRLIMIT_ISR {}
void ep2isoerr_isr() interrupt EP2ISOERR_ISR {}
void ep4isoerr_isr() interrupt EP4ISOERR_ISR {}
void ep6isoerr_isr() interrupt EP6ISOERR_ISR {}
void ep8isoerr_isr() interrupt EP8ISOERR_ISR {}
void spare_isr() interrupt RESERVED_ISR {}
void ep2pf_isr() interrupt EP2PF_ISR{}
void ep4pf_isr() interrupt EP4PF_ISR{}
void ep6pf_isr() interrupt EP6PF_ISR{}
void ep8pf_isr() interrupt EP8PF_ISR{}
void ep2ef_isr() interrupt EP2EF_ISR{}
void ep4ef_isr() interrupt EP4EF_ISR{}
void ep6ef_isr() interrupt EP6EF_ISR{}
void ep8ef_isr() interrupt EP8EF_ISR{}
void ep2ff_isr() interrupt EP2FF_ISR{}
void ep4ff_isr() interrupt EP4FF_ISR{}
void ep6ff_isr() interrupt EP6FF_ISR{}
void ep8ff_isr() interrupt EP8FF_ISR{}
void gpifdone_isr() interrupt GPIFDONE_ISR{}
void gpifwf_isr() interrupt GPIFWF_ISR{}
