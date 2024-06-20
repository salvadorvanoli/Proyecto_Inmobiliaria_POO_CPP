#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <iostream>
using namespace std;

#include "propiedad.h"

class Apartamento : public Propiedad{
    private:
        int codigoEdificio;
    public:
        Apartamento(int, int, int, int, float, DTDir*, bool, int, char*, int, int, DTInmobiliaria *);
        ~Apartamento();
        void setCodigoEdificio(int);
        int getCodigoEdificio();
        DTTipoProp getDTTipoProp();
        void modificarApartamento(int, int, int, float, DTDir*, bool);
};


#endif