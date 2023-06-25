#ifndef _KP_8_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define _KP_8_

#define MAX_SIZE 5

typedef size_t Iterator;

typedef struct List {
	int* elements;
	size_t size;
} List;


void createList(List* list);

void deleteList(List* list);

size_t get_size(List* list);

void insert(List* list, Iterator iterator, int value);


void pop(List* list, Iterator iterator);


void change_parts(List* list);


void print_list(List* list);

#endif