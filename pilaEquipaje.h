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