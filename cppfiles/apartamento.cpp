#include "../hfiles/apartamento.h"
#include <iostream>
using namespace std;

Apartamento::Apartamento(int _codigo, int _cantAmbiente, int _cantDormitorios, int _cantBanios, float _m2Edificios, DTDir * dir, bool _tieneGaraje, Zona * _zona, Edificio * _edificio, Inmobiliaria* inmo): Propiedad(_codigo, _cantAmbiente, _cantDormitorios, _cantBanios, _m2Edificios, dir, _tieneGaraje, _zona, inmo){
    this->edificio = _edificio;
    this->m2Totales = _m2Edificios;
}

Apartamento::~Apartamento(){
    this->desvincularDeEdificio();
}

void Apartamento::setEdificio(Edificio * _edificio){
    this->edificio = _edificio;
}

Edificio * Apartamento::getEdificio(){
    return this->edificio;
}

void Apartamento::desvincularDeEdificio(){
    this->edificio->desvincularPropiedad(this->getCodigo());
}

DTTipoProp Apartamento::getDTTipoProp(){
    return DTTipoProp::apartamento;
}

void Apartamento::modificarApartamento(int cantAmbientes, int cantDormitorios, int cantBanios, float m2Totales, DTDir* dir, bool tieneGaraje){
    this->cantAmbiente = cantAmbientes;
    this->cantDormitorios = cantDormitorios;
    this->cantBanios = cantBanios;
    this->m2Totales = m2Totales;
    this->m2Edificios = m2Totales;
    this->direccion = dir;
    this->tieneGaraje = tieneGaraje;
}