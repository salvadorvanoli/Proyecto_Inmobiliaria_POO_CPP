
#include <iostream>
#include "../ICollection/interfaces/ICollectible.h"
#include "../hfiles/dtchatprop.h"

DTChatProp::DTChatProp(int codigo, int cantMensajes, DTDir* direccion) {
    this->codigo = codigo;
    this->cantMensajes = cantMensajes;
    this->direccion = direccion;
};

DTChatProp::~DTChatProp() {
}

int DTChatProp::getcantMensajes() {
    return cantMensajes;
};

int DTChatProp::getCodigo() {
    return codigo;
};

DTDir* DTChatProp::getDir() {
    return direccion;
};