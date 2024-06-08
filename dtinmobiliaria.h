#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <iostream>
#include "dtdir.h"

using namespace std;

class DTInmobiliaria{
    private:
        char* nombre;
        DTDir direccion;
    public:
        DTInmobiliaria(char*, DTDir);
        ~DTInmobiliaria();
        char* getNombre();
        DTDir getDireccion();
};

#endif