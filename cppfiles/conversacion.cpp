#include "../ICollection/interfaces/ICollectible.h"
#include "../hfiles/conversacion.h"
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
   

