#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <iostream>
using namespace std;

#include "dtdir.h"
#include "../ICollection/interfaces/ICollectible.h"

class DTDir;

class DTInmobiliaria: public ICollectible{
    private:
        string nombre;
        DTDir * direccion;
    public:
        DTInmobiliaria(string, DTDir *);
        ~DTInmobiliaria();
        string getNombre();
        DTDir * getDireccion();
        friend ostream& operator << (ostream &, DTInmobiliaria *);
};

#endif