#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int main(){
	int* ptr = (int*)malloc(10 * sizeof(int));
	ptr[0] = 64;
	printf("%d", ptr[3]);
	return 0;
}
