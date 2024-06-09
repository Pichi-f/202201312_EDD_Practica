#include <iostream>
#include "nodoPasajeros.h"
#include "nodoEquipaje.h"
#include <string>

using namespace std;

class nodoEquipaje{
    public:
        this->nodoPasajeros *pasajero;
        this->nodoEquipaje *siguiente;
        this->nodoEquipaje *anterior;
        nodoEquipaje(nodoPasajeros *pasaje);
        virtual ~nodoEquipaje();
};

nodoEquipaje::nodoEquipaje(nodoPasajeros *pasaje){
    this->pasajero = pasaje;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}

nodoEquipaje::~nodoEquipaje()
{

}