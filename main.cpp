#include "Pila.h"
#include "Cola.h"
#include "Sistema.h"
#include <iostream>
#include "Lista.h"
#include "SistemaLista.h"
using namespace std;

int main(){
Proceso p1= Proceso(1,0,5,1);
Proceso p2= Proceso(2,0,3,2); 
Proceso p3= Proceso(3,0,6,9);
Proceso p4= Proceso(4,0,7,5);
Proceso p5 = Proceso(5,0,6,1);
Proceso p6 = Proceso(6,0,8,3);
Proceso p7 = Proceso(7,0,5,4);
Proceso p8 = Proceso(8,0,2,4);
Proceso p9 = Proceso(9,0,9,5);
Proceso p10 = Proceso(10,0,4,4);


SistemaLista sl;
Sistema sistemaPrincipal;


bool exit=false;

while(!exit){
bool salir=false;
int menu;
cout<<"Pulse -1 para salir del programa, 1 para la primera parte y 2 para la segunda"<<endl;
cin >> menu;
cout << menu<<endl;
if (menu==-1){exit=true;}
else if (menu==1){
    
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
        if(sistemaPrincipal.pilaVacia() && sistemaPrincipal.colaVacia() && sistemaPrincipal.nucleosVacios()){
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
                cout << "Por favor, introduzca un núme10ro mayor que 0 "<<endl;
            }
        } 
        
        break;

    case 7:  //Pasa todo el tiempo hasta que acaben todos los procesos
        if(sistemaPrincipal.pilaVacia() && sistemaPrincipal.colaVacia() && sistemaPrincipal.nucleosVacios()){
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

}


else if (menu==2) {
    while(!salir){
        int opcion;
        cout << "\nQué opción quieres?:\n|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n|-1 -> Volver\t\t\t1 -> Crear pila de procesos del sistema\t\t2 -> Mostrar pila \t3 -> Borrar pila                                  |\n|                                                                                                                                                         |\n| 4 -> Consultar ocupación  \t5 -> Mostrar procesos en nucleos\t\t6 -> Pasar N minutos\t7 -> Acabar todos los procesos y/o t.medio proc.  |\n|---------------------------------------------------------------------------------------------------------------------------------------------------------|\n\nIntroduce una opción: ";
        cin >> opcion;
        cout << opcion<<endl;

        switch (opcion){
            case -1:
                salir=true;
                break;

            case 1: //crear pila de procesos
                if(sl.pilaVacia()){
                    cout << "Creando pila..."<<endl;
                    sl.apilarSistema(p1);
                    sl.apilarSistema(p2);
                    sl.apilarSistema(p3);
                    sl.apilarSistema(p4);
                    sl.apilarSistema(p5);
                    sl.apilarSistema(p6);
                    sl.apilarSistema(p7);
                    sl.apilarSistema(p8);
                    sl.apilarSistema(p9);
                    sl.apilarSistema(p10);
                    }
                else{
                    cout<<"¡Ya tienes una pila con procesos!"<<endl;
                     }
        
                    break;

            case 2: //mostrar la pila de procesos
                sl.mostrarPilaProcesos();
                break;

            case 3: //borrar la pila de procesos
                cout << "Borrando pila..."<<endl;
                sl.borrarPila();
                break;

            case 4: //mostrar nucleo mas y menos ocupado
                sl.mostrarOcupacion();
                break;

            case 5: //mostrar los procesos activos en los nucleos
                sl.mostrarProcesosNucleo();
                break;

            case 6://Pasa n minutos en el sistema  
                if(sl.pilaVacia() && sl.listaVacia() && sl.nucleosVacios()){  //////////////////comprobar
                    cout<<"No hay procesos que ejecutar"<<endl;
                }
                else{
                    int minutos;
                    cout << "Cuantos minutos quieres que pasen: ";
                    cin >> minutos;
                    if (minutos>0){
                        sl.pasarTiempo(minutos);
                    }
                    else{
                        cout << "Por favor, introduzca un núme10ro mayor que 0 "<<endl;
                    }
                } 
        
                break;

            case 7:  //Pasa todo el tiempo hasta que acaben todos los procesos
                    if(sl.pilaVacia() && sl.listaVacia()  && sl.nucleosVacios()){
                        cout<<"No hay procesos que ejecutar"<<endl;
                    }
                    else{
                        sl.acabarProcesos();
                }   
        
                    break;

            default:
                    cout << "Opción no válida "<<endl;
                    break;
            }
        }
    }
else{
    cout << "Opción no válida "<<endl;
}

}
return 0;
}



