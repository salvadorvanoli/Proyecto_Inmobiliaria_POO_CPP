#include <iostream>
using namespace std;

#include "ICollection/interfaces/ICollectible.h"
#include "ICollection/interfaces/ICollection.h"
#include "ICollection/interfaces/OrderedKey.h"
#include "ICollection/interfaces/IKey.h"
#include "ICollection/interfaces/IDictionary.h"
#include "ICollection/interfaces/IIterator.h"
#include "ICollection/collections/List.h"
#include "ICollection/collections/OrderedDictionary.h"
#include "ICollection/interfaces/OrderedKey.h"
#include "ICollection/Integer.h"
#include "ICollection/String.h"
#include "hfiles/inmobiliaria.h"
#include "hfiles/usuario.h"
#include "hfiles/administrador.h"
#include "hfiles/interesado.h"
#include "hfiles/departamento.h"
#include "hfiles/zona.h"
#include "hfiles/sistema.h"
#include <string>


// No está terminada, es porque lo estaba haciendo donde no era y quería guardar el código
// void iniciarSesion(){
//     system("clear");
//     string opt;
//     do{
//         system("clear");
//         cout << endl << endl << "El usuario no existe, elija un tipo e ingrese su email" << endl << endl;
//         cout << "1-Administrador" << endl;
//         cout << "2-Interesado" << endl;
//         cout << "3-Inmobiliaria" << endl << endl;
//         cin >> opt;
//     } while(opt != "1" && opt != "2" && opt != "3");
//     char* nuevoEmail;
//     system("clear");
//     cout << endl << endl << "Ahora elija su nuevo email" << endl << endl;
//     cin >> nuevoEmail;
//     IKey * searchKey = new String(nuevoEmail);
//     if(this->usuarios->member(searchKey)){
//         do{
//             system("clear");
//             cout << endl << "Este usuario ya estaba registrado, ingrese uno nuevo" << endl << endl;
//             cin >> nuevoEmail;
//             searchKey = new String(nuevoEmail);
//         } while (this->usuarios->member(searchKey));
//     }
//     if(opt == "1"){
        
//     } else if(opt == "2"){

//     } else if(opt == "3"){

//     }
// }

/*

SUPONGO QUE sistema SE LLAMA LA GLOBAL SISTEMA

void mensajeInteresado(Departamento * depa, Interesado * user, DTFecha * fecha){
    ICollection * depar = sistema->listarDepartamentos(); 
    char * letraDepa;
    cout<<"Ingrese la letra del Departamento"<<endl;
    cin >> letraDepa;
    if (sistema->elegirDepartamento(letraDepa) != NULL){
        ICollection * zona = sistema->listarZonasDepartamento(depa);
        int numZona;
        cout<<"Ingrese el numero de la Zona"<<endl;
        cin >> numZona;
        if(sistema->elegirZona(depa, numZona) != NULL){
            ICollection * chatProp = sistema->listarChatProp(depa->elegirZona(numZona), sistema->user->getCorreoEletronico());
            int codProp;
            cout<<"Ingrese el codigo de la Propiedad"<<endl;
            cin >> codProp;
            if (!sistema->seleccionarPropiedad(codProp, sistema->depa->elegirZona(numZona))->isEmpty()){ //si la propiedad existe
                string mensaje;
                cout<<"Ingrese el Mensaje"<<endl;
                cin >> mensaje;
                Conversacion * conver;
                IIterator *  it = sistema->depa->elegirZona(numZona)->seleccionarPropiedad(codProp)->getConversaciones()->getIterator();
                bool encontro = false;
                while(it->hasCurrent()){
                    conver = (Conversacion *) it->getCurrent();
                    if(conver->getInteresado() == user){
                        conver->nuevoMensaje(fecha, mensaje);
                        encontro = true;
                        break;
                    }
                    it->next();
                }
                if(!encontro){
                    sistema->depa->elegirZona(numZona)->seleccionarPropiedad(codProp)->nuevoChat()->nuevoMensaje(fecha, mensaje);
                }
            }
        }
    }

}*/

#include <ctime>

