#include "../hfiles/dtlineareporte.h"
#include <iostream>
using namespace std;

DTLineaReporte::DTLineaReporte(int codigoZona, char * letraDep, int cantApartamentos, int cantCasas){
    this->codigoZona = codigoZona;
    this->letraDep = letraDep;
    this->cantApartamentos = cantApartamentos;
    this->cantCasas = cantCasas;
}

DTLineaReporte::~DTLineaReporte(){}

// Getters

int DTLineaReporte::getCodigoZona(){
    return this->codigoZona;
}

char * DTLineaReporte::getLetraDep(){
    return this->letraDep;
}

int DTLineaReporte::getCantApartamentos(){
    return this->cantApartamentos;
}

int DTLineaReporte::getCantCasas(){
    return this->cantCasas;
}
