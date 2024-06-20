
using namespace std;

//Librerias
#include <iostream>
#include <ctime>
#include <cmath>
#include <string>

//Collections
#include "../ICollection/collections/List.h"
#include "../ICollection/collections/ListIterator.h"
#include "../ICollection/collections/ListNode.h"
#include "../ICollection/collections/OrderedDictionary.h"
#include "../ICollection/collections/OrderedDictionaryEntry.h"

//Interfaces
#include "../ICollection/interfaces/ICollectible.h"
#include "../ICollection/interfaces/ICollection.h"
#include "../ICollection/interfaces/IDictionary.h"
#include "../ICollection/interfaces/IIterator.h"
#include "../ICollection/interfaces/IKey.h"
#include "../ICollection/interfaces/OrderedKey.h"

//Integer & String
#include "../ICollection/Integer.h"
#include "../ICollection/String.h"


//hora
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

DTHora::DTHora(int hora, int minuto, int segundo){
    this->hora = hora;
    this->minuto = minuto;
    this->segundo = segundo;
}

DTHora::~DTHora(){

}

int DTHora::getHora(){
    return this->hora;
}

int DTHora::getMinuto(){
    return this->minuto;
}

int DTHora::getSegundo(){
    return this->segundo;
}

ostream& operator << (ostream & o, DTHora * hora){
    o << "Hora: " << hora->getHora() << ':' << hora->getMinuto() << ':' << hora->getSegundo() << endl;
    return o;
}

//fecha
class DTFecha{
    private:
      int dia;
      int mes;
      int anio;
      DTHora * hora;
    public:
      DTFecha();
      DTFecha(int, int, int, DTHora *);
      ~DTFecha();
      int getDia();
      int getMes();
      int getAnio();
      DTHora * getHora();
      friend ostream& operator << (ostream &, DTFecha *);
};

DTFecha::DTFecha(int dia, int mes, int anio, DTHora * hora){
this->dia = dia;
this->mes = mes;
this->anio = anio;
this-> hora = hora;
}

DTFecha::~DTFecha(){

}

int DTFecha::getDia(){
    return this->dia;
}

int DTFecha::getMes(){
    return this->mes;
}

int DTFecha::getAnio(){
    return this->anio;
}

DTHora * DTFecha::getHora(){
    return this->hora;
}

ostream& operator << (ostream & o, DTFecha * fecha){
    o << "Fecha: " << fecha->getDia() << '/' << fecha->getMes() << '/' << fecha->getAnio() << endl << fecha->getHora();
    return o;
}

//dtmensaje

class DTMensaje: public ICollectible{
    private:
        string contenido;
        DTFecha * fecha; 
    public:
        DTMensaje(string, DTFecha *);
        ~DTMensaje();
        string getContenido();
        DTFecha * getFecha();
};

DTMensaje::DTMensaje(string contenido, DTFecha * fecha){
    this->contenido = contenido;
    this->fecha = fecha;
}

DTMensaje::~DTMensaje(){

}

string DTMensaje::getContenido(){
    return this->contenido;
}

DTFecha * DTMensaje::getFecha(){
    return this->fecha;
}

//dtdir
class DTDir{
    private:
        string calle;
        int numero;
        string ciudad;
    public:
        DTDir();
        DTDir(string, int, string);
        ~DTDir();
        string getCalle();
        int getNumero();
        string getCiudad();
        friend ostream& operator << (ostream &, DTDir *);
};

DTDir::DTDir(string calle, int numero, string ciudad){
    this->calle = calle;
    this->numero = numero;
    this->ciudad = ciudad;
}

DTDir::~DTDir(){

}

string DTDir::getCalle(){
    return this->calle;
}

int DTDir::getNumero(){
    return this->numero;
}

string DTDir::getCiudad(){
    return this->ciudad;
}

ostream& operator << (ostream & o, DTDir * dir){
    o << "    Ciudad: " << dir->getCiudad() << endl << "    Calle: " << dir->getCalle() << endl << "    Numero: " << dir->getNumero() << endl;
    return o;
}

//dtestadoprop
enum class DTEstadoProp {
    venta,
    alquiler,
    venta_y_alquiler
};

//dtpropiedad
class DTPropiedad: public ICollectible {
    private:
        int codigoProp;
        DTDir * direccion;
        DTEstadoProp estado;
    public:
        DTPropiedad(int, DTDir *, DTEstadoProp);
        ~DTPropiedad();
        
        // Getters

        int getCodigoProp();
        DTDir * getDireccion();
        DTEstadoProp getEstado();
        
        friend ostream& operator << (ostream &, DTPropiedad *);
};

DTPropiedad::DTPropiedad(int codigo, DTDir * direccion, DTEstadoProp estado){
    this->codigoProp = codigo;
    this->direccion = direccion;
    this->estado = estado;
}

DTPropiedad::~DTPropiedad(){}
        
// Getters

int DTPropiedad::getCodigoProp(){
    return this->codigoProp;
}

DTDir * DTPropiedad::getDireccion(){
    return this->direccion;
}

DTEstadoProp DTPropiedad::getEstado(){
    return this->estado;
}

ostream& operator << (ostream & o, DTPropiedad * prop){
    string estado;
    if (prop->getEstado() == DTEstadoProp::alquiler){
        estado = "En alquiler";
    } else if(prop->getEstado() == DTEstadoProp::venta) {
        estado = "En venta";
    } else {
        estado = "En alquiler y en venta";
    }
    o << "Codigo: " << prop->getCodigoProp() << endl << "Estado: " << estado << endl << "Direccion: " << prop->getDireccion() << endl;
    return o;
}
class DTInmobiliaria;
//dtpropiedaddetallada
class DTPropiedadDetallada: public DTPropiedad {
    private:
        int cantAmbientes;
        int cantDormitorios;
        int cantBanios;
        bool tieneGaraje;
        float m2Totales;
        DTInmobiliaria * inmo;
    public:
        DTPropiedadDetallada(int, DTDir *, DTEstadoProp, int, int, int, bool, float, DTInmobiliaria *);
        ~DTPropiedadDetallada();
        
        // Getters

        int getCantAmbientes();
        int getCantDormitorios();
        int getCantBanios();
        bool getTieneGaraje();
        float getM2Totales();
        DTInmobiliaria * getInmo();

        friend ostream& operator << (ostream &, DTPropiedadDetallada *);
};
DTPropiedadDetallada::DTPropiedadDetallada(int codigo, DTDir * direccion, DTEstadoProp estado, int cantAmbientes, int cantDormitorios, int cantBanios, bool tieneGaraje, float m2Totales, DTInmobiliaria * inmo): DTPropiedad(codigo, direccion, estado){
    this->cantAmbientes = cantAmbientes;
    this->cantDormitorios = cantDormitorios;
    this->cantBanios = cantBanios;
    this->tieneGaraje = tieneGaraje;
    this->m2Totales = m2Totales;
    this->inmo = inmo;
}

DTPropiedadDetallada::~DTPropiedadDetallada(){}

// Getters

int DTPropiedadDetallada::getCantAmbientes(){
    return this->cantAmbientes;
}

int DTPropiedadDetallada::getCantDormitorios(){
    return this->cantDormitorios;
}

int DTPropiedadDetallada::getCantBanios(){
    return this->cantBanios;
}

bool DTPropiedadDetallada::getTieneGaraje(){
    return this->tieneGaraje;
}

float DTPropiedadDetallada::getM2Totales(){
    return this->m2Totales;
}

DTInmobiliaria * DTPropiedadDetallada::getInmo(){
    return this->inmo;
}

ostream& operator << (ostream & o, DTPropiedadDetallada * prop){
    string garaje;
    if (prop->getTieneGaraje()){
        garaje = "Si";
    } else {
        garaje = "No";
    }
    string estado;
    if (prop->getEstado() == DTEstadoProp::alquiler){
        estado = "En alquiler";
    } else if(prop->getEstado() == DTEstadoProp::venta) {
        estado = "En venta";
    } else {
        estado = "En alquiler y en venta";
    }
    o << "Codigo: " << prop->getCodigoProp() << endl << "Estado: " << estado << endl << "Direccion: " << prop->getDireccion() << "Cantidad de ambientes: " << prop->getCantAmbientes() << endl << "Cantidad de dormitorios: " << prop->getCantDormitorios() << endl << "Cantidad de baños: " << prop->getCantBanios() << endl << "Tiene garaje: " << garaje << endl << "M2 Totales: " << prop->getM2Totales() << endl << "Inmobiliaria: " << endl << prop->getInmo();
    return o;
}
//dtchatprop
class DTChatProp: public ICollectible {
    private:
        int codigoProp;
        int codigoCon;
        int cantMensajes;
        DTFecha * fechaUltimoMensaje;
        DTDir* direccion;
        int valorKey;

    public:
        DTChatProp(int, int, int, DTFecha *, DTDir *);
        virtual ~DTChatProp();
        int getCodigoProp();
        int getCodigoCon();
        int getCantMensajes();
        DTDir* getDir();
        DTFecha * getFechaUltimoMensaje();
        int getValorKey();

        friend ostream& operator << (ostream &, DTChatProp *);
        int generarClaveSegunFecha(); // Esta es inchequeable (preguntale a chatGPT)

};
DTChatProp::DTChatProp(int codigo, int codigoCon, int cantMensajes, DTFecha * fechaUltimoMensaje, DTDir* direccion) {
    this->codigoProp = codigo;
    this->codigoCon = codigoCon;
    this->cantMensajes = cantMensajes;
    this->fechaUltimoMensaje = fechaUltimoMensaje;
    this->direccion = direccion;
    this->valorKey = this->generarClaveSegunFecha();
};

DTChatProp::~DTChatProp() {
}

int DTChatProp::getCantMensajes() {
    return cantMensajes;
};

int DTChatProp::getCodigoProp() {
    return codigoProp;
};

int DTChatProp::getCodigoCon() {
    return this->codigoCon;
}

DTDir* DTChatProp::getDir() {
    return direccion;
};

DTFecha* DTChatProp::getFechaUltimoMensaje(){
    return this->fechaUltimoMensaje;
}

int DTChatProp::getValorKey(){
    return this->valorKey;
}

ostream& operator << (ostream & o, DTChatProp * chat){
    o << "Codigo de la propiedad: " << chat->getCodigoProp() << endl << "Codigo de la conversacion: " << chat->getCodigoCon() << endl << "Cantidad de mensajes: " << chat->getCantMensajes() << "Fecha último mensaje: " << chat->getFechaUltimoMensaje() << endl << "Dirección de la propiedad:" << chat->getDir() << endl;
    return o;
}

// Es recontra chatGPT
int DTChatProp::generarClaveSegunFecha(){
    time_t t = time(nullptr);
    tm* ahora = localtime(&t);

    tm fechaHoraActual = *ahora;
    fechaHoraActual.tm_isdst = -1;

    tm fechaHoraComparar = {0};
    fechaHoraComparar.tm_mday = this->getFechaUltimoMensaje()->getDia();
    fechaHoraComparar.tm_mon = this->getFechaUltimoMensaje()->getMes() - 1;
    fechaHoraComparar.tm_year = this->getFechaUltimoMensaje()->getAnio() - 1900;
    fechaHoraComparar.tm_hour = this->getFechaUltimoMensaje()->getHora()->getHora();
    fechaHoraComparar.tm_min = this->getFechaUltimoMensaje()->getHora()->getMinuto();
    fechaHoraComparar.tm_sec = this->getFechaUltimoMensaje()->getHora()->getSegundo();
    fechaHoraComparar.tm_isdst = -1;

    time_t tiempoActual = mktime(&fechaHoraActual);
    time_t tiempoComparar = mktime(&fechaHoraComparar);

    double segundos = difftime(tiempoActual, tiempoComparar);
    return abs(segundos);
}
//dtdepartamento
class DTDepartamento: public ICollectible{
    private:
        char* letra;
        string nombre;
    public:
        DTDepartamento();
        DTDepartamento(char*, string);
        ~DTDepartamento();
        char* getLetra();
        string getNombre();
        friend ostream& operator << (ostream &, DTDepartamento *);
};
DTDepartamento::DTDepartamento(char* letra, string nombre){
    this->letra = letra;
    this->nombre = nombre;
}

