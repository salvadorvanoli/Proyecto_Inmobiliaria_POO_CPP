#include <iostream>
using namespace std;

#include "hfiles/sistema.h"
#include "hfiles/sistemafactory.h"
#include <string> 
#include <ctime>

// No está terminada, es porque lo estaba haciendo donde no era y quería guardar el código
// void iniciarSesion(){
//     system("cls");
//     string opt;
//     do{
//         system("cls");
//         cout << endl << endl << "El usuario no existe, elija un tipo e ingrese su email" << endl << endl;
//         cout << "1-Administrador" << endl;
//         cout << "2-Interesado" << endl;
//         cout << "3-Inmobiliaria" << endl << endl;
//         cin >> opt;
//     } while(opt != "1" && opt != "2" && opt != "3");
//     char* nuevoEmail;
//     system("cls");
//     cout << endl << endl << "Ahora elija su nuevo email" << endl << endl;
//     cin >> nuevoEmail;
//     IKey * searchKey = new String(nuevoEmail);
//     if(this->usuarios->member(searchKey)){
//         do{
//             system("cls");
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

void imprimirEdificios(ICollection * col){
    IIterator * it = col->getIterator();
    DTEdificio * edificio;
    while (it->hasCurrent()){
        edificio = (DTEdificio *) it->getCurrent();
        cout << edificio << endl;
        it->next();
    }
    delete it;
}

void imprimirProps(ICollection * col){
    IIterator * it = col->getIterator();
    DTPropiedad * prop;
    while (it->hasCurrent()){
        prop = (DTPropiedad *) it->getCurrent();
        cout << prop << endl;
        it->next();
    }
    delete it;
}

void imprimirPropsDetalladas(ICollection * col){
    IIterator * it = col->getIterator();
    DTPropiedadDetallada * propDetallada;
    while (it->hasCurrent()){
        propDetallada = (DTPropiedadDetallada *) it->getCurrent();
        cout << propDetallada << endl;
        it->next();
    }
    delete it;
}

void imprimirDTChatProps(IDictionary * col){
    IIterator * it = col->getIterator();
    DTChatProp * dtchatprop;
    DTPropiedad * dtprop;
    int i;
    while (it->hasCurrent()){
        dtchatprop = (DTChatProp *) it->getCurrent();
        if (dtchatprop != NULL){
            cout << "---Chat-Propiedad " << i << "---" << endl;
            cout << dtchatprop << endl;
        } else {
            cout << "---Propiedad " << i << "---" << endl;
            dtprop = (DTPropiedad *) it->getCurrent();
            cout << dtprop << endl;
        }
        i++;
        it->next();
    }
    delete it;
}

void imprimirDTMensajes(ICollection * col){
    IIterator * it = col->getIterator();
    DTMensaje * dtmensaje;
    while (it->hasCurrent()){
        dtmensaje = (DTMensaje *) it->getCurrent();
        cout << dtmensaje << endl;
        it->next();
    }
    delete it;
}

DTFecha * getDTFechaActual(){
    time_t t = time(nullptr);
    tm* now = localtime(&t);

    // Obtener el día, mes y año actuales
    int dia = now->tm_mday;
    int mes = now->tm_mon + 1; // Los meses van de 0 a 11, por eso se suma 1
    int anio = now->tm_year + 1900; // El año se cuenta desde 1900, por eso se suma 1900

    // Obtener la hora, minuto y segundo actuales
    int hora = now->tm_hour;
    int minuto = now->tm_min;
    int segundo = now->tm_sec;

    DTHora * dthora = new DTHora(hora, minuto, segundo);
    
    return new DTFecha(dia, mes, anio, dthora);
}

bool manejarIniciarSesion(ISistema * sistema){
    system("cls");
    char* email = new char[100];
    bool emailCorrecto;
    do{
        cout << "Inicie sesión con una cuenta" << endl << endl;
        cout << "Ingrese email" << endl << endl;
        cin >> email;
        try {
            sistema->iniciarSesion(email);
            emailCorrecto = true;
        } catch (const exception& e){
            system("cls");
            cout << "Error de ejecución: " << e.what() << endl;
            system("pause");
            emailCorrecto = false;
            system("pause");
        }
    } while(!emailCorrecto);
    if(sistema->getLoggeado()->getPrimeraVez() == true){
        try{
            system("cls");
            string pwd1;
            string pwd2;
            cout << "Es su primera vez iniciando sesión" << endl;
            cout << "Establezca una contraseña segura de más de 8 caracteres" << endl << endl;
            cin >> pwd1;
            cout << "Repita la contraseña" << endl << endl;
            cin >> pwd2;
            sistema->crearContrasenia(pwd1, pwd2);
        } catch (const exception& e){
            system("cls");
            cout << "Error de ejecución: " << e.what() << endl;
            system("pause");
            return false;
        }
    }
    system("cls");
    string pwd;
    cout << "Inicie sesión con su contraseña" << endl << endl;
    cin >> pwd;
    try{
        sistema->ingresarContrasenia(pwd);
        cout << "Sesión iniciada con éxito";
        return true;
    } catch (const exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return false;
    }
}

