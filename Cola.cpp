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

void Cola::encolar(char elemento){ 
    NodoCola* nuevo_nodo = new NodoCola(elemento);
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

char Cola::desencolar(){ 
    if(!es_vacia()){
         char elemento = primero->elemento; 
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
         return elemento;
}
}

char Cola::inicio(){
     if(!es_vacia()){
         return primero->elemento;
         }
}


char Cola::fin(){
     if(!es_vacia()){
         return ultimo->elemento;
         }
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
        cout<<"Cola Vacía:3"<<endl;}
    else {
        cout<<"Datos de la Cola: "<<endl;
        while (aux){
            cout << aux->elemento<<endl;
            aux = aux->siguiente;
        }
    }
}

//ejercicios
Cola Cola::invertir(){
    Cola aux;
    while (get_longitud() >1){

    }

}
