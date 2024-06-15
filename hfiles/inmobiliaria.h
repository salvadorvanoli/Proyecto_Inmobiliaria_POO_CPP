#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

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
#include "usuario.h"
#include "dtdir.h"
#include "venta.h"
#include "alquiler.h"
#include "propiedad.h"

class DTDir;
class ICollectible;
class ICollection;
class IKey;
class IDictionary;
class IIterator;
class OrderedKey;
class Venta;
class Alquiler;
class Propiedad;

class Inmobiliaria : public Usuario {
    private:
        string nombre;
        DTDir direccion;
        IDictionary * ventas;
        IDictionary * alquileres;
        IDictionary * propiedades;
        int cantVentas;
        int cantAlquileres;
        int cantPropiedades;
    public:
        Inmobiliaria(char*, string, DTDir);
        ~Inmobiliaria();

        //Setters
        void setNombre(string);
        void setDireccion(DTDir);
        Venta* ponerEnVenta(Propiedad*, int);
        Alquiler* ponerEnAlquiler(Propiedad*, int);
        void agregarPropiedad(Propiedad*);

        //Getters
        string getNombre();
        DTDir getDireccion();
        IDictionary* getVentas();
        IDictionary* getAlquileres();
        IDictionary* getPropiedades();

        //Métodos
        void destruirVenta(Propiedad*);
        void destruirAlquiler(Propiedad*);
};

#endif