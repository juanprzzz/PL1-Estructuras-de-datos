#ifndef SISTEMALISTA_H
#define SISTEMALISTA_H
#include "Pila.h"
#include "NodoLista.h"
#include "Lista.h"
#include "Nucleo.h"

class SistemaLista{
    private:
        Pila pilaProcesos;
        Lista lista;
        int tiempoTranscurrido = 0;


        //variables para calcular tiempo medio de proceso
        int tiempoLlegada=0;
        int tiempoFinalizacion=0;
        int ctdProcesos=0;
    public:
        SistemaLista();
        ~SistemaLista();
        
        void mostrarProcesosNucleo();
        void pasarTiempo(int N);
        bool asignarSiguienteProcesoDesdeCola(int nucleoLibre);
        void añadirNucleo(Nucleo n);
        void acabarProcesos();
        void procesoComienzo();
        void apilarSistema(Proceso proceso);
        void borrarPila();
        void mostrarPilaProcesos();
        bool pilaVacia();
        bool listaVacia();
        bool nucleosVacios();
}; 
#endif