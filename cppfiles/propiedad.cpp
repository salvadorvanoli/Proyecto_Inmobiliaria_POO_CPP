#include "../hfiles/propiedad.h"
#include <iostream>
using namespace std;

Propiedad :: Propiedad(int _codigo, int _cantAmbiente, int _cantDormitorios, int _cantBanios, int _m2Edificios, bool _tieneGaraje, Zona * _zona){
    this->codigo = _codigo;
    this->cantAmbiente =_cantAmbiente;
    this->cantDormitorios = _cantDormitorios;
    this->cantBanios = _cantBanios;
    this->m2Edificios = _m2Edificios;
    this->conversaciones = new OrderedDictionary();
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

void Propiedad :: agregarConversacion(Conversacion * _conver){
    IKey * key = new Integer(_conver->getCodigoConversacion());
    if(this->conversaciones->member(key)){
        delete key;
        throw invalid_argument("La conversación ya existe");
    }
    ICollectible * conversacion = (ICollectible*) _conver;
    this->conversaciones->add(key, conversacion);
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

IDictionary * Propiedad :: getConversaciones(){
    return this->conversaciones;
}

Zona * Propiedad :: getZona(){
    return this->zona;
}


void Propiedad :: desvincularDeZona(){
    this->zona->desvincularPropiedad(this);
}


//(en eliminar propiedad)
//seria hacer un next en la colleccion(conversacion), destruir los mensajes 
//y luego la propia conversacion
//asi uno por uno
void Propiedad :: destruirConversaciones(){ 
    IIterator * aux = this->conversaciones->getIterator();
    Conversacion * con;
    while(aux->hasCurrent()){
        con = (Conversacion *) aux->getCurrent();
        con->destruirMensajes();
        
        aux->next();
    }
    delete aux;
}

DTChatProp * Propiedad :: getDTChatProp(string aa){
    //no la he encontrado
}

ICollection * Propiedad :: getUltimosMensajes(){
    //esta operacion se pasa a conversacion(?
}

//crea una conversacion y la añade a la coleccion
Conversacion * Propiedad :: nuevoChat(){
    
}

