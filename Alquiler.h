#ifndef ALQUILER_H
#define ALQUILER_H
#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
using namespace std;

class Alquiler: public ICollectible {
    private:
        float precioAlquiler;
        propiedad* prop;
    public:
        Alquiler(float);
        virtual ~Alquiler();

        //getters y setters
        float getprecioAlquiler();
        void setprecioAlquiler(float);
};

#endif