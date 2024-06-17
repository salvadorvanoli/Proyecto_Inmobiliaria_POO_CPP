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
        Casa(int, int, int, int, float, DTDir*, bool, Zona *, float);
        void setM2Verdes(float);
        float getM2Verdes();
        DTTipoProp getDTTipoProp();
};


#endif