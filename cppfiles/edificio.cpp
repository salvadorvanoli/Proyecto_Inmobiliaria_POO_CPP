#include "../hfiles/edificio.h"
#include <iostream>
using namespace std;

Edificio::Edificio(int codigo, string nombre, int cantPisos, int gastosComunes){
    this->codigo = codigo;
    this->nombre = nombre;
    this->cantPisos = cantPisos;
    this->gastosComunes = gastosComunes;
    this->cantApartamentos = 0;
    // Falta especificar el ICollection
}

Edificio::~Edificio(){}

// Getters

int Edificio::getCodigo(){
    return this->codigo;
}

string Edificio::getNombre(){
    return this->nombre;
}

int Edificio::getCantPisos(){
    return this->cantPisos;
}

int Edificio::getGastosComunes(){
    return this->gastosComunes;
}

int Edificio::getCantApartamentos(){
    return this->cantApartamentos;
}

ICollection * Edificio::getApartamentos(){
    return this->apartamentos; // Capaz no es asi
}

// Setters

void Edificio::setCodigo(int codigo){
    this->codigo = codigo;
}

void Edificio::setNombre(string nombre){
    this->nombre = nombre;
}

void Edificio::setCantPisos(int cantPisos){
    this->cantPisos = cantPisos;
}

void Edificio::setGastosComunes(int gastosComunes){
    this->gastosComunes = gastosComunes;
}

void Edificio::setCantApartamentos(int cantApartamentos){
    this->cantApartamentos = cantApartamentos;
}

// Agregar-Quitar

void Edificio::agregarApartamento(Apartamento *){
    // ES CON ICOLLECTION
}

void Edificio::quitarApartamento(int){
    // ES CON ICOLLECTION
}

// Métodos de Edificio (DCD)

Apartamento * Edificio::crearApartamento(int cantAmbientes, int cantBanios, int cantDormitorios, bool tieneGarage, DTDir * direccion, int m2Edificados){
    return new Apartamento(cantAmbientes, cantBanios, cantDormitorios, tieneGarage, direccion, m2Edificados);
}