DTDepartamento::~DTDepartamento(){}

// Getters

char* DTDepartamento::getLetra(){
    return this->letra;
}

string DTDepartamento::getNombre(){
    return this->nombre;
}

ostream& operator << (ostream & o, DTDepartamento * dep){
    o << "Letra: " << dep->getLetra() << endl << "Nombre: " << dep->getNombre() << endl;
    return o;
}

//dtedificio
class DTEdificio: public ICollectible {
    private:
        int codigo;
        string nombre;
        int cantPisos;
        int gastosComunes;
    public:
        DTEdificio(int, string, int, int);
        ~DTEdificio();
        
        // Getters
        int getCodigo();
        string getNombre();
        int getCantPisos();
        int getGastosComunes();
        
        friend ostream& operator << (ostream &, DTEdificio *);
};
DTEdificio::DTEdificio(int codigo, string nombre, int cantPisos, int gastosComunes){
    this->codigo = codigo;
    this->nombre = nombre;
    this->cantPisos = cantPisos;
    this->gastosComunes = gastosComunes;   
}

DTEdificio::~DTEdificio(){}

// Getters

int DTEdificio::getCodigo(){
    return this->codigo;
}

string DTEdificio::getNombre(){
    return this->nombre;
}

int DTEdificio::getCantPisos(){
    return this->cantPisos;
}

int DTEdificio::getGastosComunes(){
    return this->gastosComunes;
}

ostream& operator << (ostream & o, DTEdificio * edi){
    o << "Código: " << edi->getCodigo() << endl << "Nombre: " << edi->getNombre() << endl << "Cantidad de pisos: " << edi->getCantPisos() << endl << "Gastos comunes: " << edi->getGastosComunes() << endl;
    return o;
}
//dtinmobiliaria
class DTInmobiliaria: public ICollectible{
    private:
        string nombre;
        DTDir * direccion;
    public:
        DTInmobiliaria(string, DTDir *);
        ~DTInmobiliaria();
        string getNombre();
        DTDir * getDireccion();
        friend ostream& operator << (ostream &, DTInmobiliaria *);
};
DTInmobiliaria::DTInmobiliaria(string nombre, DTDir * direccion){
    this->nombre = nombre;
    this->direccion = direccion;
}

DTInmobiliaria::~DTInmobiliaria(){

}

string DTInmobiliaria::getNombre(){
    return this->nombre;
}

DTDir * DTInmobiliaria::getDireccion(){
    return this->direccion;
}

ostream& operator << (ostream & o, DTInmobiliaria * inmo){
    o << "Nombre: " << inmo->getNombre() << endl << "Direccion: " << endl << inmo->getDireccion();
    return o;
}
//dtlineareporte
class DTLineaReporte: public ICollectible {
    private:
        int codigoZona;
        char * letraDep;
        int cantApartamentos;
        int cantCasas;
    public:
        DTLineaReporte(int, char *, int, int);
        ~DTLineaReporte();
        
        // Getters

        int getCodigoZona();
        char * getLetraDep();
        int getCantApartamentos();
        int getCantCasas();

        friend ostream& operator << (ostream &, DTLineaReporte *);
};
DTLineaReporte::DTLineaReporte(int codigoZona, char * letraDep, int cantApartamentos, int cantCasas){
    this->codigoZona = codigoZona;
    this->letraDep = letraDep;
    this->cantApartamentos = cantApartamentos;
    this->cantCasas = cantCasas;
}

DTLineaReporte::~DTLineaReporte(){}

// Getters

int DTLineaReporte::getCodigoZona(){
    return this->codigoZona;
}

char * DTLineaReporte::getLetraDep(){
    return this->letraDep;
}

int DTLineaReporte::getCantApartamentos(){
    return this->cantApartamentos;
}

int DTLineaReporte::getCantCasas(){
    return this->cantCasas;
}

ostream& operator << (ostream & o, DTLineaReporte * linea){
    o << "    Letra Departamento: " << linea->getLetraDep() << endl << "    Codigo Zona: " << linea->getCodigoZona() << endl << "    Cantidad de apartamentos: " << linea->getCantApartamentos() << endl << "    Cantidad de casas: " << linea->getCantCasas() << endl;
    return o;
}

//dtreporte
class DTReporte : ICollectible{
    private:
        DTInmobiliaria * inmo;
        ICollection * lineas;
    public:
        DTReporte(DTInmobiliaria *, ICollection * );
        ~DTReporte();
        
        // Getters

        DTInmobiliaria * getInmo();
        ICollection * getLineas();

        friend ostream& operator << (ostream &, DTReporte *);
};
DTReporte::DTReporte(DTInmobiliaria * inmo, ICollection * lineas){
    this->inmo = inmo;
    this->lineas = lineas;
}

DTReporte::~DTReporte(){}

// Getters

DTInmobiliaria * DTReporte::getInmo(){
    return this->inmo;
}

ICollection * DTReporte::getLineas(){
    return this->lineas;
}

// DUDO QUE ESTE BIEN
ostream& operator << (ostream & o, DTReporte * reporte){
    o << "Inmobiliaria: " << reporte->getInmo() << endl;
    // IIterator * it = reporte->lineas->getIterator();
    // DTLineaReporte * linea;
    // while(it->hasCurrent()){
    //     linea = (DTLineaReporte *) it->getCurrent();
    //     o << linea << endl;
    //     it->next();
    // }
    // delete it;
    return o;
}

//dtzona
class DTZona: public ICollectible{
    private:
        int codigoZona;
        string nombre;
    public:
        DTZona(int, string);
        ~DTZona();

        // Getters
        int getCodigoZona();
        string getNombre();

        friend ostream& operator << (ostream &, DTZona *);
};
DTZona::DTZona(int codigoZona, string nombre){
    this->codigoZona = codigoZona;
    this->nombre = nombre;
}

DTZona::~DTZona(){

}

int DTZona::getCodigoZona(){
    return this->codigoZona;
}

string DTZona::getNombre(){
    return this->nombre;
}

ostream& operator << (ostream & o, DTZona * zona){
    o << "Codigo: " << zona->getCodigoZona() << endl << "Nombre: " << zona->getNombre() << endl;
    return o;
}

//dttipoprop
enum class DTTipoProp {
    casa,
    apartamento
};

//usuario
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
Usuario::Usuario(char* email){
    this->correoElectronico = email;
    this->contrasenia = "";
    this->primeraVez = true;
}

Usuario::~Usuario(){}

char* Usuario::getCorreoEletronico(){
    return this->correoElectronico;
}

string Usuario::getContrasenia(){
    return this->contrasenia;
}

void Usuario::setCorreoElectronico(char* email){
    this->correoElectronico = email;
}

void Usuario::setContrasenia(string contrasenia){
    if(this->primeraVez){
        throw runtime_error("El usuario no ha establecido su primera contraseña");
    } else {
        if(contrasenia.length() >= 8){
            this->contrasenia = contrasenia;
        } else {
            throw invalid_argument("La contraseña no supera el mínimo de caracteres");
        }
    }
}

bool Usuario::esContraseniaCorrecta(string contrasenia){
    return this->contrasenia == contrasenia;
}

void Usuario::agregarContrasenia(string contrasenia){
    if(this->primeraVez){
        if(contrasenia.length() >= 8){
            this->contrasenia = contrasenia;
            this->primeraVez = false;
        } else {
            throw invalid_argument("La contraseña no supera el mínimo de caracteres");
        }
    } else {
        throw runtime_error("El usuario ya había creado contraseña");
    }
}

void Usuario::setPrimeraVez(bool opt){
    this->primeraVez = opt;
}

bool Usuario::getPrimeraVez(){
    return this->primeraVez;
}

//inmobiliaria
class Venta;
class Alquiler;
class Inmobiliaria : public Usuario {
    private:
        string nombre;
        DTDir * direccion;
        IDictionary * ventas;
        IDictionary * alquileres;
        IDictionary * propiedades;
        int cantVentas;
        int cantAlquileres;
        int cantPropiedades;
        int cantConversaciones;
    public:
        Inmobiliaria(char*, string, DTDir*);
        ~Inmobiliaria();

        //Setters
        void setNombre(char*);
        void setDireccion(DTDir*);
        Venta* ponerEnVenta(Propiedad*, float);
        Alquiler* ponerEnAlquiler(Propiedad*, float);
        void agregarPropiedad(Propiedad*);

        //Getters
        string getNombre();
        DTDir * getDireccion();
        IDictionary* getVentas();
        IDictionary* getAlquileres();
        IDictionary* getPropiedades();
        int getCantVentas();
        int getCantAlquileres();
        int getCantPropiedades();

        //Métodos
        DTInmobiliaria * getDTInmobiliaria();
        void destruirVenta(Propiedad*);
        void destruirAlquiler(Propiedad*);
        DTReporte* obtenerReporteInmobiliaria();
        Propiedad * seleccionarPropiedad(int);
        IDictionary * listarConversaciones();
        Conversacion * seleccionarConversacion(int);

        // Funciones aparte

        int generarCodigoConversacion();
        ICollection * listarPropiedades();
};
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
    char* departamentos[99]; // No puedo obtener los departamentos desde la zona, entonces por ahora son null todos
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
        col =  prop->listarConversaciones();
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
    }
    delete it;
    return lista;
}
//administrador
class Administrador : public Usuario {
    public:
        Administrador(char*, string);
};
Administrador::Administrador(char* email, string contrasenia) : Usuario(email){
    this->contrasenia = contrasenia;
    this->primeraVez = false;
}

//interesado
class Interesado : public Usuario {
    private:
        string nombre;
        string apellido;
        int edad;
    public:
        Interesado(char*, string, string, int);

        //Setters
        void setNombre(string);
        void setApellido(string);
        void setEdad(int);

        //Getters
        string getNombre();
        string getApellido();
        int getEdad();
};
Interesado::Interesado(char* email, string nombre, string apellido, int edad) : Usuario(email) {
    this->contrasenia = "";
    this->nombre = nombre;
    this->apellido = apellido;
    this->edad = edad;
    this->primeraVez = true;
}

string Interesado::getNombre(){
    return this->nombre;
}

string Interesado::getApellido(){
    return this->apellido;
}

int Interesado::getEdad(){
    return this->edad;
}

void Interesado::setNombre(string nombre){
    this->nombre = nombre;
}

void Interesado::setApellido(string apellido){
    this->apellido = apellido;
}

void Interesado::setEdad(int edad){
    this->edad = edad;
}

class Edificio;

//conversacion
class Conversacion : public ICollectible{
    private:
        int codigoConversacion;
        int cantMensajes;
        Interesado* interesado;
        ICollection* mensajes;
    public:
        Conversacion(int, Interesado *);
        virtual ~Conversacion();

        // Getters
        int getCodigoConversacion();
        int getCantidadMensajes();
        Interesado * getInteresado();

        // Setters
        void setCodigoConversacion(int);
        void setCantidadMensajes(int);
        void setInteresado(Interesado*);

        void destruirMensajes();
        ICollection* getUltimosMensajes();
        void nuevoMensaje(DTFecha *, string);

        DTFecha * getFechaUltimoMensaje();
};
// Getters
int Conversacion::getCodigoConversacion()  {
    return codigoConversacion;
}

int Conversacion::getCantidadMensajes()  {
    return cantMensajes;
}

Interesado * Conversacion::getInteresado()  {
    return interesado;
}

    // Setters
void Conversacion:: setCodigoConversacion(int codigo) {
    codigoConversacion = codigo;
}   

