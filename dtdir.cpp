#include "dtdir.h"
#include <iostream>
using namespace std;

DTDir::DTDir(string calle, int numero, string ciudad){
    this->calle = calle;
    this->numero = numero;
    this->ciudad = ciudad;
}

DTDir::~DTDir(){

}

string DTDir::getCalle(){
    return this->calle;
}

int DTDir::getNumero(){
    return this->numero;
}

string DTDir::getCiudad(){
    return this->ciudad;
}