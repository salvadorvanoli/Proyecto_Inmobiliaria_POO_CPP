#include "../hfiles/apartamento.h"
#include <iostream>
using namespace std;

Apartamento::Apartamento(int _codigo, int _cantAmbiente, int _cantDormitorios, int _cantBanios, float _m2Edificios, DTDir * dir, bool _tieneGaraje, int codZona, char* letraDep, int codEdificio, int cantCon, DTInmobiliaria * inmo): Propiedad(_codigo, _cantAmbiente, _cantDormitorios, _cantBanios, _m2Edificios, inmo, dir, _tieneGaraje, cantCon, letraDep, codigoZona){
    this->codigoEdificio = codEdificio;
    this->m2Totales = _m2Edificios;
}

Apartamento::~Apartamento(){}

void Apartamento::setCodigoEdificio(int _edificio){
    this->codigoEdificio = _edificio;
}

int Apartamento::getCodigoEdificio(){
    return this->codigoEdificio;
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