#include "../hfiles/dtdepartamento.h"
#include <iostream>
using namespace std;

DTDepartamento::DTDepartamento(char* letra, string nombre){
    this->letra = letra;
    this->nombre = nombre;
}

DTDepartamento::~DTDepartamento(){

}

char* DTDepartamento::getLetra(){
    return this->letra;
}

string DTDepartamento::getNombre(){
    return this->nombre;
}