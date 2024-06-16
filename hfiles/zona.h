#ifndef ZONA_H
#define ZONA_H

#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "edificio.h"
#include "propiedad.h"
#include "casa.h"
#include "dtedificio.h"
#include "dtdir.h"
#include "dtchatprop.h"
#include "dtmensaje.h"
#include "dtzona.h"

class ICollectible;
class Edificio;
class Propiedad;
class DTEdificio;
class DTDir;
class DTChatProp;
class DTMensaje;

class Zona : public ICollectible {
    private:
        int codigo;
        string nombre;
        IDictionary * edificios;
        int cantEdificios;
        IDictionary * propiedades;
        int cantPropiedades;
    public:
        Zona(int, string);
        ~Zona();

        // Getters

        int getCodigo();
        string getNombre();
        int getCantEdificios();
        int getCantPropiedades();
        IDictionary * getEdificios();
        IDictionary * getPropiedades();

        // Setters

        void setCodigo(int);
        void setNombre(string);
        void setCantEdificios(int);
        void setCantPropiedades(int);

        // Agregar-Quitar (Creo que esta mal)

        void agregarEdificio(Edificio *);
        void quitarEdificio(int);
        void agregarPropiedad(Propiedad *);
        void quitarPropiedad(int);
        
        // Métodos de Zona (DCD)

        DTZona * getDTZona();
        ICollection * listarEdificios();
        Edificio * seleccionarEdificio(int);
        void enlazarPropiedad(Propiedad *);      // ES LO MISMO QUE AGREGAR PROPIEDAD
        Casa * crearCasa(int, int, int, int, DTDir*, bool, int);
        void desvincularPropiedad(Propiedad *);  // ES LO MISMO QUE QUITAR PROPIEDAD
        ICollection * listarChatPropiedad(char *);
        Propiedad * seleccionarPropiedad(int);
        ICollection * getUltimosMensajes();

        // Otras funciones
        int crearClavePropiedad();
};

#endif