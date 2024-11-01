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
        aux.añadirNuevoNucleo();//primero ver si hay que añadir nvo nucleo. Sobre todo la 1a vez pq lista está vacia.
        procesoComienzo(); //Se comprueba si hay algún proceso que inicie en este minuto. Si lo hay, se añade a la cola 
        while(!aux.esVacia()){//por cada núcleo
            Nucleo prim= aux.primero->nucleo;
            if(prim.procesoEjecucion.tiempoVida == 0){
                cout<<"\nHa finalizado el siguiente proceso al final del minuto "<<tiempoTranscurrido-1<<" del sistema: "<<prim.mostrarProcesoEjecucion()<<endl; 
                tiempoFinalizacion+=tiempoTranscurrido;  //como ha acabado un proceso, se suma el tiempo actual al tiempo de finalización
                prim.terminarProceso(); // Además, como ahora el núcleo está vacío, se sustituye el proceso finalizado por uno vacío con todos los valores a -1
                
            }
            if(prim.procesoEjecucion.PID == -1 && !prim.colaEspera.es_vacia()){ //Si el proceso en ejecucion está vacío (no hay) y la cola no está vacía
//////////he juntado aqui la funcion que se llamaba de asignar siuiente proceso//////////////
                Proceso procesoNuevo = prim.colaEspera.inicio();
                procesoNuevo.nucleo = prim.ID;
                prim.ejecutarProceso(procesoNuevo);
                prim.colaEspera.desencolar();

                cout<<"\nSe ha introducido al inicio del minuto "<<tiempoTranscurrido<<" del sistema, el siguiente proceso: "<<prim.mostrarProcesoEjecucion()<<endl; 
            }
            //meter la funcion de borrar todos los que esten vacios si se puede:
            aux.eliminarNucleosVacios(aux.comprobarEliminarNucleos());
            
            prim.procesoEjecucion.tiempoVida --;
            aux.eliminarInicio();
        }
        lista.~Lista();
        lista=aux.copiarLista(); //sustituyo la lista og por la auxiliar //////////////////////
        cout<<"\n Estado de los núcleos. Minuto: "<<tiempoTranscurrido<<endl;
        lista.mostrarLista();
        tiempoTranscurrido ++;
    }
}




