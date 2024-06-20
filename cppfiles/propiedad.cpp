#include "../hfiles/propiedad.h"
#include <iostream>
using namespace std;

Propiedad :: Propiedad(int _codigo, int _cantAmbiente, int _cantDormitorios, int _cantBanios, float _m2Edificios, DTInmobiliaria* inmo, DTDir* dir, bool _tieneGaraje, int codZona, char* letraDep, int cantCon){
    this->codigo = _codigo;
    this->cantAmbiente =_cantAmbiente;
    this->cantDormitorios = _cantDormitorios;
    this->cantBanios = _cantBanios;
    this->m2Edificios = _m2Edificios;
    this->inmo = inmo;
    this->direccion = dir;
    this->tieneGaraje = _tieneGaraje;
    this->conversaciones = new OrderedDictionary();
    this->codigoZona = codZona;
    this->letraDep = letraDep;
    this->cantConversacionesInmo = cantCon;
}

Propiedad :: ~Propiedad(){
    this->destruirConversaciones();
}

void Propiedad :: setM2Totales(float _m2Totales){
    this->m2Totales = _m2Totales;
}

void Propiedad :: setM2Edificios(float _m2Edificios){
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

void Propiedad::setDireccion(DTDir * dir){
    this->direccion = dir;
}

void Propiedad :: setCodigo(int _codigo){
    this->codigo = _codigo;
}

void Propiedad::setDTInmobiliaria(DTInmobiliaria * inmo){
    this->inmo = inmo;
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

void Propiedad :: setCodigoZona(int codZona){
    this->codigoZona = codZona;
}

void Propiedad::setLetraDep(char * letra){
    this->letraDep = letra;
}

void Propiedad::setEstadoProp(DTEstadoProp estado){
    if ((this->estado == DTEstadoProp::venta && estado == DTEstadoProp::alquiler) || (this->estado == DTEstadoProp::alquiler && estado == DTEstadoProp::venta)){
        this->estado = DTEstadoProp::venta_y_alquiler;
    } else {
        this->estado = estado;
    }
}

bool Propiedad :: getTieneGaraje(){
    return this->tieneGaraje;
}

float Propiedad :: getm2Totales(){
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

DTDir * Propiedad::getDireccion(){
    return this->direccion;
}

float Propiedad :: getM2Edificios(){
    return this->m2Edificios;
}

IDictionary * Propiedad :: getConversaciones(){
    return this->conversaciones;
}

int Propiedad :: getCodigoZona(){
    return this->codigoZona;
}

char * Propiedad :: getLetraDep(){
    return this->letraDep;
}

DTEstadoProp Propiedad::getEstadoProp(){
    return this->estado;
}

int Propiedad::getCantConversacionesInmo(){
    return this->cantConversacionesInmo;
}

//(en eliminar propiedad)
//seria hacer un next en la colleccion(conversacion), destruir los mensajes 
//y luego la propia conversacion
//asi uno por uno
void Propiedad :: destruirConversaciones(){ 
    IIterator * it = this->conversaciones->getIterator();
    Conversacion * con;
    IKey * key;
    while(it->hasCurrent()){
        con = (Conversacion *) it->getCurrent();
        key = new Integer(con->getCodigoConversacion());
        it->next();
        this->conversaciones->remove(key);
        con->destruirMensajes();
        delete con;
    }
    delete it;
}

DTPropiedad * Propiedad::getDTPropiedad(){
    return new DTPropiedad(this->codigo, this->direccion, this->estado);
}

DTPropiedadDetallada * Propiedad::getDTPropiedadDetallada(){
    return new DTPropiedadDetallada(this->codigo, this->direccion, this->estado, this->cantAmbiente, this->cantDormitorios, this->cantBanios, this->tieneGaraje, this->m2Totales, this->getDTInmobiliaria());
}

ICollectible * Propiedad :: getDTChatProp(char * email){
    IIterator * it = this->conversaciones->getIterator();
    Conversacion * con;
    while(it->hasCurrent()){
        con = (Conversacion *) it->getCurrent();
        if (con->getInteresado()->getCorreoEletronico() == email){
            delete it;
            ICollectible *col = (ICollectible *) new DTChatProp(this->codigo, con->getCodigoConversacion(), con->getCantidadMensajes(), con->getFechaUltimoMensaje(), this->direccion);
            return col;
        }
        it->next();
    }
    delete it;
    ICollectible *col = (ICollectible *) new DTPropiedad(this->codigo, this->direccion, this->estado);
    return col;
    // throw
}

ICollection * Propiedad :: getUltimosMensajes(char * email){
    IIterator * it = this->conversaciones->getIterator();
    Conversacion * con;
    while (it->hasCurrent()){
        con = (Conversacion *) it->getCurrent();
        if (con->getInteresado()->getCorreoEletronico() == email){
            delete it;
            return con->getUltimosMensajes();
        }
        it->next();
    }
    delete it;
    throw invalid_argument("No hay ninguna conversación registrada con ese Interesado en la Propiedad actual");
}

Conversacion * Propiedad::getConversacion(char * email){
    IIterator * it = this->conversaciones->getIterator();
    Conversacion * con = NULL;
    while(it->hasCurrent()){
        con = (Conversacion *) it->getCurrent();
        if (con->getInteresado()->getCorreoEletronico() == email){
            delete it;
            return con;
        }
        it->next();
    }
    delete it;
    return NULL;
}

//crea una conversacion y la añade a la coleccion
Conversacion * Propiedad :: nuevoChat(Interesado * interesado){
    int clave = this->getCantConversacionesInmo();
    IKey * key = new Integer(clave);
    Conversacion * c = new Conversacion(clave, interesado);
    if(!this->conversaciones->member(key)){
        ICollectible * nuevoChat = (ICollectible *) c;
        this->conversaciones->add(key, nuevoChat);
        return c;
    }else{
        delete key;
        throw invalid_argument("La conversacion ya fue agregado con anterioridad");
    }
    return NULL;
}

// Devuelve un ICollection que contiene un DTChatProp por cada conversación de la propiedad
IDictionary * Propiedad::listarConversaciones(){
    IDictionary * lista = new OrderedDictionary();
    IIterator * it = this->conversaciones->getIterator();
    Conversacion * con = NULL;
    ICollectible * item = NULL;
    OrderedKey * key = NULL;
    while (it->hasCurrent()){
        con = (Conversacion *) it->getCurrent();
        DTChatProp * dtcon = new DTChatProp(this->codigo, con->getCodigoConversacion(), con->getCantidadMensajes(), con->getFechaUltimoMensaje(), this->getDireccion());
        key = new Integer(dtcon->getValorKey());
        item = (ICollectible *) dtcon;
        lista->add(key, item);
    }
    delete it;
    return lista;
}
