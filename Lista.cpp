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

Lista::~Lista() {
    while(!esVacia()){
        eliminarInicio();
    }
}

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
        while (aux->siguiente->siguiente!= NULL)
        { // si el elemento siguiente tiene como atributo "siguiente" null (si el siguiente del aux es el ultimo)
            aux = aux->siguiente;
        }
        ultimo = aux;
        ultimo->siguiente = NULL;
        //delete aux;
        ctdNucleos--;
    }

    else if(ctdNucleos == 1){
        primero = NULL;
        ultimo = NULL;
        ctdNucleos --;
    }
    
}

void Lista::eliminarInicio()
{ 
    if (!esVacia())
    { //////////////cuidado, siempre tiene que haber al menos 1 nucleo en lista!
        Nucleo elemento = primero->nucleo;
        NodoLista *aux = primero;
        if ((primero == ultimo) && (primero->siguiente == NULL)){ // si solo hay 1 elemento. podria ser if (ctdNucleos==1) DUDA: Si primero es el último entonces su puntero al siguiente será null, entonces ¿Por qué comprobarlo?
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete aux;
        }
        else {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete aux;
        }
        ctdNucleos--;
    }
    else if(ctdNucleos == 1){
        primero = NULL;
        ultimo = NULL;
        ctdNucleos --;
    }
}

Nucleo Lista::inicio()
{
    if (!esVacia()){
        return primero->nucleo;
    }
    else{
        return Nucleo();
    }
}

Nucleo Lista::fin()
{
    if (!esVacia())
    {
        cout<<ultimo->nucleo.colaEspera.es_vacia()<<endl;
        return ultimo->nucleo;
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
    listaAux.inicio().mostrarNucleo();
    while (!esVacia())
    {
        listaAux.añadirDerecha(inicio());
        listaResultado.añadirDerecha(inicio());
        eliminarInicio();
    }
    ctdNucleos = 0;
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


int Lista::getCtdNucleos(){
    return ctdNucleos;
}



void Lista::menosOcupado(){
    if (esVacia()){
        cout<<"Está vacía"<<endl;}
    else {
        if (ctdNucleos==1){
            cout<<"Hay 1 núcleo solo:"<<endl;
            primero->nucleo.mostrarNucleo();
            }

        else //if (ctdNucleos > 1)
        { 
            NodoLista *aux; // puntero aux para manipular el nodo
            Lista resultado;
            Nucleo nucleoAux;
            aux = primero;
            nucleoAux=primero->nucleo;
            resultado.añadirDerecha(nucleoAux);

            while (aux->siguiente != NULL)
            { //hasta que llegue al final de los elementos 
                aux = aux->siguiente;
                if (nucleoAux.colaEspera.get_longitud()>aux->nucleo.colaEspera.get_longitud()){
                    resultado.~Lista();  //si encuentra que el siguiente nucleo de la lista está menos ocupado, borra la lista y lo mete
                    nucleoAux=aux->nucleo;
                    resultado.añadirDerecha(nucleoAux);
                }     
                else if (nucleoAux.colaEspera.get_longitud()==aux->nucleo.colaEspera.get_longitud()) {
                    nucleoAux=aux->nucleo; //si encuentra que el siguiente nucleo esta igual de ocupado, lo añade también a la lista
                    resultado.añadirDerecha(nucleoAux);
                }      
            }
            cout<<"menos ocupado; ctd nucleos:"<<ctdNucleos<<endl;
            resultado.mostrarLista();
        }
    }
}


void Lista::masOcupado(){
    if (esVacia()){
        cout<<"Está vacía"<<endl;}
    else {
        if (ctdNucleos==1){
            cout<<"Hay 1 núcleo solo:"<<endl;
            primero->nucleo.mostrarNucleo();
            }

        else //if (ctdNucleos > 1)
        { 
            NodoLista *aux; // puntero aux para manipular el nodo
            Lista resultado;
            Nucleo nucleoAux;
            aux = primero;
            nucleoAux=primero->nucleo;
            resultado.añadirDerecha(nucleoAux);

            while (aux->siguiente != NULL)
            { //hasta que llegue al final de los elementos 
                aux = aux->siguiente;
                if (nucleoAux.colaEspera.get_longitud()<aux->nucleo.colaEspera.get_longitud()){
                    resultado.~Lista();  //si encuentra que el siguiente nucleo de la lista está más ocupado, borra la lista y lo mete
                    nucleoAux=aux->nucleo;
                    resultado.añadirDerecha(nucleoAux);
                }     
                else if (nucleoAux.colaEspera.get_longitud()==aux->nucleo.colaEspera.get_longitud()) {
                    nucleoAux=aux->nucleo; //si encuentra que el siguiente nucleo esta igual de ocupado, lo añade también a la lista
                    resultado.añadirDerecha(nucleoAux);
                }      
            }
            cout<<"mas ocupado; ctd nucleos:"<<ctdNucleos<<endl;
            resultado.mostrarLista();
        }
    }
}



bool Lista::comprobarAñadirNuevosNucleos(){
    Lista listaCopia = copiarLista();
    bool añadir = true;
    listaCopia.eliminarInicio(); //------------ Mirar el núcleo vacío -------------//
    while(!listaCopia.esVacia() && añadir){
        //cout<<"Kfds-->   "<<listaCopia.inicio().colaEspera.get_longitud();
        cout<<"Solucion-->"<<listaCopia.inicio().colaEspera.get_longitud()<<endl;
        if(listaCopia.inicio().colaEspera.get_longitud() < 2){
            cout<<"entraa"<<endl;
            añadir = false;
        }
        cout<<"fdsffsfsdfsdfsdfsdfsd"<<endl;
        listaCopia.eliminarInicio();
    }
    return añadir;
}
void Lista::añadirNuevoNucleo(){
    if(comprobarAñadirNuevosNucleos()){
        añadirDerecha(Nucleo(ctdNucleos + 1));
    }
        
}

bool Lista::comprobarEliminarNucleos(){
    Lista listaCopia = copiarLista();
    int nucleosVacios = 0;
    bool eliminar = false;
    while(!listaCopia.esVacia()){
        if(listaCopia.inicio().colaEspera.es_vacia() && listaCopia.inicio().procesoEjecucion.nucleo == -1){
            nucleosVacios ++;
        }

        listaCopia.eliminarInicio();
    }
    if(nucleosVacios >= 2){
        eliminar = true;
    }
    return eliminar;
}
void Lista::eliminarNucleosVacios(){
    if(comprobarEliminarNucleos()){
        Lista listaNoEliminados;
        while(!esVacia()){
            if(!(inicio().colaEspera.es_vacia() && inicio().procesoEjecucion.nucleo == -1)){
                listaNoEliminados.añadirDerecha(inicio());
            }
        }
        while(!listaNoEliminados.esVacia()){
            añadirDerecha(listaNoEliminados.inicio());
            listaNoEliminados.eliminarInicio();
        }
    }
}