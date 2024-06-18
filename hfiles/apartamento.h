#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <iostream>
using namespace std;

#include "propiedad.h"
#include "edificio.h"

class Edificio;
class Zona;

class Apartamento : public Propiedad{
    private:
        Edificio * edificio;
    public:
        Apartamento(int, int, int, int, float, DTDir*, bool, Zona *, Edificio *);
        ~Apartamento();
        void setEdificio(Edificio *);
        Edificio * getEdificio();
        DTTipoProp getDTTipoProp();
        void desvincularDeEdificio();
        void modificarApartamento(int, int, int, float, DTDir*, bool);
};


#endif