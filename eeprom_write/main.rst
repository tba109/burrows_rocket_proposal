                              1 ;--------------------------------------------------------
                              2 ; File Created by SDCC : free open source ANSI-C Compiler
                              3 ; Version 3.3.0 #8604 (Dec 30 2013) (Linux)
                              4 ; This file was generated Wed Jan 20 16:16:19 2016
                              5 ;--------------------------------------------------------
                              6 	.module main
                              7 	.optsdcc -mmcs51 --model-small
                              8 	
                              9 ;--------------------------------------------------------
                             10 ; Public variables in this module
                             11 ;--------------------------------------------------------
                             12 	.globl _main
                             13 	.globl _eeprom_write
                             14 	.globl _sio0_init
                             15 	.globl _EIPX6
                             16 	.globl _EIPX5
                             17 	.globl _EIPX4
                             18 	.globl _PI2C
                             19 	.globl _PUSB
                             20 	.globl _EIEX6
                             21 	.globl _EIEX5
                             22 	.globl _EIEX4
                             23 	.globl _EI2C
                             24 	.globl _EUSB
                             25 	.globl _SMOD1
                             26 	.globl _ERESI
                             27 	.globl _RESI
                             28 	.globl _INT6
                             29 	.globl _CY
                             30 	.globl _AC
                             31 	.globl _F0
                             32 	.globl _RS1
                             33 	.globl _RS0
                             34 	.globl _OV
                             35 	.globl _FL
                             36 	.globl _P
                             37 	.globl _TF2
                             38 	.globl _EXF2
                             39 	.globl _RCLK
                             40 	.globl _TCLK
                             41 	.globl _EXEN2
                             42 	.globl _TR2
                             43 	.globl _C_T2
                             44 	.globl _CP_RL2
                             45 	.globl _SM01
                             46 	.globl _SM11
                             47 	.globl _SM21
                             48 	.globl _REN1
                             49 	.globl _TB81
                             50 	.globl _RB81
                             51 	.globl _TI1
                             52 	.globl _RI1
                             53 	.globl _PS1
                             54 	.globl _PT2
                             55 	.globl _PS0
                             56 	.globl _PT1
                             57 	.globl _PX1
                             58 	.globl _PT0
                             59 	.globl _PX0
                             60 	.globl _PD7
                             61 	.globl _PD6
                             62 	.globl _PD5
                             63 	.globl _PD4
                             64 	.globl _PD3
                             65 	.globl _PD2
                             66 	.globl _PD1
                             67 	.globl _PD0
                             68 	.globl _EA
                             69 	.globl _ES1
                             70 	.globl _ET2
                             71 	.globl _ES0
                             72 	.globl _ET1
                             73 	.globl _EX1
                             74 	.globl _ET0
                             75 	.globl _EX0
                             76 	.globl _PC7
                             77 	.globl _PC6
                             78 	.globl _PC5
                             79 	.globl _PC4
                             80 	.globl _PC3
                             81 	.globl _PC2
                             82 	.globl _PC1
                             83 	.globl _PC0
                             84 	.globl _SM0
                             85 	.globl _SM1
                             86 	.globl _SM2
                             87 	.globl _REN
                             88 	.globl _TB8
                             89 	.globl _RB8
                             90 	.globl _TI
                             91 	.globl _RI
                             92 	.globl _PB7
                             93 	.globl _PB6
                             94 	.globl _PB5
                             95 	.globl _PB4
                             96 	.globl _PB3
                             97 	.globl _PB2
                             98 	.globl _PB1
                             99 	.globl _PB0
                            100 	.globl _TF1
                            101 	.globl _TR1
                            102 	.globl _TF0
                            103 	.globl _TR0
                            104 	.globl _IE1
                            105 	.globl _IT1
                            106 	.globl _IE0
                            107 	.globl _IT0
                            108 	.globl _PA7
                            109 	.globl _PA6
                            110 	.globl _PA5
                            111 	.globl _PA4
                            112 	.globl _PA3
                            113 	.globl _PA2
                            114 	.globl _PA1
                            115 	.globl _PA0
                            116 	.globl _EIP
                            117 	.globl _B
                            118 	.globl _EIE
                            119 	.globl _ACC
                            120 	.globl _EICON
                            121 	.globl _PSW
                            122 	.globl _TH2
                            123 	.globl _TL2
                            124 	.globl _RCAP2H
                            125 	.globl _RCAP2L
                            126 	.globl _T2CON
                            127 	.globl _SBUF1
                            128 	.globl _SCON1
                            129 	.globl _GPIFSGLDATLNOX
                            130 	.globl _GPIFSGLDATLX
                            131 	.globl _GPIFSGLDATH
                            132 	.globl _GPIFTRIG
                            133 	.globl _EP01STAT
                            134 	.globl _IP
                            135 	.globl _OEE
                            136 	.globl _OED
                            137 	.globl _OEC
                            138 	.globl _OEB
                            139 	.globl _OEA
                            140 	.globl _IOE
                            141 	.globl _IOD
                            142 	.globl _AUTOPTRSETUP
                            143 	.globl _EP68FIFOFLGS
                            144 	.globl _EP24FIFOFLGS
                            145 	.globl _EP2468STAT
                            146 	.globl _IE
                            147 	.globl _INT4CLR
                            148 	.globl _INT2CLR
                            149 	.globl _IOC
                            150 	.globl _AUTOPTRL2
                            151 	.globl _AUTOPTRH2
                            152 	.globl _AUTOPTRL1
                            153 	.globl _AUTOPTRH1
                            154 	.globl _SBUF0
                            155 	.globl _SCON0
                            156 	.globl __XPAGE
                            157 	.globl _EXIF
                            158 	.globl _IOB
                            159 	.globl _CKCON
                            160 	.globl _TH1
                            161 	.globl _TH0
                            162 	.globl _TL1
                            163 	.globl _TL0
                            164 	.globl _TMOD
                            165 	.globl _TCON
                            166 	.globl _PCON
                            167 	.globl _DPS
                            168 	.globl _DPH1
                            169 	.globl _DPL1
                            170 	.globl _DPH
                            171 	.globl _DPL
                            172 	.globl _SP
                            173 	.globl _IOA
                            174 	.globl _buf
                            175 	.globl _D5OFF
                            176 	.globl _D5ON
                            177 	.globl _D4OFF
                            178 	.globl _D4ON
                            179 	.globl _D3OFF
                            180 	.globl _D3ON
                            181 	.globl _D2OFF
                            182 	.globl _D2ON
                            183 	.globl _GPCR2
                            184 	.globl _ECC2B2
                            185 	.globl _ECC2B1
                            186 	.globl _ECC2B0
                            187 	.globl _ECC1B2
                            188 	.globl _ECC1B1
                            189 	.globl _ECC1B0
                            190 	.globl _ECCRESET
                            191 	.globl _ECCCFG
                            192 	.globl _EP8FIFOBUF
                            193 	.globl _EP6FIFOBUF
                            194 	.globl _EP4FIFOBUF
                            195 	.globl _EP2FIFOBUF
                            196 	.globl _EP1INBUF
                            197 	.globl _EP1OUTBUF
                            198 	.globl _EP0BUF
                            199 	.globl _UDMACRCQUAL
                            200 	.globl _UDMACRCL
                            201 	.globl _UDMACRCH
                            202 	.globl _GPIFHOLDAMOUNT
                            203 	.globl _FLOWSTBHPERIOD
                            204 	.globl _FLOWSTBEDGE
                            205 	.globl _FLOWSTB
                            206 	.globl _FLOWHOLDOFF
                            207 	.globl _FLOWEQ1CTL
                            208 	.globl _FLOWEQ0CTL
                            209 	.globl _FLOWLOGIC
                            210 	.globl _FLOWSTATE
                            211 	.globl _GPIFABORT
                            212 	.globl _GPIFREADYSTAT
                            213 	.globl _GPIFREADYCFG
                            214 	.globl _XGPIFSGLDATLNOX
                            215 	.globl _XGPIFSGLDATLX
                            216 	.globl _XGPIFSGLDATH
                            217 	.globl _EP8GPIFTRIG
                            218 	.globl _EP8GPIFPFSTOP
                            219 	.globl _EP8GPIFFLGSEL
                            220 	.globl _EP6GPIFTRIG
                            221 	.globl _EP6GPIFPFSTOP
                            222 	.globl _EP6GPIFFLGSEL
                            223 	.globl _EP4GPIFTRIG
                            224 	.globl _EP4GPIFPFSTOP
                            225 	.globl _EP4GPIFFLGSEL
                            226 	.globl _EP2GPIFTRIG
                            227 	.globl _EP2GPIFPFSTOP
                            228 	.globl _EP2GPIFFLGSEL
                            229 	.globl _GPIFTCB0
                            230 	.globl _GPIFTCB1
                            231 	.globl _GPIFTCB2
                            232 	.globl _GPIFTCB3
                            233 	.globl _GPIFADRL
                            234 	.globl _GPIFADRH
                            235 	.globl _GPIFCTLCFG
                            236 	.globl _GPIFIDLECTL
                            237 	.globl _GPIFIDLECS
                            238 	.globl _GPIFWFSELECT
                            239 	.globl _SETUPDAT
                            240 	.globl _SUDPTRCTL
                            241 	.globl _SUDPTRL
                            242 	.globl _SUDPTRH
                            243 	.globl _EP8FIFOBCL
                            244 	.globl _EP8FIFOBCH
                            245 	.globl _EP6FIFOBCL
                            246 	.globl _EP6FIFOBCH
                            247 	.globl _EP4FIFOBCL
                            248 	.globl _EP4FIFOBCH
                            249 	.globl _EP2FIFOBCL
                            250 	.globl _EP2FIFOBCH
                            251 	.globl _EP8FIFOFLGS
                            252 	.globl _EP6FIFOFLGS
                            253 	.globl _EP4FIFOFLGS
                            254 	.globl _EP2FIFOFLGS
                            255 	.globl _EP8CS
                            256 	.globl _EP6CS
                            257 	.globl _EP4CS
                            258 	.globl _EP2CS
                            259 	.globl _EP1INCS
                            260 	.globl _EP1OUTCS
                            261 	.globl _EP0CS
                            262 	.globl _EP8BCL
                            263 	.globl _EP8BCH
                            264 	.globl _EP6BCL
                            265 	.globl _EP6BCH
                            266 	.globl _EP4BCL
                            267 	.globl _EP4BCH
                            268 	.globl _EP2BCL
                            269 	.globl _EP2BCH
                            270 	.globl _EP1INBC
                            271 	.globl _EP1OUTBC
                            272 	.globl _EP0BCL
                            273 	.globl _EP0BCH
                            274 	.globl _FNADDR
                            275 	.globl _MICROFRAME
                            276 	.globl _USBFRAMEL
                            277 	.globl _USBFRAMEH
                            278 	.globl _TOGCTL
                            279 	.globl _WAKEUPCS
                            280 	.globl _SUSPEND
                            281 	.globl _USBCS
                            282 	.globl _XAUTODAT2
                            283 	.globl _XAUTODAT1
                            284 	.globl _I2CTL
                            285 	.globl _I2DAT
                            286 	.globl _I2CS
                            287 	.globl _PORTECFG
                            288 	.globl _PORTCCFG
                            289 	.globl _PORTACFG
                            290 	.globl _INTSETUP
                            291 	.globl _INT4IVEC
                            292 	.globl _INT2IVEC
                            293 	.globl _CLRERRCNT
                            294 	.globl _ERRCNTLIM
                            295 	.globl _USBERRIRQ
                            296 	.globl _USBERRIE
                            297 	.globl _GPIFIRQ
                            298 	.globl _GPIFIE
                            299 	.globl _EPIRQ
                            300 	.globl _EPIE
                            301 	.globl _USBIRQ
                            302 	.globl _USBIE
                            303 	.globl _NAKIRQ
                            304 	.globl _NAKIE
                            305 	.globl _IBNIRQ
                            306 	.globl _IBNIE
                            307 	.globl _EP8FIFOIRQ
                            308 	.globl _EP8FIFOIE
                            309 	.globl _EP6FIFOIRQ
                            310 	.globl _EP6FIFOIE
                            311 	.globl _EP4FIFOIRQ
                            312 	.globl _EP4FIFOIE
                            313 	.globl _EP2FIFOIRQ
                            314 	.globl _EP2FIFOIE
                            315 	.globl _OUTPKTEND
                            316 	.globl _INPKTEND
                            317 	.globl _EP8ISOINPKTS
                            318 	.globl _EP6ISOINPKTS
                            319 	.globl _EP4ISOINPKTS
                            320 	.globl _EP2ISOINPKTS
                            321 	.globl _EP8FIFOPFL
                            322 	.globl _EP8FIFOPFH
                            323 	.globl _EP6FIFOPFL
                            324 	.globl _EP6FIFOPFH
                            325 	.globl _EP4FIFOPFL
                            326 	.globl _EP4FIFOPFH
                            327 	.globl _EP2FIFOPFL
                            328 	.globl _EP2FIFOPFH
                            329 	.globl _EP8AUTOINLENL
                            330 	.globl _EP8AUTOINLENH
                            331 	.globl _EP6AUTOINLENL
                            332 	.globl _EP6AUTOINLENH
                            333 	.globl _EP4AUTOINLENL
                            334 	.globl _EP4AUTOINLENH
                            335 	.globl _EP2AUTOINLENL
                            336 	.globl _EP2AUTOINLENH
                            337 	.globl _EP8FIFOCFG
                            338 	.globl _EP6FIFOCFG
                            339 	.globl _EP4FIFOCFG
                            340 	.globl _EP2FIFOCFG
                            341 	.globl _EP8CFG
                            342 	.globl _EP6CFG
                            343 	.globl _EP4CFG
                            344 	.globl _EP2CFG
                            345 	.globl _EP1INCFG
                            346 	.globl _EP1OUTCFG
                            347 	.globl _REVCTL
                            348 	.globl _REVID
                            349 	.globl _FIFOPINPOLAR
                            350 	.globl _UART230
                            351 	.globl _BPADDRL
                            352 	.globl _BPADDRH
                            353 	.globl _BREAKPT
                            354 	.globl _FIFORESET
                            355 	.globl _PINFLAGSCD
                            356 	.globl _PINFLAGSAB
                            357 	.globl _IFCONFIG
                            358 	.globl _CPUCS
                            359 	.globl _RES_WAVEDATA_END
                            360 	.globl _GPIF_WAVE_DATA
                            361 ;--------------------------------------------------------
                            362 ; special function registers
                            363 ;--------------------------------------------------------
                            364 	.area RSEG    (ABS,DATA)
   0000                     365 	.org 0x0000
                     0080   366 _IOA	=	0x0080
                     0081   367 _SP	=	0x0081
                     0082   368 _DPL	=	0x0082
                     0083   369 _DPH	=	0x0083
                     0084   370 _DPL1	=	0x0084
                     0085   371 _DPH1	=	0x0085
                     0086   372 _DPS	=	0x0086
                     0087   373 _PCON	=	0x0087
                     0088   374 _TCON	=	0x0088
                     0089   375 _TMOD	=	0x0089
                     008A   376 _TL0	=	0x008a
                     008B   377 _TL1	=	0x008b
                     008C   378 _TH0	=	0x008c
                     008D   379 _TH1	=	0x008d
                     008E   380 _CKCON	=	0x008e
                     0090   381 _IOB	=	0x0090
                     0091   382 _EXIF	=	0x0091
                     0092   383 __XPAGE	=	0x0092
                     0098   384 _SCON0	=	0x0098
                     0099   385 _SBUF0	=	0x0099
                     009A   386 _AUTOPTRH1	=	0x009a
                     009B   387 _AUTOPTRL1	=	0x009b
                     009D   388 _AUTOPTRH2	=	0x009d
                     009E   389 _AUTOPTRL2	=	0x009e
                     00A0   390 _IOC	=	0x00a0
                     00A1   391 _INT2CLR	=	0x00a1
                     00A2   392 _INT4CLR	=	0x00a2
                     00A8   393 _IE	=	0x00a8
                     00AA   394 _EP2468STAT	=	0x00aa
                     00AB   395 _EP24FIFOFLGS	=	0x00ab
                     00AC   396 _EP68FIFOFLGS	=	0x00ac
                     00AF   397 _AUTOPTRSETUP	=	0x00af
                     00B0   398 _IOD	=	0x00b0
                     00B1   399 _IOE	=	0x00b1
                     00B2   400 _OEA	=	0x00b2
                     00B3   401 _OEB	=	0x00b3
                     00B4   402 _OEC	=	0x00b4
                     00B5   403 _OED	=	0x00b5
                     00B6   404 _OEE	=	0x00b6
                     00B8   405 _IP	=	0x00b8
                     00BA   406 _EP01STAT	=	0x00ba
                     00BB   407 _GPIFTRIG	=	0x00bb
                     00BD   408 _GPIFSGLDATH	=	0x00bd
                     00BE   409 _GPIFSGLDATLX	=	0x00be
                     00BF   410 _GPIFSGLDATLNOX	=	0x00bf
                     00C0   411 _SCON1	=	0x00c0
                     00C1   412 _SBUF1	=	0x00c1
                     00C8   413 _T2CON	=	0x00c8
                     00CA   414 _RCAP2L	=	0x00ca
                     00CB   415 _RCAP2H	=	0x00cb
                     00CC   416 _TL2	=	0x00cc
                     00CD   417 _TH2	=	0x00cd
                     00D0   418 _PSW	=	0x00d0
                     00D8   419 _EICON	=	0x00d8
                     00E0   420 _ACC	=	0x00e0
                     00E8   421 _EIE	=	0x00e8
                     00F0   422 _B	=	0x00f0
                     00F8   423 _EIP	=	0x00f8
                            424 ;--------------------------------------------------------
                            425 ; special function bits
                            426 ;--------------------------------------------------------
                            427 	.area RSEG    (ABS,DATA)
   0000                     428 	.org 0x0000
                     0080   429 _PA0	=	0x0080
                     0081   430 _PA1	=	0x0081
                     0082   431 _PA2	=	0x0082
                     0083   432 _PA3	=	0x0083
                     0084   433 _PA4	=	0x0084
                     0085   434 _PA5	=	0x0085
                     0086   435 _PA6	=	0x0086
                     0087   436 _PA7	=	0x0087
                     0088   437 _IT0	=	0x0088
                     0089   438 _IE0	=	0x0089
                     008A   439 _IT1	=	0x008a
                     008B   440 _IE1	=	0x008b
                     008C   441 _TR0	=	0x008c
                     008D   442 _TF0	=	0x008d
                     008E   443 _TR1	=	0x008e
                     008F   444 _TF1	=	0x008f
                     0090   445 _PB0	=	0x0090
                     0091   446 _PB1	=	0x0091
                     0092   447 _PB2	=	0x0092
                     0093   448 _PB3	=	0x0093
                     0094   449 _PB4	=	0x0094
                     0095   450 _PB5	=	0x0095
                     0096   451 _PB6	=	0x0096
                     0097   452 _PB7	=	0x0097
                     0098   453 _RI	=	0x0098
                     0099   454 _TI	=	0x0099
                     009A   455 _RB8	=	0x009a
                     009B   456 _TB8	=	0x009b
                     009C   457 _REN	=	0x009c
                     009D   458 _SM2	=	0x009d
                     009E   459 _SM1	=	0x009e
                     009F   460 _SM0	=	0x009f
                     00A0   461 _PC0	=	0x00a0
                     00A1   462 _PC1	=	0x00a1
                     00A2   463 _PC2	=	0x00a2
                     00A3   464 _PC3	=	0x00a3
                     00A4   465 _PC4	=	0x00a4
                     00A5   466 _PC5	=	0x00a5
                     00A6   467 _PC6	=	0x00a6
                     00A7   468 _PC7	=	0x00a7
                     00A8   469 _EX0	=	0x00a8
                     00A9   470 _ET0	=	0x00a9
                     00AA   471 _EX1	=	0x00aa
                     00AB   472 _ET1	=	0x00ab
                     00AC   473 _ES0	=	0x00ac
                     00AD   474 _ET2	=	0x00ad
                     00AE   475 _ES1	=	0x00ae
                     00AF   476 _EA	=	0x00af
                     00B0   477 _PD0	=	0x00b0
                     00B1   478 _PD1	=	0x00b1
                     00B2   479 _PD2	=	0x00b2
                     00B3   480 _PD3	=	0x00b3
                     00B4   481 _PD4	=	0x00b4
                     00B5   482 _PD5	=	0x00b5
                     00B6   483 _PD6	=	0x00b6
                     00B7   484 _PD7	=	0x00b7
                     00B8   485 _PX0	=	0x00b8
                     00B9   486 _PT0	=	0x00b9
                     00BA   487 _PX1	=	0x00ba
                     00BB   488 _PT1	=	0x00bb
                     00BC   489 _PS0	=	0x00bc
                     00BD   490 _PT2	=	0x00bd
                     00BE   491 _PS1	=	0x00be
                     00C0   492 _RI1	=	0x00c0
                     00C1   493 _TI1	=	0x00c1
                     00C2   494 _RB81	=	0x00c2
                     00C3   495 _TB81	=	0x00c3
                     00C4   496 _REN1	=	0x00c4
                     00C5   497 _SM21	=	0x00c5
                     00C6   498 _SM11	=	0x00c6
                     00C7   499 _SM01	=	0x00c7
                     00C8   500 _CP_RL2	=	0x00c8
                     00C9   501 _C_T2	=	0x00c9
                     00CA   502 _TR2	=	0x00ca
                     00CB   503 _EXEN2	=	0x00cb
                     00CC   504 _TCLK	=	0x00cc
                     00CD   505 _RCLK	=	0x00cd
                     00CE   506 _EXF2	=	0x00ce
                     00CF   507 _TF2	=	0x00cf
                     00D0   508 _P	=	0x00d0
                     00D1   509 _FL	=	0x00d1
                     00D2   510 _OV	=	0x00d2
                     00D3   511 _RS0	=	0x00d3
                     00D4   512 _RS1	=	0x00d4
                     00D5   513 _F0	=	0x00d5
                     00D6   514 _AC	=	0x00d6
                     00D7   515 _CY	=	0x00d7
                     00DB   516 _INT6	=	0x00db
                     00DC   517 _RESI	=	0x00dc
                     00DD   518 _ERESI	=	0x00dd
                     00DF   519 _SMOD1	=	0x00df
                     00E8   520 _EUSB	=	0x00e8
                     00E9   521 _EI2C	=	0x00e9
                     00EA   522 _EIEX4	=	0x00ea
                     00EB   523 _EIEX5	=	0x00eb
                     00EC   524 _EIEX6	=	0x00ec
                     00F8   525 _PUSB	=	0x00f8
                     00F9   526 _PI2C	=	0x00f9
                     00FA   527 _EIPX4	=	0x00fa
                     00FB   528 _EIPX5	=	0x00fb
                     00FC   529 _EIPX6	=	0x00fc
                            530 ;--------------------------------------------------------
                            531 ; overlayable register banks
                            532 ;--------------------------------------------------------
                            533 	.area REG_BANK_0	(REL,OVR,DATA)
   0000                     534 	.ds 8
                            535 ;--------------------------------------------------------
                            536 ; internal ram data
                            537 ;--------------------------------------------------------
                            538 	.area DSEG    (DATA)
                            539 ;--------------------------------------------------------
                            540 ; overlayable items in internal ram 
                            541 ;--------------------------------------------------------
                            542 ;--------------------------------------------------------
                            543 ; Stack segment in internal ram 
                            544 ;--------------------------------------------------------
                            545 	.area	SSEG	(DATA)
   003A                     546 __start__stack:
   003A                     547 	.ds	1
                            548 
                            549 ;--------------------------------------------------------
                            550 ; indirectly addressable internal ram data
                            551 ;--------------------------------------------------------
                            552 	.area ISEG    (DATA)
                            553 ;--------------------------------------------------------
                            554 ; absolute internal ram data
                            555 ;--------------------------------------------------------
                            556 	.area IABS    (ABS,DATA)
                            557 	.area IABS    (ABS,DATA)
                            558 ;--------------------------------------------------------
                            559 ; bit data
                            560 ;--------------------------------------------------------
                            561 	.area BSEG    (BIT)
                            562 ;--------------------------------------------------------
                            563 ; paged external ram data
                            564 ;--------------------------------------------------------
                            565 	.area PSEG    (PAG,XDATA)
                            566 ;--------------------------------------------------------
                            567 ; external ram data
                            568 ;--------------------------------------------------------
                            569 	.area XSEG    (XDATA)
                     E400   570 _GPIF_WAVE_DATA	=	0xe400
                     E480   571 _RES_WAVEDATA_END	=	0xe480
                     E600   572 _CPUCS	=	0xe600
                     E601   573 _IFCONFIG	=	0xe601
                     E602   574 _PINFLAGSAB	=	0xe602
                     E603   575 _PINFLAGSCD	=	0xe603
                     E604   576 _FIFORESET	=	0xe604
                     E605   577 _BREAKPT	=	0xe605
                     E606   578 _BPADDRH	=	0xe606
                     E607   579 _BPADDRL	=	0xe607
                     E608   580 _UART230	=	0xe608
                     E609   581 _FIFOPINPOLAR	=	0xe609
                     E60A   582 _REVID	=	0xe60a
                     E60B   583 _REVCTL	=	0xe60b
                     E610   584 _EP1OUTCFG	=	0xe610
                     E611   585 _EP1INCFG	=	0xe611
                     E612   586 _EP2CFG	=	0xe612
                     E613   587 _EP4CFG	=	0xe613
                     E614   588 _EP6CFG	=	0xe614
                     E615   589 _EP8CFG	=	0xe615
                     E618   590 _EP2FIFOCFG	=	0xe618
                     E619   591 _EP4FIFOCFG	=	0xe619
                     E61A   592 _EP6FIFOCFG	=	0xe61a
                     E61B   593 _EP8FIFOCFG	=	0xe61b
                     E620   594 _EP2AUTOINLENH	=	0xe620
                     E621   595 _EP2AUTOINLENL	=	0xe621
                     E622   596 _EP4AUTOINLENH	=	0xe622
                     E623   597 _EP4AUTOINLENL	=	0xe623
                     E624   598 _EP6AUTOINLENH	=	0xe624
                     E625   599 _EP6AUTOINLENL	=	0xe625
                     E626   600 _EP8AUTOINLENH	=	0xe626
                     E627   601 _EP8AUTOINLENL	=	0xe627
                     E630   602 _EP2FIFOPFH	=	0xe630
                     E631   603 _EP2FIFOPFL	=	0xe631
                     E632   604 _EP4FIFOPFH	=	0xe632
                     E633   605 _EP4FIFOPFL	=	0xe633
                     E634   606 _EP6FIFOPFH	=	0xe634
                     E635   607 _EP6FIFOPFL	=	0xe635
                     E636   608 _EP8FIFOPFH	=	0xe636
                     E637   609 _EP8FIFOPFL	=	0xe637
                     E640   610 _EP2ISOINPKTS	=	0xe640
                     E641   611 _EP4ISOINPKTS	=	0xe641
                     E642   612 _EP6ISOINPKTS	=	0xe642
                     E643   613 _EP8ISOINPKTS	=	0xe643
                     E648   614 _INPKTEND	=	0xe648
                     E649   615 _OUTPKTEND	=	0xe649
                     E650   616 _EP2FIFOIE	=	0xe650
                     E651   617 _EP2FIFOIRQ	=	0xe651
                     E652   618 _EP4FIFOIE	=	0xe652
                     E653   619 _EP4FIFOIRQ	=	0xe653
                     E654   620 _EP6FIFOIE	=	0xe654
                     E655   621 _EP6FIFOIRQ	=	0xe655
                     E656   622 _EP8FIFOIE	=	0xe656
                     E657   623 _EP8FIFOIRQ	=	0xe657
                     E658   624 _IBNIE	=	0xe658
                     E659   625 _IBNIRQ	=	0xe659
                     E65A   626 _NAKIE	=	0xe65a
                     E65B   627 _NAKIRQ	=	0xe65b
                     E65C   628 _USBIE	=	0xe65c
                     E65D   629 _USBIRQ	=	0xe65d
                     E65E   630 _EPIE	=	0xe65e
                     E65F   631 _EPIRQ	=	0xe65f
                     E660   632 _GPIFIE	=	0xe660
                     E661   633 _GPIFIRQ	=	0xe661
                     E662   634 _USBERRIE	=	0xe662
                     E663   635 _USBERRIRQ	=	0xe663
                     E664   636 _ERRCNTLIM	=	0xe664
                     E665   637 _CLRERRCNT	=	0xe665
                     E666   638 _INT2IVEC	=	0xe666
                     E667   639 _INT4IVEC	=	0xe667
                     E668   640 _INTSETUP	=	0xe668
                     E670   641 _PORTACFG	=	0xe670
                     E671   642 _PORTCCFG	=	0xe671
                     E672   643 _PORTECFG	=	0xe672
                     E678   644 _I2CS	=	0xe678
                     E679   645 _I2DAT	=	0xe679
                     E67A   646 _I2CTL	=	0xe67a
                     E67B   647 _XAUTODAT1	=	0xe67b
                     E67C   648 _XAUTODAT2	=	0xe67c
                     E680   649 _USBCS	=	0xe680
                     E681   650 _SUSPEND	=	0xe681
                     E682   651 _WAKEUPCS	=	0xe682
                     E683   652 _TOGCTL	=	0xe683
                     E684   653 _USBFRAMEH	=	0xe684
                     E685   654 _USBFRAMEL	=	0xe685
                     E686   655 _MICROFRAME	=	0xe686
                     E687   656 _FNADDR	=	0xe687
                     E68A   657 _EP0BCH	=	0xe68a
                     E68B   658 _EP0BCL	=	0xe68b
                     E68D   659 _EP1OUTBC	=	0xe68d
                     E68F   660 _EP1INBC	=	0xe68f
                     E690   661 _EP2BCH	=	0xe690
                     E691   662 _EP2BCL	=	0xe691
                     E694   663 _EP4BCH	=	0xe694
                     E695   664 _EP4BCL	=	0xe695
                     E698   665 _EP6BCH	=	0xe698
                     E699   666 _EP6BCL	=	0xe699
                     E69C   667 _EP8BCH	=	0xe69c
                     E69D   668 _EP8BCL	=	0xe69d
                     E6A0   669 _EP0CS	=	0xe6a0
                     E6A1   670 _EP1OUTCS	=	0xe6a1
                     E6A2   671 _EP1INCS	=	0xe6a2
                     E6A3   672 _EP2CS	=	0xe6a3
                     E6A4   673 _EP4CS	=	0xe6a4
                     E6A5   674 _EP6CS	=	0xe6a5
                     E6A6   675 _EP8CS	=	0xe6a6
                     E6A7   676 _EP2FIFOFLGS	=	0xe6a7
                     E6A8   677 _EP4FIFOFLGS	=	0xe6a8
                     E6A9   678 _EP6FIFOFLGS	=	0xe6a9
                     E6AA   679 _EP8FIFOFLGS	=	0xe6aa
                     E6AB   680 _EP2FIFOBCH	=	0xe6ab
                     E6AC   681 _EP2FIFOBCL	=	0xe6ac
                     E6AD   682 _EP4FIFOBCH	=	0xe6ad
                     E6AE   683 _EP4FIFOBCL	=	0xe6ae
                     E6AF   684 _EP6FIFOBCH	=	0xe6af
                     E6B0   685 _EP6FIFOBCL	=	0xe6b0
                     E6B1   686 _EP8FIFOBCH	=	0xe6b1
                     E6B2   687 _EP8FIFOBCL	=	0xe6b2
                     E6B3   688 _SUDPTRH	=	0xe6b3
                     E6B4   689 _SUDPTRL	=	0xe6b4
                     E6B5   690 _SUDPTRCTL	=	0xe6b5
                     E6B8   691 _SETUPDAT	=	0xe6b8
                     E6C0   692 _GPIFWFSELECT	=	0xe6c0
                     E6C1   693 _GPIFIDLECS	=	0xe6c1
                     E6C2   694 _GPIFIDLECTL	=	0xe6c2
                     E6C3   695 _GPIFCTLCFG	=	0xe6c3
                     E6C4   696 _GPIFADRH	=	0xe6c4
                     E6C5   697 _GPIFADRL	=	0xe6c5
                     E6CE   698 _GPIFTCB3	=	0xe6ce
                     E6CF   699 _GPIFTCB2	=	0xe6cf
                     E6D0   700 _GPIFTCB1	=	0xe6d0
                     E6D1   701 _GPIFTCB0	=	0xe6d1
                     E6D2   702 _EP2GPIFFLGSEL	=	0xe6d2
                     E6D3   703 _EP2GPIFPFSTOP	=	0xe6d3
                     E6D4   704 _EP2GPIFTRIG	=	0xe6d4
                     E6DA   705 _EP4GPIFFLGSEL	=	0xe6da
                     E6DB   706 _EP4GPIFPFSTOP	=	0xe6db
                     E6DC   707 _EP4GPIFTRIG	=	0xe6dc
                     E6E2   708 _EP6GPIFFLGSEL	=	0xe6e2
                     E6E3   709 _EP6GPIFPFSTOP	=	0xe6e3
                     E6E4   710 _EP6GPIFTRIG	=	0xe6e4
                     E6EA   711 _EP8GPIFFLGSEL	=	0xe6ea
                     E6EB   712 _EP8GPIFPFSTOP	=	0xe6eb
                     E6EC   713 _EP8GPIFTRIG	=	0xe6ec
                     E6F0   714 _XGPIFSGLDATH	=	0xe6f0
                     E6F1   715 _XGPIFSGLDATLX	=	0xe6f1
                     E6F2   716 _XGPIFSGLDATLNOX	=	0xe6f2
                     E6F3   717 _GPIFREADYCFG	=	0xe6f3
                     E6F4   718 _GPIFREADYSTAT	=	0xe6f4
                     E6F5   719 _GPIFABORT	=	0xe6f5
                     E6C6   720 _FLOWSTATE	=	0xe6c6
                     E6C7   721 _FLOWLOGIC	=	0xe6c7
                     E6C8   722 _FLOWEQ0CTL	=	0xe6c8
                     E6C9   723 _FLOWEQ1CTL	=	0xe6c9
                     E6CA   724 _FLOWHOLDOFF	=	0xe6ca
                     E6CB   725 _FLOWSTB	=	0xe6cb
                     E6CC   726 _FLOWSTBEDGE	=	0xe6cc
                     E6CD   727 _FLOWSTBHPERIOD	=	0xe6cd
                     E60C   728 _GPIFHOLDAMOUNT	=	0xe60c
                     E67D   729 _UDMACRCH	=	0xe67d
                     E67E   730 _UDMACRCL	=	0xe67e
                     E67F   731 _UDMACRCQUAL	=	0xe67f
                     E740   732 _EP0BUF	=	0xe740
                     E780   733 _EP1OUTBUF	=	0xe780
                     E7C0   734 _EP1INBUF	=	0xe7c0
                     F000   735 _EP2FIFOBUF	=	0xf000
                     F400   736 _EP4FIFOBUF	=	0xf400
                     F800   737 _EP6FIFOBUF	=	0xf800
                     FC00   738 _EP8FIFOBUF	=	0xfc00
                     E628   739 _ECCCFG	=	0xe628
                     E629   740 _ECCRESET	=	0xe629
                     E62A   741 _ECC1B0	=	0xe62a
                     E62B   742 _ECC1B1	=	0xe62b
                     E62C   743 _ECC1B2	=	0xe62c
                     E62D   744 _ECC2B0	=	0xe62d
                     E62E   745 _ECC2B1	=	0xe62e
                     E62F   746 _ECC2B2	=	0xe62f
                     E50D   747 _GPCR2	=	0xe50d
                     8800   748 _D2ON	=	0x8800
                     8000   749 _D2OFF	=	0x8000
                     9800   750 _D3ON	=	0x9800
                     9000   751 _D3OFF	=	0x9000
                     A800   752 _D4ON	=	0xa800
                     A000   753 _D4OFF	=	0xa000
                     B800   754 _D5ON	=	0xb800
                     B000   755 _D5OFF	=	0xb000
   3000                     756 _buf::
   3000                     757 	.ds 100
                            758 ;--------------------------------------------------------
                            759 ; absolute external ram data
                            760 ;--------------------------------------------------------
                            761 	.area XABS    (ABS,XDATA)
                            762 ;--------------------------------------------------------
                            763 ; external initialized ram data
                            764 ;--------------------------------------------------------
                            765 	.area XISEG   (XDATA)
                            766 	.area HOME    (CODE)
                            767 	.area GSINIT0 (CODE)
                            768 	.area GSINIT1 (CODE)
                            769 	.area GSINIT2 (CODE)
                            770 	.area GSINIT3 (CODE)
                            771 	.area GSINIT4 (CODE)
                            772 	.area GSINIT5 (CODE)
                            773 	.area GSINIT  (CODE)
                            774 	.area GSFINAL (CODE)
                            775 	.area CSEG    (CODE)
                            776 ;--------------------------------------------------------
                            777 ; interrupt vector 
                            778 ;--------------------------------------------------------
                            779 	.area HOME    (CODE)
   0000                     780 __interrupt_vect:
   0000 02 00 06      [24]  781 	ljmp	__sdcc_gsinit_startup
                            782 ;--------------------------------------------------------
                            783 ; global & static initialisations
                            784 ;--------------------------------------------------------
                            785 	.area HOME    (CODE)
                            786 	.area GSINIT  (CODE)
                            787 	.area GSFINAL (CODE)
                            788 	.area GSINIT  (CODE)
                            789 	.globl __sdcc_gsinit_startup
                            790 	.globl __sdcc_program_startup
                            791 	.globl __start__stack
                            792 	.globl __mcs51_genXINIT
                            793 	.globl __mcs51_genXRAMCLEAR
                            794 	.globl __mcs51_genRAMCLEAR
                            795 	.area GSFINAL (CODE)
   005F 02 00 03      [24]  796 	ljmp	__sdcc_program_startup
                            797 ;--------------------------------------------------------
                            798 ; Home
                            799 ;--------------------------------------------------------
                            800 	.area HOME    (CODE)
                            801 	.area HOME    (CODE)
   0003                     802 __sdcc_program_startup:
   0003 02 00 62      [24]  803 	ljmp	_main
                            804 ;	return from main will return to caller
                            805 ;--------------------------------------------------------
                            806 ; code
                            807 ;--------------------------------------------------------
                            808 	.area CSEG    (CODE)
                            809 ;------------------------------------------------------------
                            810 ;Allocation info for local variables in function 'main'
                            811 ;------------------------------------------------------------
                            812 ;on                        Allocated to registers 
                            813 ;size                      Allocated to registers 
                            814 ;------------------------------------------------------------
                            815 ;	main.c:30: void main() {
                            816 ;	-----------------------------------------
                            817 ;	 function main
                            818 ;	-----------------------------------------
   0062                     819 _main:
                     0007   820 	ar7 = 0x07
                     0006   821 	ar6 = 0x06
                     0005   822 	ar5 = 0x05
                     0004   823 	ar4 = 0x04
                     0003   824 	ar3 = 0x03
                     0002   825 	ar2 = 0x02
                     0001   826 	ar1 = 0x01
                     0000   827 	ar0 = 0x00
                            828 ;	main.c:35: SETCPUFREQ(CLK_48M);
   0062 90 E6 00      [24]  829 	mov	dptr,#_CPUCS
   0065 E0            [24]  830 	movx	a,@dptr
   0066 FF            [12]  831 	mov	r7,a
   0067 74 E7         [12]  832 	mov	a,#0xE7
   0069 5F            [12]  833 	anl	a,r7
   006A 90 E6 00      [24]  834 	mov	dptr,#_CPUCS
   006D 44 10         [12]  835 	orl	a,#0x10
   006F F0            [24]  836 	movx	@dptr,a
                            837 ;	main.c:36: sio0_init(57600);
   0070 90 E1 00      [24]  838 	mov	dptr,#0xE100
   0073 E4            [12]  839 	clr	a
   0074 F5 F0         [12]  840 	mov	b,a
   0076 12 04 9A      [24]  841 	lcall	_sio0_init
                            842 ;	main.c:38: eeprom_write(LG_PROM, 0, IIC_SIZE, fx2_c0);
   0079 75 20 65      [24]  843 	mov	_eeprom_write_PARM_4,#_fx2_c0
   007C 75 21 30      [24]  844 	mov	(_eeprom_write_PARM_4 + 1),#(_fx2_c0 >> 8)
   007F E4            [12]  845 	clr	a
   0080 F5 22         [12]  846 	mov	(_eeprom_write_PARM_4 + 2),a
   0082 F5 1C         [12]  847 	mov	_eeprom_write_PARM_2,a
   0084 F5 1D         [12]  848 	mov	(_eeprom_write_PARM_2 + 1),a
   0086 75 1E 08      [24]  849 	mov	_eeprom_write_PARM_3,#0x08
   0089 75 1F 00      [24]  850 	mov	(_eeprom_write_PARM_3 + 1),#0x00
   008C 75 82 51      [24]  851 	mov	dpl,#0x51
   008F 12 03 84      [24]  852 	lcall	_eeprom_write
                            853 ;	main.c:40: while(1);
   0092                     854 00102$:
   0092 80 FE         [24]  855 	sjmp	00102$
                            856 	.area CSEG    (CODE)
                            857 	.area CONST   (CODE)
                            858 	.area XINIT   (CODE)
                            859 	.area CABS    (ABS,CODE)
