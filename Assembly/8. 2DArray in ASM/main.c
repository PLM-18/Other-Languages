#include <stdlib.h>
#include <stdio.h>

extern float** addMatrices(float** matrix1, float** matrix2, int rows, int cols);

float** allocateMatrix(int rows, int cols) {
    float **matrix = (float **)malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (float *)malloc(cols * sizeof(float));
    }
    return matrix;
}
/* 
float **addMatrices(float **matrix1, float **matrix2, int rows, int cols) {
    float **result = allocateMatrix(rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return result;
} */

float** multiplyMatrices(float** matrix1, float** matrix2, int rows1, int cols1, int cols2) {
    float **result = allocateMatrix(rows1, cols2);
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
    return result;
}

void freeMatrix(float **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(float **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

void fillMatrix(float **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i][j] = i + j;
        }
    }
}

int main() {
    int row = 4, col = 4;
    float **matrix1 = allocateMatrix(row, col);
    float **matrix2 = allocateMatrix(row, col);
    fillMatrix(matrix1, row, col);
    fillMatrix(matrix2, row, col);

    float **result = addMatrices(matrix1, matrix2, row, col);
    printMatrix(result, row, col);
    freeMatrix(result, row);
    result = multiplyMatrices(matrix1, matrix2, row, col, col);
    printMatrix(result, row, col);

    freeMatrix(matrix1, row);
    freeMatrix(matrix2, row);
    freeMatrix(result, row);
    return 0;
}