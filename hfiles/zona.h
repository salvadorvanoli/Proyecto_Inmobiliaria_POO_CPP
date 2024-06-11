#ifndef ZONA_H
#define ZONA_H

#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
#include "edificio.h"
#include "propiedad.h"
#include "casa.h"
#include "dtedificio.h"
#include "dtdir.h"
#include "dtchatProp.h"
#include "dtmensaje.h"

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
        ICollection * edificios;
        int cantEdificios;
        ICollection * propiedades;
        int cantPropiedades;
    public:
        Zona(int, string);
        ~Zona();

        // Getters

        int getCodigo();
        string getNombre();
        int getCantEdificios();
        int getCantPropiedades();
        ICollection * getEdificios();
        ICollection * getPropiedades();

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

        ICollection * listarEdificios();
        Edificio * seleccionarEdificio(int);
        void enlazarZona(Propiedad *);
        Casa * crearCasa(int, int, int, bool, DTDir *, int, int);
        void desvincularZona(Propiedad *);
        DTChatProp * listarChatPropiedad(char *);
        Propiedad * seleccionarPropiedad(int);
        ICollection * getUltimosMensajes();
};

#endif