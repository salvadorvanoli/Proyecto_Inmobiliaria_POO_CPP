#ifndef SISTEMA_H
#define SISTEMA_H

#include <iostream>
using namespace std;
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/OrderedKey.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/IIterator.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/interfaces/OrderedKey.h"
#include "../ICollection/Integer.h"



class Sistema{
    private:
        IDictionary * usuarios;
        IDictionary * departamentos;
        IDictionary * propiedades;
    public:
        void iniciarSesion();
        void cerrarSesion();
        void altaInmobiliaria();
        void altaInteresado();
        void altaEdificio();
        void obtenerReporte();
        void altaPropiedad();
        void mensajeInteresado();
        void modificarPropiedad();
        void mensajeInmobiliaria();
        void consultarPropiedad();
        void eliminarPropiedad();
        ICollection*  listarDepartamentos();

};


void Sistema::altaPropiedad(){
    this->listarDepartamentos();
    
    string letra;
    cout << "Ingrese la identificación del departamento:" << endl;
    cin >> letra;
    departamento* departamentoElegido = this->elegirDepartamento(letra);
    
    if (departamentoElegido == nullptr) {
        cout << "Departamento no encontrado." << endl;
        return;
    }

    departamentoElegido->listarZonas();
    
    int codigoZ;
    cout << "Ingrese la identificación de la zona:" << endl;
    cin >> codigoZ;
    zona* zonaElegida = departamentoElegido->elegirZona(codigoZ);
    
    if (zonaElegida == nullptr) {
        cout << "Zona no encontrada." << endl;
        return;
    }

    cout << "Elija el tipo de propiedad a ingresar:" << endl;
    cout << "1. Casa" << endl;
    cout << "2. Apartamento" << endl;
    
    int eleccion;
    cin >> eleccion; 
    
    if (eleccion == 2) {
        cout << "Presione 1 si desea agregar un edificio" << endl;
        cout << "Ingrese la identificación del edificio " << endl;
        
        int codigoE;
        cin >> codigoE;

        if (codigoE == 0) {
            edificioElegido = zonaElegida->AltaEdificio();
         else {
            edificioElegido = zonaElegida->elegirEdificio(codigoE);
        }


        
}


#endif