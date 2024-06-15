#ifndef DTDEPARTAMENTO_H
#define DTDEPARTAMENTO_H

#include <iostream>
using namespace std;

class DTDepartamento{
    private:
        char* letra;
        string nombre;
    public:
        DTDepartamento();
        DTDepartamento(char*, string);
        ~DTDepartamento();
        char* getLetra();
        string getNombre();
        friend ostream& operator << (ostream &, DTDepartamento *);
};

#endif