void imprimirZonasDepto(ICollection * col){
    IIterator * it = col->getIterator();
    DTZona * zona;
    while (it->hasCurrent()){
        zona = (DTZona *) it->getCurrent();
        cout << zona << endl;
        it->next();
    }
    delete it;
}

void imprimirDepto(ICollection * col){
    IIterator * it = col->getIterator();
    DTDepartamento * departamento;
    while (it->hasCurrent()){
        departamento = (DTDepartamento *) it->getCurrent();
        cout << departamento << endl;
        it->next();
    }
    delete it;
}

void imprimirEdificio(ICollection * col){
    IIterator * it = col->getIterator();
    DTEdificio * edificio;
    while (it->hasCurrent()){
        edificio = (DTEdificio *) it->getCurrent();
        cout << edificio << endl;
        it->next();
    }
    delete it;
}

void manejarIniciarSesion(Sistema * sistema){
    system("clear");
    char* email = new char[100];
    cout << "Inicie sesión con una cuenta" << endl << endl;
    cout << "Ingrese email" << endl << endl;
    cin >> email;
    try {
        sistema->iniciarSesion(email);
    } catch (const exception& e){
        system("clear");
        cout << "Error de ejecución: " << e.what() << endl;
    }
    cout << "pinga";
    system("pause");
    if(sistema->getLoggeado()->getPrimeraVez() == true){
        try{
            system("clear");
            string pwd1;
            string pwd2;
            cout << "Es su primera vez iniciando sesión" << endl;
            cout << "Establezca una contraseña segura de más de 8 caracteres" << endl << endl;
            cin >> pwd1;
            cout << "Repita la contraseña" << endl << endl;
            cin >> pwd2;
            sistema->crearContrasenia(pwd1, pwd2);
        } catch (const exception& e){
            system("clear");
            cout << "Error de ejecución: " << e.what() << endl;
        }
    }
    system("clear");
    string pwd;
    cout << "Inicie sesión con su contraseña" << endl << endl;
    cin >> pwd;
    try{
        sistema->ingresarContrasenia(pwd);
        cout << "Sesión iniciada con éxito";
    } catch (const exception& e) {
        system("clear");
        cout << "Error de ejecución: " << e.what() << endl;
    }
}

void manejarAltaInmobiliaria(Sistema * sistema){
    system("clear");
    char* email = new char[100];
    char* nombre = new char[100];
    DTDir* dir;
    string calle;
    int numero;
    string ciudad;
    cout << "Va a ingresar un usuario inmobiliaria en el sistema" << endl << endl;
    cout << "Ingrese el email" << endl << endl;
    IKey * key = new String(email);
    if(sistema->getUsuarios()->member(key)){
        cout << "Ya existe un usuario con ese correo" << endl;
        return;
    }
    system("clear");

    cout << "Ingrese ahora un nombre para la inmobiliaria" << endl << endl;
    cin >> nombre;

    system("clear");

    cout << "Ingrese calle" << endl << endl;
    cin >> calle;

    system("clear");

    cout << "Ingrese numero" << endl << endl;
    cin >> numero;

    system("clear");

    cout << "Ingrese ciudad" << endl << endl;
    cin >> ciudad;

    dir = new DTDir(calle, numero, ciudad);

    try{
        sistema->altaInmobiliaria(email, nombre, dir);
    } catch (const exception& e){
        system("clear");
        cout << "Error de ejecución: " << e.what() << endl;
    }
}

void manejarAltaInteresado(Sistema * sistema){
    system("clear");
    char* email = new char[100];
    string nombre;
    string apellido;
    int edad;
    cout << "Va a ingresar un usuario interesado en el sistema" << endl << endl;
    cout << "Ingrese el email" << endl << endl;
    IKey * key = new String(email);
    if(sistema->getUsuarios()->member(key)){
        cout << "Ya existe un usuario con ese correo" << endl;
        return;
    }
    system("clear");

    cout << "Ingrese ahora un nombre para el interesado" << endl << endl;
    cin >> nombre;

    system("clear");

    cout << "Ingrese un apellido" << endl << endl;
    cin >> apellido;

    do {
        system("clear");
        cout << "Ingrese la edad" << endl << endl;
        cin >> edad;
    } while(edad <= 0);

    try{
        sistema->altaInteresado(email, nombre, apellido, edad);
    } catch (const exception& e){
        system("clear");
        cout << "Error de ejecución: " << e.what() << endl;
    }
}

