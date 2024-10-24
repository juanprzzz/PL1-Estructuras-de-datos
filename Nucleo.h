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

    friend class NodoPila;//para que puedan acceder tanto a metodos publicos como privados
    friend class Pila;
    friend class Sistema;
    friend class NodoCola;
    friend class Cola;
    friend class NodoLista;
    friend class Lista;
       
    public:
        Nucleo();
        Nucleo(int id); //constructor. cola vacía
        ~Nucleo(); //destructor
        void añadir(Proceso proceso); 
        void mostrarNucleo();
};

#endif // NUCLEO_H