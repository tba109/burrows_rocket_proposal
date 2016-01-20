;--------------------------------------------------------
; File Created by SDCC : free open source ANSI-C Compiler
; Version 3.3.0 #8604 (Dec 30 2013) (Linux)
; This file was generated Wed Jan 20 17:14:32 2016
;--------------------------------------------------------
	.module tcd2_gpifwvfm
	.optsdcc -mmcs51 --model-small
	
;--------------------------------------------------------
; Public variables in this module
;--------------------------------------------------------
	.globl _InitData
	.globl _FlowStates
	.globl _WaveData
;--------------------------------------------------------
; special function registers
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; special function bits
;--------------------------------------------------------
	.area RSEG    (ABS,DATA)
	.org 0x0000
;--------------------------------------------------------
; overlayable register banks
;--------------------------------------------------------
	.area REG_BANK_0	(REL,OVR,DATA)
	.ds 8
;--------------------------------------------------------
; internal ram data
;--------------------------------------------------------
	.area DSEG    (DATA)
;--------------------------------------------------------
; overlayable items in internal ram 
;--------------------------------------------------------
;--------------------------------------------------------
; indirectly addressable internal ram data
;--------------------------------------------------------
	.area ISEG    (DATA)
;--------------------------------------------------------
; absolute internal ram data
;--------------------------------------------------------
	.area IABS    (ABS,DATA)
	.area IABS    (ABS,DATA)
;--------------------------------------------------------
; bit data
;--------------------------------------------------------
	.area BSEG    (BIT)
;--------------------------------------------------------
; paged external ram data
;--------------------------------------------------------
	.area PSEG    (PAG,XDATA)
;--------------------------------------------------------
; external ram data
;--------------------------------------------------------
	.area XSEG    (XDATA)
;--------------------------------------------------------
; absolute external ram data
;--------------------------------------------------------
	.area XABS    (ABS,XDATA)
;--------------------------------------------------------
; external initialized ram data
;--------------------------------------------------------
	.area XISEG   (XDATA)
_WaveData::
	.ds 128
_FlowStates::
	.ds 36
_InitData::
	.ds 7
	.area HOME    (CODE)
	.area GSINIT0 (CODE)
	.area GSINIT1 (CODE)
	.area GSINIT2 (CODE)
	.area GSINIT3 (CODE)
	.area GSINIT4 (CODE)
	.area GSINIT5 (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area CSEG    (CODE)
;--------------------------------------------------------
; global & static initialisations
;--------------------------------------------------------
	.area HOME    (CODE)
	.area GSINIT  (CODE)
	.area GSFINAL (CODE)
	.area GSINIT  (CODE)
;--------------------------------------------------------
; Home
;--------------------------------------------------------
	.area HOME    (CODE)
	.area HOME    (CODE)
;--------------------------------------------------------
; code
;--------------------------------------------------------
	.area CSEG    (CODE)
	.area CSEG    (CODE)
	.area CONST   (CODE)
	.area XINIT   (CODE)
__xinit__WaveData:
	.db #0x81	; -127
	.db #0x04	;  4
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x07	;  7
	.db #0x01	;  1
	.db #0x02	;  2
	.db #0x02	;  2
	.db #0x02	;  2
	.db #0x02	;  2
	.db #0x02	;  2
	.db #0x02	;  2
	.db #0x00	;  0
	.db #0x1B	;  27
	.db #0x1B	;  27
	.db #0x1B	;  27
	.db #0x1B	;  27
	.db #0x1B	;  27
	.db #0x1B	;  27
	.db #0x1B	;  27
	.db #0x1F	;  31
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x3F	;  63
	.db #0x03	;  3
	.db #0x03	;  3
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x07	;  7
	.db #0x02	;  2
	.db #0x02	;  2
	.db #0x02	;  2
	.db #0x02	;  2
	.db #0x02	;  2
	.db #0x02	;  2
	.db #0x02	;  2
	.db #0x00	;  0
	.db #0x1F	;  31
	.db #0x17	;  23
	.db #0x16	;  22
	.db #0x17	;  23
	.db #0x17	;  23
	.db #0x17	;  23
	.db #0x17	;  23
	.db #0x1F	;  31
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x3F	;  63
	.db #0x81	; -127
	.db #0x08	;  8
	.db #0x04	;  4
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x07	;  7
	.db #0x01	;  1
	.db #0x00	;  0
	.db #0x02	;  2
	.db #0x04	;  4
	.db #0x08	;  8
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x1D	;  29
	.db #0x1D	;  29
	.db #0x1F	;  31
	.db #0x1F	;  31
	.db #0x1F	;  31
	.db #0x1F	;  31
	.db #0x1F	;  31
	.db #0x1F	;  31
	.db #0x09	;  9
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x3F	;  63
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x01	;  1
	.db #0x07	;  7
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x1F	;  31
	.db #0x1F	;  31
	.db #0x1F	;  31
	.db #0x1F	;  31
	.db #0x1F	;  31
	.db #0x1F	;  31
	.db #0x1F	;  31
	.db #0x1F	;  31
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x3F	;  63
__xinit__FlowStates:
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x00	;  0
__xinit__InitData:
	.db #0xC0	; -64
	.db #0x00	;  0
	.db #0x00	;  0
	.db #0x1F	;  31
	.db #0xEE	; -18
	.db #0x4E	;  78	'N'
	.db #0x00	;  0
	.area CABS    (ABS,CODE)
