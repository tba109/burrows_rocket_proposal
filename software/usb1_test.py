#!/usr/bin/env python
import struct
import usb1 
import os
import time

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

# Send the data
# buf = struct.pack('H'*100,*[i for i in range(100)])
while True:
    x = 1
    for n in range(16):
        print 'n = %d, x = %d' % (n,x)
        buf = struct.pack('H'*1,*[x<<n])
        rv = handle.bulkWrite(2,buf,0)
        print 'Sending %d, %d bytes' % (x,rv)
        time.sleep(0.25)
