#ifndef MEMENTO_H
#define MEMENTO_H

#include <iostream>
#include "State.h"
class ComplexNumber; // Forward declaration

class Memento{
  public:
    virtual ~Memento();
  private:
    friend class ComplexNumber;
    Memento(double real, double imaginary);
    State* _state;
};

#endif