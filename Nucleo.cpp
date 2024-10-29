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

void Nucleo::mostrarNucleo(){
    if(ID!=-1){ //nucleo no vacio
        cout<<"------------------------"<<endl;
        cout<<"NUCLEO---> ID: "<<ID<<endl;
        colaEspera.mostrarCola();
        cout<<procesoEjecucion.toString()<<endl;
        cout<<"------------------------"<<endl;
        
    }
    else{
        cout<<"El nucleo está vacío"<<endl;
    }

}
Nucleo::~Nucleo(){}

//setters
void Nucleo::añadirProceso(Proceso p){
    colaEspera.encolarPrioridad(p);
}

void Nucleo::desencolarProceso(){
    colaEspera.desencolar();
}

void Nucleo::ejecutarProceso(Proceso p){
   procesoEjecucion=p;
}

void Nucleo::terminarProceso(){
   procesoEjecucion=Proceso();
}
