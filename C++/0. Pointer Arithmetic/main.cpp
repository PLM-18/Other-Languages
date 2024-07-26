#include <iostream>

int main(){
    int a ;
    double *b = new double;
    char c[10];
    long const n = 20;
    int d[n];
    const int *e = (const int*) 522;
    void *f = (void*) 0xacfe2675;
    char g = 2;
    const int h = NULL;
    c[10] = *&*e;
    std::cout << c[10] << std::endl;
}