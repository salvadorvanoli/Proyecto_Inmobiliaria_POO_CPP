#ifndef CASA_H
#define CASA_H

#include <iostream>
using namespace std;

#include "propiedad.h"

class Propiedad;

class Casa : public Propiedad{
    private:
        int m2Verdes;
    public:
        Casa(int, int, int, int, int, DTDir*, bool, Zona *, int);
        void setM2Verdes(int);
        int getM2Verdes();
};


#endif