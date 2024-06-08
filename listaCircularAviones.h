#include <iostream>
#include <string>
#include "nodoAviones.h"
using namespace std;

class listaCircularAviones
{
    public:
        nodoAviones *primero;
        nodoAviones *ultimo;
        int tamano;
        listaCircularAviones();
        virtual ~listaCircularAviones();
        void insertar(string vuelo, string numero_de_registro, string modelo, string fabricante, int ano_fabricacion, int capacidad, int peso_max_despegue, string aerolinea, string estado);
        void mostrar();
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
    if (primero == 0)
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
    if (primero == 0)
    {
        cout << "No hay aviones registrados" << endl;
        return;
    }
    int contador = 0;
    nodoAviones *aux = primero;
    while (contador != tamano)
    {
        cout << "Vuelo: " << aux->vuelo << endl;
        cout << "Numero de registro: " << aux->numero_de_registro << endl;
        cout << "Modelo: " << aux->modelo << endl;
        cout << "Fabricante: " << aux->fabricante << endl;
        cout << "Ano de fabricacion: " << aux->ano_fabricacion << endl;
        cout << "Capacidad: " << aux->capacidad << endl;
        cout << "Peso maximo de despegue: " << aux->peso_max_despegue << endl;
        cout << "Aerolinea: " << aux->aerolinea << endl;
        cout << "Estado: " << aux->estado << endl;
        cout << "--------------------------------" << endl;
        aux = aux->siguiente;
        contador++;
    }   
}