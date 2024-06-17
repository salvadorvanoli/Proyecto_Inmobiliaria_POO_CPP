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
#include "../hfiles/inmobiliaria.h"
#include "../hfiles/usuario.h"
#include "../hfiles/administrador.h"
#include "../hfiles/interesado.h"
#include "../hfiles/dtpropiedaddetallada.h"

class Sistema{
    private:
        IDictionary * usuarios;
        IDictionary * departamentos;
        IDictionary * propiedades;
        Usuario * loggeado;
        string tipoUsr;
        
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
        void mensajeInteresado(Departamento *, Interesado *, DTFecha *);
        DTTipoProp modificarPropiedad(int, Inmobiliaria *);
        void mensajeInmobiliaria(string, DTFecha *, Inmobiliaria *, Conversacion *);
        void eliminarPropiedad(int);
        ICollection * listarPropiedades(Zona *);
        DTPropiedadDetallada * verDetallesPropiedad(Zona *, int);
        ICollection * listarChatProp(Zona *, char *);
        ICollection * seleccionarPropiedad(int, Zona *);
        void nuevoChat(Propiedad *);
        void nuevoMensaje(Conversacion *, string, DTFecha *);
};

#endif