/*
* Mira la pila de procesos, si nos encontramos en el minuto en el que se inicia un (o varios) nuevo proceso, lo mete en la cola ordenado por prioridad (para que un proceso menos prioritario no se ejecute antes que otro)
*/
void SistemaLista::procesoComienzo(){
    Cola colaNuevos;
    while(tiempoTranscurrido == pilaProcesos.mostrar().inicioProceso){
        colaNuevos.encolarPrioridad(pilaProcesos.mostrar());
        pilaProcesos.desapilar();
    }

    cout<<"NUEVOS ELEMENTOS A AÑADIR: "<<endl;
    colaNuevos.mostrarCola();


    while(!colaNuevos.es_vacia()){

        if (lista.primero != NULL){
            NodoLista *aux;
            aux = lista.primero;
            bool añadido=false;

            if (aux->nucleo.colaEspera.get_longitud()==2 && aux->nucleo.procesoEjecucion.PID == -1){ //compruebo si hay algo que meter a ejecutar
                    Proceso ejecutar= aux->nucleo.PrimeroCola();
                    aux->nucleo.ejecutarProceso(ejecutar);
                    cout<<"\nSe ha introducido al inicio del minuto "<<tiempoTranscurrido<<" del sistema, el siguiente proceso: "<<aux->nucleo.mostrarProcesoEjecucion()<<endl; 
                    aux->nucleo.desencolarProceso();
                }

            if (aux->siguiente == NULL && !añadido){//si solo hay 1 nucleo
                cout<<"aqui solo hay 1 nucleo"<<endl;

                if (!añadido && aux->nucleo.colaEspera.get_longitud()<2){ //si el elemento marcado por aux tiene menos de 2 procesos en su cola de espera
                    Proceso procesoNuevo = colaNuevos.inicio();
                    procesoNuevo.nucleo= aux->nucleo.ID;
                    aux->nucleo.añadirProceso(procesoNuevo);
                    colaNuevos.desencolar();
                    añadido=true;
                }

            }

            while (aux->siguiente != NULL && !añadido){
                cout<<"Entras aquí para asignarle un núcleo al proceso, intentas buscar un núcleo con capacidad"<<endl;

                if (!añadido && aux->nucleo.colaEspera.get_longitud()<2){ //si el elemento marcado por aux tiene menos de 2 procesos en su cola de espera
                    Proceso procesoNuevo = colaNuevos.inicio();
                    procesoNuevo.nucleo= aux->nucleo.ID;
                    aux->nucleo.añadirProceso(procesoNuevo);
                    colaNuevos.desencolar();
                    añadido=true;
                }

                aux = aux->siguiente;
            }
                if (!añadido){//si todos los nucleos estaban llenos
                cout << "Todos los nucleos estaban llenos" << endl;
                    lista.añadirNuevoNucleo();
                    Proceso procesoNuevo = colaNuevos.inicio();
                    procesoNuevo.nucleo= lista.ultimo->nucleo.ID;
                    lista.ultimo->nucleo.ejecutarProceso(procesoNuevo); //Como los procesos a añadir ya van ordenador por orden de prioridad, se puede ejecutar directamente
                    colaNuevos.desencolar();
                }

        }else{
            cout << "Entras aquí porque en el sistema no hay núcleos" << endl;
            lista.añadirNuevoNucleo();//si la lista está vacia se crea nuevo nucleo
            Proceso procesoNuevo = colaNuevos.inicio();
            procesoNuevo.nucleo= lista.primero->nucleo.ID;
            lista.primero->nucleo.ejecutarProceso(procesoNuevo); //Como los procesos a añadir ya van ordenador por orden de prioridad, se puede ejecutar directamente
            colaNuevos.desencolar();
        }

        cout << "FIN DE ITERACION. MOSTRAR LISTA ACTUALMENTE" << endl;
        lista.mostrarLista();
        tiempoLlegada+=tiempoTranscurrido; 
    }
}

/*
void SistemaLista::procesoComienzo()
{
    while (tiempoTranscurrido == pilaProcesos.mostrar().inicioProceso)
    {
        if (lista.primero != NULL)
        {
            NodoLista *aux;
            aux = lista.primero;
            
            bool añadido = false;
            while (aux->siguiente != NULL && !añadido)
            {
                cout<<"Entras aquí para asignarle un núcleo al proceso, intentas buscar un núcleo con capacidad"<<endl;
                cout << "???" << endl;
                if (aux->nucleo.colaEspera.get_longitud() < 2)
                { // si el elemento marcado por aux tiene menos de 2 procesos en su cola de espera
                    cout << "por cojones entras aquí" << endl;
                    cout << "Y aqui??" << endl;
                    aux->nucleo.añadirProceso(pilaProcesos.mostrar());
                    pilaProcesos.desapilar();
                    añadido = true;
                }
                cout << "aqui no" << endl;
                aux = aux->siguiente;
            }

            if (!añadido)
            { // si todos los nucleos estaban llenos
                lista.añadirNuevoNucleo();
                lista.ultimo->nucleo.añadirProceso(pilaProcesos.mostrar());
                pilaProcesos.desapilar();
            }
            // colaEspera.encolarPrioridad(pilaProcesos.mostrar());
            // pilaProcesos.desapilar();

            tiempoLlegada += tiempoTranscurrido;
        }
        else
        {
            cout << "Entras aquí porque en el sistema no hay núcleos" << endl;
            lista.añadirNuevoNucleo();
            lista.primero->nucleo.añadirProceso(pilaProcesos.mostrar());
            pilaProcesos.desapilar();
            tiempoLlegada += tiempoTranscurrido;
            cout << "Salde de aqui" << endl;
        }
    }
}

*/



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