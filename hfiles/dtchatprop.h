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
        int codigoProp;
        int codigoCon;
        int cantMensajes;
        DTFecha * fechaUltimoMensaje;
        DTDir* direccion;
        int valorKey;

    public:
        DTChatProp(int, int, int, DTFecha *, DTDir *);
        virtual ~DTChatProp();
        int getCodigoProp();
        int getCodigoCon();
        int getCantMensajes();
        DTDir* getDir();
        DTFecha * getFechaUltimoMensaje();
        int getValorKey();

        friend ostream& operator << (ostream &, DTChatProp *);
        int generarClaveSegunFecha(); // Esta es inchequeable (preguntale a chatGPT)

};

#endif


