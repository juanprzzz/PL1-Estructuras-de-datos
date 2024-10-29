#ifndef NUCLEO_H
#define NUCLEO_H
#include "Cola.h"
#include "Proceso.h"

class Nucleo 
{
    private:
        Cola colaEspera;
        int ID;
        Proceso procesoEjecucion;

    friend class NodoPila;
    friend class Pila;
    friend class Sistema;
    friend class NodoCola;
    friend class Cola;
    friend class NodoLista;
    friend class Lista;
       
    public:
        Nucleo();
        Nucleo(int id);
        ~Nucleo();
        void añadirProceso(Proceso proceso); 
        void desencolarProceso();
        void mostrarNucleo();
        void ejecutarProceso(Proceso proceso);
        void terminarProceso();
};

#endif