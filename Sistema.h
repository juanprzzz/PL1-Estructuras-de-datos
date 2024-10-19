#ifndef SISTEMA_H
#define SISTEMA_H
#include "Pila.h"
#include "Cola.h"

class Sistema{
    private:
        Pila pilaProcesos;
        Cola colaEspera;
        Proceso nucleos[3];
    public:
        Sistema();
        ~Sistema();
        void addPilaProcesos(Pila p);
        void mostrarProcesosNucleo();
        void pasarTiempo(int N);
        Proceso buscarProcesoSiguiente(int N);
        bool asignarSiguienteProceso(int nucleoLibre);
        void apilar(Proceso proceso);
        void desapilar();
        int sumarTiempos();
        void acabarProcesos();
        Proceso mostrarCima();
        void encolar(Proceso p);
        void desencolar();
        
};

#endif