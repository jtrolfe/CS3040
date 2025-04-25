# -------------------------------------------------------
# Name: John Rolfe
#
# Description: This file will make the exexutable dots
# and create a tar file containing this make file and 
# dots.c
# -------------------------------------------------------
all:dots proj2.tar

dots:dots.c
	gcc -Wall dots.c -o dots

proj2.tar:dots dots.c Makefile
	tar -cvf proj2.tar Makefile dots.c

clean:
	rm dots