/*

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
            //sistemaPrincipal.apilarSistema(p7);
            //sistemaPrincipal.apilarSistema(p8);
            //sistemaPrincipal.apilarSistema(p9);
            //sistemaPrincipal.apilarSistema(p10);
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
        if(sistemaPrincipal.pilaVacia() && sistemaPrincipal.colaVacia() && sistemaPrincipal.nucleosVacios()){
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
                cout << "Por favor, introduzca un núme10ro mayor que 0 "<<endl;
            }
        } 
        
        break;

    case 7:  //Pasa todo el tiempo hasta que acaben todos los procesos
        if(sistemaPrincipal.pilaVacia() && sistemaPrincipal.colaVacia() && sistemaPrincipal.nucleosVacios()){
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
*/


//Sistema sistemaPrincipal;
/*
Cola c=Cola();
c.encolarPrioridad(p1);
c.encolarPrioridad(p2);
c.encolarPrioridad(p3);
c.encolarPrioridad(p4);


Nucleo n1=Nucleo(1);
Nucleo n2=Nucleo(2);
Nucleo n3=Nucleo(3);
Nucleo n4 = Nucleo(4);
Nucleo n5 = Nucleo(5);

Lista l=Lista();*/






//cout<<"mostrar vacia: "<<endl;
//l.mostrarLista();

/*

cout<<"aniado procesos a n2..."<<endl;
n2.añadirProceso(p1);
n2.añadirProceso(p2); //n2=2
n2.ejecutarProceso(p3);

cout<<"aniado procesos a n2..."<<endl;
n1.añadirProceso(p4); //n1=1
n1.añadirProceso(p5); 



cout<<"aniado nucleos a cola... "<<endl;
//l.añadirIzquierda(n1);
l.añadirDerecha(n2);
l.añadirDerecha(n1);
l.añadirDerecha(n3);
//n5.ejecutarProceso(p6);
l.añadirIzquierda(n5);
l.añadirDerecha(n4);

cout<<"lista: "<<endl;
l.mostrarLista();

cout<<"l2: "<<endl;
Lista l2;
l2.copiarListaAOtra(l); //l2=l
l2.mostrarLista();

cout<<"borrar inicio: "<<endl;
l.eliminarInicio();

cout<<"lista: "<<endl;
l.mostrarLista();

cout<<"l2: "<<endl;
l2.mostrarLista();
*/
//l.quecoñopasa();
//l.añadirNuevoNucleo();

/*

cout<<"mostrar2: "<<endl;
l.mostrarLista();
cout<<"len cola n2:"<<endl;
l.fin().lenCola();
/*
cout<<"mostrar2: "<<endl;
l.mostrarLista();
cout<<"borrando... "<<endl;
l.eliminarFin();
l.eliminarInicio();
l.mostrarLista();


//bool salir=false;

Lista l;
l.añadirIzquierda(Nucleo(2));

l.añadirDerecha(Nucleo(3));
cout<<"Lista original: "<<endl;
l.añadirIzquierda(Nucleo(10));
l.añadirDerecha(Nucleo(20));


l.eliminarFin();

l.fin().mostrarNucleo();


Nucleo n1=Nucleo(1);
Nucleo n2=Nucleo(2);
//Nucleo n3=Nucleo(3);
//Nucleo n4=Nucleo(4);

n1.añadirProceso(p1);
n1.añadirProceso(p2);
//n2.añadirProceso(p3);
//n2.añadirProceso(p5);
//n3.añadirProceso(p6);
//n4.añadirProceso(p3);

cout<<"creo lista..."<<endl;
Lista l;
//l.inicio().mostrarNucleo();
l.añadirDerecha(n1);
//l.añadirDerecha(n4);
l.añadirDerecha(n2);
//l.añadirDerecha(n3);
//l.añadirDerecha(n3);
//l.añadirDerecha(n4);
//l.mostrarLista();
//n2.mostrarNucleo();
l.añadirNuevoNucleo();
l.mostrarLista();

*/
/*
cout<<"añado... "<<endl;
l.añadirIzquierda(n1);
l.añadirDerecha(n4);
l.añadirIzquierda(n2);
l.añadirDerecha(n3);


l.masOcupado();

l.menosOcupado();
*/




