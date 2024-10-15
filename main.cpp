#include "Pila.h"
#include <iostream>
using namespace std;


//tengo procesos metidos en una cola, los saco por la hora y los meto en una cola
//3 núcleos, pueden ser 1 array, si los 3 tienen procesos ejecutandose, proceso entra en cola de espera





int main()
{
Proceso p1= Proceso(1,1,10,20,3,1);
Proceso p2= Proceso(2,1,3,20,3,1);
Proceso p3= Proceso(3,1,6,20,3,1);
Proceso p4= Proceso(4,1,1,20,3,1);
Proceso p5= Proceso(5,1,624,20,3,1);


//int PID, int PPID=1,int inicioProceso, int tiempoVida, int prioridad, int nucleo

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
return 0;
}