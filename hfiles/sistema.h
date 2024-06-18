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
#include "../ICollection/String.h"
#include "../hfiles/administrador.h"
#include "../hfiles/alquiler.h"
#include "../hfiles/apartamento.h"
#include "../hfiles/casa.h"
#include "../hfiles/conversacion.h"
#include "../hfiles/departamento.h"
#include "../hfiles/dtchatprop.h"
#include "../hfiles/dtdepartamento.h"
#include "../hfiles/dtdir.h"
#include "../hfiles/dtedificio.h"
#include "../hfiles/dtestadoprop.h"
#include "../hfiles/dtfecha.h"
#include "../hfiles/dthora.h"
#include "../hfiles/dtinmobiliaria.h"
#include "../hfiles/dtlineareporte.h"
#include "../hfiles/dtmensaje.h"
#include "../hfiles/dtpropiedad.h"
#include "../hfiles/dtpropiedaddetallada.h"
#include "../hfiles/dtreporte.h"
#include "../hfiles/dttipoprop.h"
#include "../hfiles/dtzona.h"
#include "../hfiles/edificio.h"
#include "../hfiles/inmobiliaria.h"
#include "../hfiles/interesado.h"
#include "../hfiles/mensaje.h"
#include "../hfiles/propiedad.h"
#include "../hfiles/usuario.h"
#include "../hfiles/venta.h"
#include "../hfiles/zona.h"

class Sistema{
    private:
        IDictionary * usuarios;
        IDictionary * departamentos;
        IDictionary * propiedades;
        Usuario * loggeado;
        
    public:
        void iniciarSesion(char*);
        bool crearContrasenia(string, string);
        bool ingresarContrasenia(string);
        void cerrarSesion();
        ICollection * listarDepartamentos();
        bool elegirDepartamento(char *);
        ICollection * listarZonasDepartamento(Departamento *);
        bool elegirZona(Departamento *, int);
        void altaInmobiliaria(char*, char*, DTDir*);
        void altaInteresado(char*, string, string, int);
        bool altaEdificio(string, int, int, Zona*);
        void obtenerReporte();
        void altaPropiedad();
        // DTTipoProp modificarPropiedad(int, Inmobiliaria *);
        DTTipoProp modificarPropiedad(int);
        void mensajeInmobiliaria(string, DTFecha *, Inmobiliaria *, Conversacion *);
        void eliminarPropiedad(int);
        ICollection * listarPropiedades(Zona *);
        DTPropiedadDetallada * verDetallesPropiedad(Zona *, int);
        ICollection * listarChatProp(Zona *, char *);
        ICollection * seleccionarPropiedadMensajes(int, Zona *);
        Propiedad * seleccionarPropiedadInmobiliaria(int);
        DTTipoProp getDTTipoPropInmo(int);
        void modificarCasa(Casa *, int, int, int, bool, DTDir *, float, float);
        void modificarApartamento(Apartamento *, int, int, int, bool, DTDir *, float);
        void nuevoChat(Propiedad *);
        void nuevoMensaje(Conversacion *, string, DTFecha *);
        int ponerEnVenta(float valor, Propiedad* p);
        int ponerEnAlquiler(float valor, Propiedad* p);
        // void especificacionesApartamento(int cantAmb, int cantBanos, int cantDorm, int m2e, bool garage, DTDir* dir, Propiedad* propiedad, Edificio* edificio, Zona*zona);
        // void especificacionesCasa(int cantAmb, int cantBanos, int cantDorm, bool garage, DTDir* dir, int m2e, int m2v,Propiedad* propiedad, Zona* zona);
        void especificacionesApartamento(int, int, int, bool, float, DTDir*, Edificio*, Zona*);
        void especificacionesCasa(int, int, int, bool, DTDir*, float, Zona*, float);
        ICollection* listarEdificio(Zona * zona);
        bool seleccionarEdificio(int numEdificio, Zona* zona, Edificio* edificio);
        void AltaPropiedad();

        // Operaciones del sistema (fuera de los diagramas de comunicacion)
        void enlazarPropiedad(Propiedad *);
        void desvincularPropiedad(int);

};

#endif