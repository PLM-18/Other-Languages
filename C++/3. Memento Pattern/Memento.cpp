#include "Memento.h"

Memento::Memento(double real, double imaginary){
    _state = new State(real, imaginary);
}

Memento::~Memento(){
    delete _state;
    _state = NULL;
}