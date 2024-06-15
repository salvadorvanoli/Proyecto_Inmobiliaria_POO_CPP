#ifndef DTEDIFICIO_H
#define DTEDIFICIO_H

#include "../ICollection/interfaces/ICollectible.h"
#include <iostream>
using namespace std;

class DTEdificio: public ICollectible {
    private:
        string nombre;
        int cantPisos;
        int gastosComunes;
    public:
        DTEdificio(string, int, int);
        ~DTEdificio();
        
        // Getters
        string getNombre();
        int getCantPisos();
        int getGastosComunes();
};

#endif
