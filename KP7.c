#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>


#define MAX_SIZE 5


typedef struct sparseMatrix {
	double* elements; // опменять на бул всю логику
	size_t rows;
	size_t cols;
} sparseMatrix;


void createMatrix(sparseMatrix* matrix) {
    matrix->elements = malloc(MAX_SIZE * MAX_SIZE * sizeof(double));
    for (int i = 0; i < MAX_SIZE * MAX_SIZE; ++i) {
    	matrix->elements[i] = 0;
    }
    matrix->rows = 0;
    matrix->cols = 0;
}


void insert(sparseMatrix* matrix, size_t i, size_t j, double element) {
	if (matrix == NULL)
		return;
	if (i >= MAX_SIZE || j >= MAX_SIZE) {
		printf("Indexes not correct");
		return;
	}

	if (i >= matrix->rows)
		matrix->rows = i + 1;
	if (j >= matrix->cols)
		matrix->cols = j + 1;
	matrix->elements[i * MAX_SIZE + j] = element;
}


void printMatrix(sparseMatrix* matrix) {
	if (matrix == NULL)
		return;
	for (int i = 0; i < matrix->rows; ++i) {
		for (int j = 0; j < matrix->cols; ++j){
			printf("%16lf", matrix->elements[i * MAX_SIZE + j]);
		}
		printf("\n");
	}
	printf("-------------------\n");
}


void printMatrix2(sparseMatrix* matrix) {
	if (matrix == NULL)
		return;
	for (int i = 0; i < matrix->rows; ++i) {
		printf("0 %d ", i + 1);
		for (int j = 0; j < matrix->cols; ++j) {
			if (matrix->elements[i * MAX_SIZE + j] != 0) {
				printf("%d %lf ", j + 1, matrix->elements[i * MAX_SIZE + j]);
			} 
		}
	}
	printf("0 0\n");
	printf("-------------------\n");
}


void freeMatrix(sparseMatrix* matrix) {
	if (matrix == NULL)
		return;
	free(matrix->elements);
}

void division(sparseMatrix* matrix) {
	double max_element = 0;
	
	for (int i = 0; i < matrix->rows; ++i) {
		for (int j = 0; j < matrix->cols; ++j){
			if (fabs(matrix->elements[i * MAX_SIZE + j]) > max_element)
   				max_element = fabs(matrix->elements[i * MAX_SIZE + j]);
		}
	}

	printf("=>%lf\n", max_element);
	for (int i = 0; i < matrix->rows; ++i) {
		bool count_max_element = false;
		for (int j = 0; j < matrix->cols; ++j) {
			if (matrix->elements[i * MAX_SIZE + j] == max_element) {
				count_max_element = true;
				break;
			}
		}
		if (count_max_element == true) {
			for (int j = 0; j < matrix->cols; ++j) {
			if (matrix->elements[i * MAX_SIZE + j] != 0) 
				matrix->elements[i * MAX_SIZE + j] = matrix->elements[i * MAX_SIZE + j] / max_element;
			}
		}
	}
}

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