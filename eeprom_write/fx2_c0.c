// Tyler Anderson Wed Jan 20 16:08:11 EST 2016
// Found out that the newest sdcc doesn't support xdata anymore
// it has to be __xdata

/* xdata unsigned char fx2_c0[] = { */
/*  0xc0, 0xb4, 0x04, 0x10, */
/*  0x10, 0x00, 0x00, 0x00 */
/* }; */
__xdata unsigned char fx2_c0[] = {
 0xc0, 0xb4, 0x04, 0x10,
 0x10, 0x00, 0x00, 0x00
};
