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


// No está terminada, es porque lo estaba haciendo donde no era y quería guardar el código
void iniciarSesion(){
    system("clear");
    string opt;
    do{
        system("clear");
        cout << endl << endl << "El usuario no existe, elija un tipo e ingrese su email" << endl << endl;
        cout << "1-Administrador" << endl;
        cout << "2-Interesado" << endl;
        cout << "3-Inmobiliaria" << endl << endl;
        cin >> opt;
    } while(opt != "1" && opt != "2" && opt != "3");
    char* nuevoEmail;
    system("clear");
    cout << endl << endl << "Ahora elija su nuevo email" << endl << endl;
    cin >> nuevoEmail;
    IKey * searchKey = new String(nuevoEmail);
    if(this->usuarios->member(searchKey)){
        do{
            system("clear");
            cout << endl << "Este usuario ya estaba registrado, ingrese uno nuevo" << endl << endl;
            cin >> nuevoEmail;
            searchKey = new String(nuevoEmail);
        } while (this->usuarios->member(searchKey));
    }
    if(opt == "1"){
        
    } else if(opt == "2"){

    } else if(opt == "3"){

    }
}