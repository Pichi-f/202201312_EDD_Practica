#ifndef COLAPASAJEROS_H
#define COLAPASAJEROS_H
#include <iostream>
#include <string>
#include "nodoPasajeros.h"
using namespace std;

class colaPasajeros
{
    public:
        nodoPasajeros *primero;
        nodoPasajeros *ultimo;
        int tamano;
        colaPasajeros();
        virtual ~colaPasajeros();
        void insertar(string nombre, string nacionalidad, string numero_de_pasaporte, string vuelo, string asiento, string destino, string origen, int equipaje_facturado);
        void mostrarPasajeros();
        nodoPasajeros* pasajeroRegistrado();
};

colaPasajeros::colaPasajeros()
{
    primero = nullptr;
    ultimo = nullptr;
    tamano = 0;
}

colaPasajeros::~colaPasajeros()
{

}

void colaPasajeros::insertar(string nombre, string nacionalidad, string numero_de_pasaporte, string vuelo, string asiento, string destino, string origen, int equipaje_facturado)
{
    nodoPasajeros *nuevo = new nodoPasajeros(nombre, nacionalidad, numero_de_pasaporte, vuelo, asiento, destino, origen, equipaje_facturado);
    if (primero == 0)
    {
        primero = nuevo;
        primero->siguiente = nullptr;
        ultimo = primero;
        tamano++;
    }
    else
    {
        ultimo->siguiente = nuevo;
        nuevo->siguiente = nullptr;
        ultimo = nuevo;
        tamano++;
    }
}

void colaPasajeros::mostrarPasajeros()
{
    if (primero == nullptr)
    {
        cout << "No hay pasajeros registrados" << endl;
        return;
    }
    nodoPasajeros *aux = primero;
    while (aux != nullptr){
        cout << aux->numero_de_pasaporte << std::endl;
        aux = aux->siguiente;
    } 
}

nodoPasajeros* colaPasajeros::pasajeroRegistrado(){
    if (primero == nullptr)
    {
        cout << "No hay pasajeros registrados" << endl;
        return nullptr;
    }
    nodoPasajeros* nodoRegreso = primero;
    nodoPasajeros* nodoEliminar = primero;
    primero = primero->siguiente;

    if (primero == nullptr)
    {
        ultimo = nullptr;
    }
    cout << "Pasajero eliminado" << nodoEliminar->numero_de_pasaporte << endl;
    delete nodoEliminar;
    return nodoRegreso;
}

#endif // COLAPASAJEROS_H