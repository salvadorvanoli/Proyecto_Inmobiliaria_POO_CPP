#include"../hfiles/dtreporte.h"
#include <iostream>
using namespace std;

DTReporte::DTReporte(DTInmobiliaria * inmo, ICollection * lineas){
    this->inmo = inmo;
    this->lineas = lineas;
}

DTReporte::~DTReporte(){}

// Getters

DTInmobiliaria * DTReporte::getInmo(){
    return this->inmo;
}

ICollection * DTReporte::getLineas(){
    return this->lineas;
}