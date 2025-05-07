# -------------------------------------------------------
# Name: John Rolfe
#
# Description: This file will make the executable overflow
# and create a tar file containing this make file and 
# overflow.c
# -------------------------------------------------------
all:overflow

overflow:overflow.c
	gcc -Wall -g overflow.c -o overflow

proj4.tar:overflow.c Makefile
	tar -cvf proj4.tar Makefile overflow.c

clean:
	rm -f overflow