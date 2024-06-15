#ifndef CONVERSACION_H
#define CONVERSACION_H
#include "../ICollection/interfaces/ICollectible.h"
#include "mensaje.h"
#include "interesado.h"
#include "DTMensaje.h"
#include <iostream>

using namespace std;
class Conversacion{
    private:
        int codigoConversacion;
        int cantMensajes;
        Interesado* interesado;
        ICollectible* mensajes;

    public:
        Conversacion(int);
        virtual ~Conversacion();

        // Getters
        int getCodigoConversacion();
        int getCantidadMensajes();
        Interesado * getInteresado();

        // Setters
        void setCodigoConversacion(int);
        void setCantidadMensajes(int);
        void setInteresado(Interesado*);

        void destruirMensajes();
        ICollectible* getUltimosMensajes();
        void nuevoMensaje(string);
};

#endif


        