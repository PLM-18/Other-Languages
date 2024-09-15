#include <stdlib.h>
#include <stdio.h>

extern float** allocate_array_memory(int row, int col);

int main() {
    int row = 10, col = 5;
    float** array = allocate_array_memory(row, col);
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            array[i][j] = i * 1.1 + j * 0.1;
        }
    }
   
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%f ", array[i][j]);
        }
        printf("\n");
    }
    free(array);
    return 0;
}