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
// #include "venta.h"
// #include "alquiler.h"
// #include "propiedad.h"
#include "dtlineareporte.h"
#include "dtreporte.h"
// los incluyo el vale
// #include "apartamento.h"
// #include "edificio.h"
#include "mensaje.h"
#include "conversacion.h"

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
class Apartamento;
class Edificio;
class Venta;
class Alquiler;
class Propiedad;

class Inmobiliaria : public Usuario {
    private:
        char* nombre;
        DTDir * direccion;
        IDictionary * ventas;
        IDictionary * alquileres;
        IDictionary * propiedades;
        int cantVentas;
        int cantAlquileres;
        int cantPropiedades;
        int cantConversaciones;
    public:
        Inmobiliaria(char*, char*, DTDir*);
        ~Inmobiliaria();

        //Setters
        void setNombre(char*);
        void setDireccion(DTDir*);
        Venta* ponerEnVenta(Propiedad*, float);
        Alquiler* ponerEnAlquiler(Propiedad*, float);
        void agregarPropiedad(Propiedad*);

        //Getters
        string getNombre();
        DTDir * getDireccion();
        IDictionary* getVentas();
        IDictionary* getAlquileres();
        IDictionary* getPropiedades();
        int getCantVentas();
        int getCantAlquileres();
        int getCantPropiedades();

        //Métodos
        DTInmobiliaria * getDTInmobiliaria();
        void destruirVenta(Propiedad*);
        void destruirAlquiler(Propiedad*);
        DTReporte* obtenerReporteInmobiliaria();
        Propiedad * seleccionarPropiedad(int);
        ICollection * listarConversaciones();
        Conversacion * seleccionarConversacion(int);

        // Funciones aparte

        int generarCodigoConversacion();
};

#endif