#ifndef SISTEMA_H
#define SISTEMA_H
#include "Pila.h"
#include "Cola.h"

class Sistema{
    private:
        Pila pilaProcesos;
        Cola colaPrioridadUno;
        Cola colaPrioridadDos;
        Cola colaPrioridadTres;
        Proceso nucleos[3];
    public:
        Sistema();
        ~Sistema();
        Sistema(Pila pilaProcesos, Cola colaPrioridadUno, Cola colaPrioridadDos, Cola colaPrioridadTres);
        void mostrarProcesosNucleo();
        void pasarTiempo(int N);
        bool asignarSiguienteProceso(int nucleoLibre);
        void apilar(Proceso proceso);
        void desapilar();
        Proceso mostrarCima();

        void encolarCola(Proceso proceso, int nucleo);
        void desencolarCola(Proceso proceso, int nucleo);
        
};

#endif