#include "../hfiles/inmobiliaria.h"
#include <iostream>
using namespace std;

Inmobiliaria::Inmobiliaria(char* email, string nombre, DTDir direccion) : Usuario(email){
    this->contrasenia = "";
    this->nombre = nombre;
    this->direccion = direccion;
    this->ventas = new List();
    this->alquileres = new List();
    this->propiedades = new List();
    this->cantAlquileres = this->cantVentas = this->cantPropiedades = 0;
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

Venta* Inmobiliaria::ponerEnVenta(Propiedad * prop, int precio){
    Venta * nuevaVenta = new Venta(prop, precio);
    if(this->ventas->member(nuevaVenta) == true){
        throw invalid_argument("La venta ya estaba registrada");
        return NULL;
    }
    this->ventas->add(nuevaVenta);
    return nuevaVenta;
}

Alquiler* Inmobiliaria::ponerEnAlquiler(Propiedad * prop, int precio){
    Alquiler * nuevoAlquiler = new Alquiler(prop, precio);
    if(this->alquileres->member(nuevoAlquiler) == true){
        throw invalid_argument("El alquiler ya estaba registrado");
        return NULL;
    }
    this->alquileres->add(nuevoAlquiler);
    return nuevoAlquiler;
}

void Inmobiliaria::agregarPropiedad(Propiedad * prop){
    if(this->propiedades->member(prop) == true){
        throw invalid_argument("La propiedad ya estaba registrada");
        return;
    }
    this->propiedades->add(prop);
}