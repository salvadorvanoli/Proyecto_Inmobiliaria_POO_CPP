#include "../hfiles/edificio.h"
#include <iostream>
using namespace std;

Edificio::Edificio(int codigo, string nombre, int cantPisos, int gastosComunes, Zona* zona){
    this->codigo = codigo;
    this->nombre = nombre;
    this->cantPisos = cantPisos;
    this->gastosComunes = gastosComunes;
    this->apartamentos = new OrderedDictionary();
    this->cantApartamentos = 0;
    this->zona = zona;
    // Falta especificar el ICollection
}

Edificio::~Edificio(){}

// Getters

int Edificio::getCodigo(){
    return this->codigo;
}

string Edificio::getNombre(){
    return this->nombre;
}

int Edificio::getCantPisos(){
    return this->cantPisos;
}

int Edificio::getGastosComunes(){
    return this->gastosComunes;
}

int Edificio::getCantApartamentos(){
    return this->cantApartamentos;
}

IDictionary * Edificio::getApartamentos(){
    return this->apartamentos; // Capaz no es asi
}

Zona * Edificio::getZona(){
    return this->zona;
}

// Setters

void Edificio::setCodigo(int codigo){
    this->codigo = codigo;
}

void Edificio::setNombre(string nombre){
    this->nombre = nombre;
}

void Edificio::setCantPisos(int cantPisos){
    this->cantPisos = cantPisos;
}

void Edificio::setGastosComunes(int gastosComunes){
    this->gastosComunes = gastosComunes;
}

void Edificio::setCantApartamentos(int cantApartamentos){
    this->cantApartamentos = cantApartamentos;
}

void Edificio::setZona(Zona * zona){
    this->zona = zona;
}

// Agregar-Quitar

void Edificio::enlazarPropiedad(Apartamento * apartamento){

    IKey * nuevaKey = new Integer (apartamento->getCodigo());
    if (!this->apartamentos->member(nuevaKey)){
        ICollectible * nuevoApartamento = (ICollectible *) apartamento;
        this->apartamentos->add(nuevaKey, nuevoApartamento);
        this->cantApartamentos++;
        cout << "El apartamento fue agregado exitosamente!" << endl;
    } else {
        delete nuevaKey;
        throw invalid_argument("El apartamento ya fue agregada con anterioridad");
    }
    // ES CON ICOLLECTION
}

void Edificio::desvincularPropiedad(int codigo){

    IKey * clave = new Integer (codigo);
    if (this->apartamentos->member(clave)){
        this->apartamentos->remove(clave);
        delete clave;
        cout << "El apartamento fue removido de manera exitosa!" << endl;
    } else {
        delete clave;
        throw invalid_argument("El apartamento especificado no se encuentra en el edificio actual");
    }
    // ES CON ICOLLECTION
}

// Métodos de Edificio (DCD)

DTEdificio * Edificio::getDTEdifico(){
    return new DTEdificio(this->getNombre(), this->getCantPisos(), this->getGastosComunes());
}

Apartamento * Edificio::crearApartamento(int cantAmbientes, int cantDormitorios, int cantBanios, float m2Edificados, DTDir * dir, bool tieneGaraje){
    int codigo = this->zona->generarCodigoPropiedad();
    return new Apartamento(codigo, cantAmbientes, cantDormitorios, cantBanios, m2Edificados, dir, tieneGaraje, this->zona, this);
}
