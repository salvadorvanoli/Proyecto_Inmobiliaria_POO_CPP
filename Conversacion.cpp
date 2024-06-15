#include "ICollection/interfaces/ICollectible.h"
#include "mensaje.h"
#include "interesado.h"
#include "Conversacion.h"
#include <iostream>

// Getters
int Conversacion::getCodigoConversacion()  {
        return codigoConversacion;
    }

int Conversacion::getCantidadMensajes()  {
        return cantMensajes;
    }

interesado* Conversacion::getInteresado()  {
        return interesado;
    }



    // Setters
void Conversacion:: setCodigoConversacion(int codigo) {
        codigoConversacion = codigo;
    }

void Conversacion::setCantidadMensajes(int cantidad) {
        cantMensajes = cantidad;
    }

void Conversacion::setInteresado(interesado* nuevoInteresado) {
        interesado = nuevoInteresado;
    }

//constructores y destructores
Conversacion:: Conversacion(int nuevoCodigo) {
    codigoConversacion = nuevoCodigo;
}

Conversacion:: ~Conversacion() {
}
   
Conversacion:: ICollectible* getUltimosMensajes() {
    ITerator* it = mensajes->getIterator();
    ICollectible* ultimosMensajes= new ICollectible();
    for(int i = 0; it->hasCurrent() && i<5; i++) {
        ultimosMensajes->add(it->getCurrent());
        it->next();
    }
    delete it;
    return ultimosMensajes;
}

Conversacion:: void destruirMensajes() {
    ITerator* it = mensajes->getIterator();
    while(it->hasCurrent()) {
        ICollectible* eliminar = it->getCurrent();
        it->next();
        mensajes->remove(eliminar);
        delete eliminar;
    }
    delete it;
}
