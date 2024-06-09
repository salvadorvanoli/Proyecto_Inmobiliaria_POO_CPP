#include "../hfiles/inmobiliaria.h"
#include <iostream>
using namespace std;

Inmobiliaria::Inmobiliaria(char* email, string nombre, DTDir direccion) : Usuario(email){
    this->contrasenia = "";
    this->nombre = nombre;
    this->direccion = direccion;
    this->ventas = NULL;
    this->alquileres = NULL;
    this->propiedades = NULL;
}

Inmobiliaria::~Inmobiliaria(){
    // ELIMINAR TODAS LAS COLECCIONES SI EXISTEN
}

string Inmobiliaria::getNombre(){
    return this->nombre;
}

DTDir Inmobiliaria::getDireccion(){
    return this->direccion;
}

Venta** Inmobiliaria::getVentas(){
    // QUE DEVUELVA TODAS LAS VENTAS
}

Alquiler** Inmobiliaria::getAlquileres(){
    // QUE DEVUELVA TODOS LOS ALQUILERES
}

Propiedad** Inmobiliaria::getPropiedades(){
    // QUE DEVUELVA TODAS LAS PROPIEDADES
}

void Inmobiliaria::setNombre(string nombre){
    this->nombre = nombre;
}

void Inmobiliaria::setDireccion(DTDir direccion){
    this->direccion = direccion;
}

Venta Inmobiliaria::ponerEnVenta(Propiedad prop, int precio){
    // QUE AGREGUE UNA PROPIEDAD A LA COLLECCIÓN "ventas" CON EL PRECIO "precio"
}

Alquiler Inmobiliaria::ponerEnAlquiler(Propiedad prop, int precio){
    // QUE AGREGUE UNA PROPIEDAD A LA COLLECCIÓN "alquileres" CON EL PRECIO "precio"
}

void Inmobiliaria::agregarPropiedad(Propiedad prop){
    // QUE AGREGUE UNA PROPIEDAD A LA COLLECCIÓN "propiedades"
}