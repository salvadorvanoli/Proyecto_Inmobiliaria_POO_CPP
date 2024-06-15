#ifndef ALQUILER_H
#define ALQUILER_H
#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "propiedad.h"
using namespace std;

class Alquiler: public ICollectible {
    private:
        float precioAlquiler;
        Propiedad * prop;
    public:
        Alquiler(float);
        bool existeAlquiler();
        ~Alquiler();

        //getters y setters
        float getPrecioAlquiler();
        void setPrecioAlquiler(float);
};

#endif