###########################################################################
## Tyler Anderson Thu Oct 14 15:43:58 EDT 2010
###########################################################################
INCLUDES = -I../fx2lib/include -I./include
CC = sdcc -mmcs51
LIBS = fx2.lib -L../fx2lib/lib
CFLAGS = --xram-loc 0x3200
CYCFX2PROG = cycfx2prog

all : tcd2_main.ihx

tcd2_main.ihx : tmp/tcd2_gpifwvfm.rel tmp/tcd2_command.rel tmp/tcd2_event.rel tmp/tcd2_ep16_init.rel tmp/tcd2_flags.rel
	$(CC) $(CFLAGS) $(INCLUDES) tcd2_main.c tmp/tcd2_gpifwvfm.rel tmp/tcd2_command.rel tmp/tcd2_event.rel tmp/tcd2_ep16_init.rel tmp/tcd2_flags.rel $(LIBS)

tmp/tcd2_command.rel : tmp/tcd2_gpifwvfm.rel tmp/tcd2_flags.rel
	$(CC) -c $(INCLUDES) src/tcd2_command.c tmp/tcd2_gpifwvfm.rel tmp/tcd2_flags.rel -o tmp/tcd2_command.rel 

tmp/tcd2_event.rel : tmp/tcd2_gpifwvfm.rel tmp/tcd2_flags.rel
	$(CC) -c $(INCLUDES) src/tcd2_event.c tmp/tcd2_gpifwvfm.rel tmp/tcd2_flag.rel -o tmp/tcd2_event.rel 

tmp/tcd2_gpifwvfm.rel :
	$(CC) -c $(INCLUDES) src/tcd2_gpifwvfm.c -o tmp/tcd2_gpifwvfm.rel 

tmp/tcd2_ep16_init.rel :
	$(CC) -c $(INCLUDES) src/tcd2_ep16_init.c -o tmp/tcd2_ep16_init.rel 

tmp/tcd2_flags.rel :
	$(CC) -c $(INCLUDES) src/tcd2_flags.c -o tmp/tcd2_flags.rel 

clean:
	rm -f *.asm *.ihx *.lnk *.lst *.map *.mem *.rel *.rst *.sym *.hex
	rm -f tmp/*.asm tmp/*.ihx tmp/*.lnk tmp/*.lst tmp/*.map tmp/*.mem tmp/*.rel tmp/*.rst tmp/*.sym

.PHONY:run

run: tcd2_main.ihx
	packihx tcd2_main.ihx > tcd2_main.hex
	sudo fxload -v -t fx2 -I tcd2_main.hex -D /dev/bus/usb/002/045