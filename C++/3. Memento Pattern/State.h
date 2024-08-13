#ifndef STATE_H
#define STATE_H

#include <iostream>

class State{
    private :
        double value[2];
    public:
        State(double real, double imagine);
        double getFirst();
        double getSecond();
};

#endif