#include "State.h"

State::State(double real, double imaginary){
    value[0] = real;
    value[1] = imaginary;
}

double State::getFirst(){
    return value[0];
}

double State::getSecond(){
    return value[1];
}