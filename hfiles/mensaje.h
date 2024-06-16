#ifndef MENSAJE_H
#define MENSAJE_H

#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"
#include "dtfecha.h"
#include "dtmensaje.h"

class DTFecha;
class DTMensaje;

class Mensaje: public ICollectible{
    private:
        DTHora * hora;
        DTFecha * fecha;
        string texto;
    public:
        Mensaje();
        Mensaje(DTFecha *, string);
        ~Mensaje();
        DTMensaje * getDTMensaje();
        DTFecha * getFecha();
        string getTexto();
        void setFecha(DTFecha *);
        void setTexto(string);
};

#endif