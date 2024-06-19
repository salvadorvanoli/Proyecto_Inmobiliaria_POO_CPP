#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include <iostream>
using namespace std;

#include "dtmensaje.h"
#include "conversacion.h"
#include "zona.h"
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
#include "inmobiliaria.h"

class DTMensaje;
class Conversacion;
class Propiedad;
class Zona;
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
        Zona * zona;
        DTEstadoProp estado;
        Inmobiliaria * inmo;
    public:
        Propiedad(int, int, int, int, float, DTDir*, bool, Zona *);
        Propiedad(){};
        virtual ~Propiedad();

        // Setters

        void setZona(Zona *);
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
        void setInmobiliaria(Inmobiliaria *);

        // Getters

        bool getTieneGaraje();
        float getm2Totales();
        int getCodigo();
        int getCantAmbiente();
        int getCantDormitorios();
        int getCantBanios();
        float getM2Edificios();
        DTDir * getDireccion();
        Zona * getZona();
        DTEstadoProp getEstadoProp();
        Inmobiliaria * getInmobiliaria();

        DTInmobiliaria * getDTInmobiliaria();
        DTPropiedad * getDTPropiedad();
        DTPropiedadDetallada * getDTPropiedadDetallada();
        virtual DTTipoProp getDTTipoProp() = 0;
        IDictionary * getConversaciones();
        void desvincularDeZona();
        void destruirConversaciones();
        DTChatProp * getDTChatProp(char *);
        
        // ICollection * getUltimosMensajes(Conversacion *);

        Conversacion * getConversacion(char *);
        ICollection * getUltimosMensajes(char *);
        Conversacion * nuevoChat(Interesado *);
        IDictionary * listarConversaciones();
};

#endif