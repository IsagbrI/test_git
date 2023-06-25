CC = gcc

all: 24_main.o 24.o  
	$(CC) 24_main.c 24.c -o main

24_main.o: 24_main.c
	$(CC) -c 24_main.c

24.o: 24.c 24.h
	$(CC) -c 24.c

clear:
	del *.o