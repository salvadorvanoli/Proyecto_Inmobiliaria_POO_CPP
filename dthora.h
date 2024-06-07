#ifndef DTHORA_H
#define DTHORA_H

using namespace std;

class DTHora{
    private:
        int hora;
        int minuto;
        int segundo;
    public:
        DTHora(int, int, int);
        ~DTHora();
        int getHora();
        int getMinuto();
        int getSegundo();
};

#endif