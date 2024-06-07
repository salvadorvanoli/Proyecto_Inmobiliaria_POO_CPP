#ifndef DTREPORTE_H
#define DTREPORTE_H
#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "dtinmobiliaria.h"
#include "dtlineareporte.h"


class DTReporte {
    private:
        DTInmobiliaria * inmo;
        ICollection * lineas;
    public:
        DTReporte(DTInmobiliaria *, ICollection * );
        ~DTReporte();
        
        // Getters

        DTInmobiliaria * getInmo();
        DTLineaReporte ** getLineas();
};





#endif