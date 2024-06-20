#ifndef DTEDIFICIO_H
#define DTEDIFICIO_H

#include "../ICollection/interfaces/ICollectible.h"
#include <iostream>
using namespace std;

class DTEdificio: public ICollectible {
    private:
        int codigo;
        string nombre;
        int cantPisos;
        int gastosComunes;
    public:
        DTEdificio(int, string, int, int);
        ~DTEdificio();
        
        // Getters
        int getCodigo();
        string getNombre();
        int getCantPisos();
        int getGastosComunes();
        
        friend ostream& operator << (ostream &, DTEdificio *);
};

#endif
