#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "KP8.h"

void createList(List* list) {
    list->elements = malloc(MAX_SIZE * sizeof(int));
    list->size = 0;
}

void deleteList(List* list) {
	if (list == NULL)
		return;
	free(list->elements);
}

size_t get_size(List* list) {
	if (list == NULL)
		return 0;
	return list->size;
}

void insert(List* list, Iterator iterator, int value) {
	if (list == NULL)
		return;
	if (iterator < 0 || iterator > list->size) {
		printf("Iterator not correct\n");
		return;
	}
	if (list->size == MAX_SIZE) {
		printf("List full\n");
		return;	
	}

	for (int i = list->size; i > iterator; --i)
		list->elements[i] = list->elements[i - 1];
	list->elements[iterator] = value;
	list->size++;
}


void pop(List* list, Iterator iterator) {
	if (list == NULL)
		return;
	if (iterator < 0 || iterator > list->size) {
		printf("Iterator not correct\n");
		return;
	}

	for (int i = iterator; i < list->size - 1; ++i)
		list->elements[i] = list->elements[i + 1];
	list->size--;
}


void change_parts(List* list) {
	if (list == NULL)
		return;
	int temp;
	for (int i = 0; i < list->size / 2; ++i) {
		temp = list->elements[i];
		list->elements[i] = list->elements[i + (list->size + 1) / 2];
		list->elements[i + (list->size + 1) / 2] = temp;
	}
}


void print_list(List* list) {
	if (list == NULL)
		return;
	for (int i = 0; i < list->size; ++i) 
		printf("%d ", list->elements[i]);
	printf("\n");
}