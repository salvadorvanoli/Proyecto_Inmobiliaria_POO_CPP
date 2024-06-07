#ifndef DEPARTAMENTO_H
#define DEPARTAMENTO_H
#include <iostream>
#include "ICollection/interfaces/ICollectible.h"
#include "edificio.h"
#include "propiedad.h"
#include "DTEdificio.h"
#include "DTDireccion.h"
#include "DTChatProp.h"
#include "DTMensaje.h"


using namespace std;

class Zona: public ICollectible {
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
        Edificio ** getEdificios();
        Propiedad ** getPropiedades();

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
        
        // Métodos de la Zona (DCD)

        DTEdificio ** listarEdificios();
        Edificio * seleccionarEdificio(int);
        void enlazarZona(Propiedad *);
        Casa * crearCasa(int, int, int, bool, DTDir, int, int);
        void desvincularZona(Propiedad *);
        DTChatProp * listarChatPropiedad(string);
        Propiedad * seleccionarPropiedad(int);
        DTMensaje ** getUltimosMensajes();
};

#endif