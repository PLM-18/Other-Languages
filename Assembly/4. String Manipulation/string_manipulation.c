#include <stdio.h>

extern float* convertStringToFloat(const char *str);

int main(){
    //write program that takes a string and converts it to a float
    const char *str = "3.14";
    float *f = convertStringToFloat(str);
    printf("%f\n", *f);
}