void manejarAltaEdificio(Sistema * sistema){
    system("clear");
    string nombre;
    int cantPisos;
    int gastosComunes;
    Zona* zona;

    char* opt = new char[100];

    cout << "Elija uno de los departamentos listados debababaajo" << endl;
    imprimirDepto(sistema->listarDepartamentos());
    cin >> opt;
    try{
        sistema->elegirDepartamento(opt);
    } catch(const exception& e){
        cout << "Error de ejecución: " << e.what() << endl;
        return;
    }
   
    cout << "Elija una de las zonas listadas debajo" << endl;
    imprimirZonasDepto(sistema->getDepartamentoActual()->getZonas());
    
    int optint;

    cin >> optint;

    try{
        sistema->elegirZona(optint);
    } catch(const exception& e){
        system("clear");
        cout << "Error de ejecución: " << e.what() << endl;
    }

    cout << "Elija uno de los departamentos listados abajo" << endl;
    imprimirDepto(sistema->listarDepartamentos());
    cin >> opt;
    sistema->elegirDepartamento(opt);

    cout << "Va a ingresar un edificio en el sistema" << endl << endl;
    cout << "Ingrese ahora un nombre para el edificio" << endl << endl;
    cin >> nombre;

    do {
        system("clear");
        cout << "Ingrese la cantidad de pisos" << endl << endl;
        cin >> cantPisos;
    } while(cantPisos <= 0);

    do {
        system("clear");
        cout << "Ingrese los gastos comunes" << endl << endl;
        cin >> gastosComunes;
    } while(gastosComunes <= 0);

    try{
        sistema->altaEdificio(nombre, cantPisos, gastosComunes);
        sistema->setDepartamentoActual(NULL);
        sistema->setZonaActual(NULL);

    } catch (const exception& e){
        system("clear");
        cout << "Error de ejecución: " << e.what() << endl;
    }
}

