#ifndef DTDIR_H
#define DTDIR_H

#include <iostream>

using namespace std;

class DTDir{
    private:
        string calle;
        int numero;
        string ciudad;
    public:
        DTDir(string, int, string);
        ~DTDir();
        string getCalle();
        int getNumero();
        string getCiudad();
};

#endif