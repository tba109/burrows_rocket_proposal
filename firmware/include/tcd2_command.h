/*
 * Tyler Anderson
 * Wed Oct  6 23:55:47 EDT 2010
 * This is the TCD command format
 */
#ifndef _TCD2_COMMAND_H_
#define _TCD2_COMMAND_H_

#include "tcd2_config.h"

#include <fx2types.h> //Definition of BYTE, WORD
#include <fx2macros.h> //MSB, LSB

/////////////////////////////////////////////////
// Target defines
/////////////////////////////////////////////////
// b7 is the recoverable error bit. Only set when FX2LP responds that the
// command has an error.
#define ERROR 0x80
#define ERRORMASK 0x80
#define ERROROFFSET 7

// b6..b4 define action (GET, SET, etc.)
#define TCDNOP 0x00
#define GET 0x10
#define SET 0x20
#define INIT 0x30
#define EVENT 0x40
#define ACTIONMASK 0x70 
#define ACTIONOFFSET 4
#define NACTIONS 4

#define SOFTRESET 0x50
#define FLUSH 0x60
#define CLEAR 0x70

// b3..b0 define which node. Target bits
#define PXL     0x00 
#define PXR     0x01 
#define PYL     0x02 
#define PYR     0x03 
#define MXL     0x04 
#define MXR     0x05 
#define MYL     0x06 
#define MYR     0x07 
#define S3      0x08 
#define CD      0x09 
#define ROSTACK 0x0A   // Readout stack
#define NODEMASK 0x0F 
#define NODEOFFSET 0
#define NNODES 0x0B
#define NNODESDATA 0x0A

#define TCDMT PXR

// Tyler Anderson Thu Dec 16 14:17:36 EST 2010
// Per Nick Conklin's suggestion, add some node definitions for 
// setting CD values. These are the lines that should be changed
// if the relevant CD parameters are mapped to different stacks.

#define STK_CDHV1 MYL
#define STK_CDHV2 MYR
#define STK_CDTHR MXR 

//////////////////////////////////////////////////////////
// Parameter defines
/////////////////////////////////////////////////////////
#define THR00    0
#define THR01    1
#define THR02    2
#define THR03    3
#define LEVEL0   4
#define HV00     5
#define HV01     6
#define THR10    7
#define THR11    8
#define THR12    9
#define THR13    10
#define LEVEL1   11
#define HV10     12
#define HV11     13
#define DISC0    14
#define DISC1    15
#define DISC2    16
#define DISC3    17
#define CLEAR_LT 18
#define CLEAR_MT 19
#define MODE     20
#define CLEV     21
#define STKMSK   22

#define NPARAMS 23

// Here's a set of datargs that can correspond to MODE
#define INIT_MODE    0x00 // for initialization
#define CMD_MODE     0x01 // to transition to command mode
#define EVT_MODE     0x02 // to transition to event mode

// For holding data commands
typedef struct
{
  BYTE target; // b7..b5 define GET (000) or SET (001). 
               // b4..b0 define which data node
  BYTE param;
  WORD datarg;
} tcd2_command;

#define MAXNCMD 16 //64B buffer, 4B/command, so 16 command slots in buffer

typedef struct
{
  tcd2_command cmdbuf[MAXNCMD]; // command buffer
  unsigned char Ncmd; // Number of commands stored in the command buffer
  BYTE mode; // holds the current mode
  BYTE tuner; // is the autotuner on (1) or off (0)
  BYTE clev; // the coincidence level for IRQs in the overlord FPGA
  WORD stkmsk; // the active stacks to readout in the FPGA
} cmd_buffer;

////////////////////////////////////////////////////////////////////////////
// These functions are for getting or setting the action and node
// nybbles in the target byte. Since the two are intertwined into one byte
// the code looks a little cleaner if you do it this way
////////////////////////////////////////////////////////////////////////////
unsigned char get_action(unsigned char trg);
unsigned char get_action_shifted(unsigned char trg);
unsigned char get_node(unsigned char trg);
void set_action(tcd2_command * cmd, unsigned char act);
void set_action_shifted(tcd2_command * cmd, unsigned char act);
void set_node(tcd2_command * cmd, unsigned char nde);

