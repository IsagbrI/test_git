#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "KP8.h"

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