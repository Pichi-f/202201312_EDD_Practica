#ifndef PILAEQUIPAJE_H
#define PILAEQUIPAJE_H
#include <iostream>
#include "nodoPasajeros.h"
#include "nodoEquipaje.h"
#include <string>

using namespace std;

class pilaEquipaje{
    public:
        nodoEquipaje *primero;
        nodoEquipaje *ultimo;
        nodoEquipaje *pasajero;
        void insertarNodoPila(nodoPasajeros *pasajero);
        void mostrarPila();
        pilaEquipaje();
        virtual ~pilaEquipaje();
};

pilaEquipaje::pilaEquipaje(){
    this->primero = nullptr;
    this->ultimo = nullptr;
    this->pasajero = nullptr;
}

pilaEquipaje::~pilaEquipaje()
{

}

void pilaEquipaje::insertarNodoPila(nodoPasajeros *equipajePasajero){
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

void pilaEquipaje::mostrarPila(){
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

#endif // PILAEQUIPAJE_H