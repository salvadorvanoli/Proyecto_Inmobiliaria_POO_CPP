
#include <iostream>
using namespace std;

#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/OrderedKey.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/IIterator.h"
#include "../ICollection/collections/List.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/interfaces/OrderedKey.h"
#include "../ICollection/Integer.h"
#include "../hfiles/sistema.h"
#include "../hfiles/departamento.h"
#include "../hfiles/inmobiliaria.h"
#include "../cppfiles/departamento.cpp"


ICollection * Sistema::listarDepartamentos(){
    ICollection * departamentos = new List();
    IIterator * it = this->departamentos->getIterator();
    Departamento * depa;
    ICollectible * item;
    while(it->hasCurrent()){
        depa = (Departamento *) depa->getDTDepartamento();
        departamentos->add(item);
        it->next();
    }
    delete it;
    return departamentos;
}

void Sistema::mensajeInteresado(){
    
}

DTTipoProp Sistema::modificarPropiedad(int codigoProp, Inmobiliaria * inmo){
//feli
IKey * key = new Integer(codigoProp);
Propiedad * p = (Propiedad *) inmo->getPropiedades()->find(key);
if(p->getDTTipoProp() == DTTipoProp::apartamento){
    return DTTipoProp::apartamento;
}
return DTTipoProp::casa;
}

//no anda ni a palo
void Sistema::mensajeInmobiliaria(char * contenido, DTFecha fecha, Inmobiliaria * inmo, Conversacion * c){
//feli
ICollection * axlrose = (Mensaje *) ;//falta la fecha
c->getUltimosMensajes()->add(axlrose);
}