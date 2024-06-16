
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
#include "../ICollection/collections/List.h"
#include "../ICollection/Integer.h"
#include "../ICollection/String.h"
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
        depa = (Departamento *) it->getCurrent();
        item = (ICollectible *) depa->getDTDepartamento();
        departamentos->add(item);
        it->next();
    }
    delete it;
    return departamentos;
}

ICollection * Sistema::seleccionarPropiedad(int codProp, Zona * zona){
    
    if(zona->seleccionarPropiedad(codProp) != NULL){
        Propiedad * prop = zona->seleccionarPropiedad(codProp);
        return zona->getUltimosMensajes();
    }
}

void Sistema::nuevoChat(Propiedad * prop){
    prop->nuevoChat();
}

void Sistema::nuevoMensaje(Conversacion * conver, string mensaje, DTFecha * fecha){
    conver->nuevoMensaje(fecha, mensaje);
}

bool Sistema::elegirDepartamento(char * letraDepartamento){
    IKey * clave = new String (letraDepartamento);
    Departamento * depa = (Departamento *) this->departamentos->find(clave);
    delete clave;
    if(depa != NULL)
        return true;
    else   
        throw invalid_argument("El Departamento especificado no se encuentra en el Sistema.");
}

ICollection * Sistema::listarZonasDepartamento(Departamento * depa){
    return depa->listarZonasDepartamento();
}

ICollection * Sistema::listarChatProp(Zona * zona, char * email){
    return zona->listarChatPropiedad(email);
}

bool Sistema::elegirZona(Departamento * depa, int codigo){
    if (depa->elegirZona(codigo) != NULL)
        return true;
    else
        return false;
}

