#include "Proceso.h"

Proceso::Proceso(){
    PID = 0;
    PPID = 1;
    inicioProceso = 0;
    tiempoVida = 0;
    prioridad = 0;
    nucleo = 0;
}
Proceso::Proceso(int PID, int PPID = 1, int inicioProceso, int tiempoVida, int prioridad, int nucleo){
    PID = PID;
    PPID = PPID;
    inicioProceso = inicioProceso;
    tiempoVida = tiempoVida;
    prioridad = prioridad;
    nucleo = nucleo;
}
Proceso::~Proceso(){
    //Destructor
}