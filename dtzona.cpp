#include "dtzona.h"
#include <iostream>
using namespace std;

DTZona::DTZona(int codigoZona, string nombre){
    this->codigoZona = codigoZona;
    this->nombre = nombre;
}

DTZona::~DTZona(){

}

int DTZona::getCodigozona(){
    return this->codigoZona;
}

string DTZona::getNombre(){
    return this->nombre;
}
