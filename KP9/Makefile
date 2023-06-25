CC = gcc

all: KP9_main.o KP9.o  
	$(CC) KP9_main.c KP9.c -o main

KP9_main.o: KP9_main.c
	$(CC) -c KP9_main.c

KP9.o: KP9.c KP9.h
	$(CC) -c KP9.c

clear:
	del *.o