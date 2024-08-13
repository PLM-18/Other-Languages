#include "Store.h"
#include "ComplexNumber.h"

int main(){
    Store store;
    ComplexNumber* one;
    ComplexNumber* two;

    one = new ComplexNumber(1, 1);
    store.setMemento(one->createMemento()); //backup the state of one

    one = new ComplexNumber(2, 2); // Change the state of one
    
    Memento* memento = store.getMemento(); // Get the state of one
    two = new ComplexNumber();
    two->reinstateMemento(memento); // Reinstate the state of two

    one->print();
    two->print();

    one->add(*two);
    one->print();
    two->print();

    delete one;
    delete two;
}