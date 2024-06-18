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
#include "administrador.h"
#include "alquiler.h"
#include "apartamento.h"
#include "casa.h"
#include "conversacion.h"
#include "departamento.h"
#include "dtchatprop.h"
#include "dtdepartamento.h"
#include "dtdir.h"
#include "dtedificio.h"
#include "dtestadoprop.h"
#include "dtfecha.h"
#include "dthora.h"
#include "dtinmobiliaria.h"
#include "dtlineareporte.h"
#include "dtmensaje.h"
#include "dtpropiedad.h"
#include "dtpropiedaddetallada.h"
#include "dtreporte.h"
#include "dttipoprop.h"
#include "dtzona.h"
#include "edificio.h"
#include "inmobiliaria.h"
#include "interesado.h"
#include "mensaje.h"
#include "propiedad.h"
#include "usuario.h"
#include "venta.h"
#include "zona.h"

class Sistema{
    private:
        IDictionary * usuarios;
        IDictionary * departamentos;
        IDictionary * propiedades;
        Usuario * loggeado;
        Departamento * departamentoActual;
        Zona * zonaActual;
        Edificio * edificioActual;
        Propiedad * propiedadActual;
        Conversacion * conversacionActual;
        
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
        ICollection * listarChatProp(Zona *);
        // ICollection * seleccionarPropiedadMensajes(int, Zona *);
        Propiedad * seleccionarPropiedad(int, Zona *);
        Conversacion * getConversacion(Propiedad *);
        ICollection * getUltimosMensajes(Conversacion *);
        Propiedad * seleccionarPropiedadInmobiliaria(int);
        DTTipoProp getDTTipoPropInmo(int);
        void modificarCasa(Casa *, int, int, int, bool, DTDir *, float, float);
        void modificarApartamento(Apartamento *, int, int, int, bool, DTDir *, float);
        Conversacion * nuevoChat(Propiedad *);
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