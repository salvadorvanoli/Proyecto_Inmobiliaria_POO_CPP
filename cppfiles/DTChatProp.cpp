
#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "../hfiles/dtchatprop.h"

DTChatProp::DTChatProp(int codigo, int codigoCon, int cantMensajes, DTFecha * fechaUltimoMensaje, DTDir* direccion) {
    this->codigoProp = codigo;
    this->codigoCon = codigoCon;
    this->cantMensajes = cantMensajes;
    this->fechaUltimoMensaje = fechaUltimoMensaje;
    this->direccion = direccion;
    this->valorKey = this->generarClaveSegunFecha();
};

DTChatProp::~DTChatProp() {
}

int DTChatProp::getCantMensajes() {
    return cantMensajes;
};

int DTChatProp::getCodigoProp() {
    return codigoProp;
};

int DTChatProp::getCodigoCon() {
    return this->codigoCon;
}

DTDir* DTChatProp::getDir() {
    return direccion;
};

DTFecha* DTChatProp::getFechaUltimoMensaje(){
    return this->fechaUltimoMensaje;
}

int DTChatProp::getValorKey(){
    return this->valorKey;
}

ostream& operator << (ostream & o, DTChatProp * chat){
    o << "Codigo de la propiedad: " << chat->getCodigoProp() << endl << "Codigo de la conversacion: " << chat->getCodigoCon() << endl << "Cantidad de mensajes: " << chat->getCantMensajes() << "Fecha último mensaje: " << chat->getFechaUltimoMensaje() << endl << "Dirección de la propiedad:" << chat->getDir() << endl;
    return o;
}

// Es recontra chatGPT
int DTChatProp::generarClaveSegunFecha(){
    time_t t = time(nullptr);
    tm* ahora = localtime(&t);

    tm fechaHoraActual = *ahora;
    fechaHoraActual.tm_isdst = -1;

    tm fechaHoraComparar = {0};
    fechaHoraComparar.tm_mday = this->getFechaUltimoMensaje()->getDia();
    fechaHoraComparar.tm_mon = this->getFechaUltimoMensaje()->getMes() - 1;
    fechaHoraComparar.tm_year = this->getFechaUltimoMensaje()->getAnio() - 1900;
    fechaHoraComparar.tm_hour = this->getFechaUltimoMensaje()->getHora()->getHora();
    fechaHoraComparar.tm_min = this->getFechaUltimoMensaje()->getHora()->getMinuto();
    fechaHoraComparar.tm_sec = this->getFechaUltimoMensaje()->getHora()->getSegundo();
    fechaHoraComparar.tm_isdst = -1;

    time_t tiempoActual = mktime(&fechaHoraActual);
    time_t tiempoComparar = mktime(&fechaHoraComparar);

    double segundos = difftime(tiempoActual, tiempoComparar);
    return abs(segundos);
}