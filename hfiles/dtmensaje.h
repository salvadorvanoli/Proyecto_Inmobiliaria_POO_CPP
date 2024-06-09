#ifndef DTMENSAJE_H
#define DTMENSAJE_H

#include <iostream>
using namespace std;

#include "dtfecha.h"

class DTFecha;

class DTMensaje{
    private:
     string contenido;
     DTFecha fecha; 
    public:
        DTMensaje(string, DTFecha);
        ~DTMensaje();
        string getContenido();
        DTFecha getFecha();
};

#endif