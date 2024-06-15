#include "../hfiles/dtedificio.h"
#include <iostream>

DTEdificio::DTEdificio(string nombre, int cantPisos, int gastosComunes){
    this->nombre = nombre;
    this->cantPisos = cantPisos;
    this->gastosComunes = gastosComunes;   
}

DTEdificio::~DTEdificio(){}

// Getters

string DTEdificio::getNombre(){
    return this->nombre;
}

int DTEdificio::getCantPisos(){
    return this->cantPisos;
}

int DTEdificio::getGastosComunes(){
    return this->gastosComunes;
}
