#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#include "KP7.h"

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