#include <iostream>

class Object1{
    int a;
    int b;

public:
    Object1(int a, int b){
        this->a = a;
        this->b = b;
    }

   void print(){
        std::cout << "a: " << a << " b: " << b << std::endl;
    }

    Object1& operator=(Object1 obj){
        this->a = obj.a;
        this->b = obj.b;
        return *this;
    }
};

class Object2{
   Object1* obj1;

public:
    Object2(){
        obj1 = new Object1(0, 0);
    }

    Object1* clone(Object1 other){
        obj1->operator=(other);
        return obj1;
    }
};

int main(){
        Object1 obj1(10, 20);
        Object2 obj2;
        Object1* obj3 = obj2.clone(obj1);
        obj3->print();
}