#ifndef NODOLISTA_H
#define NODOLISTA_H
#include <iostream>
#include "Nucleo.h"

class NodoLista
{
    private:
        NodoLista* siguiente;
        Nucleo nucleo;
    
    friend class Lista;

    public:
        NodoLista();
        NodoLista(Nucleo n, NodoLista*sig = NULL);
        ~NodoLista();
};
#endif // NODOCOLA_H