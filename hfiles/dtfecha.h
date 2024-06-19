#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
using namespace std;

#include "dthora.h"

class DTHora;

class DTFecha{
    private:
      int dia;
      int mes;
      int anio;
      DTHora * hora;
    public:
      DTFecha();
      DTFecha(int, int, int, DTHora *);
      ~DTFecha();
      int getDia();
      int getMes();
      int getAnio();
      DTHora * getHora();
      friend ostream& operator << (ostream &, DTFecha *);
};

#endif