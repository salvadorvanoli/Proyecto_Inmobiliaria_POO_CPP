#ifndef PROPIEDAD_H
#define PROPIEDAD_H
#include <iostream>
#include "dtmensaje.h"
#include "alquiler.h"
#include "venta.h"
#include "conversacion.h"
#include "propiedad.cpp"
using namespace std;

class Propiedad /*: public ICollection*/{
    private:
        int codigo;
        int cantAmbiente;
        int cantDormitorios;
        int cantBanios;
        int m2Edificios;
        int m2Totales;
        bool tieneGaraje;
        Conversacion * conver;
    public:
        Propiedad(int, int, int, int, int, int, bool, Conversacion *);
        Propiedad(){};
        ~Propiedad();
        void setM2Totales(int);
        void setM2Edificios(int);
        void setTieneGaraje(bool);
        void setCantBanios(int);
        void setCantDormitorios(int);
        void setCantAmbiente(int);
        void setCodigo(int);
        void setConver(Conversacion *);
        bool getTieneGaraje();
        int getm2Totales();
        int getCodigo();
        int getCantAmbiente();
        int getCantDormitorios();
        int getCantBanios();
        int getM2Edificios();
        Conversacion * getConver();
        void asociarVenta(Venta);
        void asociarAlquier(Alquier);
        void desvincularZona();
        void destruirConversacion();
        void destruirVenta();
        void destruirAlquiler();
        DTChatProp getDTChatProp(string);
        DTMensaje getUltimosmensajes();
        Conversacion nuevoChat();
};

#endif