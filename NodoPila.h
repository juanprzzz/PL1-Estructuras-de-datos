#ifndef NODOPILA_H
#define NODOPILA_H
#include "Proceso.h"
#include <iostream>

class NodoPila{
    private:
        Proceso proceso;
        NodoPila *siguiente;
        friend class Pila;
    public:
        NodoPila();
        NodoPila(Proceso proceso, NodoPila *siguiente=NULL);
        ~NodoPila();
};
typedef NodoPila *pNodoPila;
#endif;