#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "../hfiles/alquiler.h"
using namespace std;

Alquiler:: Alquiler(float precioAlquiler) {
    this->precioAlquiler = precioAlquiler;
};

Alquiler:: ~Alquiler(){
};

float Alquiler:: getprecioAlquiler(){
    return precioAlquiler;
};

void Alquiler:: setprecioAlquiler(float precioAlquiler) {
    this->precioAlquiler = precioAlquiler;
};

