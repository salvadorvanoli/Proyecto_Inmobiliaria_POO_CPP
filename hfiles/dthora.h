#ifndef DTHORA_H
#define DTHORA_H

#include <iostream>
using namespace std;

class DTHora{
    private:
        int hora;
        int minuto;
        int segundo;
    public:
        DTHora();
        DTHora(int, int, int);
        ~DTHora();
        int getHora();
        int getMinuto();
        int getSegundo();
        friend ostream& operator << (ostream &, DTHora *);
};

#endif