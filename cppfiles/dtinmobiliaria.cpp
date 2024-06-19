#include "../hfiles/dtinmobiliaria.h"
#include <iostream>
using namespace std;

DTInmobiliaria::DTInmobiliaria(string nombre, DTDir * direccion){
    this->nombre = nombre;
    this->direccion = direccion;
}

DTInmobiliaria::~DTInmobiliaria(){

}

string DTInmobiliaria::getNombre(){
    return this->nombre;
}

DTDir * DTInmobiliaria::getDireccion(){
    return this->direccion;
}

ostream& operator << (ostream & o, DTInmobiliaria * inmo){
    o << "Nombre: " << inmo->getNombre() << endl << "Direccion: " << endl << inmo->getDireccion();
    return o;
}