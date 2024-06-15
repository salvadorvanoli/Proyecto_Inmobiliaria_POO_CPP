#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
using namespace std;

#include "dthora.h"

class DTHora;

class DTFecha{
    private:
      string dia;
      string mes;
      string anio;
      DTHora * hora;
    public:
      DTFecha();
      DTFecha(string, string, string, DTHora *);
      ~DTFecha();
      string getDia();
      string getMes();
      string getAnio();
      DTHora * getHora();
      friend ostream& operator << (ostream &, DTFecha *);
};

#endif