###########################################################################
## Tyler Anderson Thu Oct 14 15:43:58 EDT 2010
###########################################################################
INCLUDES = -I../fx2lib/include 
CC = sdcc -mmcs51
LIBS = fx2.lib -L../fx2lib/lib
CFLAGS = --xram-loc 0x3200
CYCFX2PROG = cycfx2prog

all : brp_main.ihx

brp_main.ihx :
	$(CC) $(CFLAGS) $(INCLUDES) brp_main.c $(LIBS)

clean:
	rm -f *.asm *.ihx *.lnk *.lst *.map *.mem *.rel *.rst *.sym *.hex
	rm -f tmp/*.asm tmp/*.ihx tmp/*.lnk tmp/*.lst tmp/*.map tmp/*.mem tmp/*.rel tmp/*.rst tmp/*.sym

.PHONY:run

run: brp_main.ihx
	packihx brp_main.ihx > brp_main.hex
	sudo cycfx2prog -id=04b4.1010 prg:brp_main.ihx run delay:100 
#	sudo cycfx2prog -id=04b4.1010 prg:brp_main.ihx run delay:100 sbulk:2,"Hi there!" 
#	sudo fxload -v -t fx2 -I brp_main.hex -D /dev/bus/usb/001/003
