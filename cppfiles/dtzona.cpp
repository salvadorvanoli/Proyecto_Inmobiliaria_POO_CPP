#include "../hfiles/dtzona.h"
#include <iostream>
using namespace std;

DTZona::DTZona(int codigoZona, string nombre){
    this->codigoZona = codigoZona;
    this->nombre = nombre;
}

DTZona::~DTZona(){

}

int DTZona::getCodigoZona(){
    return this->codigoZona;
}

string DTZona::getNombre(){
    return this->nombre;
}

ostream& operator << (ostream & o, DTZona * zona){
    o << "Codigo: " << zona->getCodigoZona() << endl << "Nombre: " << zona->getNombre() << endl;
    return o;
}