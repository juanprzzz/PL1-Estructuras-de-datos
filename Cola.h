#ifndef COLA_H
#define COLA_H
#include "NodoCola.h"
#include "Proceso.h"

class Cola{
    private:
        NodoCola * primero;
        NodoCola * ultimo;
        //int longitud;
    public:
        Cola(); 
        ~Cola();
        void encolar(Proceso);
        void encolarPrioridad(Proceso);
        Proceso inicio();
        //int get_longitud();
        Proceso fin();
        void desencolar();
        bool es_vacia();
        void mostrarCola(); //No es correcto, se implementa para ver que está creada correctamente
        Cola copiarCola();
        int get_longitud();

};
#endif // COLA_H