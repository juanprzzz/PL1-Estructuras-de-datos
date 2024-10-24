#ifndef PILA_H
#define PILA_H
#include "NodoPila.h"
#include "Proceso.h"

class Pila //clase amiga de nodopila.h
{
    private:
        pNodoPila cima; //puntero al 1er elemento, cima pila 

    public:
        Pila(); //constructor
        ~Pila(); //destructor
        bool esVacia();
        void añadir(Proceso proceso); //apila un elemento e la cima de la pila sin ordenarla
        void apilar(Proceso proceso); //apila elemento y lo ordena
        void desapilar();
        Proceso mostrar();
        Pila copiarPila();
        void mostrarPila();
};

#endif // PILA_H