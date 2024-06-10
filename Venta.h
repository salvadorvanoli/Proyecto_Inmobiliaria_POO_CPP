#ifndef VENTA_H
#define VENTA_H
#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
using namespace std;

class Venta: public ICollectible {
    private:
        float precioTotal;
    public:
        Venta(float);
        bool existeVenta();
        virtual ~Venta();

        //getters y setters
        float getprecioTotal();
        void setprecioTotal(float);
};

#endif