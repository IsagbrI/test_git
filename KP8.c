#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


#define MAX_SIZE 5

typedef size_t Iterator;

typedef struct List {
	int* elements;
	size_t size;
} List;


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


int main() {
	List list;
	createList(&list);
	int choice = 0;
    bool work = true;
    while (work) {
        printf("Select an option:\n");
        printf("1. Inserting a new element\n");
        printf("2. Deleting an element\n");
        printf("3. Rearranging parts\n");
        printf("4. Print List\n");
        printf("5. exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Print iterator and element: ");
                int iter, elem;
                scanf("%d%d", &iter, &elem);
				insert(&list, iter, elem);
                break;
            }
            case 2: {
                printf("Print iterator: ");
                int iter;
                scanf("%d", &iter);
				pop(&list, iter);
                break;
            }
            case 3: {
                change_parts(&list);
                break;
            }
            case 4: {
                print_list(&list);
                break;
            }
            case 6: {
                printf("Exiting program...\n");
                deleteList(&list);
                work = false;
                break;
            }
            default: {
                printf("Invalid choice.\n");
                break;
            }
        }
    } 
    return 0;
}