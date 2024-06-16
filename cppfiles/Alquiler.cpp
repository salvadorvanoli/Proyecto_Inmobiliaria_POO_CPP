#include <iostream>
#include "../hfiles/alquiler.h"
using namespace std;

Alquiler:: Alquiler(Propiedad * prop, float precioAlquiler) {
    this->precioAlquiler = precioAlquiler;
    this->prop = prop;
};

Alquiler:: ~Alquiler(){
};

float Alquiler:: getPrecioAlquiler(){
    return precioAlquiler;
};

void Alquiler:: setPrecioAlquiler(float precioAlquiler) {
    this->precioAlquiler = precioAlquiler;
};

