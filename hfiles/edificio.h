#ifndef EDIFICIO_H
#define EDIFICIO_H

#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/Integer.h"
#include "apartamento.h"
#include "dtedificio.h"
#include "zona.h"

class ICollectible;
class Apartamento;

class Edificio: public ICollectible {
    private:
        int codigo;
        string nombre;
        int cantPisos;
        int gastosComunes;
        IDictionary * apartamentos;
        Zona * zona;
        int cantApartamentos;
    public:
        Edificio(int, string, int, int, Zona*);
        ~Edificio();

        // Getters

        int getCodigo();
        string getNombre();
        int getCantPisos();
        int getGastosComunes();
        int getCantApartamentos();
        IDictionary * getApartamentos();
        Zona * getZona();

        // Setters

        void setCodigo(int);
        void setNombre(string);
        void setCantPisos(int);
        void setGastosComunes(int);
        void setCantApartamentos(int);
        void setZona(Zona *);

        // Agregar-Quitar (Creo que esta mal)

        void agregarApartamento(Apartamento *);
        void quitarApartamento(int);

        // Métodos de Edificio (DCD)

        DTEdificio * getDTEdifico();
        Apartamento * crearApartamento(int, int, int, int, DTDir *, bool);
        void desvincularPropiedad(Apartamento *);
};

#endif