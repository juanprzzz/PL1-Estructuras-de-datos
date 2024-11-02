#include "NodoLista.h"
#include "Lista.h"
#include "Nucleo.h"
#include <iostream>
using namespace std;

Lista::Lista()
{
    primero = NULL;
    ultimo = NULL;
    ctdNucleos = 0;
}

Lista::Lista(Nucleo n)
{
    primero = new NodoLista(n);
    ultimo = primero;
    ctdNucleos = 1;
}

Lista::~Lista()
{
    while (!esVacia())
    {
        eliminarInicio();
    }
}

void Lista::añadirIzquierda(Nucleo nucleo)
{
    ctdNucleos++;
    // Nucleo nucleo = Nucleo(ctdNucleos);
    NodoLista *nuevo_nodo = new NodoLista(nucleo);
    if (esVacia())
    {
        primero = nuevo_nodo;
        ultimo = primero;
    }
    else
    {
        nuevo_nodo->siguiente = primero;
        primero = nuevo_nodo;
    }
}

void Lista::añadirDerecha(Nucleo nucleo)
{
    ctdNucleos++;
    NodoLista *nuevo_nodo = new NodoLista(nucleo);
    if (esVacia())
    {
        primero = nuevo_nodo;
        ultimo = primero;
    }
    else
    {
        // Nucleo nucleo=Nucleo(ctdNucleos);
        ultimo->siguiente = nuevo_nodo; // puntero->atributo -------Falla<<<<
        ultimo = nuevo_nodo;
    }
}

void Lista::eliminarFin()
{
    NodoLista *aux; // puntero aux para manipular el nodo
    if (!esVacia() && ctdNucleos >= 2)
    { // si solo hay 1 no puedo hacer siguiente->siguiente
        aux = primero;
        while (aux->siguiente->siguiente != NULL)
        { // si el elemento siguiente tiene como atributo "siguiente" null (si el siguiente del aux es el ultimo)
            aux = aux->siguiente;
        }
        ultimo = aux;
        ultimo->siguiente = NULL;
        // delete aux;
        ctdNucleos--;
    }

    else if (ctdNucleos == 1)
    {
        primero = NULL;
        ultimo = NULL;
        ctdNucleos--;
    }
}

void Lista::eliminarInicio()
{
    if (!esVacia())
    { //////////////cuidado, siempre tiene que haber al menos 1 nucleo en lista!
        Nucleo elemento = primero->nucleo;
        NodoLista *aux = primero;
        if ((primero == ultimo) && (primero->siguiente == NULL))
        { // si solo hay 1 elemento. podria ser if (ctdNucleos==1) DUDA: Si primero es el último entonces su puntero al siguiente será null, entonces ¿Por qué comprobarlo?
            primero = NULL;
            ultimo = NULL;
            aux->siguiente = NULL;
            delete aux;
        }
        else
        {
            primero = primero->siguiente;
            aux->siguiente = NULL;
            delete aux;
        }
        ctdNucleos--;
    }
    else if (ctdNucleos == 1)
    {
        primero = NULL;
        ultimo = NULL;
        ctdNucleos--;
    }
}

Nucleo Lista::inicio()
{
    if (!esVacia())
    {
        return primero->nucleo;
    }
    else
    {
        return Nucleo();
    }
}

Nucleo Lista::fin()
{
    if (!esVacia())
    {
        // cout<<ultimo->nucleo.colaEspera.es_vacia()<<endl;
        return ultimo->nucleo;
    }
    else
    {
        return Nucleo();
    }
}

void Lista::mostrarLista()
{
    if (esVacia())
    {
        cout << "lista vacia:) " << endl;
    }
    else
    {
        Lista listaCopia = copiarLista();
        while (!listaCopia.esVacia())
        {
            listaCopia.inicio().mostrarNucleo();
            listaCopia.eliminarInicio();
        }
    }
}

Lista Lista::copiarLista()
{
    Lista listaAux;
    Lista listaResultado;
    // listaAux.inicio().mostrarNucleo();
    while (!esVacia())
    {
        listaAux.añadirDerecha(inicio());
        listaResultado.añadirDerecha(inicio());
        eliminarInicio();
    }
    ctdNucleos = 0;
    while (!listaAux.esVacia())
    {
        añadirDerecha(listaAux.inicio());
        listaAux.eliminarInicio();
    }
    return listaResultado;
}


bool Lista::esVacia()
{
    return ((primero == NULL) && (ultimo == NULL));
}

int Lista::getCtdNucleos()
{
    return ctdNucleos;
}

int Lista::posicMenosOcupado(){
    {
 if (esVacia())
    {
        //cout << "Está vacía. posic=-1" << endl;
        return -1;
    }
else
    {
        if (ctdNucleos == 1)
        {
           // cout << "Hay 1 núcleo solo. posic=1" << endl;
            return 1;
        }

        else // if (ctdNucleos > 1)
        {
            NodoLista *aux; // puntero aux para manipular el nodo
            Lista resultado;
            Nucleo nucleoAux;
            aux = primero;
            nucleoAux = primero->nucleo;
            resultado.añadirDerecha(nucleoAux);
            int posic=1;

            while (aux->siguiente != NULL)
            { // hasta que llegue al final de los elementos
                aux = aux->siguiente;
                if (nucleoAux.colaEspera.get_longitud() > aux->nucleo.colaEspera.get_longitud())
                {
                    resultado.~Lista(); // si encuentra que el siguiente nucleo de la lista está menos ocupado, borra la lista y lo mete
                    nucleoAux = aux->nucleo;
                    resultado.añadirDerecha(nucleoAux);
                    posic++; //si hay mas de 1 devuelve la posic del primero
                }
                else if (nucleoAux.colaEspera.get_longitud() == aux->nucleo.colaEspera.get_longitud())
                {
                    nucleoAux = aux->nucleo; // si encuentra que el siguiente nucleo esta igual de ocupado, lo añade también a la lista
                    resultado.añadirDerecha(nucleoAux);
                }
            }
            //cout << "posicion: " << posic << endl;
            //resultado.mostrarLista();
            return posic;
        }
    }
}
}