void Sistema::mensajeInteresado(Departamento * depa, Interesado * user){
    ICollection * depar = listarDepartamentos(); 
    ///
    char * letraDepa;
    cin >> letraDepa;
    if (elegirDepartamento(letraDepa) == true){
        ICollection * zona = listarZonasDepartamento(depa);
        int numZona;
        cin >> numZona;
        if(elegirZona(depa, numZona) == true){
            ICollection * chatProp = listarChatProp(depa->elegirZona(numZona), user->getCorreoEletronico());
            int codProp;
            cin >> codProp;
            if (seleccionarPropiedad(codProp, depa->elegirZona(numZona)) != NULL){ //si la propiedad existe
                string mensaje;
                cin >> mensaje;
                if (((depa->elegirZona(numZona)->seleccionarPropiedad(codProp))->getUltimosMensajes()) == NULL){// si la funcion getUltimosMensajes da null, o sea q no tiene mensajes, 
                                                                                                                //entonces no existe una conversacion y se tiene q crear una
                    (depa->elegirZona(numZona)->seleccionarPropiedad(codProp))->nuevoChat();
                    ((depa->elegirZona(numZona)->seleccionarPropiedad(codProp))->nuevoChat())->nuevoMensaje(mensaje);
                }
                else{
                    
                }  
            }
        }
    }

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
void Sistema::mensajeInmobiliaria(string contenido, DTFecha * fecha, Inmobiliaria * inmo, Conversacion * c){
    c->nuevoMensaje(fecha, contenido);
}

/* FUNCIONES PARA INICIAR SESIÓN */

void Sistema::iniciarSesion(char* email){
    IKey * key = new String(email);
    Usuario * user = (Usuario*) this->usuarios->find(key);
    delete key;
    if(user != NULL){
        Administrador * esAdmin = (Administrador*) user;
        Interesado * esInteresado = (Interesado*) user;
        Inmobiliaria * esInmobiliaria = (Inmobiliaria*) user;
        if(esAdmin != NULL){
            this->tipoUsr = "Admin";
            this->loggeado = esAdmin;
        } else if(esInteresado != NULL) {
            this->tipoUsr = "Interesado";
            this->loggeado = esInteresado;
        } else if(esInmobiliaria != NULL) {
            this->tipoUsr = "Inmobiliaria";
            this->loggeado = esInmobiliaria;
        } else {
            this->loggeado = NULL;
            this->tipoUsr = "";
            system("clear");
            throw runtime_error("No se encuentra el tipo de usuario");
            return;
        }
        return;
    } else {
        system("clear");
        throw runtime_error("No existe el usuario");
    }
}

bool Sistema::crearContrasenia(string pwd, string pwd2){
    if(this->loggeado == NULL){
        system("clear");
        throw runtime_error("No hay un usuario en el sistema");
    }
    if(this->tipoUsr == "Admin"){
        system("clear");
        throw runtime_error("El usuario administrador ya tiene una contraseña establecida, consulte con el encargado");
    }
    if(pwd == pwd2){
        this->loggeado->agregarContrasenia(pwd);
        return true;
    } else {
        system("clear");
        cout << "Las contraseñas no coinciden" << endl << endl;
        return false;
    }
}

bool Sistema::ingresarContrasenia(string pwd){
    if(this->loggeado == NULL){
        system("clear");
        throw runtime_error("No hay un usuario en el sistema");
    }
    if(this->loggeado->esContraseniaCorrecta(pwd)){
        system("clear");
        cout << "Sesión iniciada con éxito" << endl << endl;
        return true;
    } else {
        system("clear");
        cout << "Contraseña incorrecta" << endl << endl;
        return false;
    }
}

/* FIN DE LAS FUNCIONES PARA INICIAR SESIÓN */

/* FUNCIONES PARA CERRAR SESIÓN */

void Sistema::cerrarSesion(){
    if(this->loggeado == NULL){
        system("clear");
        throw runtime_error("No hay un usuario en el sistema");
    } else {
        this->loggeado = NULL;
        this->tipoUsr = "";
    }
    return;
}

/* FIN DE LAS FUNCIONES PARA CERRAR SESIÓN */

/* FUNCIONES PARA DAR ALTA UNA INMOBILIARIA */

void Sistema::altaInmobiliaria(char* nombre, char* email, DTDir* dir){
    if(this->loggeado == NULL){
        system("clear");
        throw runtime_error("No hay un usuario en el sistema");
    }
    if(this->tipoUsr != "Admin"){
        system("clear");
        throw runtime_error("El usuario ingresado no es Administrador");
    }
    IKey * key = new String(email); // No sé cómo hacer que el nombre también sea una key
    if(this->usuarios->member(key)){
        delete key;
        throw invalid_argument("Ya existe un usuario con ese correo");
    }
    Inmobiliaria * nuevaInmo = new Inmobiliaria(email, nombre, dir);
    this->usuarios->add(key, nuevaInmo);
    system("clear");
    cout << "Usuario creado con éxito" << endl << endl;
    return;
}

/* FIN DE LAS FUNCIONES PARA DAR ALTA UNA INMOBILIARIA */

/* FUNCIONES PARA DAR ALTA UN INTERESADO */

void Sistema::altaInteresado(char* email, string nom, string ape, int edad){
    if(this->loggeado == NULL){
        system("clear");
        throw runtime_error("No hay un usuario en el sistema");
    }
    if(this->tipoUsr != "Admin"){
        system("clear");
        throw runtime_error("El usuario ingresado no es Administrador");
    }
    IKey * key = new String(email);
    if(this->usuarios->member(key)){
        delete key;
        system("clear");
        throw invalid_argument("Ya existe un usuario con ese correo");
    }
    Interesado * nuevoInteresado = new Interesado(email, nom, ape, edad);
    this->usuarios->add(key, nuevoInteresado);
    system("clear");
    cout << "Usuario creado con éxito" << endl << endl;
    return;
}

/* FIN DE LAS FUNCIONES PARA DAR ALTA UN INTERESADO */

/* FUNCIONES PARA DAR ALTA UN EDIFICIO */

bool Sistema::altaEdificio(string nombre, int cantPisos, int gastosComunes, Zona * zona){
    if(this->loggeado == NULL){
        system("clear");
        throw runtime_error("No hay un usuario en el sistema");
    }
    if(this->tipoUsr != "Inmobiliaria"){
        system("clear");
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    Edificio * ed = new Edificio(zona->generarCodigoEdificio(), nombre, cantPisos, gastosComunes); // NO SÉ QUÉ CÓDIGO PONERLE, PORQUE EN TEORÍA ES AUTOGENERADO
    zona->agregarEdificio(ed);
    return true;
}

/* FIN DE LAS FUNCIONES PARA DAR ALTA UN EDIFICIO */

/* FUNCIONES PARA DAR UN REPORTE*/

void Sistema::obtenerReporte(){
    if(this->loggeado == NULL){
        system("clear");
        throw runtime_error("No hay un usuario en el sistema");
    }
    if(this->tipoUsr != "Admin"){
        system("clear");
        throw runtime_error("El usuario ingresado no es Administrador");
    }
    IIterator * it = this->usuarios->getIterator();
    Inmobiliaria * user;
    ICollection * reportes = new List();
    while(it->hasCurrent()){
        user = (Inmobiliaria *) it->getCurrent();
        if(user != NULL){
            ICollectible * reporte = (ICollectible*) user->obtenerReporteInmobiliaria();
            reportes->add(reporte);
        }
        it->next();
    }
    delete it;
}

/* FIN DE LAS FUNCIONES PARA DAR UN REPORTE*/

