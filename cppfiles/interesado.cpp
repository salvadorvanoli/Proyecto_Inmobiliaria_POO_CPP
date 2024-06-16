#include "../hfiles/interesado.h"
#include <iostream>
using namespace std;

Interesado::Interesado(char* email, string nombre, string apellido, int edad) : Usuario(email) {
    this->contrasenia = "";
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->primeraVez = true;
}

string Interesado::getNombre(){
    return this->nombre;
}

string Interesado::getApellido(){
    return this->apellido;
}

int Interesado::getEdad(){
    return this->edad;
}

void Interesado::setNombre(string nombre){
    this->nombre = nombre;
}

void Interesado::setApellido(string apellido){
    this->apellido = apellido;
}

void Interesado::setEdad(int edad){
    this->edad = edad;
}