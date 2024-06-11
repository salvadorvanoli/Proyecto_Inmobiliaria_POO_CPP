#include "../hfiles/zona.h"
#include <iostream>
using namespace std;

Zona::Zona(int codigo, string nombre){
    this->codigo = codigo;
    this->nombre = nombre;
    // Falta especificar el ICollection
}

Zona::~Zona(){}

// Getters

int Zona::getCodigo(){
    return this->codigo;
}

string Zona::getNombre(){
    return this->nombre;
}

int Zona::getCantEdificios(){
    return this->cantEdificios;
}

int Zona::getCantPropiedades(){
    return this->cantPropiedades;
}

ICollection * Zona::getEdificios(){
    return this->edificios; // Capaz no es asi
}

ICollection * Zona::getPropiedades(){
    return this->propiedades; // Capaz no es asi
}

// Setters

void Zona::setCodigo(int codigo){
    this->codigo = codigo;
}

void Zona::setNombre(string nombre){
    this->nombre = nombre;
}

void Zona::setCantEdificios(int cantEdificios){
    this->cantEdificios = cantEdificios;
}

void Zona::setCantPropiedades(int cantPropiedades){
    this->cantPropiedades = cantPropiedades;
}

// Agregar-Quitar

void Zona::agregarEdificio(Edificio *){
    // ES CON ICOLLECTION
}

void Zona::quitarEdificio(int){
    // ES CON ICOLLECTION
}

void Zona::agregarPropiedad(Propiedad *){
    // ES CON ICOLLECTION
}

void Zona::quitarPropiedad(int){
    // ES CON ICOLLECTION
}

// Métodos de Zona (DCD)

ICollection * Zona::listarEdificios(){
    // ES CON ICOLLECTION
}

Edificio * Zona::seleccionarEdificio(int){
    // ES CON ICOLLECTION
}

void Zona::enlazarZona(Propiedad *){
    // ES CON ICOLLECTION
}

Casa * Zona::crearCasa(int cantAmbientes, int cantBanios, int cantDormitorios, bool tieneGaraje, DTDir direccion,int m2Edificados, int m2Verdes){
    return new Casa(cantAmbientes, cantBanios, cantDormitorios, tieneGaraje, direccion, m2Edificados, m2Verdes);
}

void Zona::desvincularZona(Propiedad *){
    // ES CON ICOLLECTION
}

DTChatProp * Zona::listarChatPropiedad(char * email){
    // ES CON ICOLLECTION
}

Propiedad * Zona::seleccionarPropiedad(int codigoProp){
    // ES CON ICOLLECTION
}

ICollection * Zona::getUltimosMensajes(){
    // ES CON ICOLLECTION
}