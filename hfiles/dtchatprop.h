#ifndef DTCHATPROP_H
#define DTCHATPROP_H
#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "dtdir.h"
#include "dtmensaje.h"

class DTChatProp: public ICollectible {
    private:
        int codigo;
        int cantMensajes;
        DTDir* direccion;
        ICollectible* mensajes;

    public:
        DTChatProp(int);
        virtual ~DTChatProp();
        void setCodigo(int);
        void setcantMensajes(int);
        void setDir(DTDir*);
        int getCodigo();
        int getcantMensajes();
        DTDir* getDir();
};

#endif


