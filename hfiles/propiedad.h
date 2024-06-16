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
        int m2Edificios;
        int m2Totales;
        bool tieneGaraje;
        DTDir * direccion;
        IDictionary * conversaciones;
        Zona * zona;
    public:
        Propiedad(int, int, int, int, int, DTDir*, bool, Zona *);
        Propiedad(){};
        virtual ~Propiedad();
        void setZona(Zona *);
        void setM2Totales(int);
        void setM2Edificios(int);
        void setTieneGaraje(bool);
        void setCantBanios(int);
        void setCantDormitorios(int);
        void setCantAmbiente(int);
        void setCodigo(int);
        void setDireccion(DTDir *);
        void agregarConversacion(Conversacion *);
        bool getTieneGaraje();
        int getm2Totales();
        int getCodigo();
        int getCantAmbiente();
        int getCantDormitorios();
        int getCantBanios();
        int getM2Edificios();
        DTDir * getDireccion();
        DTTipoProp * getDTTipoProp(); // Capaz es virtual
        IDictionary * getConversaciones();
        Zona * getZona();
        void desvincularDeZona();
        void destruirConversaciones();
        DTChatProp * getDTChatProp(char *);
        ICollection * getUltimosMensajes(Conversacion *);
        Conversacion * nuevoChat();
        

        // Funciones aparte

        int crearClaveConversacion();
};

#endif