void Conversacion::setCantidadMensajes(int cantidad) {
    cantMensajes = cantidad;
}

void Conversacion::setInteresado(Interesado* nuevoInteresado) {
    interesado = nuevoInteresado;
}

//constructores y destructores
Conversacion::Conversacion(int nuevoCodigo, Interesado * interesado) {
    this->codigoConversacion = nuevoCodigo;
    this->interesado = interesado;
}

Conversacion::~Conversacion() {
}
   
ICollection* Conversacion::getUltimosMensajes() {
    IIterator* it = mensajes->getIterator();
    ICollection* ultimosMensajes = new List();
    Mensaje * mens;
    ICollectible * item;
    for(int i = 0; it->hasCurrent() && i<5; i++) {
        mens = (Mensaje*) it->getCurrent();
        item = (ICollectible *) mens->getDTMensaje();
        ultimosMensajes->add(item);
        it->next();
    }
    delete it;
    return ultimosMensajes;
}

void Conversacion::destruirMensajes() {
    IIterator* it = mensajes->getIterator();
    while(it->hasCurrent()) {
        ICollectible* eliminar = it->getCurrent();
        it->next();
        mensajes->remove(eliminar);
        delete eliminar;
    }
    delete it;
}

void Conversacion::nuevoMensaje(DTFecha * fecha, string contenido){
    Mensaje * mensaje = new Mensaje(fecha, contenido);
    this->mensajes->add(mensaje);
}

DTFecha * Conversacion::getFechaUltimoMensaje(){
    IIterator * it = this->mensajes->getIterator();
    Mensaje * men;
    while (it->hasCurrent()){
        men = (Mensaje *) it->getCurrent();
        delete it;
        return men->getFecha();
    }
    delete it;
    return NULL;
}

class Propiedad;
//alquiler
class Alquiler : public ICollectible {
    private:
        float precioAlquiler;
        Propiedad * prop;
    public:
        Alquiler(Propiedad*, float);
        bool existeAlquiler();
        ~Alquiler();

        //getters y setters
        float getPrecioAlquiler();
        void setPrecioAlquiler(float);
};
Alquiler:: Alquiler(Propiedad * prop, float precioAlquiler) {
    this->precioAlquiler = precioAlquiler;
    this->prop = prop;
};

Alquiler:: ~Alquiler(){
};

float Alquiler:: getPrecioAlquiler(){
    return precioAlquiler;
};

void Alquiler:: setPrecioAlquiler(float precioAlquiler) {
    this->precioAlquiler = precioAlquiler;
};

//venta
class Venta: public ICollectible {
    private:
        float precioTotal;
        Propiedad* prop;
    public:
        Venta(Propiedad*, float);
        ~Venta();
        bool existeVenta();

        //getters y setters
        float getPrecioTotal();
        void setPrecioTotal(float);
        Propiedad* getPropiedad();
};

Venta:: Venta(Propiedad * prop, float precioTotal) {
    this->precioTotal= precioTotal;
    this->prop = prop;
};

Venta:: ~Venta() {
};

float Venta::getPrecioTotal() {
    return precioTotal;
};

void Venta::setPrecioTotal(float precioTotal) {
    this->precioTotal = precioTotal;
};

Propiedad* Venta::getPropiedad(){
    return this->prop;
}

//propiedad
class Propiedad : public ICollectible{
    protected:
        int codigo;
        int cantAmbiente;
        int cantDormitorios;
        int cantBanios;
        float m2Edificios;
        float m2Totales;
        bool tieneGaraje;
        DTDir * direccion;
        IDictionary * conversaciones;
        Zona * zona;
        DTEstadoProp estado;
        Inmobiliaria * inmo;
    public:
        Propiedad(int, int, int, int, float, DTDir*, bool, Zona *);
        Propiedad(){};
        virtual ~Propiedad();

        // Setters

        void setZona(Zona *);
        void setM2Totales(float);
        void setM2Edificios(float);
        void setTieneGaraje(bool);
        void setCantBanios(int);
        void setCantDormitorios(int);
        void setCantAmbiente(int);
        void setCodigo(int);
        void setDireccion(DTDir *);
        void agregarConversacion(Conversacion *);
        void setEstadoProp(DTEstadoProp);
        void setInmobiliaria(Inmobiliaria *);

        // Getters

        bool getTieneGaraje();
        float getm2Totales();
        int getCodigo();
        int getCantAmbiente();
        int getCantDormitorios();
        int getCantBanios();
        float getM2Edificios();
        DTDir * getDireccion();
        Zona * getZona();
        DTEstadoProp getEstadoProp();
        Inmobiliaria * getInmobiliaria();

        DTInmobiliaria * getDTInmobiliaria();
        DTPropiedad * getDTPropiedad();
        DTPropiedadDetallada * getDTPropiedadDetallada();
        virtual DTTipoProp getDTTipoProp() = 0;
        IDictionary * getConversaciones();
        void desvincularDeZona();
        void destruirConversaciones();
        ICollectible * getDTChatProp(char *);
        
        // ICollection * getUltimosMensajes(Conversacion *);

        Conversacion * getConversacion(char *);
        ICollection * getUltimosMensajes(char *);
        Conversacion * nuevoChat(Interesado *);
        IDictionary * listarConversaciones();
};
Propiedad :: Propiedad(int _codigo, int _cantAmbiente, int _cantDormitorios, int _cantBanios, float _m2Edificios, DTDir* dir, bool _tieneGaraje, Zona * _zona){
    this->codigo = _codigo;
    this->cantAmbiente =_cantAmbiente;
    this->cantDormitorios = _cantDormitorios;
    this->cantBanios = _cantBanios;
    this->m2Edificios = _m2Edificios;
    this->direccion = dir;
    this->tieneGaraje = _tieneGaraje;
    this->conversaciones = new OrderedDictionary();
    this->zona = _zona;
}

Propiedad :: ~Propiedad(){
    this->desvincularDeZona();
    this->destruirConversaciones();
}

void Propiedad :: setM2Totales(float _m2Totales){
    this->m2Totales = _m2Totales;
}

void Propiedad :: setM2Edificios(float _m2Edificios){
    this->m2Edificios = _m2Edificios;
}

void Propiedad :: setTieneGaraje(bool _tieneGaraje){
    this->tieneGaraje = _tieneGaraje;
}

void Propiedad :: setCantBanios(int _cantBanios){
    this->cantBanios = _cantBanios;
}

void Propiedad :: setCantDormitorios(int _cantDormitorios){
    this->cantDormitorios = _cantDormitorios;
}

void Propiedad :: setCantAmbiente(int _cantAmbiente){
    this->cantAmbiente = _cantAmbiente;
}

void Propiedad::setDireccion(DTDir * dir){
    this->direccion = dir;
}

void Propiedad :: setCodigo(int _codigo){
    this->codigo = _codigo;
}

void Propiedad::setInmobiliaria(Inmobiliaria * inmo){
    this->inmo = inmo;
}

void Propiedad :: agregarConversacion(Conversacion * _conver){
    IKey * key = new Integer(_conver->getCodigoConversacion());
    if(this->conversaciones->member(key)){
        delete key;
        throw invalid_argument("La conversación ya existe");
    }
    ICollectible * conversacion = (ICollectible*) _conver;
    this->conversaciones->add(key, conversacion);
}

void Propiedad :: setZona(Zona * _zona){
    this->zona = _zona;
}

void Propiedad::setEstadoProp(DTEstadoProp estado){
    if ((this->estado == DTEstadoProp::venta && estado == DTEstadoProp::alquiler) || (this->estado == DTEstadoProp::alquiler && estado == DTEstadoProp::venta)){
        this->estado = DTEstadoProp::venta_y_alquiler;
    } else {
        this->estado = estado;
    }
}

bool Propiedad :: getTieneGaraje(){
    return this->tieneGaraje;
}

float Propiedad :: getm2Totales(){
    return this->m2Totales;
}

int Propiedad :: getCodigo(){
    return this->codigo;
}

int Propiedad :: getCantAmbiente(){
    return this->cantAmbiente;
}

int Propiedad :: getCantDormitorios(){
    return this->cantDormitorios;
}

int Propiedad :: getCantBanios(){
    return this->cantBanios;
}

DTDir * Propiedad::getDireccion(){
    return this->direccion;
}

float Propiedad :: getM2Edificios(){
    return this->m2Edificios;
}

IDictionary * Propiedad :: getConversaciones(){
    return this->conversaciones;
}

Zona * Propiedad :: getZona(){
    return this->zona;
}

DTEstadoProp Propiedad::getEstadoProp(){
    return this->estado;
}

Inmobiliaria * Propiedad::getInmobiliaria(){
    return this->inmo;
}

void Propiedad :: desvincularDeZona(){
    this->zona->desvincularPropiedad(this->getCodigo());
}

//(en eliminar propiedad)
//seria hacer un next en la colleccion(conversacion), destruir los mensajes 
//y luego la propia conversacion
//asi uno por uno
void Propiedad :: destruirConversaciones(){ 
    IIterator * it = this->conversaciones->getIterator();
    Conversacion * con;
    IKey * key;
    while(it->hasCurrent()){
        con = (Conversacion *) it->getCurrent();
        key = new Integer(con->getCodigoConversacion());
        it->next();
        this->conversaciones->remove(key);
        con->destruirMensajes();
        delete con;
    }
    delete it;
}

DTPropiedad * Propiedad::getDTPropiedad(){
    return new DTPropiedad(this->codigo, this->direccion, this->estado);
}

DTPropiedadDetallada * Propiedad::getDTPropiedadDetallada(){
    return new DTPropiedadDetallada(this->codigo, this->direccion, this->estado, this->cantAmbiente, this->cantDormitorios, this->cantBanios, this->tieneGaraje, this->m2Totales, this->inmo->getDTInmobiliaria());
}

ICollectible * Propiedad :: getDTChatProp(char * email){
    IIterator * it = this->conversaciones->getIterator();
    Conversacion * con;
    while(it->hasCurrent()){
        con = (Conversacion *) it->getCurrent();
        if (con->getInteresado()->getCorreoEletronico() == email){
            delete it;
            ICollectible *col = (ICollectible *) new DTChatProp(this->codigo, con->getCodigoConversacion(), con->getCantidadMensajes(), con->getFechaUltimoMensaje(), this->direccion);
            return col;
        }
        it->next();
    }
    delete it;
    ICollectible *col = (ICollectible *) new DTPropiedad(this->codigo, this->direccion, this->estado);
    return col;
    // throw
}

ICollection * Propiedad :: getUltimosMensajes(char * email){
    IIterator * it = this->conversaciones->getIterator();
    Conversacion * con;
    while (it->hasCurrent()){
        con = (Conversacion *) it->getCurrent();
        if (con->getInteresado()->getCorreoEletronico() == email){
            delete it;
            return con->getUltimosMensajes();
        }
        it->next();
    }
    delete it;
    throw invalid_argument("No hay ninguna conversación registrada con ese Interesado en la Propiedad actual");
}

Conversacion * Propiedad::getConversacion(char * email){
    IIterator * it = this->conversaciones->getIterator();
    Conversacion * con = NULL;
    while(it->hasCurrent()){
        con = (Conversacion *) it->getCurrent();
        if (con->getInteresado()->getCorreoEletronico() == email){
            delete it;
            return con;
        }
        it->next();
    }
    delete it;
    return NULL;
}

//crea una conversacion y la añade a la coleccion
Conversacion * Propiedad :: nuevoChat(Interesado * interesado){
    int clave = this->inmo->generarCodigoConversacion();
    IKey * key = new Integer(clave);
    Conversacion * c = new Conversacion(clave, interesado);
    if(!this->conversaciones->member(key)){
        ICollectible * nuevoChat = (ICollectible *) c;
        this->conversaciones->add(key, nuevoChat);
        return c;
    }else{
        delete key;
        throw invalid_argument("La conversacion ya fue agregado con anterioridad");
    }
    return NULL;
}

