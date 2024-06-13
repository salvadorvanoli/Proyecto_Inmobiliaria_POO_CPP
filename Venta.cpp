#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
using namespace std;

Venta:: Venta(float precioTotal) {
    this->precioTotal= precioTotal;
};

Venta:: ~Venta() {
};

float Venta::getprecioTotal() {
    return precioTotal;
};

void Venta:: setprecioTotal(int precioTotal) {
    this->precioTotal = precioTotal;
};



