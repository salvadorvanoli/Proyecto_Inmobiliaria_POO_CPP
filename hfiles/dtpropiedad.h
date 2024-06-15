#ifndef DTPROPIEDAD_H
#define DTPROPIEDAD_H

#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"
#include "dtdir.h"
#include "dtestadoprop.h"

class ICollectible;
class DTDir;
enum class DTEstadoProp;

class DTPropiedad: public ICollectible {
    private:
        int codigoProp;
        DTDir * direccion;
        DTEstadoProp * estado;
    public:
        DTPropiedad(int, DTDir *, DTEstadoProp *);
        ~DTPropiedad();
        
        // Getters

        int getCodigoProp();
        DTDir * getDireccion();
        DTEstadoProp * getEstado();
        
        friend ostream& operator << (ostream &, DTPropiedad *);
};





#endif