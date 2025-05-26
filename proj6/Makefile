# -------------------------------------------------------
# Name: John Rolfe
#
# Description: This file will make the executable shift
# and create a tar file containing this make file and 
# overflow.c
# -------------------------------------------------------
all:shift

shift:shift.c shift.h main.c
	gcc -Wall -g main.c shift.c -o shift

proj6.tar:shift.c shift.h main.c Makefile
	tar -cvf proj6.tar Makefile shift.c shift.h main.c

clean:
	rm -f shift