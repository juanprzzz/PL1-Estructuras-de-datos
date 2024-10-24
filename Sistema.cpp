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
//int Sistema::colaEsperaE(){return colaEspera.inicio().prioridad;}
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
}
/*
* Se encarga de que transcurra en el sistema N minutos. Se encarga de llamar a las funciones correspondientes para mostrar 
* los núcleos cada minuto, asignación de procesos...
*/
void Sistema::pasarTiempo(int N){
    int colasVacia[3] = {0,0,0}; //Se introduce esta variable para saber qué nucleos no tienen ningún proceso en la cola
    for(int i = 1; i < N + 1; i++){ //por cada minuto que pasa 
        procesoComienzo();//se llama a un método para ver si hay algún proceso que inicie en este minuto y se pueda meter directamente a un nucleo (si alguno está vacio). Si no, se añade a la cola
        for(int n = 0; n < 3; n++){ //para cada nucleo
            if(nucleos[n].nucleo == -1 && !colaEspera.es_vacia()){ //Si el núcleo está vacío y la cola no está vacía
                if(asignarSiguienteProcesoDesdeCola(n)){ 
                    cout<<"Se ha introducido en el minuto "<<tiempoTranscurrido<<" del sistema, el siguiente proceso: "<<nucleos[n].toString()<<endl;
                }
                
            }
            if(nucleos[n].tiempoVida == 0){
                cout<<"Ha finalizado el siguiente proceso en el minuto "<<tiempoTranscurrido-1<<" del sistema: "<<nucleos[n].toString()<<endl;
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
* Mira la pila de procesos, si nos encontramos en el minuto en el que se inicia un (o varios) nuevo proceso, lo mete en el núcleo si está libre, y si no, lo mete en la cola
*/
void Sistema::procesoComienzo(){
    while(tiempoTranscurrido == pilaProcesos.mostrar().inicioProceso){//mientras el tiempo de inicio del proceso de la cima sea igual al minuto actual
        /*if(nucleos[0].nucleo == -1 && colaEspera.es_vacia()){ //si uno de los tres nucleos está vacío y no hay procesos en espera se añade directamente al nucleo
            Proceso procesoUno = pilaProcesos.mostrar();
            procesoUno.nucleo = 1;
            nucleos[0] = procesoUno; //El núcleo uno está vacío, por lo que lo meto ahí
            pilaProcesos.desapilar();

            cout<<"\nSe introduce en el minuto "<<tiempoTranscurrido<<" del sistema, el siguiente proceso: "<<nucleos[0].toString()<<endl;
        }
        else if(nucleos[1].nucleo == -1 && colaEspera.es_vacia()){
            Proceso procesoDos = pilaProcesos.mostrar();
            procesoDos.nucleo = 2;
            nucleos[1] = procesoDos; //El núcleo dos está vacío, por lo que lo meto ahí
            pilaProcesos.desapilar();

            cout<<"\nSe introduce en el minuto "<<tiempoTranscurrido<<" del sistema, el siguiente proceso: "<<nucleos[1].toString()<<endl;
        }
        else if(nucleos[2].nucleo == -1 && colaEspera.es_vacia()){
            Proceso procesoTres = pilaProcesos.mostrar();
            procesoTres.nucleo = 3;
            nucleos[2] = procesoTres; //El núcleo tres está vacío, por lo que lo meto ahí
            pilaProcesos.desapilar();

            cout<<"\nSe introduce en el minuto "<<tiempoTranscurrido<<" del sistema, el siguiente proceso: "<<nucleos[2].toString()<<endl;
        }
        else{ */  //Si todos los nucleos están ocupados o hay más procesos en espera, entonces lo meto en la cola de prioridades 
            colaEspera.encolarPrioridad(pilaProcesos.mostrar());
            pilaProcesos.desapilar();
        //}
        
    }
        
}
/*
* Se encarga de que si un núcleo se queda libre,introduce otro proceso en este desde la cola
*/
bool Sistema::asignarSiguienteProcesoDesdeCola(int nucleoLibre){ //nucleo introducido es del 0 al 2
    if (!colaEspera.es_vacia()){
        Proceso procesoNuevo = colaEspera.inicio();
        procesoNuevo.nucleo = nucleoLibre; //modificar numero de nucleo del proceso (era 0 si no esta asignado)
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
    //pasarTiempo(1);
}


/*
Proceso Sistema::buscarProcesoSiguiente(int n){ //recorre la cola de espera hasta encontrar un proceso que pertenezca al núcleo indicado
    Cola aux;
    bool salir=false;
    Proceso resultado=Proceso();
    while(!colaEspera.es_vacia() && salir==false){ 
        if(colaEspera.inicio().nucleo==n){
            resultado=colaEspera.inicio();
            salir=true;
        }
        else{
            aux.encolar(colaEspera.inicio());
            } //si no he añadido el proceso de la cima se guarda en la auxiliar, si lo añado se quita de la cola de espera
        colaEspera.desencolar();
    }
    while (!colaEspera.es_vacia()){ //después añado a la auxiliar todo el resto de la cola
            aux.encolar(colaEspera.inicio());
            colaEspera.desencolar();
    }
    while(!aux.es_vacia()){ //recupero la cola original
        colaEspera.encolar(aux.inicio());
        aux.desencolar();
    }

    return resultado; //devuelve proceso() si no hay ninguno que cumpla las condiciones
}
*/
/*
int Sistema::sumarTiempos(){
    Cola aux= colaEspera.copiarCola();
    int tiempoN1=0;
    int tiempoN2=0;
    int tiempoN3=0;
    while(!aux.es_vacia()){
        int n=aux.inicio().nucleo;
        switch(n){//guarda el tiempo que va a tardar en finalizar cada uno de los tres núcleos
            case 1: tiempoN1+=aux.inicio().tiempoVida;
            break;
            case 2: tiempoN2+=aux.inicio().tiempoVida;
            break;
            case 3: tiempoN3+=aux.inicio().tiempoVida;
            break;
            default: cout<<"Proceso con nucleo no válido"<<endl;
        }
        aux.desencolar();
    }
    if(tiempoN1>=tiempoN2 && tiempoN1>=tiempoN3){return tiempoN1;} //devuelve el tiempo del núcleo que vaya a tardar más en terminar de ejecutarse
    else if(tiempoN2>=tiempoN1 && tiempoN2>=tiempoN3){return tiempoN2;}
    else if(tiempoN3>=tiempoN2 && tiempoN3>=tiempoN1){return tiempoN3;}
    else{return 0;}
}
void Sistema::acabarProcesos(){
    int n=sumarTiempos()+1; //1 min mas para comprobar que todo queda vacío
    pasarTiempo(n);
}
*/

/*
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
        default: return false;
            
    }
    return false; ////sobra con el default??
}

void Sistema::pasarTiempo(int N){
    int colasVacia[3] = {0,0,0}; //Se introduce esta variable para saber qué nucleos no tienen ningún proceso en la cola
    for(int i = 1; i < N + 1; i++){
        for(int n = 0; n < 3; n++){
            if(nucleos[n].nucleo !=-1){
                nucleos[n].tiempoVida --; //Si hay un proceso, le resto uno cada minuto
            }
            if(nucleos[n].nucleo == -1 && colasVacia[n] == 0){ //Para poder asignar un proceso, el núcleo tiene que estar libre, y debe de tener en la cola algún proceso para ese núcleo
                if(asignarSiguienteProceso(n+1)){//Se mira la cola de prioridad
                    cout<<(i == 1 ?"Minuto transcurrido " : "Minutos transcurridos: ")<<i<<", el nucleo "<< n+1<<" se encontraba libre y se le ha asignado el proceso correspondiente."<<endl; 
                }
                else{ //Si no puedo encontrar un proceso en la cola para ese núcleo, entonces no hay proceso para ese núcleo en la cola
                    cout<<"¡La cola del nucleo "<<n+1<<" está vacía!"<<endl;
                    colasVacia[n] = 1;
                    nucleos[n].nucleo = -1;
                }
            }
            else if(nucleos[n].tiempoVida == 0 && colasVacia[n] == 0){
                cout<<"Minuto "<<i<<" transcurrido: "<<endl;
                cout<<"Ha finalizado el siguiente proceso:"<<endl;
                cout<<nucleos[n].toString()<<endl;

                bool asignado = asignarSiguienteProceso(nucleos[n].nucleo);
                if(asignado){
                    cout<<"Se ha agregado un nuevo proceso al nucleo "<<n+1<<"."<<endl;
                }
                else{
                    cout<<"La cola del nucleo "<<n+1<<" esta vacia!"<<endl;
                    colasVacia[n] = 1;
                    nucleos[n].nucleo = -1;
                }
            }
            
        }
        cout<<"\nEstado de los núcleos ("<<i<<(i == 1 ? " minuto transcurrido)." : " minutos transcurridos).")<<endl;
        mostrarProcesosNucleo();
        cout<<"___________________________________________________________________________________________________"<<endl;
    }
}


*/


//métodos de utilización de las estructuras guardadas dentro de sistema para poder acceder a los atributos privados del mismo
/*
void Sistema::apilar(Proceso p){
    pilaProcesos.apilar(p);
}
void Sistema::desapilar(){
    pilaProcesos.desapilar();
}
Proceso Sistema::mostrarCima(){
    return pilaProcesos.mostrar();
}

void Sistema::encolar(Proceso p){
    colaEspera.encolarPrioridad(p); //encola correctamente según orden de prioridad
}
void Sistema::desencolar(){
    colaEspera.desencolar();
}
bool Sistema::pilaVacia(){
    return pilaProcesos.esVacia();
}
*/
/*
void Sistema::addPilaProcesos(Pila p){
    Pila aux;
    while(!p.esVacia()){
        aux.apilar(p.mostrar());
        p.desapilar();
    }
    while(!aux.esVacia()){
        pilaProcesos.apilar(aux.mostrar());
        aux.desapilar();
    }
    while(!pilaProcesos.esVacia()){
        colaEspera.encolarPrioridad(pilaProcesos.mostrar());
        pilaProcesos.desapilar();
    }
    

}
*/
/*
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
        default: cout << "n no es un núcleo válido. Solo hay del 1 al 3"<<endl;
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

*/

