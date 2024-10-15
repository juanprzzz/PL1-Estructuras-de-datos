#include "Proceso.h"
#include <iostream>
#include <string>
using namespace std;

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
string Proceso::toString(){
    string toString = "Proceso -> "+ to_string(PID) + "; Proceso padre -> "+ to_string(PPID) + "; Inicio del proceso desde 00:00 -> " + to_string(inicioProceso) + "; Tiempo de vida -> " + to_string(tiempoVida) + "; Prioridad ->  " + to_string(prioridad) + "; Núcleo -> " + to_string(nucleo);
    return toString;
}