#include "../hfiles/inmobiliaria.h"
#include "../hfiles/venta.h"
#include "../hfiles/alquiler.h"
#include "../hfiles/propiedad.h"
#include "../hfiles/apartamento.h"
#include "../hfiles/casa.h"
#include "../hfiles/edificio.h"
#include <iostream>
using namespace std;

Inmobiliaria::Inmobiliaria(char* email, string nombre, DTDir* direccion) : Usuario(email){
    this->contrasenia = "";
    this->nombre = nombre;
    this->direccion = direccion;
    this->primeraVez = true;
    this->ventas = new OrderedDictionary();
    this->alquileres = new OrderedDictionary();
    this->propiedades = new OrderedDictionary();
    this->cantAlquileres = this->cantVentas = this->cantPropiedades = 0;
    this->cantConversaciones = 0;
}

Inmobiliaria::~Inmobiliaria(){
    this->alquileres->~IDictionary();
    this->ventas->~IDictionary();
    this->propiedades->~IDictionary(); // Ni idea si esto es así

    // HAY QUE HACER FUNCIONES PARA DESTRUIR CADA UNA DE LAS COLECCIONES

}

string Inmobiliaria::getNombre(){
    return this->nombre;
}

DTDir * Inmobiliaria::getDireccion(){
    return this->direccion;
}

IDictionary* Inmobiliaria::getVentas(){
    return this->ventas;
}

IDictionary* Inmobiliaria::getAlquileres(){
    return this->alquileres;
}

IDictionary* Inmobiliaria::getPropiedades(){
    return this->propiedades;    
}

void Inmobiliaria::setNombre(char* nombre){
    this->nombre = nombre;
}

void Inmobiliaria::setDireccion(DTDir * direccion){
    this->direccion = direccion;
}

Venta* Inmobiliaria::ponerEnVenta(Propiedad * prop, float precio){
    Venta * nuevaVenta = new Venta(prop, precio);
    IKey * nuevaKey = new Integer (prop->getCodigo());
    if(this->ventas->member(nuevaKey) == true){
        throw invalid_argument("La venta ya estaba registrada");
        return NULL;
    }
    ICollectible * ventaCasteada = (ICollectible*) nuevaVenta;
    this->ventas->add(nuevaKey, ventaCasteada);
    this->cantVentas++;
    prop->setEstadoProp(DTEstadoProp::venta);
    return nuevaVenta;
}

Alquiler* Inmobiliaria::ponerEnAlquiler(Propiedad * prop, float precio){
    Alquiler * nuevoAlquiler = new Alquiler(prop, precio);
    IKey * nuevaKey = new Integer (prop->getCodigo());
    if(this->alquileres->member(nuevaKey)){
        throw invalid_argument("El alquiler ya estaba registrado");
        return NULL;
    }
    ICollectible * alquilerCasteado = (ICollectible*) nuevoAlquiler;
    this->alquileres->add(nuevaKey, alquilerCasteado);
    this->cantAlquileres++;
    prop->setEstadoProp(DTEstadoProp::alquiler);
    return nuevoAlquiler;
}

void Inmobiliaria::agregarPropiedad(Propiedad * prop){
    IKey * nuevaKey = new Integer (prop->getCodigo());
    if(this->propiedades->member(nuevaKey)){
        throw invalid_argument("La propiedad ya estaba registrada");
        return;
    }
    ICollectible * propCasteada = (ICollectible*) prop;
    this->propiedades->add(nuevaKey, propCasteada);
    this->cantPropiedades++;
}

DTInmobiliaria * Inmobiliaria::getDTInmobiliaria(){
    return new DTInmobiliaria(this->nombre, this->direccion);
}

void Inmobiliaria::destruirAlquiler(Propiedad * prop){
    IKey * key = new Integer (prop->getCodigo());
    if (this->alquileres->member(key)){
        Alquiler * alquiler = (Alquiler*) this->alquileres->find(key);
        this->alquileres->remove(key);
        delete alquiler;
        this->cantAlquileres--;
        delete key;
    } else {
        delete key;
    }
}

void Inmobiliaria::destruirVenta(Propiedad * prop){
    IKey * key = new Integer (prop->getCodigo());
    if (this->ventas->member(key)){
        Venta * venta = (Venta*) this->ventas->find(key);
        this->ventas->remove(key);
        delete venta;
        this->cantVentas--;
        delete key;
    } else {
        delete key;
    }
}

int Inmobiliaria::getCantAlquileres(){
    return this->cantAlquileres;
}

