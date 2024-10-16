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

Proceso::Proceso(int pid, int ppid,int inicioproceso, int tiempovida, int prior, int n ){
PID=pid;
PPID=ppid;
inicioProceso=inicioproceso;
tiempoVida=tiempovida;
prioridad=prior;
nucleo=n;
}

Proceso::~Proceso(){
//dtor
}
string Proceso::toString(){
    string procesoToString = "________________________\n\nPROCESO: \nPID: "+ to_string(PID) + "\nPPID: "+ to_string(PPID) + "\n" + "Inicio del proceso: " + to_string(inicioProceso) + "\n" + "Tiempo de vida: " + to_string(tiempoVida) + "\nPrioridad: " + to_string(prioridad) + "\nNúcleo: " + to_string(nucleo) + "\n________________________\n";
    return procesoToString;
}