#ifndef _KP_9_
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#define _KP_9_


#define MAX_SIZE 10
#define MAX_SIZE_STRING 50

typedef size_t Iterator;


void copy_string(char* new_string, char* string);


void print_string(char* string);


void clear_string(char* string);


// Описание структуры узла
typedef struct Node {
    double key;
    char value[MAX_SIZE_STRING];
} Node;


// Создание нового узла
Node* createNode(double key, char* value);


typedef struct List {
    struct Node** elements;
    size_t size;
} List;


void createList(List* list);


void insert(List* list, Iterator iterator, Node* node);


size_t get_size(List* list);


void print_list(List* list);


void deleteList(List* list);


void sorted(List* list);


int is_sorted(List* list);


bool find(List* list, double key, int is_sorted);


#endif