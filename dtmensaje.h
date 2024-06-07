#ifndef DTMENSAJE_H
#define DTMENSAJE_H
#include "dtfecha.h"

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