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
void Cola::encolarPrioridad(Proceso proceso){
    Cola aux;
    while(!es_vacia() && inicio().prioridad >= proceso.prioridad){
        aux.encolar(inicio());
        desencolar();
    }
    aux.encolar(proceso);
    while(!es_vacia()){
        aux.encolar(inicio());
        desencolar();
    }
    while(!aux.es_vacia()){
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
