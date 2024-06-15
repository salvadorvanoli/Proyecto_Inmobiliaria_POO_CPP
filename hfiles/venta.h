#ifndef VENTA_H
#define VENTA_H
#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "propiedad.h"

using namespace std;

class Venta: public ICollectible {
    private:
        float precioTotal;
        Propiedad* prop;
    public:
        Venta(float);
        bool existeVenta();
        ~Venta();

        //getters y setters
        float getprecioTotal();
        void setprecioTotal(float);
};

#endif