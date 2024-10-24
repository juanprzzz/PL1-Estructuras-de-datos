
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
    if (esVacia() || (proceso.inicioProceso<=mostrar().inicioProceso)){
        añadir(proceso);
    }
    else{ // (!esVacia() && !(proceso.inicioProceso<=mostrar().inicioProceso)){
        Pila aux;
        bool insertado=false;
        while (!esVacia() && insertado==false){
            aux.añadir(mostrar());
            desapilar();
            if (proceso.inicioProceso<=mostrar().inicioProceso){
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
           // std::cout << "Pila vacia"<<std::endl;
            return Proceso(); //NULL?
            }
            else{
            //std::cout << "Cima pila: "<< cima->valor<<std::endl;
            return cima->proceso; //-> para acceder al valor del puntero cima
            
            }
        }


    int Pila::contar(){
       //puedo hacer Pila aux; y despues usarla por ej como aux.cima
       Pila aux; 
        int ctd=0;
        while(cima){
            ctd++;
            aux.añadir(mostrar()); //apilar(cima->valor)
            desapilar(); 
        }
        while(aux.cima){
            añadir(aux.mostrar());
            aux.desapilar();
        }
        return ctd;
    }


    void Pila::mostrarPila(){
        Pila aux=copiarPila();
        if (!aux.esVacia()){
            while(!aux.esVacia()){
                Proceso actual=aux.mostrar();
                std::cout<<actual.toString()<<endl;
                aux.desapilar();

            }
        }
        else{std::cout<<"VACIA:D"<<std::endl;}
    }