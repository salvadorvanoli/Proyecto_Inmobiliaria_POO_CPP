#include "../hfiles/administrador.h"
#include <iostream>
using namespace std;

Administrador::Administrador(char* email, string contrasenia) : Usuario(email){
    this->contrasenia = contrasenia;
}