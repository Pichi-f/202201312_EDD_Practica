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
    if (equipajePasajero == nullptr){
        return;
    }
    nodoEquipaje *nuevo = new nodoEquipaje(equipajePasajero);
    if (this->ultimo == nullptr){
        this->primero = nuevo;
        this->ultimo = nuevo;
    }else{
        this->primero->anterior = nuevo;
        this->primero->anterior->siguiente = this->primero;
        this->primero = nuevo;
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
    texto += "node [shape=record];\n";
    nodoEquipaje* actual = primero;
    while (actual != nullptr) {
        texto += "\"" + actual->pasajero->numero_de_pasaporte + "\" [label=\"{Pasaporte: " + actual->pasajero->numero_de_pasaporte + " | Nombre: " + actual->pasajero->nombre + " | Equipaje: " + to_string(actual->pasajero->equipaje_facturado) + "}\"];\n";
        if (actual->siguiente != nullptr) {
            texto += "\"" + actual->pasajero->numero_de_pasaporte + "\" -> \"" + actual->siguiente->pasajero->numero_de_pasaporte + "\";\n";
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


#endif // PILAEQUIPAJE_H