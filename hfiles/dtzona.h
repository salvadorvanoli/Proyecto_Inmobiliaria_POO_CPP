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
        int getCodigozona();
        string getNombre();
};
#endif