#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "KP7.h"

int main() {
	int value_1, value_2, row, col;
	double element;
	FILE *file_input = fopen("data7.txt", "r");
	sparseMatrix matrix;
	createMatrix(&matrix);

	while (!feof(file_input)) {
		fscanf(file_input, "%d", &value_1);			
		fscanf(file_input, "%d", &value_2);
		if (value_1 == 0 && value_2 == 0) {
			break;
		} else if (value_1 == 0 && value_2 != 0) {
			row = value_2;
		} else if (value_1 != 0 && value_2 != 0) {
			col = value_1;
			element = (double)value_2;
			insert(&matrix, row - 1, col - 1, element);
		}
		printMatrix(&matrix);
	}

	int choice = 0;
    bool work = true;
    while (work) {
        printf("Select an option:\n");
        printf("1. Inserting a new element\n");
        printf("2. Matrix print\n");
        printf("3. Matrix print in the internal representation\n");
        printf("4. Division by the maximum element\n");
        printf("5. exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Print number of line and column and element: ");
               	double element;
               	int row, col;
                scanf("%d%d%lf", &row, &col, &element);
				insert(&matrix, row - 1, col - 1, element);
                break;
            }
            case 2: {
                printMatrix(&matrix);
                break;
            }
            case 3: {
                printMatrix2(&matrix);
                break;
            }
            case 4: {
                division(&matrix);
                break;
            }
            case 5: {
                printf("Exiting program...\n");
                freeMatrix(&matrix);
                fclose(file_input);
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