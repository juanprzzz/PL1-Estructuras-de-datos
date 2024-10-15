#include "Pila.h"
#include "NodoPila.h"
#include <iostream>
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
void Pila::apilar(Proceso proceso){
    pNodoPila nuevo = new NodoPila(proceso,cima);
    cima = nuevo;
    Pila pilaAux;
    while(!esVacia() && proceso.inicioProceso < mostrar().inicioProceso){
        pilaAux.apilar(mostrar());
        desapilar();
    }
    apilar(proceso);
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