void manejarAltaPropiedad(Sistema* s){
    system("clear");

    
   //chequear usuario
    if(s->getLoggeado() == NULL){
        system("clear");
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * inmo = (Inmobiliaria*) s->getLoggeado();
    if(inmo == NULL){
        system("clear");
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }

    //elegir departamento
    imprimirDepto(s->listarDepartamentos());
    char* opt = new char[100];
    cout << "Eliga un departamento:" << endl;
    cin >> opt;
    try{
        s->elegirDepartamento(opt);
    } catch(const exception& e){
        cout << "Error de ejecución: " << e.what() << endl;
        return;
    }
    system("clear");
   

    //elegir zona
    imprimirZonasDepto(s->listarZonasDepartamento()); 
    cout << "Ingresar identificación de la zona:" << endl;
    int numZona;
    cin >> numZona;
    try{
        s->elegirZona(numZona);
    } catch(const exception& e){
        cout << "Error de ejecución: " << e.what() << endl;
        s->setDepartamentoActual(NULL);
        return;
    }

    cout << "Ingrese tipo de propiedad" << endl;
    cout << "1. Casa" << endl;
    cout << "2. Apartamento" << endl;
    int opcion;
    cin >> opcion;
    system("clear");

    //si es apartamento
    if (opcion == 2) {
        imprimirEdificio(s->listarEdificio());
        cout << "¿Desea seleccionar un nuevo edificio?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        int opcion;
        cin >> opcion;


        //agrega edificio
        if (opcion == 1) {
            system("clear");
            string nombre;
            int pisos, gastosC;
            cout << "Ingrese nombre del edificio" << endl;
            cin >> nombre;
            system("clear");
            do {
                system("clear");
                cout << "Ingrese la cantidad de pisos" << endl << endl;
                cin >> pisos;
            } while(pisos <= 0);

            do {
                system("clear");
                cout << "Ingrese los gastos comunes" << endl << endl;
                cin >> gastosC;
            } while(gastosC <= 0);
            system("clear");
            s->altaEdificio(nombre, pisos, gastosC);         
        }

        else if (opcion == 2) {
            //seleccionar edificio
            system("clear");
            imprimirEdificio(s->listarEdificio());
            cout << "Ingresar identificación del edificio:" << endl;
            int numEdificio;
            cin >> numEdificio;
        
            try{
                s->seleccionarEdificio(numEdificio); 
            } catch(const exception& e) {
            cout << "Error de ejecución: " << e.what() << endl;
            s->setDepartamentoActual(NULL);
            s->setZonaActual(NULL);
            return;
            }
        }
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
       do {
                system("clear");
                cout << "Ingrese la cantidad de ambientes" << endl << endl;
                cin >> cantAmb;
            } while(cantAmb <= 1);
        
        do {
                system("clear");
                cout << "Ingrese la cantidad de banos" << endl << endl;
                cin >> cantBanos;
            } while(cantBanos <= 0);
        do {
                system("clear");
                cout << "Ingrese la cantidad de dormitorios" << endl << endl;
                cin >> cantDorm;
            } while(cantDorm <= 0);
        system("clear");
        cout << "Ingresar si tiene garage:" << endl;
        cout << "1. Si" << endl;
        cout << "2. No";
        cin >> opcion;
        system("clear");
        if (opcion == 1) 
            garage = true;
            do {
                system("clear");
                cout << "Ingrese metros cuadrados edificados" << endl << endl;
                cin >> m2t;
            } while(m2t <= 0);
            system("clear");
            s->especificacionesApartamento(cantAmb, cantBanos, cantDorm, m2t, garage, dir, s->getEdificioActual(), s->getZonaActual());
        }

        //si es casa
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
            do {
                system("clear");
                cout << "Ingrese la cantidad de ambientes" << endl << endl;
                cin >> cantAmb;
            } while(cantAmb <= 1);
        
            do {
                system("clear");
                cout << "Ingrese la cantidad de banos" << endl << endl;
                cin >> cantBanos;
            } while(cantBanos <= 0);

            do {
                system("clear");
                cout << "Ingrese la cantidad de dormitorios" << endl << endl;
                cin >> cantDorm;
            } while(cantDorm <= 0);

            system("clear");
            cout << "Ingresar si tiene garage:" << endl;
            cout << "1. Si" << endl;
            cout << "2. No";
            cin >> opcion;
            system("clear");
            if (opcion == 1) 
                garage = true;

            do {
                system("clear");
                cout << "Ingrese metros cuadrados edificados" << endl << endl;
                cin >> m2e;
            } while(m2e <= 0);

            do {
                system("clear");
                cout << "Ingrese metros cuadrados verdes" << endl << endl;
                cin >> m2v;
            } while(m2v < 0);
            system("clear");
            s->especificacionesCasa(cantAmb, cantDorm, cantBanos, garage, dir, m2e, s->getZonaActual(), m2v);
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
                int codigo = s->ponerEnVenta(valor);
                cout << "La propiedad ha sido ingresada exitosamente, su codigo de propiedad es " << codigo << endl;
                return;
            }
            if (option == 2) {
                float valor;
                cout << "Ingrese valor" << endl;
                cin >> valor;
                system("clear");
                int codigo = s->ponerEnAlquiler(valor);
                cout << "La propiedad ha sido ingresada exitosamente, su codigo de propiedad es "<< codigo << endl;
                return;
            }
           
    s->setPropiedadActual(NULL);
    s->setDepartamentoActual(NULL);
    s->setZonaActual(NULL);
    s->setEdificioActual(NULL);
}



void manejarConsultarPropiedad(){

}

