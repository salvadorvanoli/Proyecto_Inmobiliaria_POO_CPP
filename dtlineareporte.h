#ifndef DTLINEAREPORTE_H
#define DTLINEAREPORTE_H
#include <iostream>
#include "ICollection/interfaces/ICollectible.h"

class DTLineaReporte: public ICollectible {
    private:
        int codigoZona;
        string letraDep;
        int cantApartamentos;
        int cantCasas;
    public:
        DTLineaReporte(int, string, int, int);
        ~DTLineaReporte();
        
        // Getters

        int getCodigoZona();
        string getLetraDep();
        int getCantApartamentos();
        int getCantCasas();
};





#endif