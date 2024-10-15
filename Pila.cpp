
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








/*
    void Pila::añadir(Proceso proceso) //solo apila
        { 
            pNodoPila nuevo = new NodoPila(proceso,cima);//comienzo de la pila nuevo nodo
            cima = nuevo; //cima puntero apunta a nvo nodo
        }

    void Pila::apilar(Proceso proceso){ //apila y ordena si es necesario
        bool ordenado=true;
        if (!esVacia() && proceso.inicioProceso>mostrar().inicioProceso){ //si el tiempo nuevo es mayor al de la antigua cima no está ordenada
            ordenado=false;
        }
        añadir(proceso);
        if (ordenado==false){ //si la pila no está ordenada. Si es vacía o está ordenada no hace nada
            ordenar();
        }
    }

    void Pila::ordenar(){
        Pila aux;

        int procesoNuevoTiempo=mostrar().inicioProceso;
        Proceso nuevoNodo=mostrar();
        desapilar(); //elimino el elemento nuevo ya guardado

        //bool salir=false;
        bool insertado=false;
        while (!esVacia()){
            if (procesoNuevoTiempo<=mostrar().inicioProceso){
                añadir(nuevoNodo);
                insertado=true;
            }
            aux.añadir(mostrar());
            desapilar();
        }
        if (insertado==false){
            añadir(nuevoNodo);
        }

        while (!aux.esVacia()){ //recuperar lo que sea que haya perdido de la pila
                    añadir(aux.mostrar());
                    aux.desapilar();
                }

    }
*/






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
                std::cout<< "_________________"<<std::endl;
                std::cout<<" PROCESO:"<<std::endl;
                std::cout<<" PID: "<< actual.PID <<std::endl;
                std::cout<<" PPID: "<<actual.PPID <<std::endl;
                std::cout<<" inicio p: "<< actual.inicioProceso <<std::endl;
                std::cout<<" t vida: "<<actual.tiempoVida <<std::endl;
                std::cout<< " prioridad: "<< actual.prioridad<<std::endl;
                std::cout<< " nucleo: "<<actual.nucleo<<std::endl;
                std::cout<< "_________________"<<std::endl;

                aux.desapilar();

            }
        }
        else{std::cout<<"VACIA:D"<<std::endl;}
    }