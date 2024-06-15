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

ostream& operator << (ostream & o, DTEdificio * edi){
    o << "Nombre: " << edi->getNombre() << endl << "Cantidad de pisos: " << edi->getCantPisos() << endl << "Gastos comunes: " << edi->getGastosComunes() << endl;
    return o;
}