void Lista::menosOcupado()
{
 if (esVacia())
    {
        cout << "Está vacía" << endl;
    }
else
    {
        if (ctdNucleos == 1)
        {
            cout << "Hay 1 núcleo solo:" << endl;
            mostrarLista();
        }

        else // if (ctdNucleos > 1)
        {
            NodoLista *aux; // puntero aux para manipular el nodo
            Lista resultado;
            Nucleo nucleoAux;
            aux = primero;
            nucleoAux = primero->nucleo;
            resultado.añadirDerecha(nucleoAux);
            while (aux->siguiente != NULL)
            { // hasta que llegue al final de los elementos
                aux = aux->siguiente;
                if (nucleoAux.colaEspera.get_longitud() > aux->nucleo.colaEspera.get_longitud())
                {
                    resultado.~Lista(); // si encuentra que el siguiente nucleo de la lista está menos ocupado, borra la lista y lo mete
                    nucleoAux = aux->nucleo;
                    resultado.añadirDerecha(nucleoAux);
                   
                }
                else if (nucleoAux.colaEspera.get_longitud() == aux->nucleo.colaEspera.get_longitud())
                {
                    nucleoAux = aux->nucleo; // si encuentra que el siguiente nucleo esta igual de ocupado, lo añade también a la lista
                    resultado.añadirDerecha(nucleoAux);
                }
            }
            resultado.mostrarLista();

        }
    }

}

void Lista::masOcupado()
{
    if (esVacia())
    {
        cout << "Está vacía" << endl;
    }
    else
    {
        if (ctdNucleos == 1)
        {
            cout << "Hay 1 núcleo solo:" << endl;
            primero->nucleo.mostrarNucleo();
        }

        else // if (ctdNucleos > 1)
        {
            NodoLista *aux; // puntero aux para manipular el nodo
            Lista resultado;
            Nucleo nucleoAux;
            aux = primero;
            nucleoAux = primero->nucleo;
            resultado.añadirDerecha(nucleoAux);

            while (aux->siguiente != NULL)
            { // hasta que llegue al final de los elementos
                aux = aux->siguiente;
                if (nucleoAux.colaEspera.get_longitud() < aux->nucleo.colaEspera.get_longitud())
                {
                    resultado.~Lista(); // si encuentra que el siguiente nucleo de la lista está más ocupado, borra la lista y lo mete
                    nucleoAux = aux->nucleo;
                    resultado.añadirDerecha(nucleoAux);
                }
                else if (nucleoAux.colaEspera.get_longitud() == aux->nucleo.colaEspera.get_longitud())
                {
                    nucleoAux = aux->nucleo; // si encuentra que el siguiente nucleo esta igual de ocupado, lo añade también a la lista
                    resultado.añadirDerecha(nucleoAux);
                }
            }
            cout << "mas ocupado; ctd nucleos:" << ctdNucleos << endl;
            resultado.mostrarLista();
        }
    }
}

bool Lista::comprobarAñadirNuevosNucleos()
{
    Lista listaCopia = copiarLista();
    //listaCopia.mostrarLista();
    bool añadir = true;
    while (!listaCopia.esVacia() && añadir)
    {
        Cola c = listaCopia.inicio().colaEspera;
        int len = c.get_longitud();
        if (len < 2)
        {
            añadir = false;
        }
        listaCopia.eliminarInicio();
    }
    return añadir;
}

void Lista::añadirNuevoNucleo()
{
    if (comprobarAñadirNuevosNucleos())
    {
        añadirDerecha(Nucleo(ctdNucleos + 1));
    }
}

int Lista::comprobarEliminarNucleos()
{
    Lista listaCopia = copiarLista();
    int nucleosVacios = 0;
    while (!listaCopia.esVacia())
    {
        if (listaCopia.inicio().colaEspera.es_vacia() && listaCopia.inicio().procesoEjecucion.nucleo == -1) //Si la cola de espera está vacía y los núcleos no ejecutan ningún proceso
        {
            nucleosVacios++;
        }

        listaCopia.eliminarInicio();
    }
    if (ctdNucleos - nucleosVacios == 0) //Si la diferencia de los núcleos totales y vacíos es 0, entonces puedo eliminar n - 1 núcleos
    {
        nucleosVacios--;
    }
    return nucleosVacios;
}
void Lista::eliminarNucleosVacios(int nucleosVacios)
{
    Lista listaNoEliminados;
    int nucleosEliminados = 0;
    while (nucleosEliminados != nucleosVacios) // Elimino tantos núcleos como se indiquen (no sirve con for, eliminaría menos núcleos, pueden pasar 20 núcleos hasta poder eliminar 3 porque el resto están ocupados)
    {
        if (!(inicio().colaEspera.es_vacia() && inicio().procesoEjecucion.nucleo == -1)) // Si la cola de espera no está vacía, y hay un proceso ejecución, no puedo eliminarlo
        {
            listaNoEliminados.añadirDerecha(inicio());
        }
        else
        {
            nucleosEliminados++;
        }
        eliminarInicio();
    }
    while (!listaNoEliminados.esVacia()) //Vuelco los núcleos ocupados en la lista principal
    {
        añadirDerecha(listaNoEliminados.inicio());
        listaNoEliminados.eliminarInicio();
    }
}
