#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"

class Pila{
    private:
        pNodoPila cima;
    public:
        Pila();
        ~Pila();
        bool esVacia();
        void apilar(Proceso proceso);
        void desapilar();
        Proceso mostrar();
        void mostrarPila();
        int contar();
        Pila copiarPila();
        void mostrarProcesosPila();
};
#endif PILA_H;