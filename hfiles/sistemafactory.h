#ifndef SISTEMAFACTORY_H
#define SISTEMAFACTORY_H

#include <iostream>
using namespace std;
#include "sistema.h"
#include "isistema.h"

class Factory{
    private:
        Sistema * sistema;
    public:
        Factory();
        ~Factory();

        ISistema * getISistema();
};

#endif