// Devuelve un ICollection que contiene un DTChatProp por cada conversación de la propiedad
IDictionary * Propiedad::listarConversaciones(){
    IDictionary * lista = new OrderedDictionary();
    IIterator * it = this->conversaciones->getIterator();
    Conversacion * con = NULL;
    ICollectible * item = NULL;
    OrderedKey * key = NULL;
    while (it->hasCurrent()){
        con = (Conversacion *) it->getCurrent();
        DTChatProp * dtcon = new DTChatProp(this->codigo, con->getCodigoConversacion(), con->getCantidadMensajes(), con->getFechaUltimoMensaje(), this->getDireccion());
        key = new Integer(dtcon->getValorKey());
        item = (ICollectible *) dtcon;
        lista->add(key, item);
    }
    delete it;
    return lista;
}


//mensaje
class Mensaje: public ICollectible{
    private:
        DTHora * hora;
        DTFecha * fecha;
        string texto;
    public:
        Mensaje();
        Mensaje(DTFecha *, string);
        ~Mensaje();
        DTMensaje * getDTMensaje();
        DTFecha * getFecha();
        string getTexto();
        void setFecha(DTFecha *);
        void setTexto(string);
};

Mensaje::Mensaje(DTFecha * fecha, string texto){
    this->fecha = fecha;
    this->texto = texto;
}

Mensaje::~Mensaje(){
    delete this->fecha;
}

DTFecha * Mensaje::getFecha(){
    return this->fecha;
}

string Mensaje::getTexto(){
    return this->texto;
}

void Mensaje::setFecha(DTFecha * fecha){
    this->fecha = fecha;
}

void Mensaje::setTexto(string texto){
    this->texto = texto;
}

DTMensaje * Mensaje::getDTMensaje(){
    return new DTMensaje(this->getTexto(), this->getFecha());
}

//apartamento
class Apartamento : public Propiedad{
    private:
        Edificio * edificio;
    public:
        Apartamento(int, int, int, int, float, DTDir*, bool, Zona *, Edificio *);
        ~Apartamento();
        void setEdificio(Edificio *);
        Edificio * getEdificio();
        DTTipoProp getDTTipoProp();
        void desvincularDeEdificio();
        void modificarApartamento(int, int, int, float, DTDir*, bool);
};
Apartamento::Apartamento(int _codigo, int _cantAmbiente, int _cantDormitorios, int _cantBanios, float _m2Edificios, DTDir * dir, bool _tieneGaraje, Zona * _zona, Edificio * _edificio): Propiedad(_codigo, _cantAmbiente, _cantDormitorios, _cantBanios, _m2Edificios, dir, _tieneGaraje, _zona){
    this->edificio = _edificio;
    this->m2Totales = _m2Edificios;
}

Apartamento::~Apartamento(){
    this->desvincularDeEdificio();
}

void Apartamento::setEdificio(Edificio * _edificio){
    this->edificio = _edificio;
}

Edificio * Apartamento::getEdificio(){
    return this->edificio;
}

void Apartamento::desvincularDeEdificio(){
    this->edificio->desvincularPropiedad(this->getCodigo());
}

DTTipoProp Apartamento::getDTTipoProp(){
    return DTTipoProp::apartamento;
}

void Apartamento::modificarApartamento(int cantAmbientes, int cantDormitorios, int cantBanios, float m2Totales, DTDir* dir, bool tieneGaraje){
    this->cantAmbiente = cantAmbientes;
    this->cantDormitorios = cantDormitorios;
    this->cantBanios = cantBanios;
    this->m2Totales = m2Totales;
    this->m2Edificios = m2Totales;
    this->direccion = dir;
    this->tieneGaraje = tieneGaraje;
}

//edificio
class Edificio: public ICollectible {
    private:
        int codigo;
        string nombre;
        int cantPisos;
        int gastosComunes;
        IDictionary * apartamentos;
        Zona * zona;
        int cantApartamentos;
    public:
        Edificio(int, string, int, int, Zona*);
        ~Edificio();

        // Getters

        int getCodigo();
        string getNombre();
        int getCantPisos();
        int getGastosComunes();
        int getCantApartamentos();
        IDictionary * getApartamentos();
        Zona * getZona();

        // Setters

        void setCodigo(int);
        void setNombre(string);
        void setCantPisos(int);
        void setGastosComunes(int);
        void setCantApartamentos(int);
        void setZona(Zona *);

        // Agregar-Quitar (Creo que esta mal)

        void enlazarPropiedad(Apartamento *);

        // Métodos de Edificio (DCD)

        DTEdificio * getDTEdifico();
        Apartamento * crearApartamento(int, int, int, float, DTDir *, bool);
        void desvincularPropiedad(int);
};
Edificio::Edificio(int codigo, string nombre, int cantPisos, int gastosComunes, Zona* zona){
    this->codigo = codigo;
    this->nombre = nombre;
    this->cantPisos = cantPisos;
    this->gastosComunes = gastosComunes;
    this->apartamentos = new OrderedDictionary();
    this->cantApartamentos = 0;
    this->zona = zona;
    // Falta especificar el ICollection
}

Edificio::~Edificio(){}

// Getters

int Edificio::getCodigo(){
    return this->codigo;
}

string Edificio::getNombre(){
    return this->nombre;
}

int Edificio::getCantPisos(){
    return this->cantPisos;
}

int Edificio::getGastosComunes(){
    return this->gastosComunes;
}

int Edificio::getCantApartamentos(){
    return this->cantApartamentos;
}

IDictionary * Edificio::getApartamentos(){
    return this->apartamentos; // Capaz no es asi
}

Zona * Edificio::getZona(){
    return this->zona;
}

// Setters

void Edificio::setCodigo(int codigo){
    this->codigo = codigo;
}

void Edificio::setNombre(string nombre){
    this->nombre = nombre;
}

void Edificio::setCantPisos(int cantPisos){
    this->cantPisos = cantPisos;
}

void Edificio::setGastosComunes(int gastosComunes){
    this->gastosComunes = gastosComunes;
}

void Edificio::setCantApartamentos(int cantApartamentos){
    this->cantApartamentos = cantApartamentos;
}

void Edificio::setZona(Zona * zona){
    this->zona = zona;
}

// Agregar-Quitar

void Edificio::enlazarPropiedad(Apartamento * apartamento){

    IKey * nuevaKey = new Integer (apartamento->getCodigo());
    if (!this->apartamentos->member(nuevaKey)){
        ICollectible * nuevoApartamento = (ICollectible *) apartamento;
        this->apartamentos->add(nuevaKey, nuevoApartamento);
        this->cantApartamentos++;
        cout << "El apartamento fue agregado exitosamente!" << endl;
    } else {
        delete nuevaKey;
        throw invalid_argument("El apartamento ya fue agregada con anterioridad");
    }
    // ES CON ICOLLECTION
}

void Edificio::desvincularPropiedad(int codigo){

    IKey * clave = new Integer (codigo);
    if (this->apartamentos->member(clave)){
        this->apartamentos->remove(clave);
        delete clave;
        cout << "El apartamento fue removido de manera exitosa!" << endl;
    } else {
        delete clave;
        throw invalid_argument("El apartamento especificado no se encuentra en el edificio actual");
    }
    // ES CON ICOLLECTION
}

// Métodos de Edificio (DCD)

DTEdificio * Edificio::getDTEdifico(){
    return new DTEdificio(this->getCodigo(), this->getNombre(), this->getCantPisos(), this->getGastosComunes());
}

Apartamento * Edificio::crearApartamento(int cantAmbientes, int cantDormitorios, int cantBanios, float m2Edificados, DTDir * dir, bool tieneGaraje){
    int codigo = this->zona->generarCodigoPropiedad();
    return new Apartamento(codigo, cantAmbientes, cantDormitorios, cantBanios, m2Edificados, dir, tieneGaraje, this->zona, this);
}

//casa
class Casa : public Propiedad{
    private:
        float m2Verdes;
    public:
        Casa(int, int, int, int, float, DTDir*, bool, Zona *, float);
        void setM2Verdes(float);
        float getM2Verdes();
        DTTipoProp getDTTipoProp();
        void modificarCasa(int, int, int, float, DTDir*, bool, float);
};
Casa::Casa(int _codigo, int _cantAmbiente, int _cantDormitorios, int _cantBanios, float _m2Edificios, DTDir * dir, bool _tieneGaraje, Zona * _zona, float _m2Verdes): Propiedad(_codigo, _cantAmbiente, _cantDormitorios, _cantBanios, _m2Edificios, dir, _tieneGaraje, _zona){
    this->m2Verdes = _m2Verdes;
    this->m2Totales = _m2Edificios + _m2Verdes;
}

void Casa::setM2Verdes(float _m2Verdes){
    this->m2Verdes = _m2Verdes;
}

float Casa::getM2Verdes(){
    return this->m2Verdes;
}

DTTipoProp Casa::getDTTipoProp(){
    return DTTipoProp::casa;
}

void Casa::modificarCasa(int cantAmbientes, int cantDormitorios, int cantBanios, float m2Edificados, DTDir* dir, bool tieneGaraje, float m2Verdes){
    this->cantAmbiente = cantAmbientes;
    this->cantDormitorios = cantDormitorios;
    this->cantBanios = cantBanios;
    this->m2Edificios = m2Edificados;
    this->direccion = dir;
    this->tieneGaraje = tieneGaraje;
    this->m2Verdes = m2Verdes;
    this->m2Totales = m2Edificados + m2Verdes;
}

//zona
class Zona : public ICollectible {
    private:
        int codigo;
        string nombre;
        IDictionary * edificios;
        int cantEdificios;
        IDictionary * propiedades;
        int cantPropiedades;
        char* letraDepa;
    public:
        Zona(int, string, char*);
        ~Zona();

        // Getters

        int getCodigo();
        string getNombre();
        int getCantEdificios();
        int getCantPropiedades();
        IDictionary * getEdificios();
        IDictionary * getPropiedades();
        char* getLetraDepa();

        // Setters

        void setCodigo(int);
        void setNombre(string);
        void setCantEdificios(int);
        void setCantPropiedades(int);
        void setLetraDepa(char*);

        // Agregar-Quitar (Creo que esta mal)

        void agregarEdificio(Edificio *);
        void quitarEdificio(int);
        
        // Métodos de Zona (DCD)

        DTZona * getDTZona();
        ICollection * listarEdificios();
        Edificio * seleccionarEdificio(int);
        void enlazarPropiedad(Propiedad *);
        Casa * crearCasa(int, int, int, float, DTDir*, bool, float);
        void desvincularPropiedad(int);
        IDictionary * listarChatPropiedad(char *);
        Propiedad * seleccionarPropiedad(int);
        ICollection * getUltimosMensajes();
        ICollection * listarPropiedades();
        DTPropiedadDetallada * verDetallesPropiedad(int);

        // Otras funciones
        int generarCodigoPropiedad();
        int generarCodigoEdificio();
};
Zona::Zona(int codigo, string nombre, char* letradepa){
    this->codigo = codigo;
    this->nombre = nombre;
    this->edificios = new OrderedDictionary();
    this->propiedades = new OrderedDictionary();
    this->cantEdificios = 0;
    this->cantPropiedades = 0;
    this->letraDepa = letradepa;
    // Falta especificar el ICollection
}

Zona::~Zona(){}

// Getters

int Zona::getCodigo(){
    return this->codigo;
}

string Zona::getNombre(){
    return this->nombre;
}

int Zona::getCantEdificios(){
    return this->cantEdificios;
}

int Zona::getCantPropiedades(){
    return this->cantPropiedades;
}

IDictionary * Zona::getEdificios(){
    return this->edificios; // Capaz no es asi
}

