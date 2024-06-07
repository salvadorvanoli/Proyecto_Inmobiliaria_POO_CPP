#include <iostream>
#include "propiedad.h"
using namespace std;

Propiedad :: Propiedad(int _codigo, int _cantAmbiente, int _cantDormitorios, int _cantBanios, int _m2Edificios, int _m2Totales, bool _tieneGaraje, Conversacion * _conver){
    this->codigo = _codigo;
    this->cantAmbiente =_cantAmbiente;
    this->cantDormitorios = _cantDormitorios;
    this->cantBanios = _cantBanios;
    this->m2Edificios = _m2Edificios;
    this->m2Totales = _m2Totales;
    this->conver = _conver;
}

Propiedad :: ~Propiedad(){
    
}

void Propiedad :: setM2Totales(int _m2Totales){
    this->m2Totales = _m2Totales;
}

void Propiedad :: setM2Edificios(int _m2Edificios){
    this->m2Edificios = _m2Edificios;
}

void Propiedad :: setTieneGaraje(bool _tieneGaraje){
    this->tieneGaraje = _tieneGaraje;
}

void Propiedad :: setCantBanios(int _cantBanios){
    this->cantBanios = _cantBanios;
}

void Propiedad :: setCantDormitorios(int _cantDormitorios){
    this->cantDormitorios = _cantDormitorios;
}

void Propiedad :: setCantAmbiente(int _cantAmbiente){
    this->cantAmbiente = _cantAmbiente;
}

void Propiedad :: setCodigo(int _codigo){
    this->codigo = _codigo;
}

void Propiedad :: setConver(Conversacion * _conver){
    this->conver = _conver;
}

bool Propiedad :: getTieneGaraje(){
    return this->tieneGaraje;
}

int Propiedad :: getm2Totales(){
    return this->m2Totales;
}

int Propiedad :: getCodigo(){
    return this->codigo;
}

int Propiedad :: getCantAmbiente(){
    return this->cantAmbiente;
}

int Propiedad :: getCantDormitorios(){
    return this->cantDormitorios;
}

int Propiedad :: getCantBanios(){
    return this->cantBanios;
}

int Propiedad :: getM2Edificios(){
    return this->m2Edificios;
}

Conversacion * Propiedad :: getConver(){
    return this->conver;
}

void Propiedad :: asociarVenta(Venta){

}

void Propiedad :: asociarAlquier(Alquier){

}

void Propiedad :: desvincularZona(){
    
}

void Propiedad :: destruirConversacion(){

}

void Propiedad :: destruirVenta(){

}

void Propiedad :: destruirAlquiler(){

}

DTChatProp Propiedad :: getDTChatProp(string){

}

DTMensaje Propiedad :: getUltimosmensajes(){

}

Conversacion Propiedad :: nuevoChat(){

}

