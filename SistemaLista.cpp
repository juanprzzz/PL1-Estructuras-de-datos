#include "SistemaLista.h"
#include <iostream>
#include <string>

using namespace std;

SistemaLista::SistemaLista()
{
    Pila pilaProcesos;
    Lista lista;
}

SistemaLista::~SistemaLista()
{
    // Destructor
}

/*
 *Funciones auxiliares para el menu del main
 */
void SistemaLista::añadirNucleo(Nucleo n)
{
    lista.añadirDerecha(n);
}
void SistemaLista::borrarPila()
{
    pilaProcesos.~Pila();
}
void SistemaLista::mostrarPilaProcesos()
{
    pilaProcesos.mostrarPila();
}

bool SistemaLista::pilaVacia()
{
    return pilaProcesos.esVacia();
}
bool SistemaLista::listaVacia()
{
    return lista.esVacia();
}

void SistemaLista::mostrarProcesosNucleo()
{
    lista.mostrarLista();
}

void SistemaLista::apilarSistema(Proceso p)
{
    if (p.inicioProceso < tiempoTranscurrido)
    {
        cout << "No se puede añadir ese proceso, el minuto en el que se tiene que iniciar ese proceso, ya ocurrió" << endl;
    }
    else
    {
        pilaProcesos.apilar(p);
        ctdProcesos++;
    }
}

/*
 * Se encarga de que transcurra en el sistema N minutos. Se encarga de llamar a las funciones correspondientes para mostrar
 * los núcleos cada minuto, asignación de procesos...
 */

///////////////////////meter que si hay alguno vacio se tiene que borrar
void SistemaLista::pasarTiempo(int N)
{

    for (int i = 0; i < N; i++)
    {
        // aux.añadirNuevoNucleo();//primero ver si hay que añadir nvo nucleo. Sobre todo la 1a vez pq lista está vacia. (Ya lo hace procesoComienzo?)
        procesoComienzo(); // Se comprueba si hay algún proceso que inicie en este minuto. Si lo hay, se añade a la cola
        Lista aux = lista.copiarLista();
        // cout << "Al siguiente minuto " << lista.inicio().procesoEjecucion.tiempoVida << endl;           BORRAR
        lista.~Lista();

        // cout<<"PROCESOS AÑADIDOS. EMPEZAMOS! --> ";
        // cout << aux.esVacia() << endl;
        while (!aux.esVacia())
        { // por cada núcleo
          // Nucleo prim = aux.primero->nucleo;
            if (aux.primero->nucleo.procesoEjecucion.tiempoVida == 0)
            {
                cout << "\nHa finalizado el siguiente proceso al final del minuto " << tiempoTranscurrido - 1 << " del sistema: " << aux.primero->nucleo.mostrarProcesoEjecucion() << endl;
                tiempoFinalizacion += tiempoTranscurrido; // como ha acabado un proceso, se suma el tiempo actual al tiempo de finalización
                aux.primero->nucleo.terminarProceso();    // Además, como ahora el núcleo está vacío, se sustituye el proceso finalizado por uno vacío con todos los valores a -1
            }
            if (aux.primero->nucleo.procesoEjecucion.PID == -1 && !aux.primero->nucleo.colaEspera.es_vacia())
            { // Si el proceso en ejecucion está vacío (no hay) y la cola no está vacía
                //////////he juntado aqui la funcion que se llamaba de asignar siuiente proceso//////////////
                Proceso procesoNuevo = aux.primero->nucleo.colaEspera.inicio();
                procesoNuevo.nucleo = aux.primero->nucleo.ID;
                aux.primero->nucleo.ejecutarProceso(procesoNuevo);
                aux.primero->nucleo.colaEspera.desencolar();

                cout << "\nSe ha introducido al inicio del minuto " << tiempoTranscurrido << " del sistema, el siguiente proceso: " << aux.primero->nucleo.mostrarProcesoEjecucion() << endl;
            }
            if (aux.primero->nucleo.procesoEjecucion.PID > -1)
            {
                if (aux.primero->nucleo.procesoEjecucion.tiempoVida > 0)
                {
                    aux.primero->nucleo.procesoEjecucion.tiempoVida--;
                }
                // cout<<"En aux ----->"<<aux.inicio().procesoEjecucion.tiempoVida<<endl;
            }
            // meter la funcion de borrar todos los que esten vacios si se puede:
            aux.eliminarNucleosVacios(aux.comprobarEliminarNucleos());

            lista.añadirDerecha(aux.inicio());
            // cout<<"después de eliminar en aux "<<aux.inicio().procesoEjecucion.tiempoVida<<endl; //en el de tiempo de vida 6 lo hace bien creo, en el de tvida 5 deberia dar 4 tonces ta mal
            // cout<<"Esto está bien "<<lista.inicio().procesoEjecucion.tiempoVida<<endl;
            aux.eliminarInicio();
        }
        cout << "\n Estado de los núcleos. Minuto: " << tiempoTranscurrido << endl;
        lista.mostrarLista();

        tiempoTranscurrido++;
    }
}

