/*
 * Tyler Anderson Wed Apr 20 12:29:08 EDT 2011
 * Here be the implementation for changing FPGA interface flags
 */
// TCD2 headers
#include "tcd2_config.h"
#include "tcd2_flags.h"

// FX2LIB headers
#include <fx2regs.h>
#include <fx2macros.h>
#include <delay.h>
#include <gpif.h>


void init_flags()
{
  OEA = 0xBF; 
  IOA = 0xFF;
}

void flushn()
{
  int i;
  // Set PORTA5 to 0
  IOA = IOA & 0xDF;

  for(i = 0; i < 50; i++); // provide a solid flush about 44us wide

  // Set PORTA5 to 1
  IOA = IOA | 0x20;
}

void ol_flushn()
{
  int i;
  // Set PORTA4 to 0
  IOA = IOA & 0xEF;

  for(i = 0; i < 50; i++); // provide a solid flush about 44us wide

  // Set PORTA4 to 1
  IOA = IOA | 0x10;
}

void soft_resetn()
{
  int i;
  // Set PORTA3 to 0
  IOA = IOA & 0xF7;

  for(i = 0; i < 5000; i++); // provide a solid reset about 4.4ms wide

  // Set PORTA3 to 1
  IOA = IOA | 0x08;
}

unsigned char evt_pendn()
{
  // Return the value of PORTA6
  if( (IOA & 0x40) == 0x40 ) 
    return 1;
  else
    return 0;
}

void change_evt_collectn(unsigned char val)
{
  // Set PORTA7 to the value of val if it's 0 or 1. Otherwise, leave it alone. 
  if( val == 0 ) 
    IOA = IOA & 0x7F;
  if ( val == 1 )
    IOA = IOA | 0x80;
}

void change_rsp_timeoutn(unsigned char val)
{
  // Set PORTA2 to the value of val if it's 0 or 1. Otherwise, leave it alone.
  if( val == 0 ) 
    IOA = IOA & 0xFB;
  if ( val == 1 )
    IOA = IOA | 0x04;
}

void change_evt_timeoutn(unsigned char val)
{
  // Set PORTA1 to the value of val if it's 0 or 1. Otherwise, leave it alone.
  if( val == 0 ) 
    IOA = IOA & 0xFD;
  if ( val == 1 )
    IOA = IOA | 0x02;
}


