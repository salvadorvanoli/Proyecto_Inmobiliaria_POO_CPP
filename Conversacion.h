#ifndef CONVERSACION_H
#define CONVERSACION_H
#include "ICollection/interfaces/ICollectible.h"
#include "mensaje.h"
#include "interesado.h"
#include <iostream>

using namespace std;
class Conversacion{
    private:
    int codigoConversacion;
    int cantMensajes;
    interesado* interesado;
    ICollectible* mensajes;

    public:
    Conversacion(int);
    virtual ~Conversacion();
    void destruirMensajes();
    ICollectible* getUltimosMensajes();
    void nuevoMensaje(string);

};

#endif