#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include <iostream>
using namespace std;

#include "/ICollection/interfaces/ICollectible.h"
#include "/ICollection/interfaces/ICollection.h"
#include "/ICollection/interfaces/OrderedKey.h"
#include "/ICollection/interfaces/IKey.h"
#include "/ICollection/interfaces/IDictionary.h"
#include "/ICollection/interfaces/IIterator.h"
#include "usuario.h"


class DTDir;
class ICollectible;
class ICollection;
class IKey;
class IDictionary;
class IIterator;
class OrderedKey;
class Usuario;

class Administrador : public Usuario {
    public:
        Administrador(char*, string);
};

#endif