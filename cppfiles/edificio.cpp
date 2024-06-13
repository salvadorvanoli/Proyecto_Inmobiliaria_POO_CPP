#include "../hfiles/edificio.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/Integer.h"
#include <iostream>
using namespace std;

Edificio::Edificio(int codigo, string nombre, int cantPisos, int gastosComunes){
    this->codigo = codigo;
    this->nombre = nombre;
    this->cantPisos = cantPisos;
    this->gastosComunes = gastosComunes;
    this->apartamentos = new OrderedDictionary();
    this->cantApartamentos = 0;
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

// Agregar-Quitar

void Edificio::agregarApartamento(Apartamento * apartamento){

    IKey * nuevaKey = new Integer (apartamento->getCodigo());
    if (!this->apartamentos->member(nuevaKey)){
        ICollectible * nuevoApartamento = (ICollectible *) apartamento;
        this->apartamentos->add(nuevaKey, nuevoApartamento);
        this->cantApartamentos++;
        cout << "El apartamento fue agregado exitosamente!" << endl;
    } else {
        delete nuevaKey;
        cout << "El apartamento ya fue agregada con anterioridad" << endl;
    }
    // ES CON ICOLLECTION
}

void Edificio::quitarApartamento(int codigoApartamento){

    IKey * clave = new Integer (codigoApartamento);
    if (this->apartamentos->member(clave)){
        this->apartamentos->remove(clave);
        delete clave;
        cout << "El apartamento fue removido de manera exitosa!" << endl;
    } else {
        delete clave;
        cout << "El apartamento especificado no se encuentra en el edificio actual" << endl;
    }
    // ES CON ICOLLECTION
}

// Métodos de Edificio (DCD)

Apartamento * Edificio::crearApartamento(int cantAmbientes, int cantBanios, int cantDormitorios, bool tieneGarage, DTDir * direccion, int m2Edificados){
    return new Apartamento(cantAmbientes, cantBanios, cantDormitorios, tieneGarage, direccion, m2Edificados);
}
