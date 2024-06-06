#ifndef MENSAJE_H
#define MENSAJE_H

#include "dtfecha.h"
#include "dthora.h"
#include "dtmensaje.h"

//#include <iostream>
using namespace std;


class Mensaje{
    private:
        DTHora hora;
        DTFecha fecha;
        string texto;
    public:
        Mensaje();
        Mensaje(DTHora, DTFecha, string);
        ~Mensaje();
        DTMensaje getDTMensaje();
        DTHora getHora();
        DTFecha getfecha();
        string getTexto();
        void setHora(DTHora);
        void setFecha(DTFecha);
        void setTexto(string);
};

#endif