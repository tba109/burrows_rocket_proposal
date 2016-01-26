#!/usr/bin/env python

################################################################
# Tyler Anderson Sat Jan 23 20:44:59 EST 2016
# 
# Burrows Rocket Proposal (BRP) control software. 
# 
# A python command line interface for writing FITS files to
# the FX2LP board.
# 
# Revision Log:
#
# Fri Oct  2 22:22:47 EDT 2015
# Add a truncation/rounding option (useful when comparing 
# datasets where some rounding has been done). 
# 
# Tue Oct  6 23:26:19 EDT 2015
# Better formatting for status bar, including the ability to 
# mouse over pixels and see content. 
################################################################

import argparse
from astropy.io import fits
import struct
import usb1 
import os
import time
import truncr as tr

parser = argparse.ArgumentParser(prog="brp_usb",description="Read a bunch of FITS files and send them to the FX2LP board.")
parser.add_argument("--fits_list",type=str,help="file from which to read")
parser.add_argument("--truncr",type=int,help="number of LSBs to eliminate via rounding and truncation",default=0)
parser.add_argument("--verbose",help="Print additional debugging info",action="store_true")
parser.add_argument("--dryrun",help="Just process the data, don't do anything with USB.",action="store_true")
parser.add_argument("--countdebug",help="Send counting data.",action="store_true")
parser.add_argument("--version",action="version",version="%(prog)s 0.1")

args = parser.parse_args()

if not args.dryrun:
    # Load the USB firmware
    os.system("cycfx2prog -id=04b4.1010 prg:../firmware/brp_main.ihx run delay:100")

    # Set up the USB interface
    context = usb1.USBContext()
    handle = context.openByVendorIDAndProductID(0x04b4,0x1010,skip_on_error=True)
    
    if handle is None: 
        print 'Device not present, or user is not allowed to access device'
        exit(-1)
        
    handle.claimInterface(0) # or should it be 1? or maybe nothing?
    handle.setInterfaceAltSetting(0,1)
        
if args.fits_list == None:
    print "\nError! Must specify a FITS file list! Bailing!\n"
    exit(-1)

fits_list = open(args.fits_list)

for filename in fits_list:
    filename = filename[:-1]
    if args.verbose:
        print '-----------------------------------------------------------'
    print filename
        
    hdulist = fits.open(filename)

    debug_cnt = 0
    scidata = hdulist[0].data
    scidatatr = [[0 for x in range(len(scidata[0]))] for x in range(len(scidata))]
    usbdata = [[0 for x in range(len(scidata[0]))] for x in range(len(scidata))]
    cnt = 0
    for i in range(len(scidata)):
        for j in range(len(scidata[0])):
            # TBA_NOTE Tue Jan 26 12:26:07 EST 2016
            # Straight truncate, not truncate and round
            # scidatatr[i][j] = int(tr.truncr(scidata[i][j],args.truncr))
            scidatatr[i][j] = int(tr.trunc(scidata[i][j],args.truncr))
            # TBA_NOTE Tue Jan 26 11:51:59 EST 2016
            # 
            # usbdata[i][j] = ((i==0 and j==0)<<15) | (cnt << 12) | (0x0FFF & int(scidatatr[i][j]))
            usbdata[i][j] = ((i==0 and j==0)<<15) | ((j==0)<<14)| (cnt << 12) | (0x0FFF & int(scidatatr[i][j]))
            if args.countdebug:
                # Mon Jan 25 14:20:03 EST 2016
                # TBA_NOTE: This was added as a debug for Ted
                # TBA_NOTE Tue Jan 26 11:51:59 EST 2016: Change with a frame and row sync
                # bits 15 and 14
                # usbdata[i][j] = ((i==0 and j==0)<<15) | (cnt << 12) | (0x0FFF & debug_cnt)
                usbdata[i][j] = ((i==0 and j==0)<<15) | ((j==0)<<14)| (cnt << 12) | (0x0FFF & debug_cnt)
                debug_cnt += 1
            #END TBA_DEBUG
            usbdata[i][j] = int('{:016b}'.format(usbdata[i][j])[::-1], 2)
            # cnt=(cnt+1)%8
            cnt=(cnt+1)%4
            if(args.verbose):
                print 'scidata[%d][%d] = %s, scidatatr[%d][%d] = %s, usbdata[%d][%d] = %s' % (i,j,hex(scidata[i][j]).zfill(2),i,j,hex(scidatatr[i][j]).zfill(2),i,j,hex(usbdata[i][j]).zfill(2))

        if not args.dryrun:
            # # This version will send 512 bytes at a time
            # kstart = 0
            # if len(usbdata[i]) > 512:
            #     kend = len(usbdata[i])
            # else: 
            #     kend = 512
            # while kstart is not len(usbdata[i]):
            #     buflen = kend - kstart
            #     buf = struct.pack('H'*buflen,*usbdata[i][kstart:kend])
            #     rv = handle.bulkWrite(2,buf,0)
            #     if args.verbose:
            #         print 'Sent %d bytes over USB, bytes %d through %d' % (rv,kstart,kend)
            #     kstart = kend
            #     if len(usbdata[i]) > 512:
            #         kend = len(usbdata[i])
            #     else: 
            #         kend = 512

            # This version will send the entire packet
            buf = struct.pack('H'*len(scidata),*usbdata[i])
            rv = handle.bulkWrite(2,buf,0)
            if args.verbose:
                print 'Sent %d bytes over USB' % (rv)

