#include "Store.h"

Store::Store(){
    _memento = NULL;
}

void Store::setMemento(Memento* mem){
    _memento = mem;
}

Memento* Store::getMemento(){
    return _memento;
}

Store::~Store(){
    delete _memento;
    _memento = NULL;
}