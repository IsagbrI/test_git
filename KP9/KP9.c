#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#include "KP9.h"


void copy_string(char* new_string, char* string) {
    for (int i = 0; i < MAX_SIZE_STRING; ++i) 
        new_string[i] = string[i];
}


void print_string(char* string) {
    for (int i = 0; i < MAX_SIZE_STRING; ++i)
        printf("%c", string[i]);
    printf("\n");
}


void clear_string(char* string) {
    for (int i = 0; i < MAX_SIZE_STRING; ++i) 
        string[i] = ' ';
}



// Создание нового узла
Node* createNode(double key, char* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    copy_string(newNode->value, value);
    return newNode;
}


void createList(List* list) {
    list->elements = malloc(MAX_SIZE * sizeof(Node)); ;
    list->size = 0;
}


void insert(List* list, Iterator iterator, Node* node) {
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
    list->elements[iterator] = node;
    list->size++;
}


size_t get_size(List* list) {
    if (list == NULL)
        return 0;
    return list->size;
}


void print_list(List* list) {
    if (list == NULL)
        return;
    Node* temp_node = NULL;
    for (int i = 0; i < list->size; ++i) {
        temp_node = list->elements[i];
        printf("%4.1lf ", temp_node->key);
        print_string(temp_node->value);
    }
    printf("----------------------\n");
}


void deleteList(List* list) {
    if (list == NULL)
        return;
    Node* temp_node = NULL;
    for (int i = 0; i < list->size; ++i) {
        temp_node = list->elements[i];
        free(temp_node);
    }
    free(list->elements);
}


void sorted(List* list) {
    double a, b;
    int index;
    int index_paste_element;
    Node* node_paste_element = NULL;
    Node* temp_node = NULL;
    for (index_paste_element = 1; index_paste_element < list->size; ++index_paste_element) {
        node_paste_element = list->elements[index_paste_element];
        a = 0;
        b = index_paste_element - 1;
        index = a + (b - a + 1) / 2;
        while (a != b) {
            temp_node = list->elements[index];
            if (node_paste_element->key > temp_node->key) {
                a = index;
            } else {
                b = index - 1;
            }
            index = a + (b - a + 1) / 2;
        }
        temp_node = list->elements[index];
        if (node_paste_element->key > temp_node->key) {
            ++index;
        } 

        for (int i = index_paste_element; i > index; --i)
            list->elements[i] = list->elements[i - 1];
        list->elements[index] = node_paste_element;
        // print_list(list);
    }
}


int is_sorted(List* list) {
    Node* node_1 = NULL;
    Node* node_2 = NULL;
    int result = 1;
    for (int i = 0; i < get_size(list) - 1; ++i) {
        node_1 = list->elements[i];
        node_2 = list->elements[i + 1];
        if (node_1->key > node_2->key) {
            result = 2;
            break;
        }
    }

    if (result == 2) {
        for (int i = 0; i < get_size(list) - 1; ++i) {
            node_1 = list->elements[i];
            node_2 = list->elements[i + 1];
            if (node_1->key < node_2->key) {
                result = 0;
                break;
            }
        } 
    }
    return result;
}


bool find(List* list, double key, int is_sorted) {
    double a, b;
    int index;
    int index_paste_element;
    Node* temp_node = NULL;
    if (is_sorted == 0) {
        printf("Array is not sorted\n");
        return false;
    } 

    a = 0;
    b = get_size(list) - 1;
    index = a + (b - a + 1) / 2;
    if (is_sorted == 1) {
        while (a != b) {
            temp_node = list->elements[index];
            if (key > temp_node->key) {
                a = index;
            } else if (key < temp_node->key) {
                b = index - 1;
            } else {
                print_string(temp_node->value);
                return true;
            }
            index = a + (b - a + 1) / 2;
        }
    }

    if (is_sorted == 2) {
        while (a != b) {
            temp_node = list->elements[index];
            if (key < temp_node->key) {
                a = index;
            } else if (key > temp_node->key) {
                b = index - 1;
            } else {
                print_string(temp_node->value);
                return true;
            }
            index = a + (b - a + 1) / 2;
        }
    }
    
    temp_node = list->elements[index];
    if (key == temp_node->key) {
        print_string(temp_node->value);
        return true; 
    }
    printf("Key error\n");
    return false;

}