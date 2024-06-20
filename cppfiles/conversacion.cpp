#include "../hfiles/conversacion.h"
#include <iostream>

// Getters
int Conversacion::getCodigoConversacion()  {
    return codigoConversacion;
}

int Conversacion::getCantidadMensajes()  {
    return cantMensajes;
}

Interesado * Conversacion::getInteresado()  {
    return interesado;
}

    // Setters
void Conversacion:: setCodigoConversacion(int codigo) {
    codigoConversacion = codigo;
}   

void Conversacion::setCantidadMensajes(int cantidad) {
    cantMensajes = cantidad;
}

void Conversacion::setInteresado(Interesado* nuevoInteresado) {
    interesado = nuevoInteresado;
}

//constructores y destructores
Conversacion::Conversacion(int nuevoCodigo, Interesado * interesado) {
    this->codigoConversacion = nuevoCodigo;
    this->interesado = interesado;
}

Conversacion::~Conversacion() {
}
   
ICollection* Conversacion::getUltimosMensajes() {
    IIterator* it = mensajes->getIterator();
    ICollection* ultimosMensajes = new List();
    Mensaje * mens;
    ICollectible * item;
    for(int i = 0; it->hasCurrent() && i<5; i++) {
        mens = (Mensaje*) it->getCurrent();
        item = (ICollectible *) mens->getDTMensaje();
        ultimosMensajes->add(item);
        it->next();
    }
    delete it;
    return ultimosMensajes;
}

void Conversacion::destruirMensajes() {
    IIterator* it = mensajes->getIterator();
    while(it->hasCurrent()) {
        ICollectible* eliminar = it->getCurrent();
        it->next();
        mensajes->remove(eliminar);
        delete eliminar;
    }
    delete it;
}

void Conversacion::nuevoMensaje(DTFecha * fecha, string contenido){
    Mensaje * mensaje = new Mensaje(fecha, contenido);
    this->mensajes->add(mensaje);
}
