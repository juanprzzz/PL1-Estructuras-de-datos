#ifndef PROCESO_H ////??????????????????
#define PROCESO_H
#include <iostream>
#include <ctime>

class Proceso
{
    private:
        int PID;
        int PPID;
        int inicioProceso;
        int tiempoVida;
        int prioridad;
        int nucleo;

    friend class NodoPila;//clase pila y nodopila podra acceder tanto a metodos publicos como privados
    friend class Pila;
    friend class NodoCola;
    friend class Cola;

    public:
        Proceso(); //constructor
        Proceso(int PID, int PPID,int inicioProceso, int tiempoVida, int prioridad, int nucleo); //constructor donde meto elemento y ountero null, se hace asi por defecto
        ~Proceso(); //destructor
};

//typedef Proceso *pProceso; //creas nuevo tipo de dato nodopila que es un puntero

#endif // PROCESO_H