void manejarmodificarPropiedad(Sistema sistema){
    //feli
    system("clear");
    Inmobiliaria * inmo = (Inmobiliaria *) sistema.getLoggeado();
    if(inmo == NULL){
        throw invalid_argument("El usuario logeado no es Inmobiliaria");
    }
    cout<<"Ingrese el codigo de la Propiedad"<<endl;
    string linea;
    getline(cin, linea);
    int cod;
    try{
        cod = stoi(linea);
    }
    catch(const exception& e){
        throw invalid_argument("El codigo ingresado no es un numero");
    }
    system("clear");
    IKey * key = new Integer(cod);
    if(inmo->getPropiedades()->isEmpty()){
        throw invalid_argument("El usuario logeado no tiene Propiedades");
    }
    Propiedad * prop = (Propiedad *) inmo->getPropiedades()->find(key);
    if(prop == NULL){
        throw invalid_argument("No existe una Propiedad con ese codigo");
    }
    delete key;
    sistema.setPropiedadActual(prop);
    prop->getDTTipoProp(); //no  se si para que xd
    Apartamento * apto = (Apartamento *) prop;
    int cantAmbiente, cantDormitorio, cantBanios;
    float m2Edificios;
    bool tieneGaraje;
    DTDir * direccion;
    cout<<"Ingrese la cantidad Ambiente"<<endl;
    getline(cin, linea);
    try{
        cantAmbiente = stoi(linea);
    }
    catch(const exception& e){
        throw invalid_argument("La cantidad ingresada no es un numero");
    }
    system("clear");
    cout<<"Ingrese la cantidad de Dormitorios"<<endl;
    getline(cin, linea);
    try{
        cantDormitorio = stoi(linea);
    }
    catch(const exception& e){
        throw invalid_argument("La cantidad ingresada no es un numero");
    }
    system("clear");
    cout<<"Ingrese la cantidad de Banios"<<endl;
    getline(cin, linea);
    try{
        cantBanios = stoi(linea);
    }
    catch(const exception& e){
        throw invalid_argument("La cantidad ingresada no es un numero");
    }
    system("clear");
    cout<<"Ingrese los m2 de Edificio"<<endl;
    getline(cin, linea);
    try{
        m2Edificios = stof(linea);
    }
    catch(const exception& e){
        throw invalid_argument("La cantidad ingresada no es un numero");
    }
    system("clear");
    cout<<"¿La propiedad tiene garaje?"<<endl;
    cout<<"1)Si        2)No"<<endl;
    int respuesta;
    getline(cin, linea);
    try{
        respuesta = stoi(linea);
    }
    catch(const exception& e){
        throw invalid_argument("El codigo ingresado no es un numero");
    }
    switch(respuesta){
        case 1:
            tieneGaraje = true;
            break;
        case 2:
            tieneGaraje = false;
            break;
        default:
            throw invalid_argument("El numero ingresado no es una opcion");
    }
    system("clear");
    int numero;
    string calle, ciudad;
    cout<<"ingresa el numero de direccion"<<endl;
    getline(cin, linea);
    try{
        respuesta = stoi(linea);
    }
    catch(const exception& e){
        throw invalid_argument("El numero ingresado no es un numero");
    }
    system("clear");
    cout<<"ingresa la calle de la direccion"<<endl;
    getline(cin, linea);
    calle = linea;
    system("clear");
    cout<<"ingresa el ciudad de la direccion"<<endl;
    getline(cin, linea);
    ciudad = linea;
    system("clear");
    DTDir * dir = new DTDir(calle, numero, calle);
    prop->setCantAmbiente(cantAmbiente);
    prop->setCantDormitorios(cantDormitorio);
    prop->setCantBanios(cantBanios);
    prop->setM2Edificios(m2Edificios);
    prop->setTieneGaraje(tieneGaraje);
    prop->setDireccion(dir);
    if(apto == NULL){
        delete apto;
        int m2Verdes;
        cout<<"Ingrese los m2 Verdes"<<endl;
        getline(cin, linea);
        try{
            m2Verdes = stof(linea);
        }
        catch(const exception& e){
            throw invalid_argument("La cantidad ingresada no es un numero");
        }
        system("clear");
        return;
    }
}

void eliminarPropiedad(int){

}

