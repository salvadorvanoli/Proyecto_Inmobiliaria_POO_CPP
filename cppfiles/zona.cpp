#include "../hfiles/zona.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/Integer.h"
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
    
    IKey * nuevaKey = new Integer (edificio->getCodigo());
    if (!this->edificios->member(nuevaKey)){
        ICollectible * nuevoEdificio = (ICollectible *) edificio;
        this->edificios->add(nuevaKey, nuevoEdificio);
        this->cantEdificios++;
        cout << "El edificio fue agregado exitosamente!" << endl;
    } else {
        delete nuevaKey;
        throw invalid_argument("El edificio ya fue agregado con anterioridad");
    }

    // ES CON ICOLLECTION
}

void Zona::quitarEdificio(int codigoEdificio){

    IKey * clave = new Integer (codigoEdificio);
    if (this->edificios->member(clave)){
        this->edificios->remove(clave);
        this->cantEdificios--;
        delete clave;
        cout << "El edificio fue removido de manera exitosa!" << endl;
    } else {
        delete clave;
        throw invalid_argument("El edificio especificado no se encuentra en la zona actual");
    }
    // ES CON ICOLLECTION
}

void Zona::agregarPropiedad(Propiedad * propiedad){

    IKey * nuevaKey = new Integer (propiedad->getCodigo());
    if (!this->edificios->member(nuevaKey)){
        ICollectible * nuevaPropiedad = (ICollectible *) propiedad;
        this->propiedades->add(nuevaKey, nuevaPropiedad);
        this->cantPropiedades++;
        cout << "La propiedad fue agregado exitosamente!" << endl;
    } else {
        delete nuevaKey;
        throw invalid_argument("La propiedad ya fue agregado con anterioridad");
    }
    // ES CON ICOLLECTION
}

void Zona::quitarPropiedad(int codigoProp){

    IKey * clave = new Integer (codigoProp);
    if (this->propiedades->member(clave)){
        this->propiedades->remove(clave);
        this->cantPropiedades--;
        delete clave;
        cout << "La propiedad fue removida de manera exitosa!" << endl;
    } else {
        delete clave;
        throw invalid_argument("La propiedad especificada no se encuentra en la zona actual");
    }
    // ES CON ICOLLECTION
}

// Métodos de Zona (DCD)

ICollection * Zona::listarEdificios(){
    ICollection * edificios = new List();
    IIterator * it = this->edificios->getIterator();
    Edificio * edificio;
    ICollectible * item;
    while (it->hasCurrent()){
        edificio = (Edificio *) it->getCurrent();
        item = (ICollectible *) edificio->getDTEdifico();
        edificios->add(item);
        it->next();
    }
    delete it;
    return edificios;
    // ES CON ICOLLECTION
}

Edificio * Zona::seleccionarEdificio(int codigoEdificio){

    IKey * clave = new Integer (codigoEdificio);
    Edificio * edificio = (Edificio *) this->edificios->find(clave);
    delete clave;
    if (edificio != NULL){
        return edificio;
    } else {
        throw invalid_argument("El edificio especificado no se encuentra en la zona actual");
    }
    // ES CON ICOLLECTION
}

// ES LO MISMO QUE AGREGAR PROPIEDAD
void Zona::enlazarPropiedad(Propiedad * propiedad){
    
    IKey * nuevaKey = new Integer (propiedad->getCodigo());
    if (!this->edificios->member(nuevaKey)){
        ICollectible * nuevaPropiedad = (ICollectible *) propiedad;
        this->propiedades->add(nuevaKey, nuevaPropiedad);
        this->cantPropiedades++;
        cout << "La propiedad fue agregado exitosamente!" << endl;
    } else {
        delete nuevaKey;
        throw invalid_argument("La propiedad ya fue agregado con anterioridad");
    }
    // ES CON ICOLLECTION
}

// REVISAR ESTO !!!!!!!!!!!!!!!!!!!!!!!!!!! (el feli lo hizo mal)
Casa * Zona::crearCasa(int cantAmbientes, int cantBanios, int cantDormitorios, bool tieneGaraje, DTDir * direccion,int m2Edificados, int m2Verdes){
    return new Casa(cantAmbientes, cantBanios, cantDormitorios, tieneGaraje, direccion, m2Edificados, m2Verdes);
}

// ES LO MISMO QUE QUITAR PROPIEDAD
void Zona::desvincularPropiedad(Propiedad * propiedad){

    IKey * clave = new Integer (propiedad->getCodigo());
    if (this->propiedades->member(clave)){
        this->propiedades->remove(clave);
        delete clave;
        cout << "La propiedad fue removida de manera exitosa!" << endl;
    } else {
        delete clave;
        throw invalid_argument("La propiedad especificada no se encuentra en la zona actual");
    }
    // ES CON ICOLLECTION
}

ICollection * Zona::listarChatPropiedad(char * email){
    IIterator * it = this->propiedades->getIterator();
    ICollection * lista = new List();
    Propiedad * prop;
    ICollectible * item;
    while (it->hasCurrent()){
        prop = (Propiedad *) it->getCurrent();
        item = (ICollectible *) prop->getDTChatProp(email);
        lista->add(item);
        it->next();
    }
    delete it;
    return lista;
    // ES CON ICOLLECTION
}

Propiedad * Zona::seleccionarPropiedad(int codigoProp){

    IKey * clave = new Integer (codigoProp);
    Propiedad * propiedad = (Propiedad *) this->propiedades->find(clave);
    delete clave;
    if (propiedad != NULL){
        return propiedad;
    } else {
        throw invalid_argument("La propiedad especificada no se encuentra en la zona actual");
    }
    // ES CON ICOLLECTION
}

ICollection * Zona::getUltimosMensajes(){
    // ES CON ICOLLECTION
}