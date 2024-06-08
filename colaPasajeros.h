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
    if (primero == nullptr) // Cambio de 0 a nullptr para mejorar la legibilidad
    {
        cout << "No hay pasajeros registrados" << endl;
        return;
    }
    int contador = 0;
    nodoPasajeros *aux = primero;
    while (aux != nullptr)
    {
        cout << "Pasajero " << contador + 1 << ": " << endl;
        cout << "Nombre: " << aux->nombre << endl;
        cout << "Nacionalidad: " << aux->nacionalidad << endl;
        cout << "Numero de pasaporte: " << aux->numero_de_pasaporte << endl;
        cout << "Vuelo: " << aux->vuelo << endl;
        cout << "Asiento: " << aux->asiento << endl;
        cout << "Destino: " << aux->destino << endl;
        cout << "Origen: " << aux->origen << endl;
        cout << "Equipaje facturado: " << aux->equipaje_facturado << endl;
        cout << endl;
        aux = aux->siguiente;
        contador++;
    }
}