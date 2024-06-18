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

    imprimirZonasDepto(dep1->listarZonasDepartamento());

    dep1->agregarZona(zona2);
    
    cout << "Probamos listar zonas con dos zonas" << endl;

    imprimirZonasDepto(dep1->listarZonasDepartamento());

    dep1->agregarZona(zona3);

    cout << "Probamos listar zonas con tres zonas" << endl;

    imprimirZonasDepto(dep1->listarZonasDepartamento());

    dep1->quitarZona(2);

    cout << "Probamos listar zonas con dos zonas (una eliminada)" << endl;

    imprimirZonasDepto(dep1->listarZonasDepartamento());

    delete zona1;
    delete zona2;
    delete zona3;
    delete dep1;

    cout << "hola mundo" << endl;
    system("pause");
    return 0;
}

void manejarAltaInmobiliaria(char*, char*, DTDir){

}

void manejarAltaInteresado(char*, string, string, int){

}

void manejarAltaEdificio(string, int, int, Zona*){

}

void manejarAltaPropiedad(){

}

void manejarConsultarPropiedad(){

}

void modificarPropiedad(){

}

void eliminarPropiedad(int){

}

void manejarEnviarMensajeInteresado(){

}

void manejarEnviarMensajeInmobiliaria(){

}

void manejarReporte(){

}

void menu(Sistema * sistema){
    string opt;
    do{
        system("clear");
        string opt;
        cout << "Elija una función del sistema" << endl << endl;
        cout << "1-Iniciar sesión" << endl << endl;
    } while (opt != "1" && sistema->getLoggeado() != NULL);

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
      
        } else if (opt == "3"){

        } else if (opt == "4"){

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