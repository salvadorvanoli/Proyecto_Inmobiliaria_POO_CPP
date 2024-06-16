#include "../hfiles/inmobiliaria.h"
#include <iostream>
using namespace std;

Inmobiliaria::Inmobiliaria(char* email, char* nombre, DTDir* direccion) : Usuario(email){
    this->contrasenia = "";
    this->nombre = nombre;
    this->direccion = direccion;
    this->primeraVez = true;
    this->ventas = new OrderedDictionary();
    this->alquileres = new OrderedDictionary();
    this->propiedades = new OrderedDictionary();
    this->cantAlquileres = this->cantVentas = this->cantPropiedades = 0;
}

Inmobiliaria::~Inmobiliaria(){
    this->alquileres->~IDictionary();
    this->ventas->~IDictionary();
    this->propiedades->~IDictionary(); // Ni idea si esto es así
}

string Inmobiliaria::getNombre(){
    return this->nombre;
}

DTDir* Inmobiliaria::getDireccion(){
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

void Inmobiliaria::setDireccion(DTDir *direccion){
    this->direccion = direccion;
}

Venta* Inmobiliaria::ponerEnVenta(Propiedad * prop, float precio){
    Venta * nuevaVenta = new Venta(prop, precio);
    IKey * nuevaKey = new Integer (prop->getCodigo());
    if(this->ventas->member(nuevaKey) == true){
        throw invalid_argument("La venta ya estaba registrada");
        return NULL;
    }
    this->ventas->add(nuevaKey, nuevaVenta);
    this->cantVentas++;
    return nuevaVenta;
}

Alquiler* Inmobiliaria::ponerEnAlquiler(Propiedad * prop, float precio){
    Alquiler * nuevoAlquiler = new Alquiler(prop, precio);
    IKey * nuevaKey = new Integer (prop->getCodigo());
    if(this->alquileres->member(nuevaKey)){
        throw invalid_argument("El alquiler ya estaba registrado");
        return NULL;
    }
    this->alquileres->add(nuevaKey, nuevoAlquiler);
    this->cantAlquileres++;
    return nuevoAlquiler;
}

void Inmobiliaria::agregarPropiedad(Propiedad * prop){
    IKey * nuevaKey = new Integer (prop->getCodigo());
    if(this->propiedades->member(nuevaKey)){
        throw invalid_argument("La propiedad ya estaba registrada");
        return;
    }
    this->propiedades->add(nuevaKey, prop);
    this->cantPropiedades++;
}

void Inmobiliaria::destruirAlquiler(Propiedad * prop){
    IKey * key = new Integer (prop->getCodigo());
    if (this->alquileres->member(key)){
        Alquiler * alquiler = (Alquiler*) this->alquileres->find(key);
        this->alquileres->remove(key);
        delete alquiler;
        this->cantAlquileres--;
        delete key;
        cout << "El alquiler fue destruido satisfactoriamente" << endl;
    } else {
        delete key;
        throw invalid_argument("El alquiler proporcionado no existe");
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
        cout << "La venta fue destruida satisfactoriamente" << endl;
    } else {
        delete key;
        throw invalid_argument("La venta proporcionada no existe");
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
    char* departamentos[99] = {"null"}; // No puedo obtener los departamentos desde la zona, entonces por ahora son null todos
    int zonas[99] = {0};
    int apartamentos[99] = {0};
    int casas[99] = {0};
    while(it->hasCurrent()){
        Propiedad* prop = (Propiedad *) it->getCurrent();
        Zona* zona = prop->getZona();
        for(int i=0; i<99; i++){
            if(zona->getCodigo() == zonas[i]){
                Apartamento * ap = (Apartamento*) prop;
                Casa * ca = (Casa*) prop;
                if(ap != NULL){
                    apartamentos[i]++;
                }
                if(ca != NULL){
                    casas[i]++;
                }
            } else if(zonas[i] == 0){
                zonas[i] = zona->getCodigo();
                Apartamento * ap = (Apartamento*) prop;
                Casa * ca = (Casa*) prop;
                if(ap != NULL){
                    apartamentos[i]++;
                }
                if(ca != NULL){
                    casas[i]++;
                }
            }
        }
        it->next();
    }
    delete it;

    ICollection * lineas = new List();
    for(int i=0; i<99; i++){
        if(zonas[i] != 0){
            DTLineaReporte * linea = new DTLineaReporte(zonas[i], departamentos[i], apartamentos[i], casas[i]);
            lineas->add(linea);
        } else {
            break;
        }
    }
    DTInmobiliaria * inmo = new DTInmobiliaria(this->nombre, this->direccion);
    DTReporte * reporte = new DTReporte(inmo, lineas);
    return reporte;
}