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

void imprimirZonasDepto(IDictionary * col){
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

int main() {
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
    Zona * zona1 = new Zona(1, "SantaLu");
    Zona * zona2 = new Zona(2, "SanJo");
    Zona * zona3 = new Zona(3, "CaneLondon");

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

    cout << "hola mundo" << endl;
    system("pause");
    return 0;
}

void manejarIniciarSesion(Sistema * sistema){
    system("clear");
    char* email;
    cout << "Inicie sesión con una cuenta" << endl << endl;
    cout << "Ingrese email" << endl << endl;
    cin >> email;
    try {
        sistema->iniciarSesion(email);
    } catch (const exception& e){
        system("clear");
        cout << "Error de ejecución: " << e.what() << endl;
    }
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
    char* email;
    char* nombre;
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
    char* email;
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

    system("clear");

    cout << "Ingrese la edad" << endl << endl;
    cin >> edad;
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

    char* opt;

    cout << "Elija uno de los departamentos listados debabajo" << endl;
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

    system("clear");

    cout << "Ingrese la cantidad de pisos" << endl << endl;
    cin >> cantPisos;

    system("clear");

    cout << "Ingrese los gastos comunes" << endl << endl;
    cin >> gastosComunes;

    try{
        sistema->altaEdificio(nombre, cantPisos, gastosComunes, zona); // No sé de dónde sacar la zona
    } catch (const exception& e){
        system("clear");
        cout << "Error de ejecución: " << e.what() << endl;
    }
}

void manejarAltaPropiedad(){

}

void manejarConsultarPropiedad(){

}

void modificarPropiedad(){

}

void eliminarPropiedad(int){

}

void manejarEnviarMensajeInteresado(Sistema * sistema){
    system("clear");
    ICollection * depar = sistema->listarDepartamentos();
    char * letraDepa;
    cout<<"Ingrese la letra del Departamento"<<endl;
    cin >> letraDepa;
    if (sistema->elegirDepartamento(letraDepa) != NULL){
        ICollection * zona = sistema->listarZonasDepartamento();
        int numZona;
        cout<<"Ingrese el numero de la Zona"<<endl;
        cin >> numZona;
        if(sistema->elegirZona(numZona) != NULL){
            ICollection * chatProp = sistema->listarChatProp();
            int codProp;
            cout<<"Ingrese el codigo de la Propiedad"<<endl;
            cin >> codProp;
            if (sistema->seleccionarPropiedad(codProp) != NULL){ //si la propiedad existe
                string mensaje;
                cout<<"Ingrese el Mensaje"<<endl;
                getline(cin, mensaje);
                Conversacion * conver; //agregar bucle en caso de q el mensaje sea vacio
                IIterator *  it = sistema->getPropiedadActual()->getConversaciones();
                bool encontro = false;
                while(it->hasCurrent()){
                    conver = (Conversacion *) it->getCurrent();
                    if(conver->getInteresado() == sistema->getLoggeado()){
                        conver->nuevoMensaje(fecha, mensaje);
                        encontro = true;
                        break;
                    }
            }
        }
            
/*system("clear");
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
            ICollection * chatProp = sistema->listarChatProp(depa->elegirZona(numZona));
            int codProp;
            cout<<"Ingrese el codigo de la Propiedad"<<endl;
            cin >> codProp;
            if (sistema->seleccionarPropiedad(codProp, depa->elegirZona(numZona)) != NULL){ //si la propiedad existe
                string mensaje;
                cout<<"Ingrese el Mensaje"<<endl;
                getline(cin, mensaje);
                Conversacion * conver;
                IIterator *  it = depa->elegirZona(numZona)->seleccionarPropiedad(codProp)->getConversaciones()->getIterator();
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
                    depa->elegirZona(numZona)->seleccionarPropiedad(codProp)->nuevoChat()->nuevoMensaje(fecha, mensaje);
                }
            }
        }
    }*/
    }
}

void manejarEnviarMensajeInmobiliaria(){

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
            cout << "Departamento: " << endl; // No he implementado que el reporte guarde la letra del departamento
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
        string opt;
        cout << "Necesita iniciar sesión en el sistema" << endl << endl;
        cout << "1-Iniciar sesión" << endl << endl;
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