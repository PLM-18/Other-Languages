#include <iostream>
#include <math.h>

float fibonacci(int);

int main(){
    std::cout<<"The answer is: "<<fibonacci(6)<<"\n";
}

float fibonacci(int num){
    float val1 = pow((1 + sqrt(5)), num);
    float val2 = pow((1 - sqrt(5)), num);
    float divisor = pow(2, num) * sqrt(5);
    float answer = (val1 - val2) / divisor;
    return answer;
}
