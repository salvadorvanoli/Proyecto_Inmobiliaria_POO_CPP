#ifndef INMOBILIARIA_H
#define INMOBILIARIA_H

#include <iostream>
using namespace std;

// #include "/ICollection/interfaces/ICollectible.h"
// #include "/ICollection/interfaces/ICollection.h"
// #include "/ICollection/interfaces/OrderedKey.h"
// #include "/ICollection/interfaces/IKey.h"
// #include "/ICollection/interfaces/IDictionary.h"
// #include "/ICollection/interfaces/IIterator.h"
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
        ICollection ventas;
        ICollection alquileres;
        ICollection propiedades;
    public:
        Inmobiliaria(char*, string, string, string, int);
        ~Inmobiliaria();
        void setNombre(string);
        void setDireccion(DTDir);
        string getNombre();
        DTDir getDireccion();
        Venta ponerEnVenta(int);
        int ponerEnAlquiler(int);
};

#endif