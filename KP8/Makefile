CC = gcc

all: KP8_main.o KP8.o  
	$(CC) KP8_main.c KP8.c -o main

KP8_main.o: KP8_main.c
	$(CC) -c KP8_main.c

KP8.o: KP8.c KP8.h
	$(CC) -c KP8.c

clear:
	del *.o