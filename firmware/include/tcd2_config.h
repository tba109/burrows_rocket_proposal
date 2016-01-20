/* 
 * Tyler Anderson
 * Thu Oct  7 00:57:48 EDT 2010
 * Define all the global configuration parameters
 * and global constants here
 *
 */
#ifndef TCD2_CONFIG_H
#define TCD2_CONFIG_H

extern const char __xdata WaveData[128];
extern const char __xdata FlowStates[36];
extern const char __xdata InitData[7];                                        

// #define DEBUG // This is for writing to RS232 sio0
                // Note: main() uses this to #include <stdio.h>,
                // which is 10KB by itself. So, if you're short
                // on memory, be sure to leave this out!
                // Also note that this will slow readout way down
                // if you are getting errors because your be printing
                // messages at a horendously slow baud rate

#ifdef DEBUG
#include <serial.h>
#include <stdio.h>
#endif

// This is legacy, and shouldn't really be used
#define TIMEOUT 10000

// Looping a while loop with this while waiting for a transaction to
// complete should give a delay of about 2 x the timeout listed in microsecs
#define DTIMEOUT 100 // For data reading, about 20ms
#define CTIMEOUT 10000 // For commanding, about 20ms
                    
// TCD2 firmware revision number stuff
#define MAJREVNO 1
#define MINREVNO 2

// For debugging on sio0
#define BAUDRATE 9600

#endif 
