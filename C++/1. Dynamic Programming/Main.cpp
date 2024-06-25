#include <iostream>
#include <chrono>

int iterativefibonacci(int n);
int recursivefibonacci(int n);
int dynamicFibonacci(int n);

int main(){
    int n = 60;
    auto start = std::chrono::high_resolution_clock::now();
    std::cout << "Fibonacci of " << n << " is " << recursivefibonacci(n) << std::endl;
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> duration = end - start;
    std::cout << "Time taken by recursive fibonacci: " << duration.count() << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::cout << "/nFibonacci of " << n << " is " << dynamicFibonacci(n) << std::endl;
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time taken by dynamic fibonacci: " << duration.count() << " seconds" << std::endl;

    start = std::chrono::high_resolution_clock::now();
    std::cout << "/nFibonacci of " << n << " is " << iterativefibonacci(n) << std::endl;
    end = std::chrono::high_resolution_clock::now();
    duration = end - start;
    std::cout << "Time taken by iterative fibonacci: " << duration.count() << " seconds" << std::endl;
    return 0;
    
}

int dynamicFibonacci(int n){
    int* fib = new int[n+1];
    fib[0] = 0;
    fib[1] = 1;
    for(int i = 2; i <= n; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    return fib[n];
}

int iterativefibonacci(int n){
    int a = 0, b = 1, c;
    if(n == 0){
        return a;
    }
    for(int i = 2; i <= n; i++){
        c = a + b;
        a = b;
        b = c;
    }
    return b;
}

int recursivefibonacci(int n){
    if(n <= 1){
        return n;
    }
    return recursivefibonacci(n-1) + recursivefibonacci(n-2);
}