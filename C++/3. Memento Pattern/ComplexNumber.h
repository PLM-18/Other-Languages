#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H

#include "Memento.h"
#include <iostream>

class ComplexNumber{
  private:
    double _real;
    double _imaginary;
  public:
    ComplexNumber();
    ComplexNumber(double real, double imaginary);
    void add(ComplexNumber c);
    void multiply(ComplexNumber c);
    double getReal();
    double getImaginary();
    void print();
    Memento* createMemento();
    void reinstateMemento(Memento* mem);
};

#endif

