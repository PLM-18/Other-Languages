#include <stdlib.h>
#include <stdio.h>

extern float* allocate_array_memory(int n);

int main() {
    int n = 10;
    float* array = allocate_array_memory(n);
    for(int i = 0; i < n; i++) {
        array[i] = i * 1.1;
    }
    for (int i = 0; i < n; i++) {
        printf("%f\n", array[i]);
    }
    free(array);
    return 0;
}