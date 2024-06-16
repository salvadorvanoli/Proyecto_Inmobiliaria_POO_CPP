#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "../hfiles/venta.h"
using namespace std;

Venta:: Venta(Propiedad * prop, float precioTotal) {
    this->precioTotal= precioTotal;
    this->prop = prop;
};

Venta:: ~Venta() {
};

float Venta::getprecioTotal() {
    return precioTotal;
};

void Venta:: setprecioTotal(float precioTotal) {
    this->precioTotal = precioTotal;
};



