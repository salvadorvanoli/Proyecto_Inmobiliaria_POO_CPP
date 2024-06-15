#ifndef DTZONA_H
#define DTZONA_H

#include <iostream>
using namespace std;

class DTZona{
    private:
        int codigoZona;
        string nombre;
    public:
        DTZona(int, string);
        ~DTZona();

        // Getters
        int getCodigoZona();
        string getNombre();

        friend ostream& operator << (ostream &, DTZona *);
};
#endif