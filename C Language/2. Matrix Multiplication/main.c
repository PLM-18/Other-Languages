#include <stdlib.h>
#include <stdio.h>

float** allocateMatrix(int rows, int cols){
    float** matrix = (float**)malloc(rows * sizeof(float*));
    for(int i = 0; i < rows; i++){
        matrix[i] = (float*)malloc(cols * sizeof(float));
    }
    return matrix;
}

void freeMatrix(float** matrix, int rows){
    for(int i = 0; i < rows; i++){
        free(matrix[i]);
    }
    free(matrix);
}

void printMatrix(float** matrix, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            printf("%f", matrix[i][j]);
        }
        printf("\n");
    }
}

void multiply(float** matrix1, float** matrix2, float** result, int rows1, int cols1, int rows2, int cols2){
    for(int i = 0; i < rows1; i++){
        for(int j = 0; j < cols2; j++){
            result[i][j] = 0;
            for(int k = 0; k < cols1; k++){
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}

void addition(float** matrix1, float** matrix2, float** result, int rows, int cols){
    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

int main(){
    int rows1, cols1, rows2, cols2;
    printf("Enter the number of rows and columns of the first matrix: ");
    scanf("%d %d", &rows1, &cols1);
    printf("Enter the number of rows and columns of the second matrix: ");
    scanf("%d %d", &rows2, &cols2);
    float** matrix1 = allocateMatrix(rows1, cols1);
    float** matrix2 = allocateMatrix(rows2, cols2);
    float** result = allocateMatrix(rows1, cols2);
    printf("Enter the elements of the first matrix: ");
    for(int i = 0; i < rows1; i++){
        for(int j = 0; j < cols1; j++){
            scanf("%f", &matrix1[i][j]);
        }
    }

    printf("Enter the elements of the second matrix: ");
    for(int i = 0; i < rows2; i++){
        for(int j = 0; j < cols2; j++){
            scanf("%f", &matrix2[i][j]);
        }
    }

    if(cols1 != rows2){
        printf("The matrices cannot be multiplied\n");
        return 0;
    }

    multiply(matrix1, matrix2, result, rows1, cols1, rows2, cols2);
    printf("The result of the multiplication is:\n");
    printMatrix(result, rows1, cols2);

    addition(matrix1, matrix2, result, rows1, cols1);
    printf("The result of the addition is:\n");
    printMatrix(result, rows1, cols1);
    
    freeMatrix(matrix1, rows1);
    freeMatrix(matrix2, rows2);
    freeMatrix(result, rows1);
}