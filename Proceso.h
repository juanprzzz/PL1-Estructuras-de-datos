#ifndef PROCESO_H 
#define PROCESO_H
#include <string>

using namespace std;

class Proceso{
    private:
        int PID;
        int PPID=1;
        int inicioProceso;
        int tiempoVida;
        int prioridad;
        int nucleo=0;

        friend class NodoPila;
        friend class Pila;
        friend class Sistema;
        friend class NodoCola;
        friend class Cola;
        friend class Nucleo;
        //friend class NodoLista; Necesario para parte 2
        //friend class Lista; Necesario para Parte 2

    public:
        Proceso();
        Proceso(int PID,int inicioProceso, int tiempoVida, int prioridad); 
        ~Proceso();
        string toString(); 

};

#endif // PROCESO_H