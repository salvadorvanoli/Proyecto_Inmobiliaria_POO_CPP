
#ifndef DTCHATPROP_H
#define DTCHATPROP_H
#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "DTDir.h"
#include "DTMensaje.h"

DTChatProp:: DTChatProp(int codigo) {
    this->codigo = codigo;
};

DTChatProp:: ~DTChatProp() {
}

void DTChatProp:: setCodigo(int codigo) {
    this->codigo = codigo;
};

void DTChatProp:: setcantMensajes(int cantMensajes) {
    this->cantMensajes = cantMesajes;
};

void DTChatProp:: setDir(Dir* direccion) {
    this->direccion = direccion;
};

int DTChatProp:: getcantMensajes() {
    return cantMensajes;
};

int DTChatProp:: getCodigo() {
    return codigo;
};

DTDir* DTChatProp:: getDTDir() {
    return direccion;
};

#endif

