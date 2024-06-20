#ifndef MENSAJE_H
#define MENSAJE_H

#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"
#include "dthora.h"
#include "dtfecha.h"
#include "dtmensaje.h"

class DTFecha;
class DTMensaje;

class Mensaje: public ICollectible{
    private:
        int codigoMen;
        DTFecha * fecha;
        string texto;
    public:
        Mensaje();
        Mensaje(int, DTFecha *, string);
        ~Mensaje();
        DTMensaje * getDTMensaje();
        int getCodigo();
        DTFecha * getFecha();
        string getTexto();
        void setFecha(DTFecha *);
        void setTexto(string);
};

#endif