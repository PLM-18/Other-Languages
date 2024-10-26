#include <iostream>


class Base{
public:
    virtual void print() = 0;
};

class Derived : public Base{
public:
    void print() override{
        std::cout << "Derived" << std::endl;
    }

    void unusual(){
        std::cout << "Unusual" << std::endl;
    }
};

int main(){
    Base* b = new Derived();
    b->print();
    //b->unusual(); // Error: Base has no member named 'unusual'
    delete b;
    return 0;
}