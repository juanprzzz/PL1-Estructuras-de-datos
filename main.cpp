#include "Pila.h"
#include "Cola.h"
#include "Sistema.h"
#include <iostream>

using namespace std;

int main(){
Proceso p1= Proceso(1,10,5,7);
Proceso p2= Proceso(2,1,10,2); 
Proceso p3= Proceso(3,1,5,3);
Proceso p4= Proceso(4,1,2,5);
Proceso p5 = Proceso(5,12,5,2);
Proceso p6 = Proceso(6,3,9,9);
Proceso p7 = Proceso(7,15,5,4);
Proceso p8 = Proceso(8,12,2,4);
Proceso p9 = Proceso(9,23,9,5);
Proceso p10 = Proceso(10,2,4,4);
Sistema sistemaPrincipal;


bool salir=false;
while(!salir){
    int opcion;
    cout << "\nQué opción quieres?:\n|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n|-1 -> Salir\t\t\t1 -> Crear pila de procesos del sistema\t\t2 -> Mostrar pila \t3 -> Borrar pila                                  |\n|                                                                                                                                                         |\n| 4 -> Mostrar cola espera\t5 -> Mostrar procesos en nucleos\t\t6 -> Pasar N minutos\t7 -> Acabar todos los procesos y/o t.medio proc.  |\n|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n\nIntroduce una opción: ";
    cin >> opcion;
    cout << opcion<<endl;

    switch (opcion)
    {
    case -1:
        salir=true;
        break;

    case 1: //crear pila de procesos
        if(sistemaPrincipal.pilaVacia()){
            cout << "Creando pila..."<<endl;
            sistemaPrincipal.apilarSistema(p1);
            sistemaPrincipal.apilarSistema(p2);
            sistemaPrincipal.apilarSistema(p3);
            sistemaPrincipal.apilarSistema(p4);
            sistemaPrincipal.apilarSistema(p5);
            sistemaPrincipal.apilarSistema(p6);
            sistemaPrincipal.apilarSistema(p7);
            sistemaPrincipal.apilarSistema(p8);
            sistemaPrincipal.apilarSistema(p9);
            sistemaPrincipal.apilarSistema(p10);
        }
        else{
            cout<<"¡Ya tienes una pila con procesos!"<<endl;
        }
        
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
        if(sistemaPrincipal.pilaVacia()){
            cout<<"No hay procesos que ejecutar"<<endl;
        }
        else{
            int minutos;
            cout << "Cuantos minutos quieres que pasen: ";
            cin >> minutos;
            if (minutos>0){
                sistemaPrincipal.pasarTiempo(minutos);
            }
            else{
                cout << "Por favor, introduzca un número mayor que 0 "<<endl;
            }
        } 
        
        break;

    case 7:  //Pasa todo el tiempo hasta que acaben todos los procesos
        if(sistemaPrincipal.pilaVacia()){
            cout<<"No hay procesos que ejecutar"<<endl;
        }
        else{
            sistemaPrincipal.acabarProcesos();
        }   
        
        break;

    default:
        cout << "Opción no válida "<<endl;
        break;
    }
}


return 0;
}


