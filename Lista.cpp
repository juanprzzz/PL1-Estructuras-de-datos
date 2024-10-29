#include "NodoLista.h"
#include "Lista.h"
#include "Nucleo.h"
#include <iostream>
using namespace std;

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    ctdNucleos = 0;
}
Lista::Lista(Nucleo n)
{
    primero = new NodoLista(n);
    ultimo = primero;
    ctdNucleos = 1;
}

Lista::~Lista() {}

void Lista::añadirIzquierda(Nucleo nucleo)
{
    ctdNucleos++;
    // Nucleo nucleo = Nucleo(ctdNucleos);
    NodoLista *nuevo_nodo = new NodoLista(nucleo);
    if (esVacia())
    {
        primero = nuevo_nodo;
        ultimo = primero;
    }
    else
    {
        nuevo_nodo->siguiente = primero;
        primero = nuevo_nodo;
    }
}

void Lista::añadirDerecha(Nucleo nucleo)
{
    ctdNucleos++;
    NodoLista *nuevo_nodo = new NodoLista(nucleo);
    if (esVacia())
    {
        primero = nuevo_nodo;
        ultimo = primero;
    }
    else
    {
        // Nucleo nucleo=Nucleo(ctdNucleos);
        ultimo->siguiente = nuevo_nodo; // puntero->atributo -------Falla<<<<
        ultimo = nuevo_nodo;
    }
}

void Lista::eliminarFin()
{
    NodoLista *aux; // puntero aux para manipular el nodo
    if (!esVacia() && ctdNucleos >= 2)
    { // si solo hay 1 no puedo hacer siguiente->siguiente
        aux = primero;
        while (aux->siguiente->siguiente != NULL)
        { // si el elemento siguiente tiene como atributo "siguiente" null (si el siguiente del aux es el ultimo)
            aux = aux->siguiente;
        }
        ultimo = aux;
        ultimo->siguiente = NULL;
        delete aux;
        ctdNucleos--;
    }
}

void Lista::eliminarInicio()
{ ////////////////////warning- puede haber error de ctdNucleos. auxiliar solo!
    if (!esVacia())
    { //////////////cuidado, siempre tiene que haber al menos 1 nucleo en lista!
        Nucleo elemento = primero->nucleo;
        NodoLista *aux = primero;
        if ((primero == ultimo) && (primero->siguiente == NULL))
        { // si solo hay 1 elemento. podria ser if (ctdNucleos==1) DUDA: Si primero es el último entonces su puntero al siguiente será null, entonces ¿Por qué comprobarlo?
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete aux;
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete aux;
        }
    }
}

Nucleo Lista::inicio()
{
    if (!esVacia())
    {
        return primero->nucleo;
    }
    else
    {
        return Nucleo();
    }
}

Nucleo Lista::fin()
{
    if (!esVacia())
    {
        return primero->nucleo;
    }
    else
    {
        return Nucleo();
    }
}

void Lista::mostrarLista()
{
    Lista listaCopia = copiarLista();
    while (!listaCopia.esVacia())
    {
        listaCopia.inicio().mostrarNucleo();
        listaCopia.eliminarInicio();
    }
}
Lista Lista::copiarLista()
{
    Lista listaAux;
    Lista listaResultado;
    while (!esVacia())
    {
        listaAux.añadirDerecha(inicio());
        listaResultado.añadirDerecha(inicio());
        eliminarInicio();
    }
    while (!listaAux.esVacia())
    {
        añadirDerecha(listaAux.inicio());
        listaAux.eliminarInicio();
    }
    return listaResultado;
}

bool Lista::esVacia()
{
    return ((primero == NULL) && (ultimo == NULL));
}