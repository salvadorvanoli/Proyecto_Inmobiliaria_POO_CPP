#include "../hfiles/apartamento.h"
#include <iostream>
using namespace std;

void Apartamento :: setEdificio(Edificio * _edificio){
    this->edificio = _edificio;
}

Edificio * Apartamento :: getEdificio(){
    return this->edificio;
}

void Apartamento :: desvincularDeEdificio(){
    //this->edificio->desvincularPropiedad(this);
}