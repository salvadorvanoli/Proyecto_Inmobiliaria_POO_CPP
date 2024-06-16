#include "../hfiles/dtreporte.h"
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

// DUDO QUE ESTE BIEN
ostream& operator << (ostream & o, DTReporte * reporte){
    o << "Inmobiliaria: " << reporte->getInmo() << endl;
    IIterator * it = reporte->lineas->getIterator();
    DTLineaReporte * linea;
    while(it->hasCurrent()){
        linea = (DTLineaReporte *) it->getCurrent();
        o << linea << endl;
        it->next();
    }
    delete it;
    return o;
}