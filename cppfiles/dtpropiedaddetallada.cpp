#include "../hfiles/dtpropiedaddetallada.h"
#include <iostream>
using namespace std;

DTPropiedadDetallada::DTPropiedadDetallada(int codigo, DTDir * direccion, DTEstadoProp * estado, int cantAmbientes, int cantDormitorios, int cantBanios, bool tieneGaraje, float m2Totales, DTInmobiliaria * inmo): DTPropiedad(codigo, direccion, estado){
    this->cantAmbientes = cantAmbientes;
    this->cantDormitorios = cantDormitorios;
    this->cantBanios = cantBanios;
    this->tieneGaraje = tieneGaraje;
    this->m2Totales = m2Totales;
    this->inmo = inmo;
}

DTPropiedadDetallada::~DTPropiedadDetallada(){}

// Getters

int DTPropiedadDetallada::getCantAmbientes(){
    return this->cantAmbientes;
}

int DTPropiedadDetallada::getCantDormitorios(){
    return this->cantDormitorios;
}

int DTPropiedadDetallada::getCantBanios(){
    return this->cantBanios;
}

bool DTPropiedadDetallada::getTieneGaraje(){
    return this->tieneGaraje;
}

float DTPropiedadDetallada::getM2Totales(){
    return this->m2Totales;
}

DTInmobiliaria * DTPropiedadDetallada::getInmo(){
    return this->inmo;
}

ostream& operator << (ostream & o, DTPropiedadDetallada * prop){
    string garaje;
    if (prop->getTieneGaraje()){
        garaje = "Si";
    } else {
        garaje = "No";
    }
    o << "Codigo: " << prop->getCodigoProp() << endl << "Estado: " << prop->getEstado() << endl << "Direccion: " << prop->getDireccion() << "Cantidad de ambientes: " << prop->getCantAmbientes() << endl << "Cantidad de dormitorios: " << prop->getCantDormitorios() << endl << "Cantidad de baños: " << prop->getCantBanios() << endl << "Tiene garaje: " << garaje << endl << "M2 Totales: " << prop->getM2Totales() << endl << "Inmobiliaria: " << endl << prop->getInmo();
    return o;
}