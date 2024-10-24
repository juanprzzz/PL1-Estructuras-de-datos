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
        
        void mostrarProcesosNucleo();
        void pasarTiempo(int N);
        bool asignarSiguienteProcesoDesdeCola(int nucleoLibre); //Asigna proceso a núcleo vacío
        void añadirCola(Proceso proceso);
        void acabarProcesos();
        void procesoComienzo();
        void apilarSistema(Proceso proceso);
        void borrarPila();
        //int mostrarHora();
        void mostrarPilaProcesos();
        void mostrarColaPrioridad();
};
    
#endif