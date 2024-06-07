#ifndef DTPROPIEDADDETALLADA_H
#define DTPROPIEDADDETALLADA_H
#include <iostream>
#include "dtpropiedad.h"
#include "dtinmobiliaria.h"

class DTReporte: public DTPropiedad {
    private:
        int cantAmbientes;
        int cantDormitorios;
        int cantBanios;
        bool tieneGaraje;
        float m2Totales;
        DTInmobiliaria * inmo;
    public:
        DTPropiedadDetallada(int, int, int, int, bool, float);
        ~DTPropiedadDetallada();
        
        // Getters

        int getCantAmbientes();
        int getCantDormitorios();
        int getCantBanios();
        bool getTieneGaraje();
        float getM2Totales();
        DTInmobiliaria * getInmo();
};


#endif