#ifndef PROCESO_H
#define PROCESO_H
#include <ctime>

class Proceso{
    
    private:
        friend class NodoPila;
        friend class Pila;
        int PID;
        int PPID;
        int inicioProceso;
        int tiempoVida;
        int prioridad;
        int nucleo;
    public:
        Proceso(); //Constructor
        Proceso(int PID, int PPID = 1, int inicioProceso, int tiempoVida, int prioridad, int nucleo);
        ~Proceso(); //Destructor

};


#endif