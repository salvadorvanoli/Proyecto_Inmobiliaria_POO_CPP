#include "../hfiles/dthora.h"
#include <iostream>
using namespace std;

DTHora::DTHora(int hora, int minuto, int segundo){
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

DTHora::~DTHora(){

}

int DTHora::getHora(){
    return this->hora;
}

int DTHora::getMinuto(){
    return this->minuto;
}

int DTHora::getSegundo(){
    return this->segundo;
}

ostream& operator << (ostream & o, DTHora * hora){
    o << "    Hora: " << hora->getHora() << ':' << hora->getMinuto() << ':' << hora->getSegundo() << endl;
    return o;
}