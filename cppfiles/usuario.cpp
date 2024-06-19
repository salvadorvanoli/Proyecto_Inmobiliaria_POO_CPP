#include "../hfiles/usuario.h"
#include <iostream>
using namespace std;

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