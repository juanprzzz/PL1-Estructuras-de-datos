#include "Pila.h"
#include "Cola.h"
#include <iostream>
#include <string>
#include "Sistema.h"
using namespace std;


//tengo procesos metidos en una cola, los saco por la hora y los meto en una cola
//3 núcleos, pueden ser 1 array, si los 3 tienen procesos ejecutandose, proceso entra en cola de espera





int main()
{
Proceso p1= Proceso(1,1,10,5,7,1);
Proceso p2= Proceso(2,1,3,10,2,2);
Proceso p3= Proceso(3,1,6,5,3,2);
Proceso p4= Proceso(4,1,1,2,5,3);
Proceso p5= Proceso(5,1,624,1,4,2);
Proceso p6 = Proceso(6, 1,3,4,0,1);


Sistema sistemaPrincipal;

sistemaPrincipal.apilarSistema(p1);
sistemaPrincipal.apilarSistema(p2);

sistemaPrincipal.apilarSistema(p3);

sistemaPrincipal.apilarSistema(p4);

sistemaPrincipal.apilarSistema(p5);

sistemaPrincipal.apilarSistema(p6);


//sistemaPrincipal.addPilaProcesos(p);
//sistemaPrincipal.añadirCola(p1);
//sistemaPrincipal.añadirCola(p2);
//sistemaPrincipal.añadirCola(p3);
//sistemaPrincipal.añadirCola(p4);
//sistemaPrincipal.añadirCola(p5);
//sistemaPrincipal.añadirCola(p6);
//sistemaPrincipal.pasarTiempo(20);
//for(int i = 0; i < 6; i++){
//    cout<<sistemaPrincipal.colaEsperaE()<<endl;
//    sistemaPrincipal.desencolarCola();
//}
//return 0;
//}
sistemaPrincipal.pasarTiempo(20); 
}
/*


sistemaPrincipal.apilar(p1);
sistemaPrincipal.apilar(p2);
sistemaPrincipal.apilar(p3);
sistemaPrincipal.apilar(p4);
sistemaPrincipal.apilar(p5);
sistemaPrincipal.apilar(p6);

sistemaPrincipal.encolar(p1);
sistemaPrincipal.encolar(p2);
sistemaPrincipal.encolar(p3);
sistemaPrincipal.encolar(p4);
sistemaPrincipal.encolar(p5);
sistemaPrincipal.encolar(p6);



cout<<p1.toString()<<endl;
cout << "Creamos la cola Vacia" << endl;
Cola c; 
c.mostrarCola();

cout << "encolo p1" << endl;
c.encolarPrioridad(p1);
c.mostrarCola();

cout << "encolo p2" << endl;
c.encolarPrioridad(p2);
c.mostrarCola();

cout << "encolo p3" << endl;
c.encolarPrioridad(p3);
c.mostrarCola();

cout << "encolo p4" << endl;
c.encolarPrioridad(p4);
c.mostrarCola();

cout << "encolo p3 x2" << endl;
c.encolarPrioridad(p3);
c.mostrarCola();


cout << "encolo p5" << endl;
c.encolarPrioridad(p5);
c.mostrarCola();


cout << "Creamos la pila Vacia" << endl;
Pila p; 
p.mostrarPila();

cout << "Apilo p1" << endl;
p.apilar(p1); 
p.mostrarPila();

cout << "Apilo p2" << endl;
p.apilar(p2); 
p.mostrarPila();

cout << "Apilo p3" << endl;
p.apilar(p3); 
p.mostrarPila();

cout << "Apilo p4" << endl;
p.apilar(p4); 
p.mostrarPila();

cout << "Apilo p5" << endl;
p.apilar(p5); 
p.mostrarPila();

//int PID, int PPID=1,int inicioProceso, int tiempoVida, int prioridad, int nucleo

*/
