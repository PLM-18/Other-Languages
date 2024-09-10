#include <stdio.h>
#include <stdlib.h>

extern float** addMatrices(float** matrix1, float** matrix2, int rows, int cols);

float** allocateMatrix(int rows, int cols) {
    float **matrix = (float **)malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (float *)malloc(cols * sizeof(float));
    }
    return matrix;
}

int main(){}