IDictionary * Zona::getPropiedades(){
    return this->propiedades; // Capaz no es asi
}

// Setters

void Zona::setCodigo(int codigo){
    this->codigo = codigo;
}

void Zona::setNombre(string nombre){
    this->nombre = nombre;
}

void Zona::setCantEdificios(int cantEdificios){
    this->cantEdificios = cantEdificios;
}

void Zona::setCantPropiedades(int cantPropiedades){
    this->cantPropiedades = cantPropiedades;
}

// Agregar-Quitar

void Zona::agregarEdificio(Edificio * edificio){
    
    IKey * nuevaKey = new Integer (edificio->getCodigo());
    if (!this->edificios->member(nuevaKey)){
        ICollectible * nuevoEdificio = (ICollectible *) edificio;
        this->edificios->add(nuevaKey, nuevoEdificio);
        this->cantEdificios++;
        // cout << "El edificio fue agregado exitosamente!" << endl;
    } else {
        delete nuevaKey;
        throw invalid_argument("El edificio ya fue agregado con anterioridad");
    }

    // ES CON ICOLLECTION
}

void Zona::quitarEdificio(int codigoEdificio){

    IKey * clave = new Integer (codigoEdificio);
    if (this->edificios->member(clave)){
        this->edificios->remove(clave);
        this->cantEdificios--;
        delete clave;
        // cout << "El edificio fue removido de manera exitosa!" << endl;
    } else {
        delete clave;
        throw invalid_argument("El edificio especificado no se encuentra en la zona actual");
    }
    // ES CON ICOLLECTION
}

// Métodos de Zona (DCD)

DTZona * Zona::getDTZona(){
    return new DTZona(this->codigo, this->nombre);
}

ICollection * Zona::listarEdificios(){
    ICollection * edificios = new List();
    IIterator * it = this->edificios->getIterator();
    Edificio * edificio;
    ICollectible * item;
    while (it->hasCurrent()){
        edificio = (Edificio *) it->getCurrent();
        item = (ICollectible *) edificio->getDTEdifico();
        edificios->add(item);
        it->next();
    }
    delete it;
    return edificios;
    // ES CON ICOLLECTION
}

Edificio * Zona::seleccionarEdificio(int codigoEdificio){

    IKey * clave = new Integer (codigoEdificio);
    Edificio * edificio = (Edificio *) this->edificios->find(clave);
    delete clave;
    if (edificio != NULL){
        return edificio;
    } else {
        throw invalid_argument("El edificio especificado no se encuentra en la zona actual");
    }
    // ES CON ICOLLECTION
}

// ES LO MISMO QUE AGREGAR PROPIEDAD
void Zona::enlazarPropiedad(Propiedad * propiedad){
    
    IKey * nuevaKey = new Integer (propiedad->getCodigo());
    if (!this->propiedades->member(nuevaKey)){
        ICollectible * nuevaPropiedad = (ICollectible *) propiedad;
        this->propiedades->add(nuevaKey, nuevaPropiedad);
        this->cantPropiedades++;
        // cout << "La propiedad fue agregado exitosamente!" << endl;
    } else {
        delete nuevaKey;
        throw invalid_argument("La propiedad ya fue agregado con anterioridad");
    }
    // ES CON ICOLLECTION
}

Casa * Zona::crearCasa(int cantAmbientes, int cantDormitorios, int cantBanios, float m2Edificados, DTDir * dir, bool tieneGaraje, float m2Verdes){
    int codigo = generarCodigoPropiedad();
    return new Casa(codigo, cantAmbientes, cantDormitorios, cantBanios, m2Edificados, dir, tieneGaraje, this, m2Verdes);
}

// ES LO MISMO QUE QUITAR PROPIEDAD
void Zona::desvincularPropiedad(int codigoProp){

    IKey * clave = new Integer (codigoProp);
    if (this->propiedades->member(clave)){
        this->propiedades->remove(clave);
        this->cantPropiedades--;
        delete clave;
        // cout << "La propiedad fue removida de manera exitosa!" << endl;
    } else {
        delete clave;
        throw invalid_argument("La propiedad especificada no se encuentra en la zona actual");
    }
    // ES CON ICOLLECTION
}

IDictionary * Zona::listarChatPropiedad(char * email){
    IIterator * it = this->propiedades->getIterator();
    IDictionary * lista = new OrderedDictionary();
    int count = 99999999;
    Propiedad * prop;
    OrderedKey * key;
    ICollectible * item;
    while (it->hasCurrent()){
        prop = (Propiedad *) it->getCurrent();
        item = prop->getDTChatProp(email);
        DTChatProp * dt = dynamic_cast<DTChatProp*> (item);
        if (dt != NULL){
            key = new Integer (dt->getValorKey());
            lista->add(key, item);
        } else {
            key = new Integer (count);
            lista->add(key, item);
            count++;
        }
        it->next();
    }
    delete it;
    return lista;
    // ES CON ICOLLECTION
}

Propiedad * Zona::seleccionarPropiedad(int codigoProp){

    IKey * clave = new Integer (codigoProp);
    Propiedad * propiedad = (Propiedad *) this->propiedades->find(clave);
    delete clave;
    if (propiedad != NULL){
        return propiedad;
    } else {
        throw invalid_argument("La propiedad especificada no se encuentra en la zona actual");
    }
    // ES CON ICOLLECTION
}

// Esta mal
ICollection * Zona::getUltimosMensajes(){
    ICollection * lista = new List();
    IIterator * it = this->propiedades->getIterator();
    Mensaje * mensaje;
    ICollectible * item;
    int count = 0;
    while(it->hasCurrent() && count < 5){
        mensaje = (Mensaje *) it->getCurrent();
        item = (ICollectible *) mensaje->getDTMensaje();
        lista->add(item);
        it->next();
        count++;
    }
    delete it;
    return lista;
    // ES CON ICOLLECTION
}

