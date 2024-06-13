#ifndef NODOEQUIPAJE_H
#define NODOEQUIPAJE_H
#include <iostream>
#include "nodoPasajeros.h"
#include "nodoEquipaje.h"
#include <string>

using namespace std;

class nodoEquipaje{
    public:
        nodoPasajeros* pasajero;
        nodoEquipaje* siguiente;
        nodoEquipaje* anterior;
        nodoEquipaje(nodoPasajeros *pasaje);
        virtual ~nodoEquipaje();
};

nodoEquipaje::nodoEquipaje(nodoPasajeros *pasaje){
    pasajero = pasaje;
    siguiente = nullptr;
    anterior = nullptr;
}

nodoEquipaje::~nodoEquipaje()
{

}

#endif // NODOEQUIPAJE_H
