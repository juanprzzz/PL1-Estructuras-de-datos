#include "NodoCola.h"
#include "Cola.h"
#include <iostream>
using namespace std;


Cola::Cola(){
    primero = NULL; 
    ultimo = NULL;
    longitud = 0;
}

Cola::~Cola() { }

void Cola::encolar(Proceso proceso){ 
    NodoCola* nuevo_nodo = new NodoCola(proceso);
    if(es_vacia()){ 
        primero = nuevo_nodo;
        ultimo = nuevo_nodo;
        }
    else{ 
        ultimo->siguiente = nuevo_nodo; //puntero->atributo
        ultimo = nuevo_nodo;
        }
    longitud++;
}
/*
*Se encarga de introducir un proceso en el lugar que le corresponde por prioridad en la cola
*/
void Cola::encolarPrioridad(Proceso proceso){
    Cola aux;
    while(!es_vacia() && inicio().prioridad >= proceso.prioridad){ //Mientras que la cola no esté vacía y el primer elemento de la cola sea más prioritario que el otro proceso
        aux.encolar(inicio()); //Introduzco el proceso más prioritario en la cola aux
        desencolar();
    }
    aux.encolar(proceso); //Cuando la prioridad del primer proceso de la cola es menor, entonces se encola el proceso que quiero (ya que es más prioritario)
    while(!es_vacia()){ //Tengo que encolar en la cola aux el resto de elementos que se han quedado en la cola principal
        aux.encolar(inicio());
        desencolar();
    }
    while(!aux.es_vacia()){ //Como la función no devuelve nada, si no que modifica la cola principal, tengo que introducir los elementos de la cola aux en la principal
        encolar(aux.inicio());
        aux.desencolar();
    }
}


void Cola::desencolar(){ 
    if(!es_vacia()){
         Proceso elemento = primero->proceso; 
         NodoCola* aux = primero;
         if((primero == ultimo) && (primero->siguiente == NULL )){
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete(aux);}
         else{
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete(aux);}
         longitud--;
         //return elemento; si fuera Proceso Cola::desencolar
    }
}

Proceso Cola::inicio(){
     if(!es_vacia()){
         return primero->proceso;
         }
         else{return Proceso();}
}


Proceso Cola::fin(){
     if(!es_vacia()){
         return ultimo->proceso;
         }
         else{return Proceso();}
}

int Cola::get_longitud(){
     return longitud;
}


bool Cola::es_vacia(){
     return ((primero == NULL) && (ultimo ==NULL));
}


void Cola::mostrarCola()
//No es correcto, la cola solo puede verse mostrando el primero y desencolando, se implementa para comprobar código facilmente.
{
    NodoCola* aux = primero;
    if (es_vacia()) {
        cout<<"Cola Vacia:3"<<endl;}
    else {
        while (aux){
            cout<< "_________________"<<endl;
            cout<< "PROCESO"<<endl;
            cout << "PID: "<<aux->proceso.PID<<endl;
            cout << "prioridad: "<<aux->proceso.prioridad<<endl; 
            cout<< "_________________"<<endl;//TODO--------------------------------------------------------- 
            aux = aux->siguiente;
        }
    }
}

Cola Cola::copiarCola(){
    Cola aux;
    Cola copia;
    while(!es_vacia()){
        aux.encolar(inicio());
        copia.encolar(inicio());
        desencolar();
    }
    while(!aux.es_vacia()){
        encolar(aux.inicio());
        aux.desencolar();
    }
    return copia;
}


int Cola::contarElementos(){
    int ctd=0;
    if (es_vacia()){return ctd;}
    else{
        Cola aux=copiarCola();
        while(!aux.es_vacia()){
            ctd++;
            aux.desencolar();
        }
        return ctd;
    }
}