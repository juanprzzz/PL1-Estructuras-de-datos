#include "Proceso.h"
#include <iostream>
#include <string>
using namespace std;


Proceso::Proceso(){
PID=-1;
PPID=-1;
inicioProceso=-1;
tiempoVida=-1;
prioridad=-1;
nucleo=-1;
//constructor por defecto
}

Proceso::Proceso(int pid, int ppid,int inicioproceso, int tiempovida, int prior, int n){
    if  (pid>0  && inicioproceso>0 && tiempovida>0 && prior>=0 &&prior<=9){
        PID=pid;
        PPID=ppid;
        inicioProceso=inicioproceso;
        tiempoVida=tiempovida;
        prioridad=prior;
        nucleo=n;
    }else{Proceso();}
}

Proceso::~Proceso(){
//dtor
}
string Proceso::toString(){
    string procesoToString = "PROCESO ---> PID: "+ to_string(PID) + ", PPID: "+ to_string(PPID) + ", Inicio del proceso: " + to_string(inicioProceso) + ", Tiempo de vida: " + to_string(tiempoVida) + ", Prioridad: " + to_string(prioridad) + ", Núcleo: " + to_string(nucleo);
    return procesoToString;
}