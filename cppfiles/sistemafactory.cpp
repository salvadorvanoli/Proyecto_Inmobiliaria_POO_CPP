#include <iostream>
using namespace std;

#include "../hfiles/sistemafactory.h"

Factory::Factory(){
    this->sistema = NULL;
}

ISistema * Factory::getISistema(){
    if(this->sistema == NULL){
        this->sistema = new Sistema();
    }
    return this->sistema;
}