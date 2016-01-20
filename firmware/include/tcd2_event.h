/* 
 * Tyler Anderson Tue Nov 16 17:44:55 EST 2010
 * Header for tcd2_dataread, the routines for
 * reading event data from the TCD
 */
#ifndef _TCD2_DATAREAD_H_
#define _TCD2_DATAREAD_H_

#include "tcd2_config.h"

#define NEVTS 220

// Here's the routtine for reading in an event
unsigned char event_receive();

#endif
