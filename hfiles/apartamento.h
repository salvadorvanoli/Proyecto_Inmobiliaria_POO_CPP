#ifndef APARTAMENTO_H
#define APARTAMENTO_H

#include <iostream>
using namespace std;

#include "propiedad.h"
#include "edificio.h"

class Propiedad;

class Apartamento : public Propiedad{
    private:
        Edificio * edificio;
    public:
        Apartamento(int, int, int, int, int, bool, Zona *, Edificio *);
        void setEdificio(Edificio *);
        Edificio * getEdificio();
        void desvincularDeEdificio();
};


#endif