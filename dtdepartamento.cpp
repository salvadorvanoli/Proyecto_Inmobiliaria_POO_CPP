#include "dtdepartamento.h"
#include <iostream>
using namespace std;

DTDepartamento::DTDepartamento(string letra, string nombre){
    this->letra = letra;
    this->nombre = nombre;
}

DTDepartamento::~DTDepartamento(){

}

string DTDepartamento::getLetra(){
    return this->letra;
}

string DTDepartamento::getNombre(){
    return this->nombre;
}