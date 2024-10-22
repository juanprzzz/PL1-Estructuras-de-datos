#ifndef LISTA_H
#define LISTA_H
#include "Nucleo.h"

class Lista{
    private:
        /// falta nodoLista
        //NodoLista * primero;
        //NodoLista * ultimo;
        int ctdNucleos;
    public:
        Lista(); //empieza con un núcleo creado
        ~Lista();
        void añadirDerecha(); //añade nucleo al final
        void encolarPrioridad(Proceso);
        Nucleo primero();
        Nucleo ultimo();
        void eliminarUltimo();
        //cosas que pueden servir:
        //void eliminarPrimero();      no creo que sea necesario
        //int getCtdNucleosOperativos();     
        //int getCtdNucleosVacios();
        //bool quedaUno();    cuando solo quede un nucleo. siempre tiene que haber minimo 1
        void mostrarLista(); 

        Nucleo menosOcupado(); //devuelve cual es el nucleo menos ocupado
        Nucleo masOcupado(); //devuelve cual es el nucleo con más procesos







};
#endif 