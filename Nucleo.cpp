#include "Nucleo.h"
#include "Cola.h"
#include "Proceso.h"


Nucleo::Nucleo(){
    colaEspera=Cola();
    procesoEjecucion=Proceso();
    ID=-1;
}

Nucleo::Nucleo(int id){
    colaEspera=Cola();
    procesoEjecucion=Proceso();
    ID=id;
}


Nucleo::~Nucleo(){}
