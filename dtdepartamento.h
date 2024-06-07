#ifndef DTDEPARTAMENTO_H
#define DTDEPARTAMENTO_H

#include <iostream>
using namespace std;

class DTDepartamento{
    private:
        string letra;
        string nombre;
    public:
        DTDepartamento(string, string);
        ~DTDepartamento();
        string getLetra();
        string getNombre();
};

#endif