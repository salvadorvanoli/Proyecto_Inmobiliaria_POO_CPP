#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"
#include "dtfecha.h"

class DTFecha;

class DTMensaje: public ICollectible{
    private:
        string contenido;
        DTFecha * fecha; 
    public:
        DTMensaje(string, DTFecha *);
        ~DTMensaje();
        string getContenido();
        DTFecha * getFecha();
};

#endif