/*
 * Mira la pila de procesos, si nos encontramos en el minuto en el que se inicia un (o varios) nuevo proceso, lo mete en una cola auxiliar ordenado por prioridad (para que un proceso menos prioritario no se ejecute antes que otro)
 * Después, de la cola auxiliar mete cada proceso en la cola de un nucleo/se lo asigna si puede. Si es necesario, se crean más nucleos
 */
void SistemaLista::procesoComienzo()
{

    // primero creo una cola auxiliar para guardar todos los elementos que inician en este minuto
    Cola colaNuevos;
    while (tiempoTranscurrido == pilaProcesos.mostrar().inicioProceso)
    {
        colaNuevos.encolarPrioridad(pilaProcesos.mostrar());
        pilaProcesos.desapilar();
        tiempoLlegada += tiempoTranscurrido;
    }

    // si hay elementos que inician en este minuto...
    while (!colaNuevos.es_vacia())
    {
        if (lista.primero != NULL) // Caso 1.1: lista con más de un nucleo ya; lista no vacia
        {
            NodoLista *aux;
            aux = lista.primero;
            bool añadido = false;

            // meter aqui el ver si ya acabo proceso?
            if (aux->nucleo.colaEspera.get_longitud() == 2 && aux->nucleo.procesoEjecucion.PID == -1)
            { // compruebo si hay algo que meter a ejecutar desde la cola del propio nucleo.
                // si la cola estuviera llena con 2 procesos y no hubiera ninguno ejecutandose, no cabrian mas y se crearia un nuevo nucleo.
                // Sin embargo, realmente habría que meter el más prioritario de la cola de espera a ejecucion y ya no sería necesario el nuevo nucleo (en un nucleo caben 3 procesos, no 2)
                Proceso ejecutar = aux->nucleo.PrimeroCola();
                aux->nucleo.ejecutarProceso(ejecutar);
                cout << "\nSe ha introducido al inicio del minuto " << tiempoTranscurrido << " del sistema, el siguiente proceso: " << aux->nucleo.mostrarProcesoEjecucion() << endl;
                aux->nucleo.desencolarProceso();
                ejecutar = aux->nucleo.colaEspera.fin(); // creo q ya entiendo por qué Pero si es 1 la longitud?
            }
            ////Creo que deberiamos unificar algunas cosas, tipo si la longitud es 2 o 1, y nucleo vacio, ejecutar colaEspera.fin
            ///
            if (aux->siguiente == NULL) // Caso 2.1: solo hay un nucleo/elemento en la lista.
            {
                cout << "longiut<<" << aux->nucleo.colaEspera.get_longitud() << endl;
                if (aux->nucleo.colaEspera.get_longitud() < 2)
                {                                            // si el elemento marcado por aux tiene menos de 2 procesos en su cola de espera
                    Proceso procesoNuevo = colaNuevos.fin(); // aqui no iria fin? Queremos que en la cola queden los menos prioritarios, para ejecutar los más en otros nucleos inmediatamente
                    ///////////////////////// que pasaría si el nucleo no tuviera nada ejecutandose? se joderian las prioridades?
                    procesoNuevo.nucleo = aux->nucleo.ID; /// eso es lo q queria hacer, pero lo estaba haciendo en otro sitio xd jsjs
                    aux->nucleo.añadirProceso(procesoNuevo);
                    colaNuevos.eliminarFin(); // Hay que hacer un eliminarFin
                    añadido = true;
                }
            }

            while (aux->siguiente != NULL && !añadido) // Caso 2.2: hay más de 1 elemento en la lista. Va a ir comprobando por cada nucleo en cual puede añadir un proceso
            {
                if (!añadido && aux->nucleo.colaEspera.get_longitud() < 2)
                { // si el elemento marcado por aux tiene menos de 2 procesos en su cola de espera puedo añadir un nuevo proceso
                    // Proceso procesoNuevo = colaNuevos.inicio();
                    Proceso procesoNuevo = colaNuevos.fin();
                    procesoNuevo.nucleo = aux->nucleo.ID;
                    aux->nucleo.añadirProceso(procesoNuevo);
                    // colaNuevos.desencolar();
                    colaNuevos.eliminarFin();
                    añadido = true;
                }

                aux = aux->siguiente;
            }
            if (!añadido) // Caso 2.3: si no se ha podido añadir a ningun nucleo, todos estaban llenos, se crea uno nuevo
            {             // si todos los nucleos estaban llenos
                lista.añadirNuevoNucleo();
                Proceso procesoNuevo = colaNuevos.inicio();
                procesoNuevo.nucleo = lista.ultimo->nucleo.ID;
                lista.ultimo->nucleo.ejecutarProceso(procesoNuevo); // Como los procesos a añadir ya van ordenados por orden de prioridad, se puede ejecutar directamente
                colaNuevos.desencolar();
            }
        }
        else // Caso 1.2: lista vacía
        {
            // si la lista está vacia se crea nuevo nucleo, y como es nuevo puedo comenzar a ejecutar el proceso más prioritario actual de la cola
            lista.añadirNuevoNucleo(); // si la lista está vacia se crea nuevo nucleo
            Proceso procesoNuevo = colaNuevos.inicio();
            procesoNuevo.nucleo = lista.primero->nucleo.ID;
            lista.primero->nucleo.ejecutarProceso(procesoNuevo); // Como los procesos a añadir ya van ordenador por orden de prioridad, se puede ejecutar directamente
            colaNuevos.desencolar();
        }

        // cout << "FIN DE ITERACION. MOSTRAR LISTA ACTUALMENTE" << endl;                     //BORRAR
        // lista.mostrarLista();     //BORRAR
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

void SistemaLista::acabarProcesos()
{

    // solo saldrá del bucle una vez que ninguna condición se cumpla. Es decir, cuando la pila sea vacía y todos los núcleos estén vacíos

    while (!pilaProcesos.esVacia() || !nucleosVacios())
    {
        //   ahora el while deberia ser mientras que la pila no este vacia, la longitud de la cola no sea 1 ese 1 elemento este vacio
        pasarTiempo(1);
       
}
    double tiempoMedio = (double)(tiempoFinalizacion - tiempoLlegada) / ctdProcesos;
    cout << "La suma de los tiempos de llegada de todos los procesos es: " << tiempoLlegada << endl;
    cout << "La suma de los tiempos de finalización de todos los procesos es: " << tiempoFinalizacion << endl;
    cout << "\n El tiempo medio de estancia es: " << tiempoMedio << endl;
}
bool SistemaLista::nucleosVacios()
{
    Lista aux = lista.copiarLista();
    lista.~Lista();
    int nucleosVacios = 0;
    bool todosVacios = false;
    while (!aux.esVacia())
    {
        if (aux.inicio().procesoEjecucion.nucleo == -1 && aux.inicio().colaEspera.es_vacia())
        { // Si en el núcleo no se ejecuta nada, y la cola está vacía
            nucleosVacios++;
        }
        lista.añadirDerecha(aux.inicio());
        aux.eliminarInicio();
    }
    if (nucleosVacios == lista.ctdNucleos)
    {
        todosVacios = true;
    }
    return todosVacios;
}