#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <iostream>
#include "dtdir.h"

using namespace std;

class DTInmobiliaria{
    private:
        string nombre;
        DTDir direccion;
    public:
        DTInmobiliaria(string, DTDir);
        ~DTInmobiliaria();
        string getNombre();
        DTDir getDireccion();
};

#endif