 #include "SistemaLista.h"
#include <iostream>
#include <string>

using namespace std;

SistemaLista::SistemaLista(){
    Pila pilaProcesos;
    Lista lista;
}

SistemaLista::~SistemaLista(){
    //Destructor
}

/*
*Funciones auxiliares para el menu del main
*/
void SistemaLista::añadirNucleo(Nucleo n){
    lista.añadirDerecha(n);
}
void SistemaLista::borrarPila(){ 
    pilaProcesos.~Pila(); 
}
void SistemaLista::mostrarPilaProcesos(){
    pilaProcesos.mostrarPila();
}

bool SistemaLista::pilaVacia(){
    return pilaProcesos.esVacia();
}
bool SistemaLista::listaVacia(){
    return lista.esVacia();
}


void SistemaLista::mostrarProcesosNucleo(){
    lista.mostrarLista();
}


void SistemaLista::apilarSistema(Proceso p){
    if(p.inicioProceso < tiempoTranscurrido){
        cout<<"No se puede añadir ese proceso, el minuto en el que se tiene que iniciar ese proceso, ya ocurrió"<<endl;
    }
    else{
        pilaProcesos.apilar(p);
        ctdProcesos++;
    } 
}



/*
* Se encarga de que transcurra en el sistema N minutos. Se encarga de llamar a las funciones correspondientes para mostrar 
* los núcleos cada minuto, asignación de procesos...
*/

///////////////////////meter que si hay alguno vacio se tiene que borrar
void SistemaLista::pasarTiempo(int N){
Lista aux=lista.copiarLista();
    for(int i = 0; i < N; i++){
        procesoComienzo(); //Primero se comprueba si hay algún proceso que inicie en este minuto. Si lo hay, se añade a la cola 
        while(!aux.esVacia()){//por cada núcleo
            Nucleo prim= aux.primero->nucleo;
            if(prim.procesoEjecucion.tiempoVida == 0){
                cout<<"\nHa finalizado el siguiente proceso al final del minuto "<<tiempoTranscurrido-1<<" del sistema: "<<prim.mostrarProcesoEjecucion()<<endl; 
                tiempoFinalizacion+=tiempoTranscurrido;  //como ha acabado un proceso, se suma el tiempo actual al tiempo de finalización
                prim.terminarProceso(); // Además, como ahora el núcleo está vacío, se sustituye el proceso finalizado por uno vacío con todos los valores a -1
                
            }
            if(prim.ID == -1 && !prim.colaEspera.es_vacia()){ //Si el núcleo está vacío y la cola no está vacía
//////////he juntado aqui la funcion que se llamaba de asignar siuiente proceso//////////////77
                Proceso procesoNuevo = prim.colaEspera.inicio();
                procesoNuevo.nucleo = prim.ID;
                prim.ejecutarProceso(procesoNuevo);
                prim.colaEspera.desencolar();

                cout<<"\nSe ha introducido al inicio del minuto "<<tiempoTranscurrido<<" del sistema, el siguiente proceso: "<<prim.mostrarProcesoEjecucion()<<endl; 
                
            }
            
            prim.procesoEjecucion.tiempoVida --;
            aux.eliminarInicio();
        }
        lista=aux; //sustituyo la lista og por la auxiliar //////////////////////esto funciona????? 
        cout<<"\n Estado de los núcleos. Minuto: "<<tiempoTranscurrido<<endl;
        lista.mostrarLista();
        tiempoTranscurrido ++;
    }
}

/*
* Mira la pila de procesos, si nos encontramos en el minuto en el que se inicia un (o varios) nuevo proceso, lo mete en la cola ordenado por prioridad (para que un proceso menos prioritario no se ejecute antes que otro)
*/
void SistemaLista::procesoComienzo(){
    while(tiempoTranscurrido == pilaProcesos.mostrar().inicioProceso){
            NodoLista *aux;
            aux = lista.primero;
            bool añadido=false;
            while (aux->siguiente != NULL && !añadido){
                if (aux->nucleo.colaEspera.get_longitud()<2){ //si el elemento marcado por aux tiene menos de 2 procesos en su cola de espera
                    aux->nucleo.añadirProceso(pilaProcesos.mostrar());
                    pilaProcesos.desapilar();
                    añadido=true;
                }
                aux = aux->siguiente;
            }
            if (!añadido){//si todos los nucleos estaban llenos
                lista.añadirNuevoNucleo();
                lista.ultimo->nucleo.añadirProceso(pilaProcesos.mostrar());
                pilaProcesos.desapilar();
            }
            //colaEspera.encolarPrioridad(pilaProcesos.mostrar());
            //pilaProcesos.desapilar();
            
            tiempoLlegada+=tiempoTranscurrido;
    }   
}


void SistemaLista::acabarProcesos(){
    
    //solo saldrá del bucle una vez que ninguna condición se cumpla. Es decir, cuando la pila sea vacía y todos los núcleos estén vacíos
    //while(!pilaProcesos.esVacia() ||nucleos[0].nucleo!=-1 || nucleos[1].nucleo!=-1 || nucleos[2].nucleo!=-1){
    // ahora el while deberia ser mientras que la pila no este vacia, la longitud de la cola no sea 1 ese 1 elemento este vacio
   //     pasarTiempo(1);
   // }
    double tiempoMedio=(double) (tiempoFinalizacion-tiempoLlegada)/ctdProcesos;
    cout<<"La suma de los tiempos de llegada de todos los procesos es: "<<tiempoLlegada<<endl;
    cout<<"La suma de los tiempos de finalización de todos los procesos es: "<<tiempoFinalizacion<<endl;
    cout<<"\n El tiempo medio de estancia es: "<<tiempoMedio<<endl;
}