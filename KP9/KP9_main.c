#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

#include "KP9.h"

int main() {
    setlocale(LC_ALL, "Rus");
    FILE *keys = fopen("K9_key.txt", "r");
    FILE *text = fopen("K9_text.txt", "r");
    List list;
    createList(&list);
    Node* node = NULL;
    char string[MAX_SIZE_STRING];
    char symbol;
    int i, number_of_string; 
    double key;
    

    number_of_string = 0;
    while (true) {
        i = 0;
        clear_string(string);
        symbol = getc(keys); // получаем первый символ
        if (feof(keys))
            break;
        while (symbol != '\n') {
            string[i] = symbol;
            ++i;
            symbol = getc(keys);
        }
        print_string(string);
        key = atof(string);
        printf("%lf\n", key);

        clear_string(string);
        symbol = getc(text);
        i = 0;
        while (symbol != '\n') {
            string[i] = symbol;
            ++i;
            symbol = getc(text);
        }
        
        node = createNode(key, string);
        insert(&list, number_of_string, node);

        ++number_of_string;
    }
    fclose(keys);
    fclose(text);

    int choice = 0;
    bool work = true;
    while (work) {
        printf("Select an option:\n");
        printf("1. Print\n");
        printf("2. Sort\n");
        printf("3. Find\n");
        printf("4. exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                print_list(&list);
                break;
            }
            case 2: {
                sorted(&list);
                break;
            }
            case 3: {
                printf("Print key: ");
                double k;
                scanf("%lf", &k);
                find(&list, k, is_sorted(&list));
                k = 0.0;
                break;
            }
            case 4: {
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
