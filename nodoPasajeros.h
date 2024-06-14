#ifndef NODOPASAJEROS_H
#define NODOPASAJEROS_H

#include <iostream>
#include <string>
using namespace std;

class nodoPasajeros
{
    public:
        string nombre;
        string nacionalidad;
        string numero_de_pasaporte;
        string vuelo;
        int asiento;
        string destino;
        string origen;
        int equipaje_facturado;
        nodoPasajeros *siguiente;
        nodoPasajeros(string nombre, string nacionalidad, string numero_de_pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje_facturado);
        virtual ~nodoPasajeros();
};

nodoPasajeros::nodoPasajeros(string nombre, string nacionalidad, string numero_de_pasaporte, string vuelo, int asiento, string destino, string origen, int equipaje_facturado)
{
    this->nombre = nombre;
    this->nacionalidad = nacionalidad;
    this->numero_de_pasaporte = numero_de_pasaporte;
    this->vuelo = vuelo;
    this->asiento = asiento;
    this->destino = destino;
    this->origen = origen;
    this->equipaje_facturado = equipaje_facturado;
    this->siguiente = nullptr;
}

nodoPasajeros::~nodoPasajeros()
{
}

#endif