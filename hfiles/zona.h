#ifndef ZONA_H
#define ZONA_H

#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/Integer.h"
// #include "edificio.h"
// #include "propiedad.h"
// #include "casa.h"
#include "dtedificio.h"
#include "dtdir.h"
#include "dtchatprop.h"
#include "dtmensaje.h"
#include "dtzona.h"
#include "mensaje.h"
#include "dtpropiedaddetallada.h"

class Edificio;
class Propiedad;
class Casa;

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
        
        // Métodos de Zona (DCD)

        DTZona * getDTZona();
        ICollection * listarEdificios();
        Edificio * seleccionarEdificio(int);
        void enlazarPropiedad(Propiedad *);
        Casa * crearCasa(int, int, int, float, DTDir*, bool, float);
        void desvincularPropiedad(int);
        ICollection * listarChatPropiedad(char *);
        Propiedad * seleccionarPropiedad(int);
        ICollection * getUltimosMensajes();
        ICollection * listarPropiedades();
        DTPropiedadDetallada * verDetallesPropiedad(int);

        // Otras funciones
        int generarCodigoPropiedad();
        int generarCodigoEdificio();
};

#endif