////////////////////////////////////////////////////////////////////////////
// Initialize all members of buf to 0, and set Ncmd to the max
////////////////////////////////////////////////////////////////////////////
void command_buffer_clear(cmd_buffer * buf);

////////////////////////////////////////////////////////////////////////////
// Nicely print buf
////////////////////////////////////////////////////////////////////////////
#ifdef DEBUG
void command_buffer_print(cmd_buffer * buf);
#endif

////////////////////////////////////////////////////////////////////////////
// Put the contents of buf into EP1 and arm it. If buf EP1 not readout after
// timeout, reset EP1
////////////////////////////////////////////////////////////////////////////
void command_response(cmd_buffer *);

///////////////////////////////////////////////////////////////////////////
// Write an rostack parameter.
///////////////////////////////////////////////////////////////////////////
void command_rostack_send(cmd_buffer *, tcd2_command *);

////////////////////////////////////////////////////////////////////////////
// Return the mode in cmd if it's valid, else 0
////////////////////////////////////////////////////////////////////////////
unsigned char command_mode(tcd2_command * cmd);

////////////////////////////////////////////////////////////////////////////
// Dispatch the commands for gettings, setting, or whatever...
///////////////////////////////////////////////////////////////////////////
void command_dispatch(cmd_buffer * buf);

////////////////////////////////////////////////////////////////////////////
// receive a response from an fpga. Timeout if necessary.
///////////////////////////////////////////////////////////////////////////
void command_fpga_receive(tcd2_command * cmd, unsigned char adr);

////////////////////////////////////////////////////////////////////////////
// send a command to an fpga
///////////////////////////////////////////////////////////////////////////
void command_fpga_send(tcd2_command * cmd);

////////////////////////////////////////////////////////////////////////////
// Parse EP1OUT. If we're trying to clear the master trigger, or there's a 
// recoverable error, return 1.
// Non-recoverable errors mean it's unwise to attempt to execute any of the
// commands in EP1OUT, because it is unintelligable. This includes
// 1.) EP1OUT does not have a number of bytes commensurate
//     with an integral number of commands.
// 2.) EP1OUT does not have a target byte at the 0th, 4rd, 8th, etc
//     EP1OUT buffer positions. 
// If a non-recoverable error is found, clear the command buffer, and 
// return 1. Return 2 if the first byte said CLEARMT, since
// this operation should proceed fast, and we don't want to have to wait
// for it. Otherwise, return 0 and copy the contents of EP1OUT to the 
// command buffer.
////////////////////////////////////////////////////////////////////////////
unsigned char command_parse(cmd_buffer *);

////////////////////////////////////////////////////////////////////////////
// Check if you've received a command and process it accordingly
//   If there is data on EP1OUT, do the following
//     Suspend all interrupts (don't want to commanding to be interrupted)
//     If there are no non-recoverable errors
//       Mark the recoverable errors
//       Execute the command buffer
//     Send the command response
//     Clear the command buffer
//     Restore interrupts
//   Return a 1 if there was data, a 0 if not
////////////////////////////////////////////////////////////////////////////
unsigned char command_receive(cmd_buffer *);

////////////////////////////////////////////////////////////////////////////
// Sat Dec 31 12:54:31 EST 2011
// These functions were added as an after thought to allow the CDAQ to
// clear a given local trigger board or master trigger board
// Note that neither of these commands generate a response, and we do not
// flush after them
///////////////////////////////////////////////////////////////////////////
void master_trigger_clear();
void local_trigger_clear(unsigned char node);

////////////////////////////////////////////////////////////////////////////
// Sat Feb 11 13:56:18 EST 2012
// This function was added so that DAC initialization happens on a command,
// rather than on the RESET command
////////////////////////////////////////////////////////////////////////////
void stack_initialize();

#endif
