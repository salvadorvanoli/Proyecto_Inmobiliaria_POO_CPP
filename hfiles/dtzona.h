#ifndef DTZONA_H
#define DTZONA_H

#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
using namespace std;

class DTZona: public ICollectible{
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