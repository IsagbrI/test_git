CC = gcc

all: KP7_main.o KP7.o  
	$(CC) KP7_main.c KP7.c -o main

KP7_main.o: KP7_main.c
	$(CC) -c KP7_main.c

KP7.o: KP7.c KP7.h
	$(CC) -c KP7.c

clear:
	del *.o