ICollection * Zona::listarPropiedades(){
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

DTPropiedadDetallada * Zona::verDetallesPropiedad(int codigoProp){
    IKey * key = new Integer(codigoProp);
    Propiedad * prop;
    if (this->propiedades->member(key)){
        prop = dynamic_cast<Propiedad*> (this->propiedades->find(key)); // Cambie esto
        delete key;
        return prop->getDTPropiedadDetallada();
    } else {
        delete key;
        throw invalid_argument("La propiedad especificada no se encuentra en la zona actual");
    }
}

// Generar codigo

int Zona::generarCodigoPropiedad(){
    IIterator * it = this->propiedades->getIterator();
    Propiedad * prop = NULL;
    while (it->hasCurrent()){
        prop = (Propiedad *) it->getCurrent();
        it->next();
    }
    delete it;
    if (prop != NULL){
        return prop->getCodigo()+1;
    }
    return 1;
}

int Zona::generarCodigoEdificio(){
    IIterator * it = this->edificios->getIterator();
    Edificio * edi = NULL;
    while (it->hasCurrent()){
        edi = (Edificio *) it->getCurrent();
        it->next();
    }
    if (edi != NULL){
        return edi->getCodigo()+1;
    }
    return 1;
}

char* Zona::getLetraDepa(){
    return this->letraDepa;
}

void Zona::setLetraDepa(char* letra){
    this->letraDepa = letra;
}

//departamento
class Departamento: public ICollectible {
    private:
        char * letra;
        string nombre;
        IDictionary * zonas;
        int cantZonas;
    public:
        Departamento(char *, string);
        ~Departamento();

        // Getters

        char * getLetra();
        string getNombre();
        int getCantZonas();
        IDictionary * getZonas();

        // Setters

        void setLetra(char *);
        void setNombre(string);
        void setCantZonas(int);

        // Agregar-Quitar (Creo que esta mal)

        void agregarZona(Zona *);
        void quitarZona(int);

        // Métodos de Departamento (DCD)

        DTDepartamento * getDTDepartamento();
        ICollection * listarZonasDepartamento();
        Zona * elegirZona(int);

        // Otras funciones
        int crearClaveZona();
};
Departamento::Departamento(char * letra, string nombre){
    this->letra = letra;
    this->nombre = nombre;
    this->zonas = new OrderedDictionary();
    this->cantZonas = 0;
}

Departamento::~Departamento(){}

// Getters

char * Departamento::getLetra(){
    return this->letra;
}

string Departamento::getNombre(){
    return this->nombre;
}

int Departamento::getCantZonas(){
    return this->cantZonas;
}

IDictionary * Departamento::getZonas(){
    return this->zonas; // Capaz no es asi
}

// Setters

void Departamento::setLetra(char * letra){
    this->letra = letra;
}

void Departamento::setNombre(string nombre){
    this->nombre = nombre;
}

void Departamento::setCantZonas(int cantZonas){
    this->cantZonas = cantZonas;
}

// Agregar-Quitar

void Departamento::agregarZona(Zona * zona){

    IKey * nuevaKey = new Integer (zona->getCodigo());
    if (!this->zonas->member(nuevaKey)){
        ICollectible * nuevaZona = (ICollectible *) zona;
        this->zonas->add(nuevaKey, nuevaZona);
        this->cantZonas++;
        cout << "La zona fue agregada exitosamente!" << endl;
    } else {
        delete nuevaKey;
        throw invalid_argument("La zona ya fue agregada con anterioridad");
    }

    // ES CON ICOLLECTION
}

void Departamento::quitarZona(int codigoZona){
    IKey * clave = new Integer (codigoZona);
    if (this->zonas->member(clave)){
        this->zonas->remove(clave);
        delete clave;
        cout << "La zona fue removida de manera exitosa!" << endl;
    } else {
        delete clave;
        throw invalid_argument("La zona especificada no se encuentra en el departamento actual");
    }
    // ES CON ICOLLECTION
}

// Métodos de Departamento (DCD)

DTDepartamento * Departamento::getDTDepartamento(){
    return new DTDepartamento(this->letra, this->nombre);
}

ICollection * Departamento::listarZonasDepartamento(){
    ICollection * zonas = new List();
    IIterator * it = this->zonas->getIterator();
    Zona * zona;
    ICollectible * item;
    while (it->hasCurrent()){
        zona = (Zona *) it->getCurrent();
        item = (ICollectible *) zona->getDTZona();
        zonas->add(item);
        it->next();
    }
    delete it;
    return zonas;
    // ES CON ICOLLECTION
}

Zona * Departamento::elegirZona(int codigoZona){
    IKey * clave = new Integer (codigoZona);
    Zona * zona = (Zona *) this->zonas->find(clave);
    delete clave;
    if (zona != NULL){
        return zona;
    } else {
        throw invalid_argument("La zona especificada no se encuentra en el departamento actual");
    }
    // ES CON ICOLLECTION
}

//sistema
class Sistema : public ISistema{
    private:
        IDictionary * usuarios;
        IDictionary * departamentos;
        IDictionary * propiedades;
        Usuario * loggeado;
        Departamento * departamentoActual;
        Zona * zonaActual;
        Edificio * edificioActual;
        Propiedad * propiedadActual;
        Conversacion * conversacionActual;
    public:

        Sistema();
        ~Sistema();

        void iniciarSesion(char*);
        bool crearContrasenia(string, string);
        bool ingresarContrasenia(string);
        void cerrarSesion();
        ICollection * listarDepartamentos();
        bool elegirDepartamento(char *);
        ICollection * listarZonasDepartamento();
        bool elegirZona(int);
        void altaInmobiliaria(string, char*, DTDir*);
        void altaInteresado(char*, string, string, int);
        bool altaEdificio(string, int, int);
        ICollection* obtenerReporte();
        // DTTipoProp modificarPropiedad(int, Inmobiliaria *);
        // void mensajeInmobiliaria(string, DTFecha *);
        void eliminarPropiedad(int);
        ICollection * listarPropiedades();
        ICollection * listarPropiedadesInmo();
        DTPropiedadDetallada * verDetallesPropiedad(int);
        IDictionary * listarChatProp();
        IDictionary * listarChatsInmo();
        Conversacion * seleccionarConversacionInmo(int);
        // ICollection * seleccionarPropiedadMensajes(int, Zona *);
        Propiedad * seleccionarPropiedad(int);
        Conversacion * getConversacionInteresado();
        ICollection * getUltimosMensajes();
        Propiedad * seleccionarPropiedadInmobiliaria(int);
        DTTipoProp getDTTipoProp();
        void modificarCasa(int, int, int, bool, DTDir *, float, float);
        void modificarApartamento(int, int, int, bool, DTDir *, float);
        Conversacion * nuevoChat();
        void nuevoMensaje(string, DTFecha *);
        int ponerEnVenta(float valor);
        int ponerEnAlquiler(float valor);
        // void especificacionesApartamento(int cantAmb, int cantBanos, int cantDorm, int m2e, bool garage, DTDir* dir, Propiedad* propiedad, Edificio* edificio, Zona*zona);
        // void especificacionesCasa(int cantAmb, int cantBanos, int cantDorm, bool garage, DTDir* dir, int m2e, int m2v,Propiedad* propiedad, Zona* zona);
        void especificacionesApartamento(int, int, int, bool, float, DTDir*, Edificio*, Zona*);
        void especificacionesCasa(int, int, int, bool, DTDir*, float, Zona*, float);
        ICollection* listarEdificio();
        bool seleccionarEdificio(int);
        // void AltaPropiedad();

        // Operaciones del sistema (fuera de los diagramas de comunicacion)
        void enlazarPropiedad(Propiedad *);
        void desvincularPropiedad(int);
        Usuario * getLoggeado();
        IDictionary * getUsuarios();

        void setDepartamentoActual(Departamento*);
        void setZonaActual(Zona*);
        void setEdificioActual(Edificio*);
        void setPropiedadActual(Propiedad*);
        void setConversacionActual(Conversacion*);

        Departamento* getDepartamentoActual();
        Zona* getZonaActual();
        Edificio* getEdificioActual();
        Propiedad* getPropiedadActual();
        Conversacion* getConversacionActual();
        IDictionary* getDepartamentos();
};
Sistema::Sistema(){
    this->usuarios = new OrderedDictionary();
    this->departamentos = new OrderedDictionary();
    this->propiedades = new OrderedDictionary();
    this->loggeado = NULL;
    this->departamentoActual = NULL;
    this->zonaActual = NULL;
    this->propiedadActual = NULL;
    this->edificioActual = NULL;
    this->conversacionActual = NULL;

}

Sistema::~Sistema(){

}

ICollection * Sistema::listarDepartamentos(){
    ICollection * departamentos = new List();
    IIterator * it = this->departamentos->getIterator();
    Departamento * depa;
    ICollectible * item;
    while(it->hasCurrent()){
        depa = (Departamento *) it->getCurrent();
        item = (ICollectible *) depa->getDTDepartamento();
        departamentos->add(item);
        it->next();
    }
    delete it;
    if (departamentos->isEmpty()){
        throw runtime_error("No hay Departamentos registrados en el sistema");
    }
    return departamentos;
}

// ICollection * Sistema::seleccionarPropiedadMensajes(int codProp, Zona * zona){
    
//     if(zona->seleccionarPropiedad(codProp) != NULL){
//         Propiedad * prop = zona->seleccionarPropiedad(codProp);
//         return zona->getUltimosMensajes();
//     }
// }

Propiedad * Sistema::seleccionarPropiedad(int codigoProp){
    if (this->zonaActual == NULL){
        throw runtime_error("No se eligió una zona previamente");
    }
    try {
        this->propiedadActual = this->zonaActual->seleccionarPropiedad(codigoProp);
        // this->zonaActual = NULL;
        return this->propiedadActual;
    } catch(const std::exception& e) {
        throw invalid_argument("No se eligió una zona previamente");
    }
}

Conversacion * Sistema::getConversacionInteresado(){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Interesado * interesado = dynamic_cast<Interesado*> (this->loggeado);
    if (interesado == NULL){
        throw runtime_error("El usuario ingresado no es Interesado");
    }
    if (this->propiedadActual == NULL){
        throw runtime_error("No se eligió una propiedad previamente");
    }
    this->conversacionActual = this->propiedadActual->getConversacion(this->loggeado->getCorreoEletronico());
    // this->propiedadActual = NULL;
    return this->conversacionActual;
}

ICollection * Sistema::getUltimosMensajes(){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    if (this->conversacionActual == NULL){
        throw runtime_error("No se eligió una conversación previamente");
    }
    ICollection * mensajes = this->conversacionActual->getUltimosMensajes();
    return mensajes;
}

Conversacion * Sistema::nuevoChat(){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Interesado * usuario = dynamic_cast<Interesado*> (this->loggeado);
    if (usuario == NULL){
        throw runtime_error("El usuario ingresado no es Interesado");
    }
    if (this->conversacionActual == NULL){
        throw runtime_error("No se eligió una conversación previamente");
    }
    try {
        this->conversacionActual = this->propiedadActual->nuevoChat(usuario); // CAMBIE ESTO (LE AGREUGUE EL INTERESADO POR PARAMETRO)
        // this->propiedadActual = NULL;
        return this->conversacionActual;
    } catch(const std::exception& e) {
        throw runtime_error("La conversacion ya fue agregado con anterioridad");
    }
}

void Sistema::nuevoMensaje(string mensaje, DTFecha * fecha){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    if (this->conversacionActual == NULL){
        throw runtime_error("No se eligió una conversación previamente");
    }
    this->conversacionActual->nuevoMensaje(fecha, mensaje);
    // this->conversacionActual = NULL;
}

IDictionary * Sistema::listarChatsInmo(){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * usuario = dynamic_cast<Inmobiliaria*> (this->loggeado);
    if (usuario == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    // Podemos lanzar un error en caso de que la lista este vacía
    IDictionary * lista = usuario->listarConversaciones();
    if (lista->isEmpty()){
        throw runtime_error("La Inmobiliaria actual no tiene ninguna conversación relacionada");
    }
    return lista; 
}

Conversacion * Sistema::seleccionarConversacionInmo(int codigoCon){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * usuario = dynamic_cast<Inmobiliaria*> (this->loggeado);
    if (usuario == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    try {
        this->conversacionActual = usuario->seleccionarConversacion(codigoCon);
        return this->conversacionActual;
    } catch(const exception& e) {
        throw invalid_argument("No existe una conversación con ese código vinculada a la Inmobiliaria actual");
    }
}

bool Sistema::elegirDepartamento(char * letraDepartamento){
    IKey * clave = new String (letraDepartamento);
    Departamento * depa = (Departamento *) this->departamentos->find(clave);
    delete clave;
    if(depa != NULL){
        this->departamentoActual = depa;
        return true;
    } else {
        throw invalid_argument("El Departamento especificado no se encuentra en el Sistema");
    }
}

ICollection * Sistema::listarZonasDepartamento(){
    if (this->departamentoActual == NULL){
        throw runtime_error("No se eligió un Departamento previamente");
    }
    ICollection * zonas = this->departamentoActual->listarZonasDepartamento();
    if (zonas->isEmpty()){
        throw runtime_error("No existen Zonas establecidas en el Departamento actual");
    }
    return zonas;
}

IDictionary * Sistema::listarChatProp(){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    IDictionary * lista = this->zonaActual->listarChatPropiedad(this->loggeado->getCorreoEletronico());
    return lista;
}

/*
bool Sistema::elegirZona(Departamento * depa, int codigo){
    if (depa->elegirZona(codigo) != NULL)
        return true;
    else
        return false;
}
*/

bool Sistema::elegirZona(int codigo){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    try {
        this->zonaActual = this->departamentoActual->elegirZona(codigo);
        // this->departamentoActual = NULL;
        // return this->zonaActual;
        return true;
    } catch(const exception& e) {
        throw invalid_argument("La zona especificada no se encuentra en el departamento actual");
    }
}


Propiedad * Sistema::seleccionarPropiedadInmobiliaria(int codigoProp){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * inmo = dynamic_cast<Inmobiliaria*> (this->loggeado);
    if (inmo == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    try {
        this->propiedadActual = inmo->seleccionarPropiedad(codigoProp);
        return this->propiedadActual;
    } catch(const std::exception& e) {
        throw invalid_argument("La propiedad especificada no se encuentra en la Inmobiliaria actual");
    }

}

DTTipoProp Sistema::getDTTipoProp(){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    if (this->propiedadActual == NULL){
        throw runtime_error("No se eligió una propiedad previamente");
    }
    return this->propiedadActual->getDTTipoProp();
}

// DTTipoProp Sistema::modificarPropiedad(int codigoProp, Inmobiliaria * inmo){
// //feli
//     IKey * key = new Integer(codigoProp);
//     Propiedad * p = (Propiedad *) inmo->getPropiedades()->find(key);
//     return p->getDTTipoProp();
// }

void Sistema::modificarCasa(int cantAmbientes, int cantDormitorios, int cantBanios, bool tieneGaraje, DTDir * dir, float m2Edificados, float m2Verdes){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * inmo = dynamic_cast<Inmobiliaria*> (this->loggeado);
    if (inmo == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    if (this->propiedadActual == NULL){
        throw runtime_error("No se eligió una propiedad previamente");
    }
    Casa * casa = dynamic_cast<Casa*> (this->propiedadActual);
    // this->propiedadActual = NULL;
    casa->modificarCasa(cantAmbientes, cantDormitorios, cantBanios, m2Edificados, dir, tieneGaraje, m2Verdes);
}

void Sistema::modificarApartamento(int cantAmbientes, int cantDormitorios, int cantBanios, bool tieneGaraje, DTDir * dir, float m2Totales){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * inmo = dynamic_cast<Inmobiliaria*> (this->loggeado);
    if (inmo == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    if (this->propiedadActual == NULL){
        throw runtime_error("No se eligió una propiedad previamente");
    }
    Apartamento * apartamento = dynamic_cast<Apartamento*> (this->propiedadActual);
    // this->propiedadActual = NULL;
    apartamento->modificarApartamento(cantAmbientes, cantDormitorios, cantBanios, m2Totales, dir, tieneGaraje);
}

// void Sistema::mensajeInmobiliaria(string contenido, DTFecha * fecha){
//     //feli // HAY QUE SEGUIR ACAAAAAA
//     this->conversacionActual->nuevoMensaje(fecha, contenido);
// }

/* FUNCIONES PARA INICIAR SESIÓN */

void Sistema::iniciarSesion(char* email){
    IKey * key = new String(email);
    Usuario * user = (Usuario*) this->usuarios->find(key);
    delete key;
    if(user != NULL){
        this->loggeado = user;
        return;
    } else {
        system("cls");
        throw runtime_error("No existe el usuario");
    }
}

bool Sistema::crearContrasenia(string pwd, string pwd2){
    if(this->loggeado == NULL){
        system("cls");
        throw runtime_error("No hay un usuario en el sistema");
    }
    Administrador * admin = dynamic_cast<Administrador*> (this->loggeado);
    if(admin != NULL){
        system("cls");
        throw runtime_error("El usuario administrador ya tiene una contraseña establecida, consulte con el encargado");
    }
    if(pwd == pwd2){
        try {
            this->loggeado->agregarContrasenia(pwd);
            return true;
        } catch (const exception& e){
            throw runtime_error("No se pudo agregar la contraseña correctamente");   
        }
    } else {
        system("cls");
        cout << "Las contraseñas no coinciden" << endl << endl;
        return false;
    }
}

bool Sistema::ingresarContrasenia(string pwd){
    if(this->loggeado == NULL){
        system("cls");
        throw runtime_error("No hay un usuario en el sistema");
    }
    if(this->loggeado->esContraseniaCorrecta(pwd)){
        system("cls");
        cout << "Sesión iniciada con éxito" << endl << endl;
        return true;
    } else {
        system("cls");
        throw runtime_error("La contraseña introducida no es correcta");
    }
}

/* FIN DE LAS FUNCIONES PARA INICIAR SESIÓN */

/* FUNCIONES PARA CERRAR SESIÓN */

void Sistema::cerrarSesion(){
    if(this->loggeado == NULL){
        system("cls");
        throw runtime_error("No hay un usuario en el sistema");
    } else {
        this->loggeado = NULL;
    }
    return;
}

/* FIN DE LAS FUNCIONES PARA CERRAR SESIÓN */

/* FUNCIONES PARA DAR ALTA UNA INMOBILIARIA */

void Sistema::altaInmobiliaria(string nombre, char* email, DTDir* dir){
    if(this->loggeado == NULL){
        system("cls");
        throw runtime_error("No hay un usuario en el sistema");
    }
    Administrador * admin = dynamic_cast<Administrador*> (this->loggeado);
    if(admin == NULL){
        system("cls");
        throw runtime_error("El usuario ingresado no es Administrador");
    }
    IKey * key = new String(email);
    if(this->usuarios->member(key)){
        delete key;
        throw invalid_argument("Ya existe un usuario con ese correo");
    }
    Inmobiliaria * nuevaInmo = new Inmobiliaria(email, nombre, dir);
    ICollectible * inmoCasteada = (ICollectible*) nuevaInmo;
    this->usuarios->add(key, inmoCasteada);
    system("cls");
    cout << "Usuario creado con éxito" << endl << endl;
    return;
}

/* FIN DE LAS FUNCIONES PARA DAR ALTA UNA INMOBILIARIA */

/* FUNCIONES PARA DAR ALTA UN INTERESADO */

void Sistema::altaInteresado(char* email, string nom, string ape, int edad){
    if(this->loggeado == NULL){
        system("cls");
        throw runtime_error("No hay un usuario en el sistema");
    }
    Administrador * admin = dynamic_cast<Administrador*> (this->loggeado);
    if(admin == NULL){
        system("cls");
        throw runtime_error("El usuario ingresado no es Administrador");
    }
    IKey * key = new String(email);
    if(this->usuarios->member(key)){
        delete key;
        system("cls");
        throw invalid_argument("Ya existe un usuario con ese correo");
    }
    Interesado * nuevoInteresado = new Interesado(email, nom, ape, edad);
    ICollectible * interesadoCasteado = (ICollectible*) nuevoInteresado;
    this->usuarios->add(key, interesadoCasteado);
    system("cls");
    cout << "Usuario creado con éxito" << endl << endl;
    return;
}

/* FIN DE LAS FUNCIONES PARA DAR ALTA UN INTERESADO */

/* FUNCIONES PARA DAR ALTA UN EDIFICIO */

bool Sistema::altaEdificio(string nombre, int cantPisos, int gastosComunes){
    if(this->loggeado == NULL){
        system("cls");
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * inmo = dynamic_cast<Inmobiliaria*> (this->loggeado);
    if(inmo == NULL){
        system("cls");
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    if (this->zonaActual == NULL){
        throw runtime_error("No se eligió una zona previamente");
    }
    this->edificioActual = new Edificio(this->zonaActual->generarCodigoEdificio(), nombre, cantPisos, gastosComunes, this->zonaActual);
    this->zonaActual->agregarEdificio(this->edificioActual);
    return true;
}

/* FIN DE LAS FUNCIONES PARA DAR ALTA UN EDIFICIO */

/* FUNCIONES PARA DAR UN REPORTE*/

ICollection * Sistema::obtenerReporte(){
    if(this->loggeado == NULL){
        system("cls");
        throw runtime_error("No hay un usuario en el sistema");
    }
    Administrador * admin = dynamic_cast<Administrador*> (this->loggeado);
    if(admin == NULL){
        system("cls");
        throw runtime_error("El usuario ingresado no es Administrador");
    }
    IIterator * it = this->usuarios->getIterator();
    Inmobiliaria * user;
    ICollection * reportes = new List();
    while(it->hasCurrent()){
        user = dynamic_cast<Inmobiliaria*> (it->getCurrent()); // Este tengo dudas
        if(user != NULL){
            ICollectible * reporte = (ICollectible*) user->obtenerReporteInmobiliaria();
            reportes->add(reporte);
        }
        it->next();
    }
    delete it;
    return reportes;
}

/* FIN DE LAS FUNCIONES PARA DAR UN REPORTE*/

/*funciones de Alta propiedad*/

int Sistema::ponerEnVenta(float valor) {
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria* user = dynamic_cast<Inmobiliaria*> (this->loggeado);
    if (user == NULL){
        throw runtime_error("El usuario ingresado no es Administrador");
    }
    if (this->propiedadActual == NULL){
        throw runtime_error("No se eligió una propiedad previamente");
    }
    user->ponerEnVenta(this->propiedadActual, valor);
    return this->propiedadActual->getCodigo();
}

int Sistema::ponerEnAlquiler(float valor) {
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria* user = dynamic_cast<Inmobiliaria*> (this->loggeado);
    if (user == NULL){
        throw runtime_error("El usuario ingresado no es Administrador");
    }
    if (this->propiedadActual == NULL){
        throw runtime_error("No se eligió una propiedad previamente");
    }
    user->ponerEnAlquiler(this->propiedadActual, valor);
    return this->propiedadActual->getCodigo();
}



// void Sistema::especificacionesApartamento(int cantAmb, int cantBanos, int cantDorm, int m2e, bool garage, DTDir* dir, Propiedad* propiedad, Edificio* edificio, Zona*zona) {
//     // Apartamento* apartamento = (Apartamento*) propiedad;
//     apartamento = edificio->crearApartamento(cantAmb, cantBanos, cantDorm, garage, dir, m2e);
//     edificio->enlazarPropiedad(apartamento);
//     zona->agregarPropiedad(apartamento);
//     return;
//     //propiedad->vincularZona(zona); ??
//     //propiedad->vincularEdificio(edificio); ??
// }

void Sistema::especificacionesApartamento(int cantAmb, int cantDorm, int cantBanos, bool garage, float m2e, DTDir* dir, Edificio* edificio, Zona*zona) {
    if (cantAmb < 0 || cantDorm < 0 || cantBanos < 0 || m2e < 0) {
        throw std::runtime_error("Los valores no pueden ser negativos");
    }
    Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*> (this->loggeado);
    if (inmo == NULL){
        throw runtime_error("El usuario ingresado no es Administrador");
    }
    Apartamento *apartamento = NULL;
    apartamento = edificio->crearApartamento(cantAmb, cantDorm, cantBanos, m2e, dir, garage);
    edificio->enlazarPropiedad(apartamento);
    zona->enlazarPropiedad(apartamento);
    this->enlazarPropiedad(apartamento);
    inmo->agregarPropiedad(apartamento);
    this->propiedadActual = apartamento;
    //return apartamento
}

void Sistema::especificacionesCasa(int cantAmb, int cantDorm, int cantBanos, bool garage, DTDir* dir, float m2e, Zona* zona, float m2v) {
    if (cantAmb < 0 || cantDorm < 0 || cantBanos < 0 || m2e < 0 || m2v < 0) {
        throw std::runtime_error("Los valores no pueden ser negativos");
    }
    if (cantAmb < 0 || cantDorm < 0 || cantBanos < 0 || m2e < 0) {
        throw std::runtime_error("Los valores no pueden ser negativos");
    }
    Inmobiliaria* inmo = dynamic_cast<Inmobiliaria*> (this->loggeado);
    if (inmo == NULL){
        throw runtime_error("El usuario ingresado no es Administrador");
    }
    Casa *casa = NULL;
    casa = zona->crearCasa(cantAmb, cantDorm, cantBanos, m2e, dir, garage, m2v);
    zona->enlazarPropiedad(casa);
    this->enlazarPropiedad(casa);
    inmo->agregarPropiedad(casa);
    this->propiedadActual = casa;
    //return casa;
}

// void Sistema::especificacionesCasa(int cantAmb, int cantBanos, int cantDorm, bool garage, DTDir* dir, int m2e, int m2v, Propiedad* propiedad, Zona* zona) {
//     Casa* casa = (Casa*) propiedad;
//     casa = zona->crearCasa(cantAmb, cantBanos,cantDorm, garage,dir, m2e, m2v);
//     zona->agregarPropiedad(casa);
//     return;
//     //propiedad->vincularZona(zona) ??
// }


ICollection* Sistema::listarEdificio() {
    return this->zonaActual->listarEdificios();
}

bool Sistema::seleccionarEdificio(int numEdificio) {
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    if (this->zonaActual == NULL){
        throw runtime_error("No se eligió una zona previamente");
    }
    try {
        this->zonaActual->seleccionarEdificio(numEdificio);
        this->edificioActual = this->zonaActual->seleccionarEdificio(numEdificio);
        // this->zonaActual = NULL;
        return true;
    } catch(const std::exception& e) {
        throw invalid_argument("El edificio especificado no se encuentra en la zona actual");
    }
}




// void Sistema:: AltaPropiedad() { 
//     system("cls");

//    //chequear usuario
//     if(this->loggeado == NULL){
//         system("cls");
//         throw runtime_error("No hay un usuario en el sistema");
//     }
//     Inmobiliaria * inmo = dynamic_cast<Inmobiliaria*> (this->loggeado);
//     if(inmo == NULL){
//         system("cls");
//         throw runtime_error("El usuario ingresado no es Inmobiliaria");
//     }

//     //elegir departamento
//     ICollection* listaDeps = this->listarDepartamentos();
//     char * letraDepa;
//     cout << "Ingresar identificación del departamento:" << endl;
//     cin >> letraDepa;
//     system("cls");
   
//     if (elegirDepartamento(letraDepa)){ 
//         //elegir zona
//         ICollection * listaZonas = listarZonasDepartamento(); 
//         cout << "Ingresar identificación de la zona:" << endl;
//         int numZona;
//         cin >> numZona;
//         system("cls");
        
//         if(this->elegirZona(numZona)){ 
//             cout << "Ingrese tipo de propiedad" << endl;
//             cout << "1. Casa" << endl;
//             cout << "2. Apartamento" << endl;
//             int opcion;
//             cin >> opcion;
//             system("cls");

//             //si es apartamento
//             if (opcion == 2) {
//                 ICollection* listaEdificios = listarEdificio(); //la zona devuelve sus edificios
//                 cout << "¿Desea seleccionar un nuevo edificio?" << endl;
//                 cout << "1. Si" << endl;
//                 cout << "2. No" << endl;
//                 int opcion;
//                 cin >> opcion;
//                 system("cls");

//                 //agrega edificio
//                 if (opcion == 1) {
//                     string nombre;
//                     int pisos, gastosC;
//                     cout << "Ingrese nombre del edificio" << endl;
//                     cin >> nombre;
//                     system("cls");
//                     cout << "Ingrese la cantidad de pisos" << endl;
//                     cin >> nombre;
//                     system("cls");
//                     cout << "Ingrese los gastos comunes" << endl;
//                     cin >> nombre;
//                     system("cls");
//                     bool res = altaEdificio(nombre, pisos, gastosC); //Como es un bool no se que hacer
//                 }

//                 //seleccionar edificio
//                 int numEdificio;
//                 cout << "Ingresar identificación del edificio:" << endl;
//                 cin >> numEdificio;
//                 system("cls");
//                 if (seleccionarEdificio(numEdificio)) { 
//                     int cantAmb, cantBanos, cantDorm, numero;
//                     float m2t;
//                     string calle, ciudad;
//                     bool garage = false;
//                     int opcion;
//                     cout << "Ingresar calle:" << endl;
//                     cin >> calle; 
//                     system("cls");
//                     cout << "Ingresar numero:" << endl;
//                     cin >> numero;
//                     system("cls");
//                     cout << "Ingresar ciudad:" << endl;
//                     cin >> ciudad;
//                     system("cls");
//                     DTDir* dir = new DTDir(calle, numero, ciudad);
//                     cout << "Ingresar cantidad de ambientes:" << endl;
//                     cin >> cantAmb;
//                     system("cls");
//                     cout << "Ingresar cantidad de banos:" << endl;
//                     cin >> cantBanos;
//                     system("cls");
//                     cout << "Ingresar cantidad de dormitorios:" << endl;
//                     cin >> cantDorm;
//                     system("cls");
//                     cout << "Ingresar si tiene garage:" << endl;
//                     cout << "1. Si" << endl;
//                     cout << "2. No";
//                     cin >> opcion;
//                     system("cls");
//                     if (opcion == 1) 
//                         garage = true;
//                     cout << "Ingresar metros cuadrados edificados:" << endl;
//                     cin >> m2t;
//                     system("cls");
//                     especificacionesApartamento(cantAmb, cantBanos, cantDorm, m2t, garage, dir, this->edificioActual, this->zonaActual);
//                 }
//             }
//             else if (opcion == 1) {
//                 int cantAmb, cantBanos, cantDorm, numero;
//                 float m2v, m2e;
//                 string ciudad, calle;
//                 bool garage = false;
//                 int opcion;
//                 cout << "Ingresar calle:" << endl;
//                 cin >> calle;
//                 system("cls");
//                 cout << "Ingresar numero:" << endl;
//                 cin >> numero;
//                 system("cls");
//                 cout << "Ingresar ciudad:" << endl;
//                 cin >> ciudad;
//                 system("cls");
//                 DTDir* dir = new DTDir(calle, numero, ciudad);
//                 cout << "Ingresar cantidad de ambientes:" << endl;
//                 cin >> cantAmb;
//                 system("cls");
//                 cout << "Ingresar cantidad de banos:" << endl;
//                 cin >> cantBanos;
//                 system("cls");
//                 cout << "Ingresar cantidad de dormitorios:" << endl;
//                 cin >> cantDorm;
//                 system("cls");
//                 cout << "Ingresar si tiene garage:" << endl;
//                 cout << "1. Si" << endl;
//                 cout << "2. No";
//                 cin >> opcion;
//                 system("cls");
//                 if (opcion == 1) 
//                     garage = true;
//                 cout << "Ingresar metros cuadrados edificados:" << endl;
//                 cin >> m2e;
//                 system("cls");
//                 cout << "Ingresar metros cuadrados verdes:" << endl;
//                 cin >> m2v;
//                 system("cls");
//                 especificacionesCasa(cantAmb, cantDorm, cantBanos, garage, dir, m2e, this->zonaActual, m2v);
//             }
//             cout << "1. Poner en venta" << endl;
//             cout << "2. Poner en alquiler" << endl;
//             int option;
//             cin >> option;
//             system("cls");
//             if (option == 1) {
//                 float valor;
//                 cout << "Ingrese valor" << endl;
//                 cin >> valor;
//                 system("cls");
//                 int codigo = ponerEnVenta(valor);
//                 cout << "La propiedad ha sido ingresada exitosamente, su codigo de propiedad es " << codigo << endl;
//                 return;
//             }
//             if (option == 2) {
//                 float valor;
//                 cout << "Ingrese valor" << endl;
//                 cin >> valor;
//                 system("cls");
//                 int codigo = ponerEnAlquiler(valor);
//                 cout << "La propiedad ha sido ingresada exitosamente, su codigo de propiedad es "<< codigo << endl;
//                 return;
//             }
//             this->propiedadActual = NULL;
//         }

//     }
//     Departamento* departamento = nullptr;
//     Zona* zona = nullptr;
//     Edificio* edificio = nullptr;
//     Propiedad* propiedad = nullptr;
// }

        
/* FUNCION ELIMINAR PROPIEDAD */

void Sistema::eliminarPropiedad(int codigoProp){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * inmo = dynamic_cast<Inmobiliaria*> (this->loggeado);
    if (inmo == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    IKey * key = new Integer(codigoProp);
    if (inmo->getPropiedades()->member(key)){
        Propiedad * prop = (Propiedad * ) inmo->getPropiedades()->find(key);
        inmo->getPropiedades()->remove(key);
        delete key;
        // prop->desvincularDeZona();
        // Apartamento * ap = (Apartamento *) prop;
        // if (ap != NULL){
        //     ap->desvincularDeEdificio();
        // }
        // prop->destruirConversaciones();
        inmo->destruirAlquiler(prop); // DEVUELVE ERROR SI NO TIENE ALQUILER
        inmo->destruirVenta(prop); // DEVUELVE ERROR SI NO TIENE VENTA
        delete prop;
    } else {
        delete key;
        throw invalid_argument("No tienes una propiedad registrada con dicho código");
    }
}

/* FIN DE ELIMINAR PROPIEDAD */

/* FUNCIONES PARA CONSULTAR PROPIEDAD */

ICollection * Sistema::listarPropiedades(){
    if (this->zonaActual == NULL){
        throw runtime_error("No se eligió un Departamento previamente");
    }
    return this->zonaActual->listarPropiedades();
}

ICollection * Sistema::listarPropiedadesInmo(){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * inmo = dynamic_cast<Inmobiliaria*> (this->loggeado);
    if (inmo == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    ICollection * lista = inmo->listarPropiedades();
    if (lista->isEmpty()){
        throw runtime_error("La Inmobiliaria actual no tiene ninguna propiedad en su posesión");
    }
}

DTPropiedadDetallada * Sistema::verDetallesPropiedad(int codigoProp){
    try {
        return this->zonaActual->verDetallesPropiedad(codigoProp);
    } catch(const std::exception& e) {
        throw invalid_argument("La propiedad especificada no se encuentra en la zona actual");
    }
}

/* FIN DE FUNCIONES PARA CONSULTAR PROPIEDAD */

/* OPERACIONES DEL SISTEMA (FUERA DE LOS DIAGRAMAS DE COMUNICACION) */

void Sistema::enlazarPropiedad(Propiedad * propiedad){
    IKey * nuevaKey = new Integer (propiedad->getCodigo());
    if (!this->propiedades->member(nuevaKey)){
        ICollectible * nuevaPropiedad = (ICollectible *) propiedad;
        this->propiedades->add(nuevaKey, nuevaPropiedad);
        // this->cantPropiedades++;
        // cout << "La propiedad fue agregado exitosamente!" << endl;
    } else {
        delete nuevaKey;
        throw invalid_argument("La propiedad ya fue agregado con anterioridad");
    }
}

void Sistema::desvincularPropiedad(int codigoProp){
    IKey * clave = new Integer (codigoProp);
    if (this->propiedades->member(clave)){
        this->propiedades->remove(clave);
        // this->cantPropiedades--;
        delete clave;
        cout << "La propiedad fue removida de manera exitosa!" << endl;
    } else {
        delete clave;
        throw invalid_argument("La propiedad especificada no se encuentra en la zona actual");
    }
}

Usuario * Sistema::getLoggeado(){
    return this->loggeado;
}

IDictionary * Sistema::getUsuarios(){
    return this->usuarios;
}

void Sistema::setDepartamentoActual(Departamento* depa){
    this->departamentoActual = depa;
}

void Sistema::setZonaActual(Zona* zona){
    this->zonaActual = zona;
}

void Sistema::setEdificioActual(Edificio* edificio){
    this->edificioActual = edificio;
}

void Sistema::setPropiedadActual(Propiedad* prop){
    this->propiedadActual = prop;
}

void Sistema::setConversacionActual(Conversacion* conversacion){
    this->conversacionActual = conversacion;
}

Departamento* Sistema::getDepartamentoActual(){
    return this->departamentoActual;
}

Zona* Sistema::getZonaActual(){
    return this->zonaActual;
}

Edificio* Sistema::getEdificioActual(){
    return this->edificioActual;
}

Propiedad* Sistema::getPropiedadActual(){
    return this->propiedadActual;
}

Conversacion* Sistema::getConversacionActual(){
    return this->conversacionActual;
}

IDictionary* Sistema::getDepartamentos(){
    return this->departamentos;
}

//isistema
class ISistema{
    public:
        ISistema();
        virtual ~ISistema();

        virtual void iniciarSesion(char*) = 0;
        virtual bool crearContrasenia(string, string) = 0;
        virtual bool ingresarContrasenia(string) = 0;
        virtual void cerrarSesion() = 0;
        virtual ICollection * listarDepartamentos() = 0;
        virtual bool elegirDepartamento(char *) = 0;
        virtual ICollection * listarZonasDepartamento() = 0;
        virtual bool elegirZona(int) = 0;
        virtual void altaInmobiliaria(string, char*, DTDir*) = 0;
        virtual void altaInteresado(char*, string, string, int) = 0;
        virtual bool altaEdificio(string, int, int) = 0;
        virtual ICollection* obtenerReporte() = 0;
        virtual void eliminarPropiedad(int) = 0;
        virtual ICollection * listarPropiedades() = 0;
        virtual ICollection * listarPropiedadesInmo() = 0;
        virtual DTPropiedadDetallada * verDetallesPropiedad(int) = 0;
        virtual IDictionary * listarChatProp() = 0;
        virtual IDictionary * listarChatsInmo() = 0;
        virtual Conversacion * seleccionarConversacionInmo(int) = 0;
        virtual Propiedad * seleccionarPropiedad(int) = 0;
        virtual Conversacion * getConversacionInteresado() = 0;
        virtual ICollection * getUltimosMensajes() = 0;
        virtual Propiedad * seleccionarPropiedadInmobiliaria(int) = 0;
        virtual DTTipoProp getDTTipoProp() = 0;
        virtual void modificarCasa(int, int, int, bool, DTDir *, float, float) = 0;
        virtual void modificarApartamento(int, int, int, bool, DTDir *, float) = 0;
        virtual Conversacion * nuevoChat() = 0;
        virtual void nuevoMensaje(string, DTFecha *) = 0;
        virtual int ponerEnVenta(float valor) = 0;
        virtual int ponerEnAlquiler(float valor) = 0;
        virtual void especificacionesApartamento(int, int, int, bool, float, DTDir*, Edificio*, Zona*) = 0;
        virtual void especificacionesCasa(int, int, int, bool, DTDir*, float, Zona*, float) = 0;
        virtual ICollection* listarEdificio() = 0;
        virtual bool seleccionarEdificio(int) = 0;
        // virtual void AltaPropiedad() = 0;

        // Operaciones del sistema (fuera de los diagramas de comunicacion)
        virtual void enlazarPropiedad(Propiedad *) = 0;
        virtual void desvincularPropiedad(int) = 0;
        virtual Usuario * getLoggeado() = 0;
        virtual IDictionary * getUsuarios() = 0;

        virtual void setDepartamentoActual(Departamento*) = 0;
        virtual void setZonaActual(Zona*) = 0;
        virtual void setEdificioActual(Edificio*) = 0;
        virtual void setPropiedadActual(Propiedad*) = 0;
        virtual void setConversacionActual(Conversacion*) = 0;

        virtual Departamento* getDepartamentoActual() = 0;
        virtual Zona* getZonaActual() = 0;
        virtual Edificio* getEdificioActual() = 0;
        virtual Propiedad* getPropiedadActual() = 0;
        virtual Conversacion* getConversacionActual() = 0;
        virtual IDictionary* getDepartamentos() = 0;
};
ISistema::ISistema(){
}

ISistema::~ISistema(){}

//sistemafactory
class Factory{
    private:
        Sistema * sistema;
    public:
        Factory();
        ~Factory();

        ISistema * getISistema();
};
Factory::Factory(){
    this->sistema = NULL;
}

ISistema * Factory::getISistema(){
    if(this->sistema == NULL){
        this->sistema = new Sistema();
    }
    return this->sistema;
}
