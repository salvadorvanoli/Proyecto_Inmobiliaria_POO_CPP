#include "../hfiles/dtmensaje.h"
#include "../hfiles/dtfecha.h"
#include "dtfecha.cpp"
#include <iostream>
using namespace std;

DTMensaje::DTMensaje(string contenido, DTFecha fecha){
    this->contenido = contenido;
    this->fecha = fecha;
}

DTMensaje::~DTMensaje(){

}

string DTMensaje::getContenido(){
    return this->contenido;
}

DTFecha DTMensaje::getFecha(){
    return this->fecha;
}