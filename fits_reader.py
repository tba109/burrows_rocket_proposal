#!/usr/bin/env python

################################################################
# Tyler Anderson Mon Jun  8 01:29:53 EDT 2015
# 
# A python command line interface for reading and printing
# fits files
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
import truncr as tr
import numpy as np
import matplotlib.pyplot as plt

parser = argparse.ArgumentParser(prog="fits_reader",description="Read, print, and plot the contents of FITS files.")
parser.add_argument("--fits",type=str,help="file from which to read")
parser.add_argument("--truncr",type=int,help="number of LSBs to eliminate via rounding and truncation",default=0)
parser.add_argument("--version",action="version",version="%(prog)s 0.1")

args = parser.parse_args()

if args.fits == None:
    print "\nError! Must specify a FITS file! Bailing!\n"
    exit(-1)
else:
    hdulist = fits.open(args.fits)

print hdulist[0].header.tostring
scidata = hdulist[0].data

for i in range(len(scidata)):
    for j in range(len(scidata[0])):
        scidata[i][j] = int(tr.truncr(scidata[i][j],args.truncr))

print scidata

fig = plt.figure()
ax = fig.add_subplot(111)
im = ax.imshow(scidata, interpolation = "none", origin = "lower", cmap = 'gray')
cb = fig.colorbar(im)
cb.set_clim(tr.truncr(scidata.min(),args.truncr),tr.truncr(scidata.max(),args.truncr))

X = np.array(scidata)
numrows, numcols = X.shape
def format_coord(x, y):
    col = int(x+0.5)
    row = int(y+0.5)
    if col>=0 and col<numcols and row>=0 and row<numrows:
        z = X[row,col]
        return 'x=%d, y=%d, z=%d'%(int(x+0.5), int(y+0.5), int(z+0.5))
    else:
        return 'x=%d, y=%d'%(int(x+0.5), int(y+0.5))
        
ax.format_coord = format_coord
plt.xlim(-0.5,len(scidata[0])-0.5)
plt.ylim(-0.5,len(scidata)-0.5)
plt.show()


