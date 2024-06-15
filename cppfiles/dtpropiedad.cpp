#include "../hfiles/dtpropiedad.h"
#include <iostream>
using namespace std;

DTPropiedad::DTPropiedad(int codigo, DTDir * direccion, DTEstadoProp * estado){
    this->codigoProp = codigo;
    this->direccion = direccion;
    this->estado = estado;
}

DTPropiedad::~DTPropiedad(){}
        
// Getters

int DTPropiedad::getCodigoProp(){
    return this->codigoProp;
}

DTDir * DTPropiedad::getDireccion(){
    return this->direccion;
}

DTEstadoProp * DTPropiedad::getEstado(){
    return this->estado;
}

ostream& operator << (ostream & o, DTPropiedad * prop){
    o << "Codigo: " << prop->getCodigoProp() << endl << "Estado: " << prop->getEstado() << endl << "Direccion: " << prop->getDireccion() << endl;
    return o;
}