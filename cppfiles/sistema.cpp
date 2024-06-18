#include "../hfiles/sistema.h"
#include <iostream>
using namespace std;

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
        this->zonaActual = NULL;
        return this->propiedadActual;
    } catch(const std::exception& e) {
        throw invalid_argument("No se eligió una zona previamente");
    }
}

Conversacion * Sistema::getConversacionInteresado(){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Interesado * interesado = (Interesado *) this->loggeado;
    if (interesado == NULL){
        throw runtime_error("El usuario ingresado no es Interesado");
    }
    if (this->propiedadActual == NULL){
        throw runtime_error("No se eligió una propiedad previamente");
    }
    try {
        this->conversacionActual = this->propiedadActual->getConversacion(this->loggeado->getCorreoEletronico());
        this->propiedadActual = NULL;
        return this->conversacionActual;
    } catch(const std::exception& e) {
        throw invalid_argument("No existen conversaciones registradas con dicho usuario en esta propiedad");
    }
}

ICollection * Sistema::getUltimosMensajes(){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Interesado * interesado = (Interesado *) this->loggeado;
    if (interesado == NULL){
        throw runtime_error("El usuario ingresado no es Interesado");
    }
    if (this->conversacionActual == NULL){
        throw runtime_error("No se eligió una conversación previamente");
    }
    return this->conversacionActual->getUltimosMensajes();
}

