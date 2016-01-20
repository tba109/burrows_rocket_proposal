/*
 * Tyler Anderson Mon Nov 22 19:37:19 EST 2010
 * From fx2lib reset function, for writing the eeprom
 * You've got to change the LG_PROM or SM_PROM depending
 * on whether you're flashing small EEPROM or large EEPROM
 * This is basically the key to renumerating!
 * The bytes to be written are in fx2_c0.c
 */

#include <stdio.h>

#include <fx2regs.h>
#include <fx2macros.h>

#include <serial.h>
#include <delay.h>
#include <i2c.h>
#include <lights.h>

#define LG_PROM 0x51  // large prom ( is 16 bit addr mode)
#define SM_PROM 0x50 // small prom

#define READ_SIZE 100

__xdata BYTE buf[READ_SIZE];

#define IIC_SIZE 8
extern __xdata BYTE fx2_c0[];

void main() {
  
 BOOL on=FALSE;
 unsigned int size=0;
 
 SETCPUFREQ(CLK_48M);
 sio0_init(57600);
 
 eeprom_write(LG_PROM, 0, IIC_SIZE, fx2_c0);
 
 while(1);
}

