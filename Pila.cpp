#include "Pila.h"
#include "NodoPila.h"
#include <iostream>
#include <string>
using namespace std;
Pila::Pila(){
    cima = NULL;
}
Pila::~Pila(){
    while(cima) desapilar();
}
bool Pila::esVacia(){ 
    return cima == NULL; 
}
/**
 * Apila los procesos en la pila de procesos de forma ordenada según inicio del proceso (aquellos que llevan más tiempo aparecen arriba)
 */
void Pila::apilar(Proceso proceso){
    pNodoPila nuevo = new NodoPila(proceso,cima);
    cima = nuevo;
    Pila pilaAux;
    while(!esVacia() && proceso.inicioProceso < mostrar().inicioProceso){ 
        pilaAux.apilar(mostrar());
        desapilar();
    }
    apilar(proceso);//Si la pila es vacía o el inicio del proceso es mayor que el inicio del proceso de la cima, apilo directamente
    while(!pilaAux.esVacia()){
        apilar(pilaAux.mostrar());
        pilaAux.desapilar();
    }
}
void Pila::desapilar(){
    pNodoPila nodo; 
    if(cima){
        nodo = cima;
        cima = nodo->siguiente;
        delete nodo;
    }
        
}
Proceso Pila::mostrar(){
    if(esVacia()) {
        cout << "Pila vacia"<<endl;
        return NULL;
    }
    else{
        return cima->proceso;
    }
    
}
int Pila::contar(){
    int contar = 0;
    Pila aux;
    while(cima){
        aux.apilar(mostrar());
        desapilar();
        contar ++;
    }
    while(aux.cima){
        apilar(aux.mostrar());
        aux.desapilar();
    }
    return contar;
}
Pila Pila::copiarPila(){
    Pila pilaAux;
    Pila pilaCopia;
    while(!esVacia()){
        pilaAux.apilar(mostrar());
        desapilar();
    }
    while(!pilaAux.esVacia()){
        pilaCopia.apilar(pilaAux.mostrar());
        apilar(pilaAux.mostrar());
        pilaAux.desapilar();
    }

}
void Pila::mostrarProcesosPila(){
    Pila copiaPila = copiarPila();
    while(!copiaPila.esVacia()){
        cout<<copiaPila.mostrar().toString()<<endl;
        copiaPila.desapilar();
    }
}