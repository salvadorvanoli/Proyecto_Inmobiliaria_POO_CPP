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
        void altaInmobiliaria(char*, char*, DTDir*);
        void altaInteresado(char*, string, string, int);
        bool altaEdificio(string, int, int, Zona*);
        void obtenerReporte();
        void altaPropiedad();
        void mensajeInteresado();
        DTTipoProp modificarPropiedad(int, Inmobiliaria *);
        void mensajeInmobiliaria(char * contenido, DTFecha fecha, Inmobiliaria * inmo, Conversacion * c);
        void consultarPropiedad();
        void eliminarPropiedad();
};

#endif