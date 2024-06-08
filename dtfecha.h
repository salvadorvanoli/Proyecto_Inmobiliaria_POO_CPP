#ifndef DTFECHA_H
#define DTFECHA_H

#include <iostream>
#include "dthora.h"
using namespace std;


class DTFecha{
    private:
      string dia;
      string mes;
      string anio;
      DTHora hora;
    public:
        DTFecha();
        DTFecha(string, string, string, DTHora);
        ~DTFecha();
        string getDia();
        string getMes();
        string getAnio();
        DTHora getHora();
};

#endif