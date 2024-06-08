#include "mensaje.h"
#include "dthora.h"
#include "dthora.cpp"
#include "dtmensaje.cpp"
#include "dtmensaje.h"
#include <iostream>
using namespace std;

Mensaje::Mensaje(DTHora hora, DTFecha fecha, string texto){
    this->hora = hora;
    this->fecha = fecha;
    this->texto = texto;
}

Mensaje::~Mensaje(){

}

DTHora Mensaje::getHora(){
    return this->hora;
}

DTFecha Mensaje::getFecha(){
    return this->fecha;
}

string Mensaje::getTexto(){
    return this->texto;
}

void Mensaje::setHora(DTHora hora){
    this->hora = hora;
}

void Mensaje::setFecha(DTFecha fecha){
    this->fecha = fecha;
}

void Mensaje::setTexto(string texto){
    this->texto = texto;
}

DTMensaje Mensaje::getDTMensaje(){
    DTMensaje a(this->texto, this->fecha);
    return a;
}