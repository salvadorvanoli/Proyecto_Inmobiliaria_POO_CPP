#include <iostream>
using namespace std;
#include "../ICollection/String.h"

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
#include "../hfiles/sistema.h"
#include "../hfiles/departamento.h"
#include "../cppfiles/departamento.cpp"
#include "../hfiles/zona.h"
#include "../hfiles/propiedad.h"
#include "../hfiles/venta.h"
#include "../hfiles/alquiler.h"
#include "../hfiles/edificio.h"

//ok
//ventas, alquileres
void Sistema::ponerEnVenta(float valor) {
    this->loggeado->ponerEnVenta(Propiedad* p, valor);
    this->loggeado->agregarPropiedad(Propiedad*);
}

void Sistema::ponerEnAlquiler(float valor) {
    this->loggeado->ponerEnAlquiler(Propiedad* p, valor);
    this->loggeado->agregarPropiedad(Propiedad*);
}
crearApartamento(int, int, int, bool, DTDir *, int);

void Sistema::especificacionesApartamento(int cantAmb, int cantBanos, int cantDorm, int m2e, bool garage, DTDir* dir, Propiedad* propiedad, Edificio* edificio, Zona*zona) {
    //de donde saco la clave
    edificio->(edificio->crearApartamento(cantAmb, cantBanos, cantDorm, garage, dir, m2e));
    edificio->agregarApartamento(propiedad);
    zona->agregarPropiedad(propiedad);
    //propiedad->vincularZona(zona) ??
}

void Sistema::especificacionesCasa(int cantAmb, int cantBanos, int cantDorm, bool garage, DTDir* dir, int m2e, int m2v, Zona* zona) {
    zona->agregarPropiedad(zona->crearCasa(cantAmb, cantBanos,cantDorm, garage,dir, m2e, m2v));
    //propiedad->vincularZona(zona) ??
}


ICollection* Sistema::listarEdificio(Zona * zona) {
    return zona->listarEdificios();
}

bool Sistema::seleccionarEdificio(int numEdificio, Zona* zona) {
    if (zona->seleccionarEdificio(numEdificio) != NULL) {
        return true;
    }
    else
        return false;
}















void Sistema:: AltaPropiedad() {
    ICollection* listaDeps = this->listarDepartamentos();
    char * letraDepa;
    cout << "Ingresar identificación del departamento:" << endl;
    cin >> letraDepa;

    if (elegirDepartamento(letraDepa)){
        ICollection * zona = listarZonasDepartamento(depa); //asumo que depa es una variable global
        int numZona;
        cout << "Ingresar identificación de la zona:" << endl;
        cin >> numZona;

        if(this->elegirZona(numZona, depa)){
            cout << "Ingrese tipo de propiedad" << endl;
            cout << "1. Casa" << endl;
            cout << "2. Apartamento" << endl;
            cin >> opcion;

            if (opcion == 2) {
                ICollection* listaEdificios = listarEdificio(zona);
                cout << "¿Desea seleccionar un nuevo edificio?" << endl;
                cout << "1. Si" << endl;
                cout << "2. No" << endl;
                int opcion;
                cin >> opcion;

                if (opcion == 1) {
                    //AltaEdificio(); no se como hacerlo
                }

                int numEdificio;
                cout << "Ingresar identificación del edificio:" << endl;
                cin >> numEdificio;

                if (elegirEdificio(numEdificio)) {
                    int cantAmb, cantBanos, cantDorm, m2t, numero;
                    string calle, ciudad;
                    bool garage = false;
                    int opcion;
                    cout << "Ingresar calle:" << endl;
                    string >> calle;
                    cout << "Ingresar numero:" << endl;
                    cin >> numero;
                    cout << "Ingresar ciudad:" << endl;
                    cin >> ciudad;
                    DTDir* dir = new DTDir(calle, numero, ciudad);
                    cout << "Ingresar cantidad de ambientes:" << endl;
                    cin >> cantAmb;
                    cout << "Ingresar cantidad de banos:" << endl;
                    cin >> cantBanos;
                    cout << "Ingresar cantidad de dormitorios:" << endl;
                    cin >> cantDorm;
                    cout << "Ingresar si tiene garage:" << endl;
                    cout << "1. Si" << endl;
                    cout << "2. No";
                    cin << opcion;
                    if (opcion == 1) 
                        garage = true;
                    cout << "Ingresar metros cuadrados edificados:" << endl;
                    cin >> m2t;
                    especificacionesApartamento(cantAmb, cantBanos, cantDorm, m2t, garage, dir);
                }
            }
            else if (opcion == 1) {
                int cantAmb, cantBanos, cantDorm, m2e, numero, m2v;
                string ciudad, calle;
                bool garage = false;
                int opcion;
                cout << "Ingresar calle:" << endl;
                cin >> calle;
                cout << "Ingresar numero:" << endl;
                cin >> numero;
                cout << "Ingresar ciudad:" << endl;
                string >> ciudad;
                DTDir* dir = new DTDir(calle, numero, ciudad);
                cout << "Ingresar cantidad de ambientes:" << endl;
                cin >> cantAmb;
                cout << "Ingresar cantidad de banos:" << endl;
                cin >> cantBanos;
                cout << "Ingresar cantidad de dormitorios:" << endl;
                cin >> cantDorm;
                cout << "Ingresar si tiene garage:" << endl;
                cout << "1. Si" << endl;
                cout << "2. No";
                cin >> opcion;
                if (opcion == 1) 
                    garage = true;
                cout << "Ingresar metros cuadrados edificados:" << endl;
                cin >> m2e;
                cout << "Ingresar metros cuadrados verdes:" << endl;
                cin >> m2v;
                especificacionesCasa(cantAmb, cantBanos, cantDorm, m2e, garage, dir, m2v);
            }
            cout << "1. Poner en venta" << endl;
            cout << "2. Poner en alquiler" << endl;
            int option;
            cin >> option;
            if (option == 1) {
                float valor;
                cout << "Ingrese valor" << endl;
                cin >> valor;
                //ponerEnVenta(valor);
            }
             if (option == 2) {
                float valor;
                cout << "Ingrese valor" << endl;
                cin >> valor;
                //ponerEnAlquiler(valor);
            }
        }

    }

}

