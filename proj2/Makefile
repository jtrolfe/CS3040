# -------------------------------------------------------
# Name: John Rolfe
#
# Description: This file will make the exexutable asciitotal
# and create a tar file containing this make file and 
# asciitotal.c
# -------------------------------------------------------
all:dots

dots:dots.c
	gcc -Wall dots.c -o dots

dots.tar:dots dots.c
	tar -cvf dots.tar Makefile dots.c

clean:
	rm dots