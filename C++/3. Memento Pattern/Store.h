#ifndef STORE_H
#define STORE_H


#include <iostream>
#include "Memento.h"

class Store{
  private:
    Memento* _memento;
  public:
    Store();
    void setMemento(Memento* mem);
    Memento* getMemento();
    ~Store();
};

#endif