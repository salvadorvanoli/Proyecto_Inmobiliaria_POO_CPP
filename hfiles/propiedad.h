#ifndef PROPIEDAD_H
#define PROPIEDAD_H

#include <iostream>
using namespace std;

#include "dtmensaje.h"
#include "alquiler.h"
#include "venta.h"
#include "conversacion.h"
#include "../cppfiles/propiedad.cpp"
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

class DTMensaje;
class Alquiler;
class Venta;
class Conversacion;
class Propiedad;
class Zona;
class ICollectible;


class Propiedad : public ICollectible{
    private:
        int codigo;
        int cantAmbiente;
        int cantDormitorios;
        int cantBanios;
        int m2Edificios;
        int m2Totales;
        bool tieneGaraje;
        IDictionary * conversaciones;
        Zona * zona;
    public:
        Propiedad(int, int, int, int, int, int, bool, Zona *);
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
        void agregarConversacion(Conversacion *);
        bool getTieneGaraje();
        int getm2Totales();
        int getCodigo();
        int getCantAmbiente();
        int getCantDormitorios();
        int getCantBanios();
        int getM2Edificios();
        IDictionary * getConversaciones();
        Zona * getZona();
        void desvincularDeZona();
        void destruirConversacion();
        DTChatProp * getDTChatProp(string);
        ICollection * getUltimosMensajes();
        Conversacion * nuevoChat();
};

#endif