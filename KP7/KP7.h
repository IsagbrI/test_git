#ifndef _KP_7_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define _KP_7_

#define MAX_SIZE 5


typedef struct sparseMatrix {
	double* elements;
	size_t rows;
	size_t cols;
} sparseMatrix;


void createMatrix(sparseMatrix* matrix);


void insert(sparseMatrix* matrix, size_t i, size_t j, double element);


void printMatrix(sparseMatrix* matrix);


void printMatrix2(sparseMatrix* matrix);


void freeMatrix(sparseMatrix* matrix);


void division(sparseMatrix* matrix);

#endif