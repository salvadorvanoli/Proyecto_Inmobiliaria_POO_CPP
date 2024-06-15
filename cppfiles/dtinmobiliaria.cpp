#include "../hfiles/dtinmobiliaria.h"
#include "dtdir.cpp"
#include "../hfiles/dtdir.h"
#include <iostream>
using namespace std;

DTInmobiliaria::DTInmobiliaria(char* nombre, DTDir * direccion){
    this->nombre = nombre;
    this->direccion = direccion;
}

DTInmobiliaria::~DTInmobiliaria(){

}

char* DTInmobiliaria::getNombre(){
    return this->nombre;
}

DTDir * DTInmobiliaria::getDireccion(){
    return this->direccion;
}

ostream& operator << (ostream & o, DTInmobiliaria * inmo){
    o << "Nombre: " << inmo->getNombre() << endl << "Direccion: " << endl << inmo->getDireccion();
    return o;
}