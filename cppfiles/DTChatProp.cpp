
#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "../hfiles/dtchatprop.h"

DTChatProp::DTChatProp(int codigo) {
    this->codigo = codigo;
};

DTChatProp::~DTChatProp() {
}

void DTChatProp::setCodigo(int codigo) {
    this->codigo = codigo;
};

void DTChatProp::setcantMensajes(int cantMensajes) {
    this->cantMensajes = cantMensajes;
};

void DTChatProp::setDir(DTDir* direccion) {
    this->direccion = direccion;
};

int DTChatProp::getcantMensajes() {
    return cantMensajes;
};

int DTChatProp::getCodigo() {
    return codigo;
};

DTDir* DTChatProp::getDir() {
    return direccion;
};