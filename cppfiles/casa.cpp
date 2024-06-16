#include "../hfiles/casa.h"
#include <iostream>
using namespace std;

Casa::Casa(int _codigo, int _cantAmbiente, int _cantDormitorios, int _cantBanios, int _m2Edificios, DTDir * dir, bool _tieneGaraje, Zona * _zona, int _m2Verdes): Propiedad(_codigo, _cantAmbiente, _cantDormitorios, _cantBanios, _m2Edificios, dir, _tieneGaraje, _zona){
    this->m2Verdes = _m2Verdes;
    this->m2Totales = _m2Edificios + _m2Verdes;
}

void Casa::setM2Verdes(int _m2Verdes){
    this->m2Verdes = _m2Verdes;
}

int Casa::getM2Verdes(){
    return this->m2Verdes;
}