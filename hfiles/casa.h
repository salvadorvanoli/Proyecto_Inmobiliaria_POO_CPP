#ifndef CASA_H
#define CASA_H

#include <iostream>
using namespace std;

#include "propiedad.h"

class Zona;

class Casa : public Propiedad{
    private:
        float m2Verdes;
    public:
        Casa(int, int, int, int, float, DTDir*, bool, int, char*, float, int, DTInmobiliaria*);
        void setM2Verdes(float);
        float getM2Verdes();
        DTTipoProp getDTTipoProp();
        void modificarCasa(int, int, int, float, DTDir*, bool, float);
};


#endif