#include <iostream>
using namespace std;

#include "hfiles/sistema.h"
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

void imprimirDTChatProps(ICollection * col){
    IIterator * it = col->getIterator();
    DTChatProp * dtchatprop;
    while (it->hasCurrent()){
        dtchatprop = (DTChatProp *) it->getCurrent();
        cout << dtchatprop << endl;
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
    string day = to_string(dia), month = to_string(mes), year = to_string(anio);
    
    return new DTFecha(day, month, year, dthora);
}

bool manejarIniciarSesion(Sistema * sistema){
    system("clear");
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
            emailCorrecto = false;
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
        return false;
    }
}

void manejarAltaInmobiliaria(Sistema * sistema){
    system("cls");
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
        sistema->altaInmobiliaria(email, nombre, dir);
    } catch (const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
    }
}


void manejarAltaInteresado(Sistema * sistema){
    system("cls");
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
    }
}

void manejarAltaEdificio(Sistema * sistema){
    system("cls");
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
    imprimirZonasDepto(sistema->listarZonasDepartamento()); // Valentin cambió esto
    
    int optint;

    cin >> optint;

    try{
        sistema->elegirZona(optint);
    } catch(const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl; // Faltó return
    }

    cout << "Elija uno de los departamentos listados abajo" << endl; // ??? Dos veces preguntas por los departamentos
    imprimirDepto(sistema->listarDepartamentos());
    cin >> opt;
    sistema->elegirDepartamento(opt);

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
    }
}

void manejarAltaPropiedad(Sistema* s){
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
    cout << "Eliga un departamento:" << endl;
    cin >> opt;
    try{
        s->elegirDepartamento(opt);
    } catch(const exception& e){
        cout << "Error de ejecución: " << e.what() << endl;
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
        cout << "Error de ejecución: " << e.what() << endl;
        s->setDepartamentoActual(NULL);
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
            } while(cantAmb <= 1);
        
        do {
                system("cls");
                cout << "Ingrese la cantidad de banos" << endl << endl;
                cin >> cantBanos;
            } while(cantBanos <= 0);
        do {
                system("cls");
                cout << "Ingrese la cantidad de dormitorios" << endl << endl;
                cin >> cantDorm;
            } while(cantDorm <= 0);
        system("cls");
        cout << "Ingresar si tiene garage:" << endl;
        cout << "1. Si" << endl;
        cout << "2. No";
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
            } while(cantAmb <= 1);
        
            do {
                system("cls");
                cout << "Ingrese la cantidad de banos" << endl << endl;
                cin >> cantBanos;
            } while(cantBanos <= 0);

            do {
                system("cls");
                cout << "Ingrese la cantidad de dormitorios" << endl << endl;
                cin >> cantDorm;
            } while(cantDorm <= 0);

            system("cls");
            cout << "Ingresar si tiene garage:" << endl;
            cout << "1. Si" << endl;
            cout << "2. No";
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
            } while(m2v < 0);
            system("cls");
            s->especificacionesCasa(cantAmb, cantDorm, cantBanos, garage, dir, m2e, s->getZonaActual(), m2v);
            }


            cout << "1. Poner en venta" << endl;
            cout << "2. Poner en alquiler" << endl;
            int option;
            cin >> option;
            system("cls");
            if (option == 1) {
                float valor;
                cout << "Ingrese valor" << endl;
                cin >> valor;
                system("cls");
                int codigo = s->ponerEnVenta(valor);
                cout << "La propiedad ha sido ingresada exitosamente, su codigo de propiedad es " << codigo << endl;
                return;
            }
            if (option == 2) {
                float valor;
                cout << "Ingrese valor" << endl;
                cin >> valor;
                system("cls");
                int codigo = s->ponerEnAlquiler(valor);
                cout << "La propiedad ha sido ingresada exitosamente, su codigo de propiedad es "<< codigo << endl;
                return;
            }
           
    s->setPropiedadActual(NULL);
    s->setDepartamentoActual(NULL);
    s->setZonaActual(NULL);
    s->setEdificioActual(NULL);
}

