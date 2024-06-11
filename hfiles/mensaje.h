#ifndef MENSAJE_H
#define MENSAJE_H

#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollection.h"
#include "dtfecha.h"
#include "dthora.h"
#include "dtmensaje.h"

class DTFecha;
class DTHora;
class DTMensaje;

class Mensaje: public ICollection{
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
        DTFecha getFecha();
        string getTexto();
        void setHora(DTHora);
        void setFecha(DTFecha);
        void setTexto(string);
};

#endif