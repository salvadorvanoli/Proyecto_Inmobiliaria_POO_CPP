#include "dtinmobiliaria.h"
#include "dtdir.h"
#include "dtdir.cpp"
#include <iostream>
using namespace std;

DTInmobiliaria::DTInmobiliaria(char* nombre, DTDir direccion){
    this->nombre = nombre;
    this->direccion = direccion;
}

DTInmobiliaria::~DTInmobiliaria(){

}

char* DTInmobiliaria::getNombre(){
    return this->nombre;
}

DTDir DTInmobiliaria::getDireccion(){
    return this->direccion;
}


