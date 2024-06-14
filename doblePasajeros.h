#ifndef DOBLEPASAJEROS_H
#define DOBLEPASAJEROS_H
#include <iostream>
#include "nodoPasajeros.h"
#include "nodoEquipaje.h"
#include <string>

using namespace std;

class doblePasajeros{
    public:
        nodoEquipaje *primero;
        nodoEquipaje *ultimo;
        nodoEquipaje *pasajero;
        void insertarNodoDoble(nodoPasajeros *pasajero);
        void mostrarDoble();
        void graficarDoble(string Nombre);
        void busqueda(string pasaporte);
        void limpiar();
        doblePasajeros();
        virtual ~doblePasajeros();
};

doblePasajeros::doblePasajeros(){
    this->primero = nullptr;
    this->ultimo = nullptr;
    this->pasajero = nullptr;
}

doblePasajeros::~doblePasajeros()
{

}

void doblePasajeros::insertarNodoDoble(nodoPasajeros *equipajePasajero){
    if (equipajePasajero == nullptr) {
        return;
    }

    nodoEquipaje *nuevo = new nodoEquipaje(equipajePasajero);

    // Ordenar los nodos por vuelo y asiento
    if (primero == nullptr) {
        primero = nuevo;
        ultimo = nuevo;
    } else {
        nodoEquipaje *actual = primero;
        while (actual != nullptr) {
            if (actual->pasajero->vuelo < nuevo->pasajero->vuelo) {
                actual = actual->siguiente;
            } else if (actual->pasajero->vuelo == nuevo->pasajero->vuelo && actual->pasajero->asiento < nuevo->pasajero->asiento) {
                actual = actual->siguiente;
            } else {
                if (actual == primero) {
                    nuevo->siguiente = primero;
                    primero->anterior = nuevo;
                    primero = nuevo;
                } else {
                    nuevo->siguiente = actual;
                    nuevo->anterior = actual->anterior;
                    actual->anterior->siguiente = nuevo;
                    actual->anterior = nuevo;
                }
                break;
            }
        }

        if (actual == nullptr) {
            ultimo->siguiente = nuevo;
            nuevo->anterior = ultimo;
            ultimo = nuevo;
        }
    }
}

void doblePasajeros::mostrarDoble(){
    if (this->primero == nullptr){
        cout << "No hay equipaje registrado" << endl;
    }else{
        nodoEquipaje *aux = this->primero;
        while (aux != nullptr){
            cout << "Pasajero: " << aux->pasajero->nombre << endl;
            cout << "Nacionalidad: " << aux->pasajero->nacionalidad << endl;
            cout << "Numero de pasaporte: " << aux->pasajero->numero_de_pasaporte << endl;
            cout << "Vuelo: " << aux->pasajero->vuelo << endl;
            cout << "Asiento: " << aux->pasajero->asiento << endl;
            cout << "Destino: " << aux->pasajero->destino << endl;
            cout << "Origen: " << aux->pasajero->origen << endl;
            cout << "Equipaje facturado: " << aux->pasajero->equipaje_facturado << endl;
            cout << "--------------------------------" << endl;
            aux = aux->siguiente;
        }
    }
}

void doblePasajeros::graficarDoble(string Nombre){
    string texto = "digraph G {\n";
    if (primero == 0) {
        cout << "No hay pasajeros registrados en la LDE " << endl;
        return;
    }
    texto += "node [shape=record];\n";
    nodoEquipaje* actual = primero;
    while (actual != nullptr) {
        texto += "\"" + actual->pasajero->numero_de_pasaporte + "\" [label=\"{Pasaporte: " + actual->pasajero->numero_de_pasaporte + " | Nombre: " + actual->pasajero->nombre + " | Equipaje: " + to_string(actual->pasajero->equipaje_facturado) + "}\"];\n";
        if (actual->siguiente != nullptr) {
            texto += "\"" + actual->pasajero->numero_de_pasaporte + "\" -> \"" + actual->siguiente->pasajero->numero_de_pasaporte + "\";\n";
        }
        if (actual->anterior != nullptr) {
            texto += "\"" + actual->pasajero->numero_de_pasaporte + "\" -> \"" + actual->anterior->pasajero->numero_de_pasaporte + "\";\n";
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

void doblePasajeros::busqueda(string pasaporte) {
    nodoEquipaje* actual = primero;
    while (actual != nullptr) {
        if (actual->pasajero->numero_de_pasaporte == pasaporte) {
            cout << "Nombre: " << actual->pasajero->nombre << endl;
            cout << "Vuelo: " << actual->pasajero->vuelo << endl;
            cout << "Asiento: " << actual->pasajero->asiento << endl;
            return;
        }
        actual = actual->siguiente;
    }
    cout << "No se encontró el pasajero con el número de pasaporte: " << pasaporte << endl;
}

void doblePasajeros::limpiar() {
    while (primero != nullptr) {
        nodoEquipaje* actual = primero;
        primero = primero->siguiente;
        delete actual;
    }
    primero = nullptr;
    ultimo = nullptr;
}

#endif // PILAEQUIPAJE_H