void manejarEnviarMensajeInteresado(Sistema * sistema){
    system("clear");
    ICollection * depar = sistema->listarDepartamentos();
    char * letraDepa;
    cout<<"Ingrese la letra del Departamento"<<endl;
    cin >> letraDepa;
    if (sistema->elegirDepartamento(letraDepa)){
        ICollection * zona = sistema->listarZonasDepartamento();
        int numZona;
        cout<<"Ingrese el numero de la Zona"<<endl;
        cin >> numZona;
        if(sistema->elegirZona(numZona)){
            ICollection * chatProp = sistema->listarChatProp();
            int codProp;
            cout<<"Ingrese el codigo de la Propiedad"<<endl;
            cin >> codProp;
            if (sistema->seleccionarPropiedad(codProp)){ //si la propiedad existe
                string mensaje;
                cout<<"Ingrese el Mensaje"<<endl;
                getline(cin, mensaje);
                Conversacion * conver; //agregar bucle en caso de q el mensaje sea vacio
                IIterator *  it = (IIterator *) sistema->getPropiedadActual()->getConversaciones()->getIterator();
                bool encontro = false;
                DTFecha * FECHA; //SUPONGAMOS Q ACA VA LA FECHA DE LA COMPU O LO Q SEA
                while(it->hasCurrent()){
                    conver = (Conversacion *) it->getCurrent();
                    if(conver->getInteresado() == sistema->getLoggeado()){
                        conver->nuevoMensaje(FECHA, mensaje);
                        encontro = true;
                        break;
                    }
                    it->next();
                }
                if(!encontro){
                    Interesado * inter = (Interesado *) sistema->getLoggeado();
                    sistema->getPropiedadActual()->nuevoChat(inter)->nuevoMensaje(FECHA, mensaje);
                }
            }
            
        }
    }
    sistema->setConversacionActual(NULL);
    sistema->setDepartamentoActual(NULL);
    sistema->setEdificioActual(NULL);
    sistema->setPropiedadActual(NULL);
    sistema->setZonaActual(NULL);
}

void manejarEnviarMensajeInmobiliaria(){
    //feli
    system("clear");
}

void manejarReporte(Sistema * sistema){
    system("clear");
    ICollection * reportes;
    try {
        reportes = sistema->obtenerReporte();
    } catch (const exception& e){
        cout << "Error de ejecución: " << e.what() << endl;
    }
    int i = 1;
    IIterator * it = reportes->getIterator();
    while(it->hasCurrent()){
        DTReporte * reporte = (DTReporte*) it->getCurrent();
        cout << "Reporte: " << i << endl;
        cout << "Inmobiliaria: " << reporte->getInmo()->getNombre() << endl << endl;
        IIterator * it2 = reporte->getLineas()->getIterator();
        while(it2->hasCurrent()){
            DTLineaReporte * linea = (DTLineaReporte*) it->getCurrent();
            cout << "Departamento: " << linea->getLetraDep() << endl;
            cout << "Código de la zona: " << linea->getCodigoZona() << endl;
            cout << "Cantidad de casas: " << linea->getCantCasas() << endl;
            cout << "Cantidad de apartamentos: " << linea->getCantApartamentos() << endl << endl;
        }
        i++;
        it->next();
    }
}

