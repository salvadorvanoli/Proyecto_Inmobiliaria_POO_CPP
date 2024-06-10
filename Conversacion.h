#ifndef CONVERSACION_H
#define CONVERSACION_H
#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "Mensaje.h"
#include "Interesado.h"
#include "DTMensaje.h"
using namespace std;

class Conversacion: public ICollectible {
    private:
        string codigoConversacion;
        int cantMensajes;
        Interesado* Interesado; //??
        ICollectible* Mensaje; //??
    public:
        Conversacion(string);
        void destruirMensajes();
        void nuevoMensaje(string);
        virtual ~Conversacion();
        ICollectible* getUltimosMensajes(); //??

        //getters y setters
        void setcantMensajes(int);
        int getcantMensajes();
        void setcodigoConversacion(string);
        string getcodigoConversacion();

};

#endif


        