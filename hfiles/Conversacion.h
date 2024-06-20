#ifndef CONVERSACION_H
#define CONVERSACION_H
#include "../ICollection/interfaces/ICollectible.h"
#include "mensaje.h"
#include "interesado.h"
#include "DTMensaje.h"
#include "dtfecha.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/OrderedKey.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/IIterator.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/interfaces/OrderedKey.h"
#include "../ICollection/Integer.h"

#include <iostream>
using namespace std;

class Conversacion : public ICollectible{
    private:
        int codigoConversacion;
        int cantMensajes;
        Interesado* interesado;
        ICollection* mensajes;
    public:
        Conversacion(int, Interesado *);
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
        ICollection* getUltimosMensajes();
        void nuevoMensaje(DTFecha *, string);

        DTFecha * getFechaUltimoMensaje();
};

#endif


        