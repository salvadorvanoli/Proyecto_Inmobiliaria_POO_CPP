#ifndef DTINMOBILIARIA_H
#define DTINMOBILIARIA_H

#include <iostream>
using namespace std;

#include "dtdir.h"

class DTDir;

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