int Inmobiliaria::getCantVentas(){
    return this->cantVentas;
}

int Inmobiliaria::getCantPropiedades(){
    return this->cantPropiedades;
}

DTReporte* Inmobiliaria::obtenerReporteInmobiliaria(){
    IIterator * it = this->propiedades->getIterator();
    Venta * venta;
    char* departamentos[99];
    int zonas[99] = {0};
    int apartamentos[99] = {0};
    int casas[99] = {0};
    while(it->hasCurrent()){
        Propiedad* prop = (Propiedad *) it->getCurrent();
        Zona* zona = prop->getZona();
        for(int i=0; i<99; i++){
            if(zona->getCodigo() == zonas[i]){
                Apartamento * ap = dynamic_cast<Apartamento*>(prop);
                Casa * ca = dynamic_cast<Casa*>(prop);
                if(ap != NULL){
                    apartamentos[i]++;
                }
                if(ca != NULL){
                    casas[i]++;
                }
                break;
            } else if(zonas[i] == 0){
                zonas[i] = zona->getCodigo();
                departamentos[i] = zona->getLetraDepa();
                Apartamento * ap = dynamic_cast<Apartamento*>(prop);
                Casa * ca = dynamic_cast<Casa*>(prop);
                if(ap != NULL){
                    apartamentos[i]++;
                }
                if(ca != NULL){
                    casas[i]++;
                }
                break;
            }
        }
        it->next();
    }
    delete it;

    ICollection * lineas = new List();
    for(int i=0; i<99; i++){
        if(zonas[i] != 0){
            DTLineaReporte * linea = new DTLineaReporte(zonas[i], departamentos[i], apartamentos[i], casas[i]);
            ICollectible * item = (ICollectible *) linea;
            lineas->add(item);
        } else {
            break;
        }
    }
    string nombre = this->getNombre();
    DTInmobiliaria * inmo = new DTInmobiliaria(nombre, this->direccion);
    DTReporte * reporte = new DTReporte(inmo, lineas);
    return reporte;
}

Propiedad * Inmobiliaria::seleccionarPropiedad(int codigoProp){
    IKey * key = new Integer(codigoProp);
    Propiedad * prop = (Propiedad *) this->propiedades->find(key);
    delete key;
    if (prop != NULL){
        return prop;
    } else {
        throw invalid_argument("La propiedad especificada no se encuentra en la inmobiliaria actual");
    }
}

// Devuelve un ICollection que contiene un DTChatProp por cada conversación de cada propiedad relacionada
IDictionary * Inmobiliaria::listarConversaciones(){
    IDictionary * lista = new OrderedDictionary();
    IIterator * it = this->propiedades->getIterator();
    OrderedKey * key = NULL;
    Propiedad * prop = NULL;
    DTChatProp * dtchat = NULL;
    IDictionary * col = NULL;
    ICollectible * item = NULL;
    while (it->hasCurrent()){
        prop = (Propiedad *) it->getCurrent();
        col = prop->listarConversaciones();
        IIterator * aux = col->getIterator();
        while (aux->hasCurrent()){
            item = aux->getCurrent();
            dtchat = (DTChatProp *) item;
            key = new Integer(dtchat->getValorKey());
            lista->add(key, item);
            aux->next();
        }
        delete aux;
        it->next();
    }
    delete it;
    return lista;
}

Conversacion * Inmobiliaria::seleccionarConversacion(int codigoCon){
    IIterator * it = this->propiedades->getIterator();
    IKey * clave = new Integer(codigoCon);
    Propiedad * prop = NULL;
    Conversacion * con = NULL;
    while (it->hasCurrent()){
        prop = (Propiedad *) it->getCurrent();
        IDictionary * aux = prop->getConversaciones();
        con = (Conversacion *) aux->find(clave);
        if (con != NULL){
            delete it;
            delete clave;
            return con;
        }
        it->next();
    }
    delete it;
    delete clave;
    throw invalid_argument("No existe una conversación con ese código vinculada a la Inmobiliaria actual");
}

int Inmobiliaria::generarCodigoConversacion(){
    this->cantConversaciones++;
    return this->cantConversaciones;
}

ICollection * Inmobiliaria::listarPropiedades(){
    ICollection * lista = new List();
    IIterator * it = this->propiedades->getIterator();
    Propiedad * prop;
    ICollectible * item;
    while (it->hasCurrent()){
        prop = (Propiedad *) it->getCurrent();
        item = (ICollectible *) prop->getDTPropiedad();
        lista->add(item);
        it->next();
    }
    delete it;
    return lista;
}