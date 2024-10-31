#ifndef LISTA_H
#define LISTA_H
#include "Nucleo.h"
#include "NodoLista.h"

class Lista{
    private:
        NodoLista* primero; //o NodoLista*
        NodoLista* ultimo;
        int ctdNucleos;

        friend class SistemaLista; 
    public:
        Lista(); 
        Lista(Nucleo nucleo);
        ~Lista();
        
        void añadirDerecha(Nucleo nucleo); //añade nucleo al final
        void añadirIzquierda(Nucleo nucleo); //añade nucleo al inicio
        Nucleo inicio();
        Nucleo fin();
        void eliminarFin();
        void eliminarInicio();
        //int getCtdNucleosOperativos();     
        //int getCtdNucleosVacios();
        int getCtdNucleos(); //longitud de la lista
        //bool quedaUno();    cuando solo quede un nucleo. siempre tiene que haber minimo 1
        void mostrarLista(); 
        bool esVacia();
        Lista copiarLista();
        void menosOcupado(); //devuelve cual es el nucleo menos ocupado
        void masOcupado(); //devuelve cual es el nucleo con más procesos
        bool comprobarAñadirNuevosNucleos();
        void añadirNuevoNucleo();
        int comprobarEliminarNucleos();
        void eliminarNucleosVacios(int nucleosVacios);




        void quecoñopasa();

};

#endif 