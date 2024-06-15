#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "../hfiles/alquiler.h"
using namespace std;

Alquiler:: Alquiler(float precioAlquiler) {
    this->precioAlquiler = precioAlquiler;
};

Alquiler:: ~Alquiler(){
};

float Alquiler:: getPrecioAlquiler(){
    return precioAlquiler;
};

void Alquiler:: setPrecioAlquiler(float precioAlquiler) {
    this->precioAlquiler = precioAlquiler;
};

