#ifndef PROCESO_H ////??????????????????
#define PROCESO_H
#include <iostream>
//#include <ctime>
#include <string>
using namespace std;
class Proceso
{
    private:
        int PID;
        int PPID;
        int inicioProceso;
        int tiempoVida;
        int prioridad;
        int nucleo;

    friend class NodoPila;//para que puedan acceder tanto a metodos publicos como privados
    friend class Pila;
    friend class Sistema;
    friend class NodoCola;
    friend class Cola;
    friend class Nucleo;
    friend class NodoLista;
    friend class Lista;

    public:
        Proceso(); //constructor
        Proceso(int PID, int PPID,int inicioProceso, int tiempoVida, int prioridad, int nucleo); 
        ~Proceso(); //destructor
        string toString(); 

};

#endif // PROCESO_H