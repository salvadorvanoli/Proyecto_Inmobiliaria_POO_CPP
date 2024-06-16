#include <iostream>
#include "../hfiles/venta.h"
using namespace std;

Venta:: Venta(Propiedad * prop, float precioTotal) {
    this->precioTotal= precioTotal;
    this->prop = prop;
};

Venta:: ~Venta() {
};

float Venta::getPrecioTotal() {
    return precioTotal;
};

void Venta::setPrecioTotal(float precioTotal) {
    this->precioTotal = precioTotal;
};

Propiedad* Venta::getPropiedad(){
    return this->prop;
}

