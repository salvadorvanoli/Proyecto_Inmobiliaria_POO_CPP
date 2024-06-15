#include "../hfiles/dtfecha.h"
#include "../hfiles/dthora.h"
#include "dthora.cpp"
#include <iostream>
using namespace std;

DTFecha::DTFecha(string dia, string mes, string anio, DTHora hora){
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