void manejarConsultarPropiedad(Sistema * sistema){
    system("cls");
    char* opt = new char[100];

    cout << "Elija uno de los departamentos listados debabajo" << endl;
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

    system("cls");
   
    cout << "Elija una de las zonas listadas debajo" << endl;
    imprimirZonasDepto(sistema->listarZonasDepartamento());
    
    string optstr;
    int optint;

    while (true){
        cout << "Ingrese el código de la zona: ";
        cin >> optstr;
        try {
            optint = stoi(optstr);
            break;
        } catch(const exception& e) {
            cout << endl << "Por favor, ingrese un código de zona válido" << endl;
        }
    }

    try{
        sistema->elegirZona(optint);
    } catch(const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    system("cls");

    cout << "Elija una de las propiedades listadas debajo" << endl;
    imprimirProps(sistema->listarPropiedades());

    while (true){
        cout << "Ingrese el código de la propiedad: ";
        cin >> optstr;
        try {
            optint = stoi(optstr);
            break;
        } catch(const exception& e) {
            cout << endl << "Por favor, ingrese un código de propiedad válido" << endl;
        }
    }

    try{
        cout << "---Propiedad Detallada---" << endl << endl;
        cout << sistema->verDetallesPropiedad(optint);
        system("pause");
    } catch(const exception& e){
        system("cls");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    system("cls");

}

// void manejarModificarPropiedad(Sistema * sistema){
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

void manejarModificarPropiedad(Sistema * sistema){
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
            cout << endl << "Por favor, ingrese un código de propiedad válido" << endl;
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
            cout << endl << "Por favor, ingresa una cantidad numérica" << endl;
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
            cout << endl << "Por favor, ingresa una cantidad numérica" << endl;
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
            cout << endl << "Por favor, ingresa una cantidad numérica" << endl;
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
            cout << endl << "Por favor, ingresa un valor numérico" << endl;
        }
    }

    system("cls");

    cout << "Dirección de la propiedad" << endl << "Especifica la ciudad: ";
    cin >> ciudad;

    cout << endl << "Especifica la calle: ";
    cin >> calle;

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
            cout << endl << "Por favor, ingresa un valor numérico" << endl;
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
                cout << endl << "Por favor, ingresa una cantidad numérica" << endl;
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
                cout << endl << "Por favor, ingresa una cantidad numérica" << endl;
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
                cout << endl << "Por favor, ingresa una cantidad numérica" << endl;
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

void manejarEliminarPropiedad(Sistema * sistema){
    system("cls");
    ICollection * props = sistema->listarPropiedadesInmo();
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
            cout << endl << "Por favor, ingresa un código numérico" << endl;
        }
    }
    
    try {
        sistema->eliminarPropiedad(codigoNumerico);
        system("cls");
        cout << "La propiedad fue removida exitosamente!" << endl;
        system("pause");
    } catch(const exception& e) {
        cout << "Error de ejecución: " << e.what() << endl;
        return;
    }
}

void manejarEnviarMensajeInteresado(Sistema * sistema){
    system("cls");
    ICollection * depar = sistema->listarDepartamentos();
    char * letraDepa;
    cout<<"Ingrese la letra del Departamento"<<endl;
    cin >> letraDepa;

    try{
        sistema->elegirDepartamento(letraDepa);
         
    }catch(const exception& e){
        cout << "El Departamento ingresado no es valido." << endl;
        return;
    }

    ICollection * zona = sistema->listarZonasDepartamento();
    int numZona;
    cout<<"Ingrese el numero de la Zona"<<endl;
    cin >> numZona;

    try{
        sistema->elegirZona(numZona);
    }catch(const exception& e){
        cout << "La Zona ingresada no es valida." << endl;
        return;
    }

    ICollection * chatProp = sistema->listarChatProp();
    int codProp;
    cout<<"Ingrese el codigo de la Propiedad"<<endl;
    cin >> codProp;
    try{
        sistema->seleccionarPropiedad(codProp);
    }catch(const exception& e){
        cout << "La zona ingresada no es valida." << endl;
        return;
    }

    string mensaje;
    do{
        cin.ignore();
        cout<<"Ingrese un Mensaje no vacio"<<endl;
        getline(cin, mensaje);
    }while(mensaje == "");
    Conversacion * conver; //agregar bucle en caso de q el mensaje sea vacio
    IIterator *  it = (IIterator *) sistema->getPropiedadActual()->getConversaciones()->getIterator();
    bool encontro = false;
    DTFecha * FECHA = getDTFechaActual();
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
    sistema->setConversacionActual(NULL);
    sistema->setDepartamentoActual(NULL);
    sistema->setEdificioActual(NULL);
    sistema->setPropiedadActual(NULL);
    sistema->setZonaActual(NULL);
}


