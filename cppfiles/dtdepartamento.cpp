#include "../hfiles/dtdepartamento.h"
#include <iostream>
using namespace std;

DTDepartamento::DTDepartamento(char* letra, string nombre){
    this->letra = letra;
    this->nombre = nombre;
}

DTDepartamento::~DTDepartamento(){}

// Getters

char* DTDepartamento::getLetra(){
    return this->letra;
}

string DTDepartamento::getNombre(){
    return this->nombre;
}

ostream& operator << (ostream & o, DTDepartamento * dep){
    o << "Letra: " << dep->getLetra() << endl << "Nombre: " << dep->getNombre() << endl;
    return o;
}