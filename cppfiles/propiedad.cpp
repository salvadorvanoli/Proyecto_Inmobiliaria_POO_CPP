#include "../hfiles/propiedad.h"
#include <iostream>
using namespace std;

Propiedad :: Propiedad(int _codigo, int _cantAmbiente, int _cantDormitorios, int _cantBanios, int _m2Edificios, int _m2Totales, bool _tieneGaraje, Conversacion * _conver, Zona * _zona){
    this->codigo = _codigo;
    this->cantAmbiente =_cantAmbiente;
    this->cantDormitorios = _cantDormitorios;
    this->cantBanios = _cantBanios;
    this->m2Edificios = _m2Edificios;
    this->m2Totales = _m2Totales;
    this->conversacion = _conver;
    this->zona = _zona;
}

Propiedad :: ~Propiedad(){
    
}

void Propiedad :: setM2Totales(int _m2Totales){
    this->m2Totales = _m2Totales;
}

void Propiedad :: setM2Edificios(int _m2Edificios){
    this->m2Edificios = _m2Edificios;
}

void Propiedad :: setTieneGaraje(bool _tieneGaraje){
    this->tieneGaraje = _tieneGaraje;
}

void Propiedad :: setCantBanios(int _cantBanios){
    this->cantBanios = _cantBanios;
}

void Propiedad :: setCantDormitorios(int _cantDormitorios){
    this->cantDormitorios = _cantDormitorios;
}

void Propiedad :: setCantAmbiente(int _cantAmbiente){
    this->cantAmbiente = _cantAmbiente;
}

void Propiedad :: setCodigo(int _codigo){
    this->codigo = _codigo;
}

void Propiedad :: setConversacion(Conversacion * _conver){
    this->conversacion = _conver;
}

void Propiedad :: setZona(Zona * _zona){
    this->zona = _zona;
}

bool Propiedad :: getTieneGaraje(){
    return this->tieneGaraje;
}

int Propiedad :: getm2Totales(){
    return this->m2Totales;
}

int Propiedad :: getCodigo(){
    return this->codigo;
}

int Propiedad :: getCantAmbiente(){
    return this->cantAmbiente;
}

int Propiedad :: getCantDormitorios(){
    return this->cantDormitorios;
}

int Propiedad :: getCantBanios(){
    return this->cantBanios;
}

int Propiedad :: getM2Edificios(){
    return this->m2Edificios;
}

Conversacion * Propiedad :: getConversacion(){
    return this->nodoconversacion;
}

Zona * Propiedad :: getZona(){
    return this->zona;
}


void Propiedad :: desvincularZona(){
    this->zona->desvincularZona(this);
}

void Propiedad :: destruirConversacion(){ //(en eliminar propiedad)
    //seria hacer un next en la colleccion(conversacion), destruir los mensajes 
    //y luego la propia conversacion
    //asi uno por uno
    ICollection * aux;
    aux = this->conversacion;
    if(aux->isEmpty()){
        //se deberia hacer un next en la collecion conversacion en esta linea
        //aux->~Conversacion();
        delete aux;
        return;
    }
    /*while(){

    }*/
    delete aux;
}

void Propiedad :: destruirVenta(){//(en eliminar propiedad)
    //si la venta existe se le hace destroy
    if(this->venta->existeVenta()){
        this->venta->~Venta();
    }
}

void Propiedad :: destruirAlquiler(){//(en eliminar propiedad)
    //si el alquiler existe se le hace destroy
}

DTChatProp * Propiedad :: getDTChatProp(string aa){
    //no la he encontrado
}

DTMensaje * Propiedad :: getUltimosmensajes(){
    //esta operacion se pasa a conversacion(?
}

Conversacion * Propiedad :: nuevoChat(){
    //crea una conversacion y la añade a la collecion
}

