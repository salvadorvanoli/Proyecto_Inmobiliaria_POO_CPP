#ifndef ISISTEMA_H
#define ISISTEMA_H

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

class ICollection;
class DTPropiedadDetallada;
class IDictionary;
class Conversacion;
class Propiedad;
class Usuario;
class Zona;
class Departamento;
class Edificio;
class DTDir;
class DTFecha;

class ISistema{
    public:
        ISistema();
        virtual ~ISistema();

        virtual void iniciarSesion(char*) = 0;
        virtual bool crearContrasenia(string, string) = 0;
        virtual bool ingresarContrasenia(string) = 0;
        virtual void cerrarSesion() = 0;
        virtual ICollection * listarDepartamentos() = 0;
        virtual bool elegirDepartamento(char *) = 0;
        virtual ICollection * listarZonasDepartamento() = 0;
        virtual bool elegirZona(int) = 0;
        virtual void altaInmobiliaria(string, char*, DTDir*) = 0;
        virtual void altaInteresado(char*, string, string, int) = 0;
        virtual bool altaEdificio(string, int, int) = 0;
        virtual ICollection* obtenerReporte() = 0;
        virtual void altaPropiedad() = 0;
        virtual DTTipoProp modificarPropiedad(int) = 0;
        virtual void eliminarPropiedad(int) = 0;
        virtual ICollection * listarPropiedades() = 0;
        virtual ICollection * listarPropiedadesInmo() = 0;
        virtual DTPropiedadDetallada * verDetallesPropiedad(int) = 0;
        virtual IDictionary * listarChatProp();
        virtual ICollection * listarChatsInmo();
        virtual Conversacion * seleccionarConversacionInmo(int) = 0;
        virtual Propiedad * seleccionarPropiedad(int) = 0;
        virtual Conversacion * getConversacionInteresado() = 0;
        virtual ICollection * getUltimosMensajes() = 0;
        virtual Propiedad * seleccionarPropiedadInmobiliaria(int) = 0;
        virtual DTTipoProp getDTTipoProp() = 0;
        virtual void modificarCasa(int, int, int, bool, DTDir *, float, float) = 0;
        virtual void modificarApartamento(int, int, int, bool, DTDir *, float) = 0;
        virtual Conversacion * nuevoChat() = 0;
        virtual void nuevoMensaje(string, DTFecha *) = 0;
        virtual int ponerEnVenta(float valor) = 0;
        virtual int ponerEnAlquiler(float valor) = 0;
        virtual void especificacionesApartamento(int, int, int, bool, float, DTDir*, Edificio*, Zona*) = 0;
        virtual void especificacionesCasa(int, int, int, bool, DTDir*, float, Zona*, float) = 0;
        virtual ICollection* listarEdificio() = 0;
        virtual bool seleccionarEdificio(int) = 0;
        virtual void AltaPropiedad() = 0;

        // Operaciones del sistema (fuera de los diagramas de comunicacion)
        virtual void enlazarPropiedad(Propiedad *) = 0;
        virtual void desvincularPropiedad(int) = 0;
        virtual Usuario * getLoggeado() = 0;
        virtual IDictionary * getUsuarios() = 0;

        virtual void setDepartamentoActual(Departamento*) = 0;
        virtual void setZonaActual(Zona*) = 0;
        virtual void setEdificioActual(Edificio*) = 0;
        virtual void setPropiedadActual(Propiedad*) = 0;
        virtual void setConversacionActual(Conversacion*) = 0;

        virtual Departamento* getDepartamentoActual() = 0;
        virtual Zona* getZonaActual() = 0;
        virtual Edificio* getEdificioActual() = 0;
        virtual Propiedad* getPropiedadActual() = 0;
        virtual Conversacion* getConversacionActual() = 0;
        virtual IDictionary* getDepartamentos() = 0;
};

#endif