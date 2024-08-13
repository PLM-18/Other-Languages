#include "ComplexNumber.h"

    ComplexNumber::ComplexNumber(){
      _real = 0;
      _imaginary = 0;
    }

    ComplexNumber::ComplexNumber(double real, double imaginary){
      this->_real = real;
      this->_imaginary = imaginary;
    }

    void ComplexNumber::add(ComplexNumber c){
      _real = _real + c._real;
      _imaginary = _imaginary + c._imaginary;
    }

    void ComplexNumber::multiply(ComplexNumber c){
      _real = (_real * c._real) - (_imaginary * c._imaginary);
      _imaginary = (_real * c._imaginary) + (_imaginary * c._real);
    } 

    double ComplexNumber::getReal(){
      return _real;
    }

    double ComplexNumber::getImaginary(){
      return _imaginary;
    }

    void ComplexNumber::print(){
      std::cout << _real <<" + "<<_imaginary<<"i"<<std::endl;
    }

    Memento* ComplexNumber::createMemento(){
      return new Memento(_real, _imaginary);
    }

    void ComplexNumber::reinstateMemento(Memento* mem){
      this->_real = mem->_state->getFirst();
      this->_imaginary = mem->_state->getSecond();
    }

