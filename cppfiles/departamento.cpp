#include "../hfiles/departamento.h"
#include "../hfiles/dtdepartamento.h"
#include <iostream>
using namespace std;

Departamento::Departamento(char * letra, string nombre){
    this->letra = letra;
    this->nombre = nombre;
    // Falta especificar el ICollection
}

Departamento::~Departamento(){}

// Getters

char * Departamento::getLetra(){
    return this->letra;
}

string Departamento::getNombre(){
    return this->nombre;
}

int Departamento::getCantZonas(){
    return this->cantZonas;
}

ICollection * Departamento::getZonas(){
    return this->zonas; // Capaz no es asi
}

// Setters

void Departamento::setLetra(char * letra){
    this->letra = letra;
}

void Departamento::setNombre(string nombre){
    this->nombre = nombre;
}

void Departamento::setCantZonas(int cantZonas){
    this->cantZonas = cantZonas;
}

// Agregar-Quitar

void Departamento::agregarZona(Zona *){
    // ES CON ICOLLECTION
}

void Departamento::quitarZona(int){
    // ES CON ICOLLECTION
}

// Métodos de Departamento (DCD)

DTDepartamento * Departamento::getDTDepartamento(){
    return new DTDepartamento(this->letra, this->nombre);
}

ICollection * Departamento::listarZonasDepartamento(){
    // ES CON ICOLLECTION
}

Zona * Departamento::elegirZona(int){
    // ES CON ICOLLECTION
}