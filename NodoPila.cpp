#include "NodoPila.h"

NodoPila::NodoPila(){
    Proceso proceso = Proceso();
    siguiente = NULL;
}
NodoPila::NodoPila(Proceso proceso, NodoPila *siguiente){
    proceso = proceso;
    siguiente = siguiente;
}
NodoPila::~NodoPila(){
    //Destructor
}