void manejarAltaInmobiliaria(ISistema * sistema){
    system("cls");
    char* email = new char[100];
    string nombre;
    DTDir* dir;
    string calle;
    int numero;
    string ciudad;
    cout << "Va a ingresar un usuario inmobiliaria en el sistema" << endl << endl;
    cout << "Ingrese el email" << endl << endl;
    cin >> email;
    IKey * key = new String(email);
    if(sistema->getUsuarios()->member(key)){
        cout << "Ya existe un usuario con ese correo" << endl;
        return;
    }
    system("cls");

    cout << "Ingrese ahora un nombre para la inmobiliaria" << endl << endl;
    cin >> nombre;

    system("cls");

    cout << "Ingrese calle" << endl << endl;
    cin >> calle;

    system("cls");

    cout << "Ingrese numero" << endl << endl;
    cin >> numero;

    system("cls");

    cout << "Ingrese ciudad" << endl << endl;
    cin >> ciudad;

    dir = new DTDir(calle, numero, ciudad);

    try{
        sistema->altaInmobiliaria(nombre, email, dir);
    } catch (const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }
}


void manejarAltaInteresado(ISistema * sistema){
    system("cls");
    char* email = new char[100];
    string nombre;
    string apellido;
    int edad;
    cout << "Va a ingresar un usuario interesado en el sistema" << endl << endl;
    cout << "Ingrese el email" << endl << endl;
    cin >> email;
    IKey * key = new String(email);
    if(sistema->getUsuarios()->member(key)){
        cout << "Ya existe un usuario con ese correo" << endl;
        return;
    }
    system("cls");

    cout << "Ingrese ahora un nombre para el interesado" << endl << endl;
    cin >> nombre;

    system("cls");

    cout << "Ingrese un apellido" << endl << endl;
    cin >> apellido;

    do {
        system("cls");
        cout << "Ingrese la edad" << endl << endl;
        cin >> edad;
    } while(edad <= 0);

    try{
        sistema->altaInteresado(email, nombre, apellido, edad);
    } catch (const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }
}

