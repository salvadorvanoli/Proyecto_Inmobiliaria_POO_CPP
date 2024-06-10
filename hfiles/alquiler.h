#ifndef ALQUILER_H
#define ALQUILER_H
#include <iostream>
#include "../ICollection/interfaces/ICollection.h"
using namespace std;

class Alquiler: public ICollectible {
    private:
        float precioAlquiler;
    public:
        Alquiler(float);
        bool existeAlquiler();
        virtual ~Alquiler();

        //getters y setters
        float getprecioAlquiler();
        void setprecioAlquiler(float);
};

#endif