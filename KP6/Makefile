CC = gcc

all: KP6_main.o KP6.o  
	$(CC) KP6_main.c KP6.c -o main

KP6_main.o: KP6_main.c
	$(CC) -c KP6_main.c

KP6.o: KP6.c KP6.h
	$(CC) -c KP6.c

clear:
	del *.o