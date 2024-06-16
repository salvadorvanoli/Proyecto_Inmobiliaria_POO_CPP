#include "../hfiles/apartamento.h"
#include <iostream>
using namespace std;

Apartamento::Apartamento(int _codigo, int _cantAmbiente, int _cantDormitorios, int _cantBanios, int _m2Edificios, bool _tieneGaraje, Zona * _zona, Edificio * _edificio): Propiedad(_codigo, _cantAmbiente, _cantDormitorios, _cantBanios, _m2Edificios, _tieneGaraje, _zona){
    this->edificio = _edificio;
    this->m2Totales = _m2Edificios;
}

void Apartamento::setEdificio(Edificio * _edificio){
    this->edificio = _edificio;
}

Edificio * Apartamento::getEdificio(){
    return this->edificio;
}

void Apartamento::desvincularDeEdificio(){
    //this->edificio->desvincularPropiedad(this);
}