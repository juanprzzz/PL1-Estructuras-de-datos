#ifndef LISTA_H
#define LISTA_H
#include "Nucleo.h"
#include "NodoLista.h"

class Lista{
    private:
        NodoLista* primero; //o NodoLista*
        NodoLista* ultimo;
        int ctdNucleos;
    public:
        Lista(); //empieza con un núcleo creado
        ~Lista();
        
        void añadirDerecha(); //añade nucleo al final
        void añadirIzquierda(); //añade nucleo al inicio
        Nucleo inicio();
        Nucleo fin();
        void eliminarFin();
        void eliminarInicio();
        //int getCtdNucleosOperativos();     
        //int getCtdNucleosVacios();
        //bool quedaUno();    cuando solo quede un nucleo. siempre tiene que haber minimo 1
        void mostrarLista(); 
        bool esVacia();

        Nucleo menosOcupado(); //devuelve cual es el nucleo menos ocupado
        Nucleo masOcupado(); //devuelve cual es el nucleo con más procesos

};
#endif 