void manejarEnviarMensajeInmobiliaria(Sistema * sistema){
    //feli
    system("clear");

    try{
        imprimirDTChatProps(sistema->listarChatProp());
    } catch(const exception& e){
        system("clear");
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
            cout << endl << "Por favor, ingrese un código de coinversación válido" << endl;
        }
    }

    system("cls");

    Conversacion * conver;

    try{
        conver = sistema->seleccionarConversacionInmo(codigo);
    } catch(const exception& e){
        system("clear");
        cout << "Error de ejecución: " << e.what() << endl;
        system("pause");
        return;
    }

    system("cls");

    cout << "Ingresa el contenido del Mensaje: " << endl;
    getline(cin, respuesta);

    DTFecha * fecha = getDTFechaActual();

    conver->nuevoMensaje(fecha, respuesta);



}

void manejarReporte(Sistema * sistema){
    system("cls");
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

        do{
            system("cls");
            cout << "Necesita iniciar sesión en el sistema" << endl << endl;
            cout << "1-Iniciar sesión" << endl << endl;
            cin >> opt;
        } while (opt != "1");

        bool sesionCorrecta;
        do{
            sesionCorrecta = manejarIniciarSesion(sistema);
        } while(!sesionCorrecta);

        if(sesionCorrecta){
            Inmobiliaria * inmo = dynamic_cast<Inmobiliaria*>(sistema->getLoggeado());
            Administrador * admin = dynamic_cast<Administrador*>(sistema->getLoggeado());
            Interesado* interesado = dynamic_cast<Interesado*>(sistema->getLoggeado());

            if(admin != NULL){
                do{
                    system("cls");
                    cout << "Elija una función del sistema" << endl << endl;
                    cout << "1-Cerrar sesión" << endl;
                    cout << "2-Alta inmobiliaria" << endl;
                    cout << "3-Alta interesado" << endl;
                    cout << "4-Obtener reporte de inmobiliaria" << endl << endl;
                    cout << "exit-Salir del programa" << endl << endl;
                    cin >> opt;
                } while(opt != "1" && opt != "2" && opt != "3"  && opt != "4" && opt != "exit");
                if(opt == "1"){
                    sistema->cerrarSesion();
                } else if(opt == "2"){
                    manejarAltaInmobiliaria(sistema);
                    system("pause");
                } else if (opt == "3"){
                    manejarAltaInteresado(sistema);
                } else if (opt == "4"){
                    manejarReporte(sistema);
                } else if (opt == "exit"){
                    return;
                } else {
                    throw invalid_argument("No se encontró una opción válida");
                }
            } else if(inmo != NULL) {
                do{
                    system("cls");
                    cout << "Elija una función del sistema" << endl << endl;
                    cout << "1-Cerrar sesión" << endl;
                    cout << "2-Alta edificio" << endl;
                    cout << "3-Alta propiedad" << endl;
                    cout << "4-Consultar propiedad" << endl;
                    cout << "5-Modificar propiedad" << endl;
                    cout << "6-Eliminar propiedad" << endl;
                    cout << "7-Enviar mensaje inmobiliaria" << endl << endl;
                    cout << "exit-Salir del programa" << endl << endl;
                    cin >> opt;
                } while(opt != "1" && opt != "2" && opt != "3" && opt != "4" && opt != "5" && opt != "6" && opt != "7" && opt != "exit");
                if (opt == "1"){
                    sistema->cerrarSesion();
                } else if(opt == "2"){
                    manejarAltaEdificio(sistema);
                } else if (opt == "3"){
                    manejarAltaPropiedad(sistema);
                } else if (opt == "4"){
                    manejarConsultarPropiedad(sistema);
                } else if (opt == "5"){
                    manejarModificarPropiedad(sistema);
                } else if (opt == "6"){
                    manejarEliminarPropiedad(sistema);
                } else if (opt == "7"){
                    manejarEnviarMensajeInmobiliaria(sistema);
                } else if (opt == "exit"){
                    return;
                } else {
                    throw invalid_argument("No se encontró una opción válida");
                }
            } else if (interesado != NULL){
                do{
                    system("cls");
                    cout << "Elija una función del sistema" << endl << endl;
                    cout << "1-Cerrar sesión" << endl;
                    cout << "2-Consultar propiedad" << endl;
                    cout << "3-Enviar mensaje interesado" << endl << endl;
                    cout << "exit-Salir del programa" << endl << endl;
                    cin >> opt;
                } while(opt != "1" && opt != "2" && opt != "3" && opt != "exit");
                if(opt == "1"){
                    sistema->cerrarSesion();
                } else if(opt == "2"){
                    manejarConsultarPropiedad(sistema);
                } else if (opt == "3"){
                    manejarEnviarMensajeInteresado(sistema);
                } else if (opt == "exit"){
                    return;
                } else {
                    throw invalid_argument("No se encontró una opción válida");
                }
            }
        }
    } while(opt != "exit");
}


int main() {

    Sistema * sistema = new Sistema();

    char* email = "s";

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