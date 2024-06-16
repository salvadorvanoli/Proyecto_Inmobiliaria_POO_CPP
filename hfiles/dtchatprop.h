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

    public:
        DTChatProp(int, int, DTDir *);
        virtual ~DTChatProp();
        int getCodigo();
        int getcantMensajes();
        DTDir* getDir();
};

#endif