void menu(Sistema * sistema){
    string opt;
    do{
        system("clear");
        cout << "Necesita iniciar sesión en el sistema" << endl << endl;
        cout << "1-Iniciar sesión" << endl << endl;
        cin >> opt;
    } while (opt != "1");

    manejarIniciarSesion(sistema);

    Administrador* admin = (Administrador*) sistema->getLoggeado();
    Inmobiliaria* inmo = (Inmobiliaria*) sistema->getLoggeado();
    Interesado* interesado = (Interesado*) sistema->getLoggeado();

    if(admin != NULL){
        do{
            system("clear");
            cout << "Elija una función del sistema" << endl << endl;
            cout << "1-Cerrar sesión" << endl;
            cout << "2-Alta inmobiliaria" << endl;
            cout << "3-Alta interesado" << endl;
            cout << "4-Obtener reporte de inmobiliaria" << endl << endl;
            cin >> opt;
        } while(opt != "1" && opt != "2" && opt != "3"  && opt != "4");
        if(opt == "1"){
            sistema->cerrarSesion();
        } else if(opt == "2"){
            manejarAltaInmobiliaria(sistema);
        } else if (opt == "3"){
            manejarAltaInteresado(sistema);
        } else if (opt == "4"){
            manejarReporte(sistema);
        } else {
            throw invalid_argument("No se encontró una opción válida");
        }
    } else if(inmo != NULL) {
        do{
            system("clear");
            cout << "Elija una función del sistema" << endl << endl;
            cout << "1-Cerrar sesión" << endl;
            cout << "2-Alta edificio" << endl;
            cout << "3-Alta propiedad" << endl;
            cout << "4-Consultar propiedad" << endl;
            cout << "5-Modificar propiedad" << endl;
            cout << "6-Eliminar propiedad" << endl;
            cout << "7-Enviar mensaje inmobiliaria" << endl << endl;
        } while(opt != "1" && opt != "2" && opt != "3" && opt != "4" && opt != "5" && opt != "6" && opt != "7");
    } else if (interesado != NULL){
        do{
            system("clear");
            cout << "Elija una función del sistema" << endl << endl;
            cout << "1-Cerrar sesión" << endl;
            cout << "2-Consultar propiedad" << endl;
            cout << "3-Enviar mensaje interesado" << endl << endl;
        } while(opt != "1" && opt != "2" && opt != "3");
    }
}


int main() {

    system("pause");

    Sistema * sistema = new Sistema();

    char* email = "s";

    Administrador * nuevoAdmin = new Administrador(email, "abc");
    ICollectible * nuevo = (ICollectible*) nuevoAdmin;

    cout << nuevoAdmin->getCorreoEletronico() << endl;
    cout << nuevoAdmin->getContrasenia() << endl;

    IKey * key = new String(nuevoAdmin->getCorreoEletronico());

    sistema->getUsuarios()->add(key, nuevo);

    system("pause");

    menu(sistema);













    /*
    // Obtener la hora actual del sistema
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    // Obtener el día, mes y año actuales
    int dia = now->tm_mday;
    int mes = now->tm_mon + 1; // Los meses van de 0 a 11, por eso se suma 1
    int año = now->tm_year + 1900; // El año se cuenta desde 1900, por eso se suma 1900

    // Obtener la hora, minuto y segundo actuales
    int hora = now->tm_hour;
    int minuto = now->tm_min;
    int segundo = now->tm_sec;

    // Imprimir los resultados
    std::cout << "Fecha actual: " << dia << "/" << mes << "/" << año << std::endl;
    std::cout << "Hora actual: " << hora << ":" << minuto << ":" << segundo << std::endl;

    Departamento * dep1 = new Departamento("A", "Canelones");
    Zona * zona1 = new Zona(1, "SantaLu", "A");
    Zona * zona2 = new Zona(2, "SanJo", "A");
    Zona * zona3 = new Zona(3, "CaneLondon", "A");

    cout << "Zona 1 es: " << endl << zona1->getDTZona() << endl;
    cout << "Zona 2 es: " << endl << zona2->getDTZona() << endl;
    cout << "Zona 3 es: " << endl << zona3->getDTZona() << endl;

    dep1->agregarZona(zona1);

    cout << "Probamos listar zonas con una zona" << endl;

    // imprimirZonasDepto(dep1->listarZonasDepartamento());

    dep1->agregarZona(zona2);
    
    cout << "Probamos listar zonas con dos zonas" << endl;

    // imprimirZonasDepto(dep1->listarZonasDepartamento());

    dep1->agregarZona(zona3);

    cout << "Probamos listar zonas con tres zonas" << endl;

    // imprimirZonasDepto(dep1->listarZonasDepartamento());

    dep1->quitarZona(2);

    cout << "Probamos listar zonas con dos zonas (una eliminada)" << endl;

    // imprimirZonasDepto(dep1->listarZonasDepartamento());

    delete zona1;
    delete zona2;
    delete zona3;
    delete dep1;

    */

    cout << "hola mundo" << endl;
    system("pause");
    return 0;
}