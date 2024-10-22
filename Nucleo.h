#ifndef NUCLEO_H
#define NUCLEO_H
#include "Cola.h"
#include "Proceso.h"

class Nucleo 
{
    private:
        Cola colaEspera;
        int ID;
        //pid de proceso en ejecución?

       
    public:
        Nucleo(int id); //constructor. cola vacía
        ~Nucleo(); //destructor
        void añadir(Proceso proceso); 
        void mostrarNucleo();
};

#endif // NUCLEO_H