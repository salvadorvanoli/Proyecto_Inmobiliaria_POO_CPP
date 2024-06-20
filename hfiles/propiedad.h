#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include <iostream>
using namespace std;

#include "dtmensaje.h"
#include "conversacion.h"
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/OrderedKey.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/Integer.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/IIterator.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "dttipoprop.h"
#include "dtchatprop.h"
#include "dtpropiedad.h"
#include "dtpropiedaddetallada.h"

class DTMensaje;
class Conversacion;
class Propiedad;
class ICollectible;


class Propiedad : public ICollectible{
    protected:
        int codigo;
        int cantAmbiente;
        int cantDormitorios;
        int cantBanios;
        float m2Edificios;
        float m2Totales;
        bool tieneGaraje;
        DTDir * direccion;
        IDictionary * conversaciones;
        int codigoZona;
        char * letraDep;
        DTEstadoProp estado;
        DTInmobiliaria * inmo;
        int cantConversacionesInmo;
    public:
        Propiedad(int, int, int, int, float, DTInmobiliaria*, DTDir*, bool, int, char*, int);
        Propiedad(){};
        virtual ~Propiedad();

        // Setters

        void setCodigoZona(int);
        void setLetraDep(char*);
        void setM2Totales(float);
        void setM2Edificios(float);
        void setTieneGaraje(bool);
        void setCantBanios(int);
        void setCantDormitorios(int);
        void setCantAmbiente(int);
        void setCodigo(int);
        void setDireccion(DTDir *);
        void agregarConversacion(Conversacion *);
        void setEstadoProp(DTEstadoProp);
        void setDTInmobiliaria(DTInmobiliaria *);

        // Getters

        bool getTieneGaraje();
        float getm2Totales();
        int getCodigo();
        int getCantAmbiente();
        int getCantDormitorios();
        int getCantBanios();
        float getM2Edificios();
        DTDir * getDireccion();
        int getCodigoZona();
        char * getLetraDep();
        DTEstadoProp getEstadoProp();
        int getCantConversacionesInmo();

        DTInmobiliaria * getDTInmobiliaria();
        DTPropiedad * getDTPropiedad();
        DTPropiedadDetallada * getDTPropiedadDetallada();
        virtual DTTipoProp getDTTipoProp() = 0;
        IDictionary * getConversaciones();
        void destruirConversaciones();
        ICollectible * getDTChatProp(char *);
        
        // ICollection * getUltimosMensajes(Conversacion *);

        Conversacion * getConversacion(char *);
        ICollection * getUltimosMensajes(char *);
        Conversacion * nuevoChat(Interesado *);
        IDictionary * listarConversaciones();
};

#endif