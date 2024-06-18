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
        ICollection * listarZonasDepartamento();
        bool elegirZona(int);
        void altaInmobiliaria(char*, char*, DTDir*);
        void altaInteresado(char*, string, string, int);
        bool altaEdificio(string, int, int);
        ICollection* obtenerReporte();
        void altaPropiedad();
        // DTTipoProp modificarPropiedad(int, Inmobiliaria *);
        DTTipoProp modificarPropiedad(int);
        // void mensajeInmobiliaria(string, DTFecha *);
        void eliminarPropiedad(int);
        ICollection * listarPropiedades();
        DTPropiedadDetallada * verDetallesPropiedad(int);
        ICollection * listarChatProp();
        ICollection * listarChatsInmo();
        Conversacion * seleccionarConversacionInmo(int);
        // ICollection * seleccionarPropiedadMensajes(int, Zona *);
        Propiedad * seleccionarPropiedad(int);
        Conversacion * getConversacionInteresado();
        ICollection * getUltimosMensajes();
        Propiedad * seleccionarPropiedadInmobiliaria(int);
        DTTipoProp getDTTipoPropInmo(int);
        void modificarCasa(int, int, int, bool, DTDir *, float, float);
        void modificarApartamento(int, int, int, bool, DTDir *, float);
        Conversacion * nuevoChat();
        void nuevoMensaje(string, DTFecha *);
        int ponerEnVenta(float valor);
        int ponerEnAlquiler(float valor);
        // void especificacionesApartamento(int cantAmb, int cantBanos, int cantDorm, int m2e, bool garage, DTDir* dir, Propiedad* propiedad, Edificio* edificio, Zona*zona);
        // void especificacionesCasa(int cantAmb, int cantBanos, int cantDorm, bool garage, DTDir* dir, int m2e, int m2v,Propiedad* propiedad, Zona* zona);
        void especificacionesApartamento(int, int, int, bool, float, DTDir*, Edificio*, Zona*);
        void especificacionesCasa(int, int, int, bool, DTDir*, float, Zona*, float);
        ICollection* listarEdificio();
        bool seleccionarEdificio(int);
        void AltaPropiedad();

        // Operaciones del sistema (fuera de los diagramas de comunicacion)
        void enlazarPropiedad(Propiedad *);
        void desvincularPropiedad(int);
        Usuario * getLoggeado();
        IDictionary * getUsuarios();

        void setDepartamentoActual(Departamento*);
        void setZonaActual(Zona*);
        void setEdificioActual(Edificio*);
        void setPropiedadActual(Propiedad*);
        void setConversacionActual(Conversacion*);

        Departamento* getDepartamentoActual();
        Zona* getZonaActual();
        Edificio* getEdificioActual();
        Propiedad* getPropiedadActual();
        Conversacion* getConversacionActual();
};

#endif