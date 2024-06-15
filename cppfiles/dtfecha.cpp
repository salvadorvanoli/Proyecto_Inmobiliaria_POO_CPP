#include "../hfiles/dtfecha.h"
#include "../hfiles/dthora.h"
#include <iostream>
using namespace std;

DTFecha::DTFecha(string dia, string mes, string anio, DTHora * hora){
this->dia = dia;
this->mes = mes;
this->anio = anio;
this-> hora = hora;
}

DTFecha::~DTFecha(){

}

string DTFecha::getDia(){
    return this->dia;
}

string DTFecha::getMes(){
    return this->mes;
}

string DTFecha::getAnio(){
    return this->anio;
}

DTHora * DTFecha::getHora(){
    return this->hora;
}

ostream& operator << (ostream & o, DTFecha * fecha){
    o << "Fecha: " << fecha->getDia() << '/' << fecha->getMes() << '/' << fecha->getAnio() << endl << fecha->getHora();
    return o;
}