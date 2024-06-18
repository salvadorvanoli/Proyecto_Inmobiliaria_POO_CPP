#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/OrderedKey.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/IIterator.h"

class DTDir;
class ICollectible;
class ICollection;
class IKey;
class IDictionary;
class IIterator;
class OrderedKey;

class Usuario : public ICollectible {
    protected:
        char* correoElectronico;
        string contrasenia;
        bool primeraVez;
    public:
        Usuario(char*);
        virtual ~Usuario();

        // Métodos
        void agregarContrasenia(string);
        bool esContraseniaCorrecta(string);

        // Setters
        void setCorreoElectronico(char*);
        void setContrasenia(string);
        void setPrimeraVez(bool);

        // Getters
        char* getCorreoEletronico();
        string getContrasenia();
        bool getPrimeraVez();
};

#endif