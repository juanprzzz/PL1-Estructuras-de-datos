#include "Pila.h"
#include "NodoPila.h"
#include "Proceso.h"
#include <iostream>


Pila::Pila()
{
    cima = NULL;}

Pila::~Pila()
{   
    while(cima) {
        desapilar();}
    }


 void Pila::añadir(Proceso proceso) //solo apila
        { 
            pNodoPila nuevo = new NodoPila(proceso,cima);//comienzo de la pila nuevo nodo
            cima = nuevo; //cima puntero apunta a nvo nodo
        }

void Pila::apilar(Proceso proceso){ //apila y ordena si es necesario
    if (esVacia() || (proceso.inicioProceso<=mostrar().inicioProceso)){ //si la pila es vacia o si el tiempo del nuevo es menor o igual al de la cima
        añadir(proceso); //apilo el nuevo directamente
    }
    else{ 
        Pila aux;
        bool insertado=false;
        while (!esVacia() && insertado==false){
            aux.añadir(mostrar()); //voy guardando los que no cumplan la condición del if de abajo. Se guarda directamente el primer elemento por la condicion del if arriba
            desapilar();
            if (proceso.inicioProceso<=mostrar().inicioProceso){
                añadir(proceso);
                insertado=true;
            }
        }
        if (insertado==false){ //si la pila se quedó vacía y el tiempo del nuevo era mayor a todos, se mete al fondo 
            añadir(proceso);
        }

        while (!aux.esVacia()){ //recuperar lo que sea que haya perdido de la pila
                    añadir(aux.mostrar());
                    aux.desapilar();
                }
    }
    
}


    Pila Pila::copiarPila(){ //copia pila actual en aux sin perder pila
        Pila aux;
        Pila pilaCopia;
        while (!esVacia()){
            aux.añadir(mostrar());
            pilaCopia.añadir(mostrar());
            desapilar();
        }
        while(!aux.esVacia()){
            añadir(aux.mostrar());
            aux.desapilar();
        }
        return pilaCopia;
    }


    void Pila::desapilar()
        { pNodoPila aux; //puntero aux para manipular el nodo
        if(cima){ //si cima !=NULL
            aux = cima;
            cima = aux->siguiente; //cima= el valor (que es un puntero por el tipo de dato) de la variable siguiente de aux(=cima)
            delete aux;  
            }
        }

     bool Pila::esVacia() 
        { return cima == NULL; }



    Proceso Pila::mostrar() 
        {   
        if(esVacia()) {
            return Proceso(); 
            }
        else{
            return cima->proceso; 
            }
        }


    void Pila::mostrarPila(){
        Pila aux=copiarPila();
        cout<<"La cima es: "<<mostrar().toString()<<endl;
        cout<<"PILA: "<<endl;
        if (!aux.esVacia()){
            while(!aux.esVacia()){
                Proceso actual=aux.mostrar();
                std::cout<<actual.toString()<<endl;
                aux.desapilar();
            }
        }
        else{std::cout<<"La pila está vacía"<<std::endl;}
    }