#include <stdio.h>
#include <stdlib.h>

extern float** addMatrices(float** matrix1, float** matrix2, int rows, int cols);
extern float** allocateMatrix(int rows, int cols);

/* float** allocateMatrix(int rows, int cols) {
    float **matrix = (float **)malloc(rows * sizeof(float *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (float *)malloc(cols * sizeof(float));
    }
    return matrix;
} */

void freeMatrix(float** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(float** matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(){
    int rows = 2, cols = 2;
    float **matrix1 = allocateMatrix(rows, cols);
    float **matrix2 = allocateMatrix(rows, cols);

     // Initialize matrix1
    matrix1[0][0] = 1.0; matrix1[0][1] = 2.0;
    matrix1[1][0] = 3.0; matrix1[1][1] = 4.0;

    // Initialize matrix2
    matrix2[0][0] = 5.0; matrix2[0][1] = 6.0;
    matrix2[1][0] = 7.0; matrix2[1][1] = 8.0;

    printMatrix(matrix1, rows, cols);
    printMatrix(matrix2, rows, cols);

    /* float **resultMatrix = addMatrices(matrix1, matrix2, rows, cols);
    printf("Result of adding Matrix 1 and Matrix 2:\n");
    printMatrix(resultMatrix, rows, cols); */
}