#! /usr/bin/env python
####################################################################
# Tyler Anderson Fri Oct  2 22:15:10 EDT 2015
#
# A simply function to truncate and round numbers
###################################################################

def truncr(x,n):
    if n != 0:
        return int(x + (1 << (n-1))) >> n
    else:
        return x

def trunc(x,n):
    if n != 0:
        return int(x) >> n
    else:
        return x
