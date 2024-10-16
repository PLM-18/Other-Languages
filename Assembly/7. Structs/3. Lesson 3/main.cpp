#include <iostream>
#include <string>

extern "C" int AddInts(int a, int b, int c, int d);
extern "C" int MulBy(int a);
extern "C" int Sub5x(int a, int b);
extern "C" char* printer(char* name);

int main(){
    std::cout<<AddInts(5,7,2,9)<<"\n";
    std::cout<<MulBy(5)<<"\n";
    std::cout<<Sub5x(5,7)<<"\n";
    std::cout<<printer("jonathan");
}