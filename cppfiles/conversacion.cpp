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
    this->cantMensajes = 0;
    this->mensajes = new List();
}

Conversacion::~Conversacion() {
}
   
ICollection* Conversacion::getUltimosMensajes() {
    IIterator* it = this->mensajes->getIterator();
    IDictionary* mensajes = new OrderedDictionary();
    IKey * key;
    Mensaje * mens;
    ICollectible * item;

    while(it->hasCurrent()) {
        mens = (Mensaje*) it->getCurrent();
        key = new Integer(mens->getCodigo());
        item = (ICollectible *) mens->getDTMensaje();
        mensajes->add(key, item);
        it->next();
    }

    delete it;
    IIterator * it2 = mensajes->getIterator();
    ICollection * ultimosMensajes = new List();
    DTMensaje * dtmen;

    for(int i = 0;it2->hasCurrent() && i < 5; i++){
        item = it2->getCurrent();
        dtmen = (DTMensaje*) item;
        ultimosMensajes->add(item);
        it2->next();
    }

    delete it2;
    // IIterator * it3 = mensajes->getIterator(); // Intento de eliminar la copia
    // while (it3->hasCurrent()){
    //     mens = (Mensaje*) it->getCurrent();
    //     key = new Integer(mens->getCodigo());
    //     it3->next();
    //     mensajes->remove(key);
    //     delete mens;
    // }
    // delete it3;
    return ultimosMensajes;
}

void Conversacion::destruirMensajes() {
    IIterator* it = mensajes->getIterator();
    Mensaje * men;
    ICollectible* eliminar;
    while(it->hasCurrent()) {
        ICollectible* eliminar = it->getCurrent();
        it->next();
        mensajes->remove(eliminar);
        delete eliminar;
    }
    delete it;
}

void Conversacion::nuevoMensaje(DTFecha * fecha, string contenido){
    int codigo = this->generarCodigoMensaje();
    Mensaje * mensaje = new Mensaje(codigo, fecha, contenido);
    ICollectible * colmen = dynamic_cast<ICollectible*> (mensaje);
    this->mensajes->add(colmen);
    this->cantMensajes++;
}

DTFecha * Conversacion::getFechaUltimoMensaje(){
    IIterator * it = this->mensajes->getIterator();
    Mensaje * men = NULL;
    while (it->hasCurrent()){
        men = (Mensaje *) it->getCurrent();
        it->next();
    }
    delete it;
    if (men != NULL){
        return men->getFecha();
    }
    return NULL;
}

int Conversacion::generarCodigoMensaje(){
    return this->cantMensajes+1;
}