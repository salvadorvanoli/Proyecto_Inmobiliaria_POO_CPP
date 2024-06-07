#ifndef PROPIEDAD_H
#define PROPIEDAD_H
#include <iostream>
#include "dtmensaje.h"
#include "alquiler.h"
#include "venta.h"
#include "conversacion.h"
#include "propiedad.cpp"
using namespace std;

class Propiedad : public ICollection{
    private:
        int codigo;
        int cantAmbiente;
        int cantDormitorios;
        int cantBanios;
        int m2Edificios;
        int m2Totales;
        bool tieneGaraje;
        conversacion * conver;
    public:
        propiedad(int, int, int, int, int, int, bool);
        ~propiedad();
        void setM2Totales(int);
        void setM2Edificios(int);
        void setTieneGaraje(bool);
        void setCantBanios(int);
        void setCantDormitorios(int);
        void setCantAmbiente(int);
        void setCodigo(int);
        void setConver(conversacion *);
        bool getTieneGaraje();
        int getm2Totales();
        int getCodigo();
        int getCantAmbiente();
        int getCantDormitorios();
        int getCantBanios();
        int getM2Edificios();
        conversacion * getConver();
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