Conversacion * Sistema::nuevoChat(){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Interesado * usuario = (Interesado *) this->loggeado;
    if (usuario == NULL){
        throw runtime_error("El usuario ingresado no es Interesado");
    }
    if (this->conversacionActual == NULL){
        throw runtime_error("No se eligió una conversación previamente");
    }
    try {
        this->conversacionActual = this->propiedadActual->nuevoChat(usuario); // CAMBIE ESTO (LE AGREUGUE EL INTERESADO POR PARAMETRO)
        this->propiedadActual = NULL;
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
    this->conversacionActual = NULL;
}

ICollection * Sistema::listarChatsInmo(){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * usuario = (Inmobiliaria *) this->loggeado;
    if (usuario == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    // Podemos lanzar un error en caso de que la lista este vacía
    return usuario->listarConversaciones();
}

Conversacion * Sistema::seleccionarConversacionInmo(int codigoCon){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * usuario = (Inmobiliaria *) this->loggeado;
    if (usuario == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    try {
        return usuario->seleccionarConversacion(codigoCon);
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
        throw invalid_argument("El Departamento especificado no se encuentra en el Sistema.");
    }
}

ICollection * Sistema::listarZonasDepartamento(){
    return this->departamentoActual->listarZonasDepartamento();
}

ICollection * Sistema::listarChatProp(){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Interesado * interesado = (Interesado *) this->loggeado;
    if (interesado == NULL){
        throw runtime_error("El usuario ingresado no es Interesado");
    }
    ICollection * lista = this->zonaActual->listarChatPropiedad(this->loggeado->getCorreoEletronico());
    if (lista->isEmpty()){
        throw runtime_error("El usuario especificado no tiene conversaciones");
    }
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
        this->departamentoActual = NULL;
        return this->zonaActual;
    } catch(const exception& e) {
        throw invalid_argument("La zona especificada no se encuentra en el departamento actual");
    }
}


Propiedad * Sistema::seleccionarPropiedadInmobiliaria(int codigoProp){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * inmo = (Inmobiliaria *) this->loggeado;
    if (inmo == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    this->propiedadActual = inmo->seleccionarPropiedad(codigoProp);
    return this->propiedadActual;
}

DTTipoProp Sistema::getDTTipoPropInmo(int codigoProp){
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
    Inmobiliaria * inmo = (Inmobiliaria *) this->loggeado;
    if (inmo == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    if (this->propiedadActual == NULL){
        throw runtime_error("No se eligió una propiedad previamente");
    }
    Casa * casa = (Casa *) this->propiedadActual;
    this->propiedadActual = NULL;
    casa->modificarCasa(cantAmbientes, cantDormitorios, cantBanios, m2Edificados, dir, tieneGaraje, m2Verdes);
}

void Sistema::modificarApartamento(int cantAmbientes, int cantDormitorios, int cantBanios, bool tieneGaraje, DTDir * dir, float m2Totales){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * inmo = (Inmobiliaria *) this->loggeado;
    if (inmo == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    if (this->propiedadActual == NULL){
        throw runtime_error("No se eligió una propiedad previamente");
    }
    Apartamento * apartamento = (Apartamento *) this->propiedadActual;
    this->propiedadActual = NULL;
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
        system("clear");
        throw runtime_error("No existe el usuario");
    }
}

bool Sistema::crearContrasenia(string pwd, string pwd2){
    if(this->loggeado == NULL){
        system("clear");
        throw runtime_error("No hay un usuario en el sistema");
    }
    Administrador * admin = (Administrador*) this->loggeado;
    if(admin == NULL){
        system("clear");
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
        throw runtime_error("La contraseña introducida no es correcta");
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
    Administrador * admin = (Administrador*) this->loggeado;
    if(admin == NULL){
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
    Administrador * admin = (Administrador*) this->loggeado;
    if(admin == NULL){
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
    Inmobiliaria * inmo = (Inmobiliaria*) this->loggeado;
    if(inmo == NULL){
        system("clear");
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    Edificio * ed = new Edificio(zona->generarCodigoEdificio(), nombre, cantPisos, gastosComunes, zona);
    zona->agregarEdificio(ed);
    return true;
}

/* FIN DE LAS FUNCIONES PARA DAR ALTA UN EDIFICIO */

/* FUNCIONES PARA DAR UN REPORTE*/

ICollection * Sistema::obtenerReporte(){
    if(this->loggeado == NULL){
        system("clear");
        throw runtime_error("No hay un usuario en el sistema");
    }
    Administrador * admin = (Administrador*) this->loggeado;
    if(admin == NULL){
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
    return reportes;
}

/* FIN DE LAS FUNCIONES PARA DAR UN REPORTE*/

/*funciones de Alta propiedad*/

int Sistema::ponerEnVenta(float valor) {
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria* user = (Inmobiliaria*) this->loggeado;
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
    Inmobiliaria* user = (Inmobiliaria*) this->loggeado;
    if (user == NULL){
        throw runtime_error("El usuario ingresado no es Administrador");
    }
    if (this->propiedadActual == NULL){
        throw runtime_error("No se eligió una propiedad previamente");
    }
    user->ponerEnAlquiler(this->propiedadActual, valor);
    return this->propiedadActual->getCodigo();
}

void Sistema::especificacionesApartamento(int cantAmb, int cantDorm, int cantBanos, bool garage, float m2e, DTDir* dir, Edificio* edificio, Zona*zona){
    Apartamento * apartamento = NULL;
    apartamento = edificio->crearApartamento(cantAmb, cantDorm, cantBanos, m2e, dir, garage);
    edificio->enlazarPropiedad(apartamento);
    zona->enlazarPropiedad(apartamento);
    this->enlazarPropiedad(apartamento);
    //return apartamento
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

void Sistema::especificacionesCasa(int cantAmb, int cantDorm, int cantBanos, bool garage, DTDir* dir, float m2e, Zona* zona, float m2v){
    Casa * casa = NULL;
    casa = zona->crearCasa(cantAmb, cantDorm, cantBanos, m2e, dir, garage, m2v);
    zona->enlazarPropiedad(casa);
    this->enlazarPropiedad(casa);
    //return casa;
}

// void Sistema::especificacionesCasa(int cantAmb, int cantBanos, int cantDorm, bool garage, DTDir* dir, int m2e, int m2v, Propiedad* propiedad, Zona* zona) {
//     Casa* casa = (Casa*) propiedad;
//     casa = zona->crearCasa(cantAmb, cantBanos,cantDorm, garage,dir, m2e, m2v);
//     zona->agregarPropiedad(casa);
//     return;
//     //propiedad->vincularZona(zona) ??
// }


ICollection* Sistema::listarEdificio(Zona * zona) {
    return zona->listarEdificios();
}

bool Sistema::seleccionarEdificio(int numEdificio, Zona* zona, Edificio* edificio) {
    if (zona->seleccionarEdificio(numEdificio) != NULL) {
        edificio = zona->seleccionarEdificio(numEdificio);
        return true;
    }
    else
        return false;
}


void Sistema:: AltaPropiedad() { //sería para el main?
    system("clear");

    Departamento* departamento = nullptr;
    Zona* zona = nullptr;
    Edificio* edificio = nullptr;
    Propiedad* propiedad = nullptr;

    if(this->loggeado == NULL){
        system("clear");
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * inmo = (Inmobiliaria*) this->loggeado;
    if(inmo == NULL){
        system("clear");
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }

    ICollection* listaDeps = this->listarDepartamentos();
    char * letraDepa;
    cout << "Ingresar identificación del departamento:" << endl;
    cin >> letraDepa;
    system("clear");
    // if (elegirDepartamento(letraDepa, departamento)){
    if (elegirDepartamento(letraDepa)){ //HABRIA QUE MODIFICAR elegirDepartamento. devuelve true si letraDepa existe y en ese caso incializa departamento
        ICollection * listaZonas = listarZonasDepartamento(); //departamento lista sus zonas
        cout << "Ingresar identificación de la zona:" << endl;
        int numZona;
        cin >> numZona;
        system("clear");
        // if(this->elegirZona(numZona, departamento, zona)){ asi estaba antes
        if(this->elegirZona(numZona)){ // HABRIA QUE MODIFICAR elegirZona. devuelve true si numZona existe en las zonas de departamento e inicializa zona
            cout << "Ingrese tipo de propiedad" << endl;
            cout << "1. Casa" << endl;
            cout << "2. Apartamento" << endl;
            int opcion;
            cin >> opcion;
            system("clear");
            if (opcion == 2) {
                ICollection* listaEdificios = listarEdificio(zona); //la zona devuelve sus edificios
                cout << "¿Desea seleccionar un nuevo edificio?" << endl;
                cout << "1. Si" << endl;
                cout << "2. No" << endl;
                int opcion;
                cin >> opcion;
                system("clear");
                if (opcion == 1) {
                    string nombre;
                    int pisos, gastosC;
                    cout << "Ingrese nombre del edificio" << endl;
                    cin >> nombre;
                    system("clear");
                    cout << "Ingrese la cantidad de pisos" << endl;
                    cin >> nombre;
                    system("clear");
                    cout << "Ingrese los gastos comunes" << endl;
                    cin >> nombre;
                    system("clear");
                    altaEdificio(nombre, pisos, gastosC, zona);
                }

                int numEdificio;
                cout << "Ingresar identificación del edificio:" << endl;
                cin >> numEdificio;
                system("clear");
                if (seleccionarEdificio(numEdificio, zona, edificio)) { //devuelve true si el edificio existe e inicializa edificio
                    int cantAmb, cantBanos, cantDorm, numero;
                    float m2t;
                    string calle, ciudad;
                    bool garage = false;
                    int opcion;
                    cout << "Ingresar calle:" << endl;
                    cin >> calle; 
                    system("clear");
                    cout << "Ingresar numero:" << endl;
                    cin >> numero;
                    system("clear");
                    cout << "Ingresar ciudad:" << endl;
                    cin >> ciudad;
                    system("clear");
                    DTDir* dir = new DTDir(calle, numero, ciudad);
                    cout << "Ingresar cantidad de ambientes:" << endl;
                    cin >> cantAmb;
                    system("clear");
                    cout << "Ingresar cantidad de banos:" << endl;
                    cin >> cantBanos;
                    system("clear");
                    cout << "Ingresar cantidad de dormitorios:" << endl;
                    cin >> cantDorm;
                    system("clear");
                    cout << "Ingresar si tiene garage:" << endl;
                    cout << "1. Si" << endl;
                    cout << "2. No";
                    cin >> opcion;
                    system("clear");
                    if (opcion == 1) 
                        garage = true;
                    cout << "Ingresar metros cuadrados edificados:" << endl;
                    cin >> m2t;
                    system("clear");
                    especificacionesApartamento(cantAmb, cantBanos, cantDorm, m2t, garage, dir, edificio, zona);
                }
            }
            else if (opcion == 1) {
                int cantAmb, cantBanos, cantDorm, numero;
                float m2v, m2e;
                string ciudad, calle;
                bool garage = false;
                int opcion;
                cout << "Ingresar calle:" << endl;
                cin >> calle;
                system("clear");
                cout << "Ingresar numero:" << endl;
                cin >> numero;
                system("clear");
                cout << "Ingresar ciudad:" << endl;
                cin >> ciudad;
                system("clear");
                DTDir* dir = new DTDir(calle, numero, ciudad);
                cout << "Ingresar cantidad de ambientes:" << endl;
                cin >> cantAmb;
                system("clear");
                cout << "Ingresar cantidad de banos:" << endl;
                cin >> cantBanos;
                system("clear");
                cout << "Ingresar cantidad de dormitorios:" << endl;
                cin >> cantDorm;
                system("clear");
                cout << "Ingresar si tiene garage:" << endl;
                cout << "1. Si" << endl;
                cout << "2. No";
                cin >> opcion;
                system("clear");
                if (opcion == 1) 
                    garage = true;
                cout << "Ingresar metros cuadrados edificados:" << endl;
                cin >> m2e;
                system("clear");
                cout << "Ingresar metros cuadrados verdes:" << endl;
                cin >> m2v;
                system("clear");
                especificacionesCasa(cantAmb, cantDorm, cantBanos, garage, dir, m2e, zona, m2v);
            }
            cout << "1. Poner en venta" << endl;
            cout << "2. Poner en alquiler" << endl;
            int option;
            cin >> option;
            system("clear");
            if (option == 1) {
                float valor;
                cout << "Ingrese valor" << endl;
                cin >> valor;
                system("clear");
                int codigo = ponerEnVenta(valor);
                cout << "La propiedad ha sido ingresada exitosamente, su codigo de propiedad es " << codigo << endl;
                return;
            }
            if (option == 2) {
                float valor;
                cout << "Ingrese valor" << endl;
                cin >> valor;
                system("clear");
                int codigo = ponerEnAlquiler(valor);
                cout << "La propiedad ha sido ingresada exitosamente, su codigo de propiedad es "<< codigo << endl;
                return;
            }
            this->propiedadActual = NULL;
        }

    }
    Departamento* departamento = nullptr;
    Zona* zona = nullptr;
    Edificio* edificio = nullptr;
    Propiedad* propiedad = nullptr;

}

        
/* FUNCION ELIMINAR PROPIEDAD */

void Sistema::eliminarPropiedad(int codigoProp){
    if (this->loggeado == NULL){
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * inmo = (Inmobiliaria *) this->loggeado;
    if (inmo == NULL){
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }
    IKey * key = new Integer(codigoProp);
    if (inmo->getPropiedades()->member(key)){
        Propiedad * prop = (Propiedad * ) inmo->getPropiedades()->find(key);
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
    return this->zonaActual->listarPropiedades();
}

DTPropiedadDetallada * Sistema::verDetallesPropiedad(int codigoProp){
    return this->zonaActual->verDetallesPropiedad(codigoProp);
}

/* FIN DE FUNCIONES PARA CONSULTAR PROPIEDAD */

/* OPERACIONES DEL SISTEMA (FUERA DE LOS DIAGRAMAS DE COMUNICACION) */

void Sistema::enlazarPropiedad(Propiedad * propiedad){
    IKey * nuevaKey = new Integer (propiedad->getCodigo());
    if (!this->propiedades->member(nuevaKey)){
        ICollectible * nuevaPropiedad = (ICollectible *) propiedad;
        this->propiedades->add(nuevaKey, nuevaPropiedad);
        // this->cantPropiedades++;
        cout << "La propiedad fue agregado exitosamente!" << endl;
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