#include "Sistema.h"
#include <iostream>
#include <array>
#include <string>
using namespace std;
Sistema::Sistema(){
    Pila pilaProcesos;
    Cola colaPrioridadUno;
    Cola colaPrioridadDos;
    Cola colaPrioridadTres;
    Proceso nucleos[3];
}
Sistema::Sistema(Pila pilaProcesosI, Cola colaPrioridadUnoI, Cola colaPrioridadDosI, Cola colaPrioridadTresI){
    pilaProcesos = pilaProcesosI;
    colaPrioridadUno = colaPrioridadUnoI;
    colaPrioridadDos = colaPrioridadDosI;
    colaPrioridadTres = colaPrioridadTresI;
    Proceso nucleos[3];
}
Sistema::~Sistema(){
    //Destructor
}
void Sistema::mostrarProcesosNucleo(){
    for(int i = 0; i < 3; i++){
        if(nucleos[i].nucleo!=-1){
            cout<<nucleos[i].toString()<<endl;
        }
        else{
            cout<<"Núcleo: "<< i+1 <<" libre."<<endl;     
        }
        
    }
}
void Sistema::pasarTiempo(int N){
    int colasVacia[3] = {0,0,0};
    for(int i = 1; i < N + 1; i++){
        for(int n = 0; n < 3; n++){
            if(nucleos[n].nucleo !=-1){
                nucleos[n].tiempoVida --;
            }
            if(nucleos[n].nucleo == -1 && colasVacia[n] == 0){
                if(asignarSiguienteProceso(n+1)){//Se mira la cola de prioridad correspondiente al siguiente núcleo
                    cout<<(i == 1 ?"Minuto transcurrido " : "Minutos transcurridos: ")<<i<<", el núcleo "<< n+1<<" se encontraba libre y se le ha asignado el proceso correspondiente."<<endl; 
                }
                else{
                    cout<<"¡La cola del núcleo "<<n+1<<" está vacía!"<<endl;
                    colasVacia[n] = 1;
                    nucleos[n].nucleo = -1;
                }
            }
            else if(nucleos[n].tiempoVida == 0 && colasVacia[n] == 0){
                cout<<"_________________"<<endl;
                cout<<"Minuto "<<i<<" transcurrido: "<<endl;
                cout<<"Ha finalizado el siguiente proceso:"<<endl;
                cout<<nucleos[n].toString()<<endl;

                bool asignado = asignarSiguienteProceso(nucleos[n].nucleo);
                if(asignado){
                    cout<<"Se ha añadido un nuevo proceso al núcleo "<<n+1<<"."<<endl;
                }
                else{
                    cout<<"¡La cola del núcleo "<<n+1<<" está vacía!"<<endl;
                    colasVacia[n] = 1;
                    nucleos[n].nucleo = -1;
                }
            }
        }
        cout<<"Estado de los núcleos ("<<i<<(i == 1 ? " minuto transcurrido)." : " minutos transcurridos).")<<endl;
        mostrarProcesosNucleo();
    }
}
bool Sistema::asignarSiguienteProceso(int nucleo){
    switch(nucleo){
        case 1:
            if(!colaPrioridadUno.es_vacia()){
                nucleos[0] = colaPrioridadUno.inicio();
                colaPrioridadUno.desencolar();
                return true;
            }
            break;
            
        case 2:
            if(!colaPrioridadDos.es_vacia()){
                nucleos[1]  = colaPrioridadDos.inicio();
                colaPrioridadUno.desencolar();
                return true; 
            }
            break;
            
        case 3:
            if(!colaPrioridadTres.es_vacia()){
                nucleos[2] = colaPrioridadTres.inicio();
                colaPrioridadTres.desencolar();
                return true;
            }
            break;
            
    }
    return false;
}
void Sistema::apilar(Proceso p){
    pilaProcesos.apilar(p);
}
void Sistema::desapilar(){
    pilaProcesos.desapilar();
}
Proceso Sistema::mostrarCima(){
    return pilaProcesos.mostrar();
}
void Sistema::encolarCola(Proceso p, int n){
    switch(n){
        case 1:
            colaPrioridadUno.encolar(p);
            break;
        case 2:
            colaPrioridadDos.encolar(p);
            break;
        case 3:
            colaPrioridadTres.encolar(p);
            break;
    }
}
void Sistema::desencolarCola(Proceso p, int n){
    switch(n){
        case 1:
            colaPrioridadUno.desencolar();
            break;
        case 2:
            colaPrioridadDos.desencolar();
            break;
        case 3:
            colaPrioridadTres.desencolar();
            break;
    }
}

