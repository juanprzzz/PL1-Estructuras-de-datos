#include "Sistema.h"
#include <iostream>

using namespace std;

Sistema::Sistema(){
    Pila pilaProcesos;
    Cola colaEspera;
    Proceso nucleos[3];
    int tiempoTranscurrido = 0;
}



Sistema::~Sistema(){
    //Destructor
}

/*
*Funciones auxiliares para el menu del main
*/
void Sistema::añadirCola(Proceso p){
    colaEspera.encolarPrioridad(p);
}
void Sistema::borrarPila(){ 
    pilaProcesos.~Pila(); 
}
void Sistema::mostrarPilaProcesos(){
    pilaProcesos.mostrarPila();
}
void Sistema::mostrarColaPrioridad(){
    colaEspera.mostrarCola();
}



void Sistema::mostrarProcesosNucleo(){
    for(int i = 0; i < 3; i++){
        if(nucleos[i].nucleo!=-1){ 
            cout<<"Núcleo "<<i+1<<": \n"<<nucleos[i].toString()<<endl;
        }
        else{
            cout<<"Núcleo "<< i+1 <<": "<<" libre."<<endl;     
        }
        
    }
}


void Sistema::apilarSistema(Proceso p){
    if(p.inicioProceso < tiempoTranscurrido){
        cout<<"No se puede añadir ese proceso, el minuto en el que se tiene que iniciar ese proceso, ya ocurrió"<<endl;
    }
    else{
        pilaProcesos.apilar(p);
        ctdProcesos++;
        cout<<"\n metiendo en pila. ctd procesos: "<<ctdProcesos<<endl;
    }
    
}
/*
* Se encarga de que transcurra en el sistema N minutos. Se encarga de llamar a las funciones correspondientes para mostrar 
* los núcleos cada minuto, asignación de procesos...
*/
void Sistema::pasarTiempo(int N){

    for(int i = 1; i < N + 1; i++){
        procesoComienzo();
        for(int n = 0; n < 3; n++){
            if(nucleos[n].nucleo == -1 && !colaEspera.es_vacia()){ //Si el núcleo está vacío y la cola no está vacía
                if(asignarSiguienteProcesoDesdeCola(n)){ 
                    cout<<"Se ha introducido en el minuto "<<tiempoTranscurrido<<" del sistema, el siguiente proceso: "<<nucleos[n].toString()<<endl;
                } 
            }
            if(nucleos[n].tiempoVida == 0){
                cout<<"Ha finalizado el siguiente proceso en el minuto "<<tiempoTranscurrido-1<<" del sistema: "<<nucleos[n].toString()<<endl;
                tiempoFinalizacion+=(tiempoTranscurrido-1); 
                nucleos[n] = Proceso();
            }
            nucleos[n].tiempoVida --;
        }

        cout<<"\n Estado de los núcleos. Minuto: "<<tiempoTranscurrido<<endl;
        mostrarProcesosNucleo();
        tiempoTranscurrido ++;
    }
}


/*
* Mira la pila de procesos, si nos encontramos en el minuto en el que se inicia un (o varios) nuevo proceso, lo mete en la cola ordenado por prioridad (para que un proceso menos prioritario no se ejecute antes que otro)
*/
void Sistema::procesoComienzo(){
    while(tiempoTranscurrido == pilaProcesos.mostrar().inicioProceso){
            colaEspera.encolarPrioridad(pilaProcesos.mostrar());
            pilaProcesos.desapilar();
            tiempoLlegada+=tiempoTranscurrido;
            cout<<"\n metiendo en cola. El tiempo total de llegada es: "<<tiempoLlegada<<endl;
        
    }
        
}
/*
* Si un núcleo se queda libre,introduce otro proceso en este desde la cola
*/
bool Sistema::asignarSiguienteProcesoDesdeCola(int nucleoLibre){ //nucleo introducido es del 0 al 2
    if (!colaEspera.es_vacia()){
        Proceso procesoNuevo = colaEspera.inicio();
        procesoNuevo.nucleo = nucleoLibre+1;
        nucleos[nucleoLibre] = procesoNuevo;
        colaEspera.desencolar();
        return true;
    }
    else{
        return false;
    }

}



void Sistema::acabarProcesos(){
    cout<<pilaProcesos.esVacia()<<endl;
    while(!pilaProcesos.esVacia() ||nucleos[0].nucleo!=-1 || nucleos[1].nucleo!=-1 || nucleos[2].nucleo!=-1){
        pasarTiempo(1);
    }
    double tiempoMedio=(double) (tiempoFinalizacion-tiempoLlegada)/ctdProcesos;
    cout<<"\n El tiempo medio de proceso es: "<<tiempoMedio<<endl;
}
bool Sistema::pilaVacia(){
    return pilaProcesos.esVacia();
}

