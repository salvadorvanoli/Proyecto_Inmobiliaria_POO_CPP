#include "../hfiles/casa.h"
#include <iostream>
using namespace std;

Casa::Casa(int _codigo, int _cantAmbiente, int _cantDormitorios, int _cantBanios, float _m2Edificios, DTDir * dir, bool _tieneGaraje, Zona * _zona, float _m2Verdes, Inmobiliaria* inmo): Propiedad(_codigo, _cantAmbiente, _cantDormitorios, _cantBanios, _m2Edificios, dir, _tieneGaraje, _zona, inmo){
    this->m2Verdes = _m2Verdes;
    this->m2Totales = _m2Edificios + _m2Verdes;
}

void Casa::setM2Verdes(float _m2Verdes){
    this->m2Verdes = _m2Verdes;
}

float Casa::getM2Verdes(){
    return this->m2Verdes;
}

DTTipoProp Casa::getDTTipoProp(){
    return DTTipoProp::casa;
}

void Casa::modificarCasa(int cantAmbientes, int cantDormitorios, int cantBanios, float m2Edificados, DTDir* dir, bool tieneGaraje, float m2Verdes){
    this->cantAmbiente = cantAmbientes;
    this->cantDormitorios = cantDormitorios;
    this->cantBanios = cantBanios;
    this->m2Edificios = m2Edificados;
    this->direccion = dir;
    this->tieneGaraje = tieneGaraje;
    this->m2Verdes = m2Verdes;
    this->m2Totales = m2Edificados + m2Verdes;
}