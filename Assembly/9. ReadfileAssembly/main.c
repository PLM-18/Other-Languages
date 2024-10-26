#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <unistd.h>
#include <limits.h>
#include <linux/limits.h>

extern char* readfile(const char* filename);

int main(){
    const char* filename = "image01.ppm";
    char* content = readfile(filename);
    if(content == NULL){
        printf("Failed to read file %s\n", filename);
        return 1;
    }
    printf("Content of file %s: %s\n", filename, content);
    free(content);
    return 0;
}