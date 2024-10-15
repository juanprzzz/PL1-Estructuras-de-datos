#include "Proceso.h"
#include <iostream>
using namespace std;


Proceso::Proceso(){
PID=0;
PPID=1;
inicioProceso=0;
tiempoVida=0;
prioridad=0;
nucleo=0;
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