#include "Pila.h"
#include "Cola.h"
#include <iostream>
using namespace std;


//tengo procesos metidos en una cola, los saco por la hora y los meto en una cola
//3 núcleos, pueden ser 1 array, si los 3 tienen procesos ejecutandose, proceso entra en cola de espera





int main()
{
Proceso p1= Proceso(1,1,10,20,10,1);
Proceso p2= Proceso(2,1,3,20,3,1);
Proceso p3= Proceso(3,1,6,20,6,1);
Proceso p4= Proceso(4,1,1,20,1,1);
Proceso p42= Proceso(42,1,1,2,1,1);
Proceso p5= Proceso(5,1,624,20,624,1);
Proceso p43= Proceso(43,1,1,2,1,1);
//proceso: int PID, int PPID=1,int inicioProceso, int tiempoVida, int prioridad, int nucleo

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

cout << "encolo p42" << endl;
c.encolarPrioridad(p42);
c.mostrarCola();

cout << "encolo p5" << endl;
c.encolarPrioridad(p5);
c.mostrarCola();

cout << "encolo p43" << endl;
c.encolarPrioridad(p43);
c.mostrarCola();

/*
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

p.~Pila(); //es innecesario, se va a llamar al destructor al salir de la ejecución
*/

return 0;
}