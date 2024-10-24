#include "Pila.h"
#include "Cola.h"
#include <iostream>
#include <string>
#include "Sistema.h"
using namespace std;


//tengo procesos metidos en una cola, los saco por la hora y los meto en una cola
//3 núcleos, pueden ser 1 array, si los 3 tienen procesos ejecutandose, proceso entra en cola de espera




//TIEMPO MEDIO DE UN PROCESO


int main(){
Proceso p1= Proceso(1,1,10,5,7,0);
Proceso p2= Proceso(2,1,1,10,2,0);
Proceso p3= Proceso(3,1,1,5,3,0);
Proceso p4= Proceso(4,1,1,2,5,0);
Proceso p5= Proceso(5,1,624,9,4,0);
Proceso p6 = Proceso(6,1,3,4,0,0);
Proceso p7= Proceso(7,1,2,2,5,0);
Proceso p8= Proceso(8,1,1,5,0,0);
//Proceso p9= Proceso(9,1,11,15,1,0);
//Proceso p10= Proceso(10,1,10,2,9,0);
Sistema sistemaPrincipal;


Pila ptest;
Cola ctest;

bool salir=false;
while(!salir){
    int opcion;
    cout << "Qué opción quieres?:\n|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n|-1 -> Salir\t\t\t1 -> Crear pila de procesos del sistema\t\t2 -> Mostrar procesos de la pila \t3 -> Borrar pila                  |\n|                                                                                                                                                         |\n| 4 -> Mostrar cola espera\t5 -> Mostrar procesos en nucleos\t\t6 -> Pasar N minutos\t\t\t7 -> Acabar todos los procesos    |\n|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n\nIntroduce una opción: ";
    cin >> opcion;
    cout << opcion<<endl;

    switch (opcion)
    {
    case -1:
        salir=true;
        break;

    case 1: //crear pila de procesos
        cout << "Creando pila"<<endl;
        sistemaPrincipal.apilarSistema(p1);
        sistemaPrincipal.apilarSistema(p2);
        sistemaPrincipal.apilarSistema(p3);
        sistemaPrincipal.apilarSistema(p4);
        sistemaPrincipal.apilarSistema(p5);
        sistemaPrincipal.apilarSistema(p6);
        sistemaPrincipal.apilarSistema(p7);
        sistemaPrincipal.apilarSistema(p8);
        break;

    case 2: //mostrar la pila de procesos
        sistemaPrincipal.mostrarPilaProcesos();
        break;

    case 3: //borrar la pila de procesos
        cout << "Borrando pila..."<<endl;
        sistemaPrincipal.borrarPila();
        break;

    case 4: //mostrar la cola de prioridades
        sistemaPrincipal.mostrarColaPrioridad();
        break;

    case 5: //mostrar los procesos activos en los nucleos
        sistemaPrincipal.mostrarProcesosNucleo();
        break;

    case 6://Pasa n minutos en el sistema   
        int minutos;
        cout << "Cuantos minutos quieres que pasen: ";
        cin >> minutos;
        if (minutos>0){
            sistemaPrincipal.pasarTiempo(minutos);
        }
        else{
            cout << "Minutos<0 ??? "<<endl;}
        break;

    case 7:  //Pasa todo el tiempo hasta que acaben todos los procesos   
        sistemaPrincipal.acabarProcesos();
        break;

    case 8: //////////////////////////debug de metodos de apilar y encolar
        ptest.apilar(p1);
        ptest.apilar(p2);
        ptest.apilar(p3);
        ptest.apilar(p4);
        ptest.apilar(p5);
        ptest.apilar(p6);
        ptest.apilar(p7);
        ptest.apilar(p8);
        cout << "Pila: "<<endl;
        ptest.mostrarPila();

        while(!ptest.esVacia()){
            ctest.encolarPrioridad(ptest.mostrar());
            ptest.desapilar();
        }
        cout << "cola: "<<endl;
        ctest.mostrarCola();
        break;

    default:
        cout << "Opcion no valida "<<endl;
        break;
    }
}


return 0;
}


