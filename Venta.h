#ifndef VENTA_H
#define ALQUILERVENTA_H
#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
using namespace std;

class Venta: public ICollectible {
    private:
        float precioTotal;
        propiedad* prop;
    public:
        Venta(float);
        virtual ~Venta();

        //getters y setters
        float getprecioTotal();
        void setprecioTotal(float);
};

#endif