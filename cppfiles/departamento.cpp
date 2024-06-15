#include "../hfiles/departamento.h"
#include "../hfiles/dtdepartamento.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/Integer.h"
#include <iostream>
using namespace std;

Departamento::Departamento(char * letra, string nombre){
    this->letra = letra;
    this->nombre = nombre;
    this->zonas = new OrderedDictionary();
    this->cantZonas = 0;
}

Departamento::~Departamento(){}

// Getters

char * Departamento::getLetra(){
    return this->letra;
}

string Departamento::getNombre(){
    return this->nombre;
}

int Departamento::getCantZonas(){
    return this->cantZonas;
}

IDictionary * Departamento::getZonas(){
    return this->zonas; // Capaz no es asi
}

// Setters

void Departamento::setLetra(char * letra){
    this->letra = letra;
}

void Departamento::setNombre(string nombre){
    this->nombre = nombre;
}

void Departamento::setCantZonas(int cantZonas){
    this->cantZonas = cantZonas;
}

// Agregar-Quitar

void Departamento::agregarZona(Zona * zona){

    IKey * nuevaKey = new Integer (zona->getCodigo());
    if (!this->zonas->member(nuevaKey)){
        ICollectible * nuevaZona = (ICollectible *) zona;
        this->zonas->add(nuevaKey, nuevaZona);
        this->cantZonas++;
        cout << "La zona fue agregada exitosamente!" << endl;
    } else {
        delete nuevaKey;
        throw invalid_argument("La zona ya fue agregada con anterioridad");
    }

    // ES CON ICOLLECTION
}

void Departamento::quitarZona(int codigoZona){
    IKey * clave = new Integer (codigoZona);
    if (this->zonas->member(clave)){
        this->zonas->remove(clave);
        delete clave;
        cout << "La zona fue removida de manera exitosa!" << endl;
    } else {
        delete clave;
        throw invalid_argument("La zona especificada no se encuentra en el departamento actual");
    }
    // ES CON ICOLLECTION
}

// Métodos de Departamento (DCD)

DTDepartamento * Departamento::getDTDepartamento(){
    return new DTDepartamento(this->letra, this->nombre);
}

ICollection * Departamento::listarZonasDepartamento(){
    ICollection * zonas = new List();
    IIterator * it = this->zonas->getIterator();
    Zona * zona;
    ICollectible * item;
    while (it->hasCurrent()){
        zona = (Zona *) it->getCurrent();
        item = (ICollectible *) zona->getDTZona();
        zonas->add(item);
        it->next();
    }
    delete it;
    return zonas;
    // ES CON ICOLLECTION
}

Zona * Departamento::elegirZona(int codigoZona){
    IKey * clave = new Integer (codigoZona);
    Zona * zona = (Zona *) this->zonas->find(clave);
    delete clave;
    if (zona != NULL){
        return zona;
    } else {
        throw invalid_argument("La zona especificada no se encuentra en el departamento actual");
    }
    // ES CON ICOLLECTION
}