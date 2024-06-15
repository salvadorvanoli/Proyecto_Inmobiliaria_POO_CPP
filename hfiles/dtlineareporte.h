#ifndef DTLINEAREPORTE_H
#define DTLINEAREPORTE_H

#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"

class ICollectible;

class DTLineaReporte: public ICollectible {
    private:
        int codigoZona;
        char * letraDep;
        int cantApartamentos;
        int cantCasas;
    public:
        DTLineaReporte(int, char *, int, int);
        ~DTLineaReporte();
        
        // Getters

        int getCodigoZona();
        char * getLetraDep();
        int getCantApartamentos();
        int getCantCasas();

        friend ostream& operator << (ostream &, DTLineaReporte *);
};

#endif