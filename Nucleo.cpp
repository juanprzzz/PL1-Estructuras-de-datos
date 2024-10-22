#include "Nucleo.h"
#include "Cola.h"
#include "Proceso.h"
#include <iostream>





Nucleo::Nucleo(int id){
    colaEspera=Cola();
    ID=id;
}


Nucleo::~Nucleo(){}
