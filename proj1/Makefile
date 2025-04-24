# -------------------------------------------------------
# Name: John Rolfe
#
# Description: This file will make the exexutable asciitotal
# and create a tar file containing this make file and 
# asciitotal.c
# -------------------------------------------------------
all:asciitotal asciitotal.tar

asciitotal:asciitotal.c
	gcc -Wall asciitotal.c -o asciitotal

asciitotal.tar:asciitotal asciitotal.c Makefile
	tar -cvf asciitotal.tar Makefile asciitotal.c