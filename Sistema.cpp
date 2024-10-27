#include "Sistema.h"
#include <iostream>
#include <array>
#include <string>
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
//void Sistema::desencolarCola(){colaEspera.desencolar();}
void Sistema::borrarPila(){ 
    pilaProcesos.~Pila(); //desapila mientras haya procesos dentro
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
    pilaProcesos.apilar(p);
    ctdProcesos++;
    cout<<"\n metiendo en pila. ctd procesos: "<<ctdProcesos<<endl;
}
/*
* Se encarga de que transcurra en el sistema N minutos. Se encarga de llamar a las funciones correspondientes para mostrar 
* los núcleos cada minuto, asignación de procesos...
*/
void Sistema::pasarTiempo(int N){
    int colasVacia[3] = {0,0,0}; //Se introduce esta variable para saber qué nucleos no tienen ningún proceso en la cola
    for(int i = 1; i < N + 1; i++){ //por cada minuto que pasa 
        procesoComienzo();//se llama a un método para ver si hay algún proceso que inicie en este minuto, que se añade a la cola
        for(int n = 0; n < 3; n++){ //para cada nucleo
            if(nucleos[n].nucleo == -1 && !colaEspera.es_vacia()){ //Si el núcleo está vacío y la cola no está vacía

//////////////////////////////////////necesario el !colaespera vacia??? en asignar siguiente ya lo comprueba (es la unica comprobacion que tiene)
/////////////////////////////////// se podria hacer que asignarsiguienteproceso fuera void en vez de bool y hiciera el print directamente dentro para bajar coste (1 if menos)


                if(asignarSiguienteProcesoDesdeCola(n)){ 
                    cout<<"Se ha introducido en el minuto "<<tiempoTranscurrido<<" del sistema, el siguiente proceso: "<<nucleos[n].toString()<<endl;
                } 
            }
            if(nucleos[n].tiempoVida == 0){
                cout<<"Ha finalizado el siguiente proceso en el minuto "<<tiempoTranscurrido-1<<" del sistema: "<<nucleos[n].toString()<<endl;
                tiempoFinalizacion+=(tiempoTranscurrido-1); 
                cout<<"\n t. finalizacion: "<<tiempoFinalizacion<<endl;
                //como ha acabado un proceso, se suma el tiempo actual al tiempo de finalización
                nucleos[n] = Proceso();
            }

///////////////////////////////////////// meter lo de tiempo-- en else ?

            nucleos[n].tiempoVida --;
        }
        cout<<"\n Estado de los núcleos. Minuto: "<<tiempoTranscurrido<<endl;
        mostrarProcesosNucleo();

        tiempoTranscurrido ++;
    }
}


/*
* Mira la pila de procesos, si nos encontramos en el minuto en el que se inicia un (o varios) nuevo proceso, lo mete en el núcleo si está libre, y si no, lo mete en la cola
*/
void Sistema::procesoComienzo(){
    while(tiempoTranscurrido == pilaProcesos.mostrar().inicioProceso){//mientras el tiempo de inicio del proceso de la cima sea igual al minuto actual
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
        procesoNuevo.nucleo = nucleoLibre+1; //modificar numero de nucleo del proceso (era 0 si no esta asignado)
        nucleos[nucleoLibre] = procesoNuevo;
        colaEspera.desencolar();
        return true;
    }
    else{
        return false;
    }

}



void Sistema::acabarProcesos(){
    while(!pilaProcesos.esVacia() ||nucleos[0].nucleo!=-1 || nucleos[1].nucleo!=-1 || nucleos[2].nucleo!=-1 ){
        pasarTiempo(1);
    }

    double tiempoMedio=(double) (tiempoFinalizacion-tiempoLlegada)/ctdProcesos;
    cout<<"\n t. llegada: "<<tiempoLlegada<<endl;
    cout<<"\n t. finalizacion: "<<tiempoFinalizacion<<endl;
    cout<<"\n ctd procesos: "<<ctdProcesos<<endl;
    cout<<"\n El tiempo medio de proceso es: "<<tiempoMedio<<endl;
}

