#include <iostream>
#include "nodoPasajeros.h"
using namespace std;

class nodoEquipaje{
    public:
        nodoPasajeros *pasajero;
        nodoEquipaje *siguiente;
        nodoEquipaje *anterior;
}