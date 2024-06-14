#ifndef COLAPASAJEROS_H
#define COLAPASAJEROS_H
#include <iostream>
#include <string>
#include "nodoPasajeros.h"
#include <cstdlib>
#include <fstream>
#include <thread>
using namespace std;

class colaPasajeros
{
    public:
        nodoPasajeros *primero;
        nodoPasajeros *ultimo;
        int tamano;
        colaPasajeros();
        virtual ~colaPasajeros();
        void insertar(string nombre, string nacionalidad, string numero_de_pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje_facturado);
        void mostrarPasajeros();
        void graficar(string Nombre);
        void limpiar();
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

void colaPasajeros::insertar(string nombre, string nacionalidad, string numero_de_pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje_facturado)
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
    return nodoRegreso;
}

void colaPasajeros::graficar(string Nombre) {
    string texto = "digraph G {\n";
    if (this->primero == 0) {
        cout << "No hay pasajeros registrados en la Cola" << endl;
        return;
    }
    texto += "node [shape=record];\n";
    nodoPasajeros* actual = primero;
    while (actual != 0) {
        texto += "\"" + actual->numero_de_pasaporte + "\" [label=\"{Pasaporte: " + actual->numero_de_pasaporte + " | Nombre: " + actual->nombre + " | Equipaje: " + to_string(actual->equipaje_facturado) + "}\"];\n";
        if (actual->siguiente != 0) {
            texto += "\"" + actual->numero_de_pasaporte + "\" -> \"" + actual->siguiente->numero_de_pasaporte + "\";\n";
        }
        actual = actual->siguiente;
    }
    texto += "}\n";

    ofstream archivo(Nombre + ".dot");
    if (archivo.is_open()) {
        archivo << texto;
        archivo.close();
        string comando = "dot -Tpng " + Nombre + ".dot -o " + Nombre + ".png";
        system(comando.c_str());

        // Detectar el sistema operativo y elegir el comando adecuado para abrir la imagen
        #ifdef _WIN32
        comando = "explorer " + Nombre + ".png";
        #elif __APPLE__
        comando = "open " + Nombre + ".png &";
        #elif __linux__
        comando = "xdg-open " + Nombre + ".png &";
        #else
        #error "OS not supported!"
        #endif

        system(comando.c_str());
    } else {
        cerr << "No se pudo abrir el archivo para escribir el gráfico." << endl;
    }
}

void colaPasajeros::limpiar() {
    while (primero != nullptr) {
        nodoPasajeros* actual = primero;
        primero = primero->siguiente;
        delete actual;
    }
    primero = nullptr;
    ultimo = nullptr;
}

#endif // COLAPASAJEROS_H