void manejarAltaEdificio(ISistema * sistema){
    system("cls");
    string nombre;
    int cantPisos;
    int gastosComunes;
    Zona* zona;

    char* opt = new char[100];

    cout << "Elija uno de los departamentos listados debajo" << endl;
    imprimirDepto(sistema->listarDepartamentos());
    cin >> opt;
    try{
        sistema->elegirDepartamento(opt);
    } catch(const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }
   
    cout << "Elija una de las zonas listadas debajo" << endl;
    imprimirZonasDepto(sistema->listarZonasDepartamento()); // Valentin cambió esto
    
    int optint;

    cin >> optint;

    try{
        sistema->elegirZona(optint);
    } catch(const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    cout << "Va a ingresar un edificio en el sistema" << endl << endl;
    cout << "Ingrese ahora un nombre para el edificio" << endl << endl;
    cin >> nombre;

    do {
        system("cls");
        cout << "Ingrese la cantidad de pisos" << endl << endl;
        cin >> cantPisos;
    } while(cantPisos <= 0);

    do {
        system("cls");
        cout << "Ingrese los gastos comunes" << endl << endl;
        cin >> gastosComunes;
    } while(gastosComunes <= 0);

    try{
        sistema->altaEdificio(nombre, cantPisos, gastosComunes);
        sistema->setDepartamentoActual(NULL);
        sistema->setZonaActual(NULL);

    } catch (const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }
}

void manejarAltaPropiedad(ISistema * s){
    system("cls");

    
   //chequear usuario
    if(s->getLoggeado() == NULL){
        system("cls");
        throw runtime_error("No hay un usuario en el sistema");
    }
    Inmobiliaria * inmo = (Inmobiliaria*) s->getLoggeado();
    if(inmo == NULL){
        system("cls");
        throw runtime_error("El usuario ingresado no es Inmobiliaria");
    }

    //elegir departamento
    imprimirDepto(s->listarDepartamentos());
    char* opt = new char[100];
    cout << "Elija un departamento:" << endl;
    cin >> opt;
    try{
        s->elegirDepartamento(opt);
    } catch(const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }
    system("cls");
   

    //elegir zona
    imprimirZonasDepto(s->listarZonasDepartamento()); 
    cout << "Ingresar identificación de la zona:" << endl;
    int numZona;
    cin >> numZona;
    try{
        s->elegirZona(numZona);
    } catch(const exception& e){
        system("cls");
        s->setDepartamentoActual(NULL);
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    cout << "Ingrese tipo de propiedad" << endl;
    cout << "1. Casa" << endl;
    cout << "2. Apartamento" << endl;
    int opcion;
    cin >> opcion;
    system("cls");

    //si es apartamento
    if (opcion == 2) {
        imprimirEdificios(s->listarEdificio());
        cout << "¿Desea seleccionar un nuevo edificio?" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        opcion = 0;
        cin >> opcion;


        //agrega edificio
        if (opcion == 1) {
            system("cls");
            string nombre;
            int pisos, gastosC;
            cout << "Ingrese nombre del edificio" << endl;
            cin >> nombre;
            system("cls");
            do {
                system("cls");
                cout << "Ingrese la cantidad de pisos" << endl << endl;
                cin >> pisos;
            } while(pisos <= 0);

            do {
                system("cls");
                cout << "Ingrese los gastos comunes" << endl << endl;
                cin >> gastosC;
            } while(gastosC <= 0);
            system("cls");
            s->altaEdificio(nombre, pisos, gastosC);         
        }

        else if (opcion == 2) {
            //seleccionar edificio
            system("cls");
            imprimirEdificios(s->listarEdificio());
            cout << "Ingresar identificación del edificio:" << endl;
            int numEdificio;
            cin >> numEdificio;
        
            try{
                s->seleccionarEdificio(numEdificio); 
            } catch(const exception& e) {
                system("cls");
                cout << "Error de ejecución: " << e.what() << endl;
                system("pause");
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
        system("cls");
        cout << "Ingresar numero:" << endl;
        cin >> numero;
        system("cls");
        cout << "Ingresar ciudad:" << endl;
        cin >> ciudad;
        system("cls");
        DTDir* dir = new DTDir(calle, numero, ciudad);
       do {
                system("cls");
                cout << "Ingrese la cantidad de ambientes" << endl << endl;
                cin >> cantAmb;
            } while(cantAmb < 1);
        
        do {
                system("cls");
                cout << "Ingrese la cantidad de banos" << endl << endl;
                cin >> cantBanos;
            } while(cantBanos < 0);
        do {
                system("cls");
                cout << "Ingrese la cantidad de dormitorios" << endl << endl;
                cin >> cantDorm;
            } while(cantDorm < 0);
        system("cls");
        cout << "Ingresar si tiene garage:" << endl;
        cout << "1. Si" << endl;
        cout << "2. No" << endl;
        cin >> opcion;
        system("cls");
        if (opcion == 1) 
            garage = true;
            do {
                system("cls");
                cout << "Ingrese metros cuadrados edificados" << endl << endl;
                cin >> m2t;
            } while(m2t <= 0);
            system("cls");
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
            system("cls");
            cout << "Ingresar numero:" << endl;
            cin >> numero;
            system("cls");
            cout << "Ingresar ciudad:" << endl;
            cin >> ciudad;
            system("cls");
            DTDir* dir = new DTDir(calle, numero, ciudad);
            do {
                system("cls");
                cout << "Ingrese la cantidad de ambientes" << endl << endl;
                cin >> cantAmb;
            } while(cantAmb < 1);
        
            do {
                system("cls");
                cout << "Ingrese la cantidad de banos" << endl << endl;
                cin >> cantBanos;
            } while(cantBanos < 0);

            do {
                system("cls");
                cout << "Ingrese la cantidad de dormitorios" << endl << endl;
                cin >> cantDorm;
            } while(cantDorm < 0);

            system("cls");
            cout << "Ingresar si tiene garage:" << endl;
            cout << "1. Si" << endl;
            cout << "2. No" << endl;
            cin >> opcion;
            system("cls");
            if (opcion == 1) 
                garage = true;

            do {
                system("cls");
                cout << "Ingrese metros cuadrados edificados" << endl << endl;
                cin >> m2e;
            } while(m2e <= 0);

            do {
                system("cls");
                cout << "Ingrese metros cuadrados verdes" << endl << endl;
                cin >> m2v;
            } while(m2v <= 0);
                system("cls");
                s->especificacionesCasa(cantAmb, cantDorm, cantBanos, garage, dir, m2e, s->getZonaActual(), m2v);
            }


            cout << "1. Poner en venta" << endl;
            cout << "2. Poner en alquiler" << endl;
            cout << "3. Poner en venta y alquiler" << endl;
            int option;
            cin >> option;
            system("cls");
            if (option == 1) {
                float valorV;
                cout << "Ingrese valor de la venta" << endl;
                system("cls");
                s->ponerEnVenta(valorV);
                cout << "La propiedad ha sido ingresada exitosamente, su codigo de propiedad es "<< s->getPropiedadActual()->getCodigo() << endl;
                return;
            }
            if (option == 2) {
                float valorA;
                cout << "Ingrese valor del alquiler" << endl;
                system("cls");
                s->ponerEnAlquiler(valorA);
                cout << "La propiedad ha sido ingresada exitosamente, su codigo de propiedad es "<< s->getPropiedadActual()->getCodigo() << endl;
                return;
            }
            if (option == 3) {
                float valorA;
                float valorV;
                cout << "Ingrese valor de la venta" << endl;
                cin >> valorV;
                system("cls");
                cout << "Ingrese valor del alquiler" << endl;
                cin >> valorA;
                s->ponerEnAlquiler(valorA);
                s->ponerEnVenta(valorV);
                cout << "La propiedad ha sido ingresada exitosamente, su codigo de propiedad es "<< s->getPropiedadActual()->getCodigo() << endl;
                return;
            }
           
    s->setPropiedadActual(NULL);
    s->setDepartamentoActual(NULL);
    s->setZonaActual(NULL);
    s->setEdificioActual(NULL);
}

void manejarConsultarPropiedad(ISistema * sistema){
    system("cls");
    
    char* opt = new char[100];

    cout << "Elija uno de los departamentos listados debajo" << endl;

    try {
        imprimirDepto(sistema->listarDepartamentos());
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    cin >> opt;
    
    try {
        sistema->elegirDepartamento(opt);
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    system("cls");

    cout << "Elija una de las zonas listadas debajo" << endl;

    try {
        imprimirZonasDepto(sistema->listarZonasDepartamento());
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }
    
    string optstr;
    int optint;

    while (true){
        cout << "Ingrese el código de la zona: "<<endl;
        cin >> optstr;
        try {
            optint = stoi(optstr);
            break;
        } catch(const exception& e) {
            system("cls");
            cout << endl << "Por favor, ingrese un código de zona válido" << endl;
            system("pause");
        }
    }

    try {
        sistema->elegirZona(optint);
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    system("cls");

    cout << "Elija una de las propiedades listadas debajo" << endl;

    try {
        imprimirProps(sistema->listarPropiedades());
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    while (true){
        cout << "Ingrese el código de la propiedad: "<<endl;
        cin >> optstr;
        try {
            optint = stoi(optstr);
            break;
        } catch(const exception& e) {
            system("cls");
            cout << endl << "Por favor, ingrese un código de propiedad válido" << endl;
            system("pause");
        }
    }

    cout << "---Propiedad Detallada---" << endl << endl;
    DTPropiedadDetallada * prop;

    try {
        prop = sistema->verDetallesPropiedad(optint);
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    cout << prop;
    
    system("pause");
    system("cls");

}

// void manejarModificarPropiedad(ISistema * sistema){
//     //feli
//     system("cls");
//     Inmobiliaria * inmo = (Inmobiliaria *) sistema->getLoggeado();
//     if(inmo == NULL){
//         throw invalid_argument("El usuario logeado no es Inmobiliaria");
//     }
//     cout<<"Ingrese el codigo de la Propiedad"<<endl;
//     string linea;
//     getline(cin, linea);
//     int cod;
//     try{
//         cod = stoi(linea);
//     }
//     catch(const exception& e){
//         throw invalid_argument("El codigo ingresado no es un numero");
//     }
//     if(cod <= 0){
//         throw invalid_argument("Codigo no puede ser menor a 1");
//     }
//     system("cls");
//     IKey * key = new Integer(cod);
//     if(inmo->getPropiedades()->isEmpty()){
//         throw invalid_argument("El usuario logeado no tiene Propiedades");
//     }
//     Propiedad * prop = (Propiedad *) inmo->getPropiedades()->find(key);
//     if(prop == NULL){
//         throw invalid_argument("No existe una Propiedad con ese codigo");
//     }
//     delete key;
//     sistema->setPropiedadActual(prop);
//     DTTipoProp tipoprop = prop->getDTTipoProp(); 
//     int cantAmbiente, cantDormitorio, cantBanios;
//     float m2Edificados;
//     bool tieneGaraje;
//     DTDir * direccion;
//     cout<<"Ingrese la cantidad Ambiente"<<endl;
//     getline(cin, linea);
//     try{
//         cantAmbiente = stoi(linea);
//     }
//     catch(const exception& e){
//         throw invalid_argument("La cantidad ingresada no es un numero");
//     }
//     if(cantAmbiente <= 0){
//         throw invalid_argument("Cantidad de Ambientes no puede ser menor a 1");
//     }
//     system("cls");
//     cout<<"Ingrese la cantidad de Dormitorios"<<endl;
//     getline(cin, linea);
//     try{
//         cantDormitorio = stoi(linea);
//     }
//     catch(const exception& e){
//         throw invalid_argument("La cantidad ingresada no es un numero");
//     }
//     if(cantDormitorio <= -1){
//         throw invalid_argument("Cantidad de Dormitorios no puede ser menor a 0");
//     }
//     system("cls");
//     cout<<"Ingrese la cantidad de Banios"<<endl;
//     getline(cin, linea);
//     try{
//         cantBanios = stoi(linea);
//     }
//     catch(const exception& e){
//         throw invalid_argument("La cantidad ingresada no es un numero");
//     }
//     if(cantBanios <= -1){
//         throw invalid_argument("Cantidad de Banios no puede ser menor a 0");
//     }
//     system("cls");
//     cout<<"Ingrese los m2 de Edificio"<<endl;
//     getline(cin, linea);
//     try{
//         m2Edificados = stof(linea);
//     }
//     catch(const exception& e){
//         throw invalid_argument("La cantidad ingresada no es un numero");
//     }
//     if(m2Edificados <= 0){
//         throw invalid_argument("los m2 edificados no pueden ser menor a 1");
//     }
//     system("cls");
//     cout<<"¿La propiedad tiene garaje?"<<endl;
//     cout<<"1)Si        2)No"<<endl;
//     int respuesta;
//     getline(cin, linea);
//     try{
//         respuesta = stoi(linea);
//     }
//     catch(const exception& e){
//         throw invalid_argument("El codigo ingresado no es un numero");
//     }
//     switch(respuesta){
//         case 1:
//             tieneGaraje = true;
//             break;
//         case 2:
//             tieneGaraje = false;
//             break;
//         default:
//             throw invalid_argument("El numero ingresado no es una opcion");
//     }
//     system("cls");
//     int numero;
//     string calle, ciudad;
//     cout<<"ingresa el numero de direccion"<<endl;
//     getline(cin, linea);
//     try{
//         numero = stoi(linea);
//     }
//     catch(const exception& e){
//         throw invalid_argument("El numero ingresado no es un numero");
//     }
//     if(numero <= 0){
//         throw invalid_argument("El codigo de direccion no puede ser menor a 1");
//     }
//     system("cls");
//     cout<<"ingresa la calle de la direccion"<<endl;
//     getline(cin, linea);
//     calle = linea;
//     system("cls");
//     cout<<"ingresa el ciudad de la direccion"<<endl;
//     getline(cin, linea);
//     ciudad = linea;
//     system("cls");
//     DTDir * dir = new DTDir(calle, numero, calle);
//     if(tipoprop == DTTipoProp::casa){
//         int m2Verdes;
//         cout<<"Ingrese los m2 Verdes"<<endl;
//         getline(cin, linea);
//         try{
//             m2Verdes = stof(linea);
//         }
//         catch(const exception& e){
//             throw invalid_argument("La cantidad ingresada no es un numero");
//         }
//         if(m2Verdes <= -1){
//             throw invalid_argument("Cantidad de Ambientes no puede ser menor a 1");
//         }
//         system("cls");
//         sistema->modificarCasa(cantAmbiente, cantDormitorio,  cantBanios,  m2Edificados,  dir,  tieneGaraje, m2Verdes);
//         return;
//     }
//     int m2Totales;
//     cout<<"Ingrese los m2 Totales"<<endl;
//     getline(cin, linea);
//     try{
//         m2Totales = stof(linea);
//     }
//     catch(const exception& e){
//         throw invalid_argument("La cantidad ingresada no es un numero");
//     }
//     if(m2Totales <= 0){
//         throw invalid_argument("Los m2 totales no puede ser menor a 1");
//     }
//     system("cls");
//     sistema->modificarApartamento(cantAmbiente, cantDormitorio, cantBanios, m2Totales, dir, tieneGaraje);
// }

void manejarModificarPropiedad(ISistema * sistema){
    //vale
    system("cls");

    cout << "Selecciona una de las siguientes propiedades para modificarla" << endl;
    imprimirProps(sistema->listarPropiedadesInmo());

    string optstr;
    int codigoProp;

    while (true){
        cout << "Ingresa el código de la propiedad: ";
        cin >> optstr;
        try {
            codigoProp = stoi(optstr);
            break;
        } catch(const exception& e) {
            system("cls");
            cout << endl << "Por favor, ingrese un código de propiedad válido" << endl;
            system("pause");        
        }
    }

    try{
        sistema->seleccionarPropiedadInmobiliaria(codigoProp);
    } catch(const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    DTTipoProp tipoProp = sistema->getDTTipoProp();

    int cantAmbientes, cantDormitorios, cantBanios;
    bool tieneGaraje;

    // Para la dirección
    DTDir * direccion;
    string calle, ciudad;
    int numero;


    system("cls");

    while (true){
        cout << "Ingresa la cantidad de ambientes: ";
        cin >> optstr;
        try {
            cantAmbientes = stoi(optstr);
            if (cantAmbientes >= 1){
                break;
            }
            cout << endl << "Por favor, ingresa una cantidad de ambientes válida (mayor a 0)" << endl;
        } catch(const exception& e) {
            system("cls");
            cout << endl << "Por favor, ingresa una cantidad numérica" << endl;
            system("pause");
        }
    }

    system("cls");

    while (true){
        cout << "Ingresa la cantidad de dormitorios: ";
        cin >> optstr;
        try {
            cantDormitorios = stoi(optstr);
            if (cantDormitorios >= 0){
                break;
            }
            cout << endl << "Por favor, ingresa una cantidad de dormitorios válida (0 o más)" << endl;
        } catch(const exception& e) {
            system("cls");
            cout << endl << "Por favor, ingresa una cantidad numérica" << endl;
            system("pause");
        }
    }

    system("cls");

    while (true){
        cout << "Ingresa la cantidad de baños: ";
        cin >> optstr;
        try {
            cantBanios = stoi(optstr);
            if (cantBanios >= 0){
                break;
            }
            cout << endl << "Por favor, ingresa una cantidad de baños válida (0 o más)" << endl;
        } catch(const exception& e) {
            system("cls");
            cout << endl << "Por favor, ingresa una cantidad numérica" << endl;
            system("pause");
        }
    }

    system("cls");

    while (true){
        cout << "Indica a continuación si la propiedad tiene garaje" << endl << "1 - No tiene garaje" << endl << "2 - Tiene Garaje" << endl << endl << "Ingresa tu opción: ";
        cin >> optstr;
        try {
            tieneGaraje = stoi(optstr)-1;
            if (tieneGaraje == 0 || tieneGaraje == 1){
                break;
            }
            cout << endl << "Por favor, ingresa una opción válida (1 o 2)" << endl;
        } catch(const exception& e) {
            system("cls");
            cout << endl << "Por favor, ingresa un valor numérico" << endl;
            system("pause");
        }
    }

    system("cls");

    cout << "Dirección de la propiedad" << endl << "Especifica la ciudad: ";
    getline(cin, ciudad);

    cout << endl << "Especifica la calle: ";
    getline(cin, calle);;

    cout << endl;

    while (true){
        cout << "Especifica el número: ";
        cin >> optstr;
        try {
            numero = stoi(optstr);
            if (numero > 0){
                break;
            }
            cout << endl << "Por favor, ingresa un valor válido (mayor a 0)" << endl;
        } catch(const exception& e) {
            system("cls");
            cout << endl << "Por favor, ingresa un valor numérico" << endl;
            system("pause");
        }
    }

    direccion = new DTDir(calle, numero, ciudad);

    system("cls");

    if (tipoProp == DTTipoProp::apartamento){
        float m2Totales;
        
        while (true){
            cout << "Introduce los m2Totales: ";
            cin >> optstr;
            try {
                m2Totales = stof(optstr);
                if (m2Totales > 0){
                    break;
                }
                cout << endl << "Por favor, ingresa un valor válido (mayor a 0)" << endl;
            } catch(const exception& e) {
                system("cls");
                cout << endl << "Por favor, ingresa una cantidad numérica" << endl;
                system("pause");
            }
        }

        try{
            sistema->modificarApartamento(cantAmbientes, cantDormitorios, cantBanios, tieneGaraje, direccion, m2Totales);
        } catch(const exception& e){
            system("cls");
            cout << "Error de ejecución: " << e.what() << endl;
            system("pause");
            return;
        }

        cout << "Apartamento modificado de manera exitosa!" << endl;

    } else {
        float m2Edificados, m2Verdes;

        while (true){
            cout << "Introduce los m2Edificados: ";
            cin >> optstr;
            try {
                m2Edificados = stof(optstr);
                if (m2Edificados > 0){
                    break;
                }
                cout << endl << "Por favor, ingresa un valor válido (mayor a 0)" << endl;
            } catch(const exception& e) {
                system("cls");
                cout << endl << "Por favor, ingresa una cantidad numérica" << endl;
                system("pause");
            }
        }

        system("cls");

        while (true){
            cout << "Introduce los m2Verdes: ";
            cin >> optstr;
            try {
                m2Verdes = stof(optstr);
                if (m2Verdes >= 0){
                    break;
                }
                cout << endl << "Por favor, ingresa un valor válido (mayor o igual a 0)" << endl;
            } catch(const exception& e) {
                system("cls");
                cout << endl << "Por favor, ingresa una cantidad numérica" << endl;
                system("pause");
            }
        }

        try{
            sistema->modificarCasa(cantAmbientes, cantDormitorios, cantBanios, tieneGaraje, direccion, m2Edificados, m2Verdes);
        } catch(const exception& e){
            system("cls");
            cout << "Error de ejecución: " << e.what() << endl;
            system("pause");
            return;
        }

        cout << "Casa modificada de manera exitosa!" << endl;

    }
}

void manejarEliminarPropiedad(ISistema * sistema){
    system("cls");
    
    try {
        imprimirProps(sistema->listarPropiedadesInmo());
    } catch(const exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    cout << "¿Qué propiedad te gustaría eliminar?" << endl << endl;
    string codigoProp;
    int codigoNumerico;

    while (true){
        cout << "Ingresa el código de la misma: ";
        cin >> codigoProp;
        try {
            codigoNumerico = stoi(codigoProp);
            break;
        } catch(const exception& e) {
            system("cls");
            cout << endl << "Por favor, ingresa un código numérico" << endl;
            system("pause");
        }
    }

    try {
        sistema->eliminarPropiedad(codigoNumerico);
    } catch(const exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    system("cls");
    cout << "La propiedad fue removida exitosamente!" << endl;
    system("pause");

}

// TIENE QUE SER CON TODO TRY-CATCHS
void manejarEnviarMensajeInteresado(ISistema * sistema){
    system("cls");

    try {
        imprimirDepto(sistema->listarDepartamentos());
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    char * letraDepa = new char[100];
    cout << "Ingrese la letra del Departamento: ";
    cin >> letraDepa;

    try {
        sistema->elegirDepartamento(letraDepa);
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    system("cls");

    try {
        imprimirZonasDepto(sistema->listarZonasDepartamento());
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    string opcion;
    int numZona;

    while (true){
        cout << "Ingrese el codigo de la Zona: ";
        cin >> opcion;
        try {
            numZona = stoi(opcion);
            break;
        } catch(const exception& e) {
            system("cls");
            cout << endl << "Por favor, ingrese un código de Zona válido" << endl;
            system("pause");
        }
    }

    system("cls");

    try {
        sistema->elegirZona(numZona);
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    IDictionary * dic;

    try {
        dic = sistema->listarChatProp();
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }
    
    if (dic->isEmpty()){
        cout << "Error de ejecución: No hay Propiedades en la zona elegida" << endl;
        system("pause");
        return;
    }

    imprimirDTChatProps(dic);

    int codProp;

    while (true){
        cout << "Ingrese el codigo de la Propiedad para ingresar al chat o inicializar uno: ";
        cin >> opcion;
        try {
            codProp = stoi(opcion);
            break;
        } catch(const exception& e) {
            system("cls");
            cout << endl << "Por favor, ingrese un código de Propiedad válido" << endl;
            system("pause");
        }
    }
    
    try {
        sistema->seleccionarPropiedad(codProp);
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    Conversacion * cons = sistema->getConversacionInteresado(); // Antes hacía un try-catch con esto
    if (cons == NULL){
        sistema->nuevoChat();
    }

    system("cls");

    ICollection * col;

    try {
        col = sistema->getUltimosMensajes();
    } catch(const exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    if (!col->isEmpty()){
        cout << "---Ultimos mensajes---" << endl;
        imprimirDTMensajes(col);
    } else {
        cout << "No hay mensajes anteriores para mostrar";
    }

    string mensaje;
    do{
        cin.ignore();
        cout << "Ingrese un Mensaje no vacio" << endl;
        getline(cin, mensaje);
    } while(mensaje == ""); //agregar bucle en caso de q el mensaje sea vacio

    DTFecha * FECHA = getDTFechaActual();
    
    try {
        sistema->nuevoMensaje(mensaje, FECHA);
    } catch(const std::exception& e) {
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    system("cls");
    cout << "El mensaje se envió de manera exitosa!" << endl;
    system("pause");

    // sistema->setConversacionActual(NULL); // No es necesario
    // sistema->setDepartamentoActual(NULL);
    // sistema->setEdificioActual(NULL);
    // sistema->setPropiedadActual(NULL);
    // sistema->setZonaActual(NULL);

}


void manejarEnviarMensajeInmobiliaria(ISistema * sistema){
    //feli
    system("cls");

    try{
        imprimirDTChatProps(sistema->listarChatsInmo());
    } catch(const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }
    
    string respuesta;
    int codigo;
    getline(cin, respuesta);

    while (true){
        cout << "Ingrese el código de la conversación que desee seleccionar: ";
        cin >> respuesta;
        try {
            codigo = stoi(respuesta);
            break;
        } catch(const exception& e) {
            system("cls");
            cout << endl << "Por favor, ingrese un código de conversación válido" << endl;
            system("pause");
        }
    }

    system("cls");

    try{
        sistema->seleccionarConversacionInmo(codigo);
    } catch(const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    system("cls");

    cout << "Ingresa el contenido del Mensaje: " << endl;
    getline(cin, respuesta);

    DTFecha * fecha = getDTFechaActual();

    try{
        sistema->nuevoMensaje(respuesta, fecha);
    } catch(const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    cout << "El mensaje fue agregado de manera exitosa!" << endl;

    system("pause");

}

void manejarReporte(ISistema * sistema){
    system("cls");
    ICollection * reportes;
    try {
        reportes = sistema->obtenerReporte();
    } catch (const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }
    int i = 1;
    IIterator * it = reportes->getIterator();
    while(it->hasCurrent()){
        DTReporte * reporte = (DTReporte*) it->getCurrent();
        cout << "[REPORTE " << i << "]" << endl;
        // cout << reporte << endl << endl;
        cout << "Inmobiliaria: " << reporte->getInmo() << endl << endl;
        IIterator * it2 = reporte->getLineas()->getIterator();
        while(it2->hasCurrent()){
            DTLineaReporte * linea = (DTLineaReporte*) it2->getCurrent();
            // cout << linea << endl << endl;
            cout << "Departamento: " << linea->getLetraDep() << endl;
            cout << "Código de la zona: " << linea->getCodigoZona() << endl;
            cout << "Cantidad de casas: " << linea->getCantCasas() << endl;
            cout << "Cantidad de apartamentos: " << linea->getCantApartamentos() << endl << endl;
            it2->next();
        }
        i++;
        it->next();
    }
}

void menu(ISistema * sistema){
    string opt;
    do{

        do{
            opt = "";
            sistema->setConversacionActual(NULL);
            sistema->setDepartamentoActual(NULL);
            sistema->setEdificioActual(NULL);
            sistema->setPropiedadActual(NULL);
            sistema->setZonaActual(NULL);
            system("cls");
            cout << "Necesita iniciar sesión en el sistema" << endl << endl;
            cout << "1-Iniciar sesión" << endl;
            cout << "exitsystem-Salir del sistema" << endl << endl;
            cin >> opt;
        } while (opt != "1" && opt != "exitsystem");

        if(opt != "exitsystem"){
            bool sesionCorrecta;
            do{
                sesionCorrecta = manejarIniciarSesion(sistema);
                system("pause");
            } while(!sesionCorrecta);

            if(sesionCorrecta){
                Inmobiliaria * inmo = dynamic_cast<Inmobiliaria*>(sistema->getLoggeado());
                Administrador * admin = dynamic_cast<Administrador*>(sistema->getLoggeado());
                Interesado* interesado = dynamic_cast<Interesado*>(sistema->getLoggeado());

                if(admin != NULL){
                    do{
                        do{
                            system("cls");
                            opt = "";
                            sistema->setConversacionActual(NULL);
                            sistema->setDepartamentoActual(NULL);
                            sistema->setEdificioActual(NULL);
                            sistema->setPropiedadActual(NULL);
                            sistema->setZonaActual(NULL);
                            cout << "Elija una función del sistema" << endl << endl;
                            cout << "1-Cerrar sesión" << endl;
                            cout << "2-Alta inmobiliaria" << endl;
                            cout << "3-Alta interesado" << endl;
                            cout << "4-Obtener reporte de inmobiliaria" << endl << endl;
                            cin >> opt;
                        } while(opt != "1" && opt != "2" && opt != "3"  && opt != "4");

                        if(opt == "1"){
                            sistema->cerrarSesion();
                            continue;
                        } else if(opt == "2"){
                            manejarAltaInmobiliaria(sistema);
                            system("pause");
                        } else if (opt == "3"){
                            manejarAltaInteresado(sistema);
                            system("pause");
                        } else if (opt == "4"){
                            manejarReporte(sistema);
                            system("pause");
                        } else {
                            throw invalid_argument("No se encontró una opción válida");
                        }
                    } while(opt != "1");
                } else if(inmo != NULL) {
                    do{
                        do{
                            system("cls");
                            opt = "";
                            sistema->setConversacionActual(NULL);
                            sistema->setDepartamentoActual(NULL);
                            sistema->setEdificioActual(NULL);
                            sistema->setPropiedadActual(NULL);
                            sistema->setZonaActual(NULL);
                            cout << "Elija una función del sistema" << endl << endl;
                            cout << "1-Cerrar sesión" << endl;
                            cout << "2-Alta edificio" << endl;
                            cout << "3-Alta propiedad" << endl;
                            cout << "4-Consultar propiedad" << endl;
                            cout << "5-Modificar propiedad" << endl;
                            cout << "6-Eliminar propiedad" << endl;
                            cout << "7-Enviar mensaje inmobiliaria" << endl << endl;
                            cin >> opt;
                        } while(opt != "1" && opt != "2" && opt != "3" && opt != "4" && opt != "5" && opt != "6" && opt != "7");

                        if (opt == "1"){
                            sistema->cerrarSesion();
                            continue;
                        } else if(opt == "2"){
                            manejarAltaEdificio(sistema);
                            system("pause");
                        } else if (opt == "3"){
                            manejarAltaPropiedad(sistema);
                            system("pause");
                        } else if (opt == "4"){
                            manejarConsultarPropiedad(sistema);
                            system("pause");
                        } else if (opt == "5"){
                            manejarModificarPropiedad(sistema);
                            system("pause");
                        } else if (opt == "6"){
                            manejarEliminarPropiedad(sistema);
                            system("pause");
                        } else if (opt == "7"){
                            manejarEnviarMensajeInmobiliaria(sistema);
                            system("pause");
                        } else {
                            throw invalid_argument("No se encontró una opción válida");
                        }
                    } while(opt != "1");
                } else if (interesado != NULL){
                    do{
                        do{
                            system("cls");
                            opt = "";
                            sistema->setConversacionActual(NULL);
                            sistema->setDepartamentoActual(NULL);
                            sistema->setEdificioActual(NULL);
                            sistema->setPropiedadActual(NULL);
                            sistema->setZonaActual(NULL);
                            cout << "Elija una función del sistema" << endl << endl;
                            cout << "1-Cerrar sesión" << endl;
                            cout << "2-Consultar propiedad" << endl;
                            cout << "3-Enviar mensaje interesado" << endl << endl;
                            cin >> opt;
                        } while(opt != "1" && opt != "2" && opt != "3");

                        if(opt == "1"){
                            sistema->cerrarSesion();
                            continue;
                        } else if(opt == "2"){
                            manejarConsultarPropiedad(sistema);
                            system("pause");
                        } else if (opt == "3"){
                            manejarEnviarMensajeInteresado(sistema);
                            system("pause");
                        } else {
                            throw invalid_argument("No se encontró una opción válida");
                        }
                    }while(opt != "1");
                }
            }
        }
    } while(opt != "exitsystem");
}


int main() {

    ISistema * sistema = (new Factory())->getISistema();
    
    Departamento * dep1 = new Departamento("A", "Canelones");
    Departamento * dep2 = new Departamento("S", "Montevideo");
    Departamento * dep3 = new Departamento("M", "San Jose");

    // Zonas de dep1
    Zona* zona1 = new Zona(1, "Santa Lucia", "A");
    Zona* zona2 = new Zona(2, "Canelones", "A");
    Zona* zona3 = new Zona(3, "Juanico", "A");

    // Zonas de dep2
    Zona* zona4 = new Zona(4, "Malvin Norte", "S");
    Zona* zona5 = new Zona(5, "Prado", "S");
    Zona* zona6 = new Zona(6, "Ciudad Vieja", "S");

    // Zonas de dep3
    Zona* zona7 = new Zona(7, "Rodriguez", "M");
    Zona* zona8 = new Zona(8, "Prado", "M");
    Zona* zona9 = new Zona(9, "Ciudad Vieja", "M");

    ICollectible * zonacol1 = (ICollectible*) zona1;
    ICollectible * zonacol2 = (ICollectible*) zona2;
    ICollectible * zonacol3 = (ICollectible*) zona3;
    ICollectible * zonacol4 = (ICollectible*) zona4;
    ICollectible * zonacol5 = (ICollectible*) zona5;
    ICollectible * zonacol6 = (ICollectible*) zona6;
    ICollectible * zonacol7 = (ICollectible*) zona7;
    ICollectible * zonacol8 = (ICollectible*) zona8;
    ICollectible * zonacol9 = (ICollectible*) zona9;

    IKey * keyzona1 = new Integer(1);
    IKey * keyzona2 = new Integer(2);
    IKey * keyzona3 = new Integer(3);
    IKey * keyzona4 = new Integer(4);
    IKey * keyzona5 = new Integer(5);
    IKey * keyzona6 = new Integer(6);
    IKey * keyzona7 = new Integer(7);
    IKey * keyzona8 = new Integer(8);
    IKey * keyzona9 = new Integer(9);

    dep1->getZonas()->add(keyzona1, zona1);
    dep1->getZonas()->add(keyzona2, zona2);
    dep1->getZonas()->add(keyzona3, zona3);
    dep2->getZonas()->add(keyzona4, zona4);
    dep2->getZonas()->add(keyzona5, zona5);
    dep2->getZonas()->add(keyzona6, zona6);
    dep3->getZonas()->add(keyzona7, zona7);
    dep3->getZonas()->add(keyzona8, zona8);
    dep3->getZonas()->add(keyzona9, zona9);

    IKey * keydepa1 = new String(dep1->getLetra());
    IKey * keydepa2 = new String(dep2->getLetra());
    IKey * keydepa3 = new String(dep3->getLetra());



    char* email = "s";
    sistema->getDepartamentos()->add(keydepa1, dep1);
    sistema->getDepartamentos()->add(keydepa2, dep2);
    sistema->getDepartamentos()->add(keydepa3, dep3);

    Administrador * nuevoAdmin = new Administrador(email, "abc");
    ICollectible * nuevo = (ICollectible*) nuevoAdmin;

    IKey * key = new String(nuevoAdmin->getCorreoEletronico());

    sistema->getUsuarios()->add(key, nuevo);

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
    system("pause");
    return 0;
}