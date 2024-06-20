
#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "../hfiles/dtchatprop.h"

DTChatProp::DTChatProp(int codigo, int cantMensajes, DTFecha * fechaUltimoMensaje, DTDir* direccion) {
    this->codigo = codigo;
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

int DTChatProp::getCodigo() {
    return codigo;
};

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
    o << "Codigo de la conversación: " << chat->getCodigo() << endl << "Cantidad de mensajes: " << chat->getCantMensajes() << endl << "Fecha último mensaje: " << endl << chat->getFechaUltimoMensaje() << "Dirección de la propiedad:" << endl << chat->getDir() << endl;
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