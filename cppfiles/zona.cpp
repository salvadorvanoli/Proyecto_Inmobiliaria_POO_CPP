#include "../hfiles/zona.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include <iostream>
using namespace std;

Zona::Zona(int codigo, string nombre){
    this->codigo = codigo;
    this->nombre = nombre;
    this->edificios = new OrderedDictionary();
    this->propiedades = new OrderedDictionary();
    this->cantEdificios = 0;
    this->cantPropiedades = 0;
    // Falta especificar el ICollection
}

Zona::~Zona(){}

// Getters

int Zona::getCodigo(){
    return this->codigo;
}

string Zona::getNombre(){
    return this->nombre;
}

int Zona::getCantEdificios(){
    return this->cantEdificios;
}

int Zona::getCantPropiedades(){
    return this->cantPropiedades;
}

IDictionary * Zona::getEdificios(){
    return this->edificios; // Capaz no es asi
}

IDictionary * Zona::getPropiedades(){
    return this->propiedades; // Capaz no es asi
}

// Setters

void Zona::setCodigo(int codigo){
    this->codigo = codigo;
}

void Zona::setNombre(string nombre){
    this->nombre = nombre;
}

void Zona::setCantEdificios(int cantEdificios){
    this->cantEdificios = cantEdificios;
}

void Zona::setCantPropiedades(int cantPropiedades){
    this->cantPropiedades = cantPropiedades;
}

// Agregar-Quitar

void Zona::agregarEdificio(Edificio * edificio){
    
    IKey * nuevaKey = (IKey *) edificio->getCodigo();
    if (!this->edificios->member(nuevaKey)){
        ICollectible * nuevoEdificio = (ICollectible *) edificio;
        this->edificios->add(nuevaKey, nuevoEdificio);
        this->cantEdificios++;
        cout << "El edificio fue agregado exitosamente!" << endl;
    } else {
        cout << "El edificio ya fue agregado con anterioridad" << endl;
    }

    // ES CON ICOLLECTION
}

void Zona::quitarEdificio(int codigoEdificio){

    IKey * clave = (IKey *) codigoEdificio;
    if (this->edificios->member(clave)){
        this->edificios->remove(clave);
        this->cantEdificios--;
        cout << "El edificio fue removido de manera exitosa!" << endl;
    } else {
        cout << "El edificio especificado no se encuentra en la zona actual" << endl;
    }
    // ES CON ICOLLECTION
}

void Zona::agregarPropiedad(Propiedad * propiedad){

    IKey * nuevaKey = (IKey *) propiedad->getCodigo();
    if (!this->edificios->member(nuevaKey)){
        ICollectible * nuevaPropiedad = (ICollectible *) propiedad;
        this->propiedades->add(nuevaKey, nuevaPropiedad);
        this->cantPropiedades++;
        cout << "La propiedad fue agregado exitosamente!" << endl;
    } else {
        cout << "La propiedad ya fue agregado con anterioridad" << endl;
    }
    // ES CON ICOLLECTION
}

void Zona::quitarPropiedad(int codigoProp){

    IKey * clave = (IKey *) codigoProp;
    if (this->propiedades->member(clave)){
        this->propiedades->remove(clave);
        this->cantPropiedades--;
        cout << "La propiedad fue removida de manera exitosa!" << endl;
    } else {
        cout << "La propiedad especificada no se encuentra en la zona actual" << endl;
    }
    // ES CON ICOLLECTION
}

// Métodos de Zona (DCD)

ICollection * Zona::listarEdificios(){
    // ES CON ICOLLECTION
}

Edificio * Zona::seleccionarEdificio(int codigoEdificio){

    IKey * clave = (IKey *) codigoEdificio;
    Edificio * edificio = (Edificio *) this->edificios->find(clave);
    if (edificio != NULL){
        return edificio;
    } else {
        cout << "El edificio especificado no se encuentra en la zona actual" << endl;
        return NULL;
    }
    // ES CON ICOLLECTION
}

void Zona::enlazarZona(Propiedad *){
    // ES CON ICOLLECTION
}

// REVISAR ESTO !!!!!!!!!!!!!!!!!!!!!!!!!!! (el feli lo hizo mal)
Casa * Zona::crearCasa(int cantAmbientes, int cantBanios, int cantDormitorios, bool tieneGaraje, DTDir * direccion,int m2Edificados, int m2Verdes){
    return new Casa(cantAmbientes, cantBanios, cantDormitorios, tieneGaraje, direccion, m2Edificados, m2Verdes);
}

// NO ES ASI
void Zona::desvincularZona(Propiedad * propiedad){

    IKey * codigoProp = (IKey *) propiedad->getCodigo();
    if (this->propiedades->member(codigoProp)){
        this->propiedades->remove(codigoProp);
        cout << "La propiedad fue removida de manera exitosa!" << endl;
    } else {
        cout << "La propiedad especificada no se encuentra en la zona actual" << endl;
    }
    // ES CON ICOLLECTION
}

DTChatProp * Zona::listarChatPropiedad(char * email){
    // ES CON ICOLLECTION
}

Propiedad * Zona::seleccionarPropiedad(int codigoProp){

    IKey * clave = (IKey *) codigoProp;
    Propiedad * propiedad = (Propiedad *) this->propiedades->find(clave);
    if (propiedad != NULL){
        return propiedad;
    } else {
        cout << "La propiedad especificada no se encuentra en la zona actual" << endl;
        return NULL;
    }
    // ES CON ICOLLECTION
}

ICollection * Zona::getUltimosMensajes(){
    // ES CON ICOLLECTION
}