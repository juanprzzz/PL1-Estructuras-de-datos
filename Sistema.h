#ifndef SISTEMA_H
#define SISTEMA_H
#include "Pila.h"
#include "Cola.h"

class Sistema{
    private:
        Pila pilaProcesos;
        Cola colaEspera;
        Proceso nucleos[3];
        int tiempoTranscurrido = 0;
    public:
        Sistema();
        ~Sistema();
        void addPilaProcesos(Pila p);
        void mostrarProcesosNucleo();
        void pasarTiempo(int N);
        Proceso buscarProcesoSiguiente(int N); //Busca proceso en cola de prioridades
        bool asignarSiguienteProceso(int nucleoLibre); //Asigna proceso a núcleo vacío
        void añadirCola(Proceso proceso);
        int colaEsperaE();
        int sumarTiempos();
        void acabarProcesos();
        void desencolarCola();
        void procesoComienzo();
        void apilarSistema(Proceso proceso);

        int mostrarHora();
};
    
#endif