//#include "NodoLista.h"
#include "Lista.h"
#include <iostream>
using namespace std;


Lista::Lista(){
    //primero = NodoLista(); 
    //ultimo = primero;
    ctdNucleos=1;
}

Lista::~Lista() { }

void Lista::añadirDerecha(){ 
    ctdNucleos++;
    Nucleo nucleo=Nucleo(ctdNucleos);
   // NodoLista* nuevo_nodo = new NodoLista(nucleo);
    //ultimo->siguiente = nuevo_nodo; //puntero->atributo
    //ultimo = nuevo_nodo;
}



void Lista::eliminarUltimo(){ 
    ////////////////////////////////////hacer
         ctdNucleos--;
    }


Nucleo Lista::primero(){
     ///////////////
}


Nucleo Lista::ultimo(){
    /////////////
}


void Lista::mostrarLista(){
    ////////////////
}