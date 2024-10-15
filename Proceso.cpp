#include "Proceso.h"
#include <iostream>
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