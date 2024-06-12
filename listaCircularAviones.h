#ifndef LISTACIRCULARAVIONES_H
#define LISTACIRCULARAVIONES_H
#include <iostream>
#include <string>
#include "nodoAviones.h"
using namespace std;

class listaCircularAviones
{
    public:
        nodoAviones* primero;
        nodoAviones* ultimo;
        int tamano;
        listaCircularAviones();
        virtual ~listaCircularAviones();
        void insertar(string vuelo, string numero_de_registro, string modelo, string fabricante, int ano_fabricacion, int capacidad, int peso_max_despegue, string aerolinea, string estado);
        void mostrar();
        void graficar(string Nombre);
        nodoAviones* cambiarEstado(string estado, string vuelo);
};

listaCircularAviones::listaCircularAviones()
{
    primero = nullptr;
    ultimo = nullptr;
    tamano = 0;
}

listaCircularAviones::~listaCircularAviones()
{

}

void listaCircularAviones::insertar(string vuelo, string numero_de_registro, string modelo, string fabricante, int ano_fabricacion, int capacidad, int peso_max_despegue, string aerolinea, string estado)
{
    nodoAviones *nuevo = new nodoAviones(vuelo, numero_de_registro, modelo, fabricante, ano_fabricacion, capacidad, peso_max_despegue, aerolinea, estado);
    if (primero == nullptr)
    {
        primero = nuevo;
        ultimo = nuevo;
        primero->siguiente = primero;
        primero->anterior = ultimo;
        tamano++;
    }
    else
    {
        ultimo->siguiente = nuevo;
        nuevo->anterior = ultimo;
        nuevo->siguiente = primero;
        ultimo = nuevo;
        primero->anterior = ultimo;
        tamano++;
    }
}

void listaCircularAviones::mostrar()
{
    if (primero == nullptr && ultimo == nullptr)
    {
        cout << "No hay aviones registrados" << endl;
        return;
    }
    nodoAviones *actual = primero;
    do
    {
        cout << "Vuelo: " << actual->vuelo << endl;
        cout << "Numero de registro: " << actual->numero_de_registro << endl;
        cout << "Estado: " << actual->estado << endl;
        cout << "--------------------------------" << endl;
        actual = actual->siguiente;
    } while (actual != primero);        
     
}

nodoAviones* listaCircularAviones::cambiarEstado(string estado, string registro){
    if (primero == nullptr && ultimo == nullptr)
    {
        cout << "No hay aviones registrados" << endl;
        return nullptr;
    }
    int contador = 0;
    cout<<estado<<endl<<"\n";
    nodoAviones *aux = primero;
    while (contador != tamano)
    {
        if(aux->numero_de_registro == registro){
            nodoAviones *actual = aux;
            if (actual == primero && actual == ultimo)
            {
                primero = nullptr;
                ultimo = nullptr;
            }
            else if (actual == primero){
                primero = primero->siguiente;
                primero->anterior = ultimo;
                ultimo->siguiente = primero;
            }
            else if (actual == ultimo){
                ultimo = ultimo->anterior;
                ultimo->siguiente = primero;
                primero->anterior = ultimo;
            }
            else{
                actual->anterior->siguiente = actual->siguiente;
                actual->siguiente->anterior = actual->anterior;
            }
            tamano--;
            return aux;
        }
        aux = aux->siguiente;
        contador++;
    }
    return 0;
}

#endif // LISTACIRCULARAVIONES_H