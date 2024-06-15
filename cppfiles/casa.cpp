#include "../hfiles/casa.h"
#include <iostream>
using namespace std;

Casa :: Casa(int _m2Verdes){
    this->m2Verdes = _m2Verdes;
}

void Casa :: setM2Verdes(int _m2Verdes){
    this->m2Verdes = _m2Verdes;
}

int Casa :: getM2Verdes(){
    return this->m2Verdes;
}