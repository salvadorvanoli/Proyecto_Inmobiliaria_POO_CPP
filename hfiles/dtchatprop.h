#ifndef DTCHATPROP_H
#define DTCHATPROP_H
#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "dtdir.h"
#include "dtfecha.h"
#include <ctime>
#include <cmath>

class DTChatProp: public ICollectible {
    private:
        int codigo;
        int cantMensajes;
        DTFecha * fechaUltimoMensaje;
        DTDir* direccion;
        int valorKey;

    public:
        DTChatProp(int, int, DTFecha *, DTDir *);
        virtual ~DTChatProp();
        int getCodigo();
        int getCantMensajes();
        DTDir* getDir();
        DTFecha * getFechaUltimoMensaje();
        int getValorKey();

        friend ostream& operator << (ostream &, DTChatProp *);
        int generarClaveSegunFecha(); // Esta es inchequeable (preguntale a chatGPT)

};

#endif


