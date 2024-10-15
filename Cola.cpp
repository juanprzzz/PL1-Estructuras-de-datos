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
        
    if (es_vacia() || (proceso.prioridad>=fin().prioridad) ){ //si la prioridad del nuevo es mayor a la del último elemento de la cola o si la cola está vacía, se mete al final
        encolar(proceso);        
    }
    else if ((proceso.prioridad<inicio().prioridad)){ //si la prioridad del nuevo es menor a la del primero, se mete primero
        aux.encolar(proceso); //añado a la auxiliar el nuevo para que sea el 1er elemento
        while (!es_vacia()){ //después añado a la auxiliar todo el resto de la cola
            aux.encolar(inicio());
            desencolar();
        }
        while(!aux.es_vacia()){ //recupero la cola original
            encolar(aux.inicio());
            aux.desencolar();
        }

    }else{ // (!es_vacia() && !(proceso.prioridad<=inicio().prioridad)){
        bool insertado=false;
        while(!es_vacia() && insertado==false){
            aux.encolar(inicio());
            desencolar();
            if(proceso.prioridad<inicio().prioridad){//si la prioridad del nuevo es menor que la del actual primero de la cola
                aux.encolar(proceso); //entonces añado a la auxiliar el nuevo
                insertado=true;

                while (!es_vacia()){ //después añado a la auxiliar todo el resto de la cola
                    aux.encolar(inicio());
                    desencolar();
                }
            }
            if(proceso.prioridad==inicio().prioridad){//si la prioridad del nuevo es igual que la del actual primero 
            //el nuevo se añade después del último con esa prioridad ya que va por tiempo de espera
                while(proceso.prioridad==inicio().prioridad){ //se añaden los de la misma prioridad a la auxiliar hasta que deje de haber. 
                //Nunca se llegará al final de la cola en este bucle por comprobación anterior
                    aux.encolar(inicio());
                    desencolar();
                }
                aux.encolar(proceso); //entonces añado a la auxiliar el nuevo
                insertado=true;

                while (!es_vacia()){ //después añado a la auxiliar todo el resto de la cola
                    aux.encolar(inicio());
                    desencolar();
                }
            }
        }
        while(!aux.es_vacia()){ //recupero la cola original
            encolar(aux.inicio());
            aux.desencolar();
        }
        
        /*
        //no creo que sea necesario por comprobaciones iniciales
        if (insertado==false){ //si después de recuperar la cola original aun no se ha insertado el nuevo, lo metemos al final
            encolar(proceso);
        }*/
    }
}


/*
void Pila::apilar(Proceso proceso){ //apila y ordena si es necesario
    if (esVacia() || (proceso.inicioProceso>=mostrar().inicioProceso)){
        añadir(proceso);
    }
    else{ // (!esVacia() && !(proceso.inicioProceso<=mostrar().inicioProceso)){
        Pila aux;
        bool insertado=false;
        while (!esVacia() && insertado==false){
            aux.añadir(mostrar());
            desapilar();
            if (proceso.inicioProceso>=mostrar().inicioProceso){
                añadir(proceso);
                insertado=true;
            }
        }
        if (insertado==false){
            añadir(proceso);
        }

        while (!aux.esVacia()){ //recuperar lo que sea que haya perdido de la pila
                    añadir(aux.mostrar());
                    aux.desapilar();
                }
    }
    
}

*/


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


