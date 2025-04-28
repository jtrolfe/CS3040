# -------------------------------------------------------
# Name: John Rolfe
#
# Description: This file will make the executable randadd
# and create a tar file containing this make file and 
# dots.c
# -------------------------------------------------------
all:randadd proj3.tar

randadd:randadd.c
	gcc -Wall -g randadd.c -o randadd

proj3.tar:randadd randadd.c Makefile
	tar -cvf proj2.tar Makefile randadd.c

clean:
	rm randadd