#ifndef NODO_AVIONES_H
#define NODO_AVIONES_H

#include <iostream>
#include <string>
using namespace std;

class nodoAviones
{
    public:
        std::string vuelo;
        std::string numero_de_registro;
        std::string modelo;
        std::string fabricante;
        int ano_fabricacion;
        int capacidad;
        int peso_max_despegue;
        std::string aerolinea;
        std::string estado;
        nodoAviones *siguiente;
        nodoAviones *anterior;
        nodoAviones(std::string vuelo, std::string numero_de_registro, std::string modelo, std::string fabricante, int ano_fabricacion, int capacidad, int peso_max_despegue, std::string aerolinea, std::string estado);
        virtual ~nodoAviones();
};

nodoAviones::nodoAviones(string vuelo, string numero_de_registro, string modelo, string fabricante, int ano_fabricacion, int capacidad, int peso_max_despegue, string aerolinea, string estado)
{
    this->vuelo = vuelo;
    this->numero_de_registro = numero_de_registro;
    this->modelo = modelo;
    this->fabricante = fabricante;
    this->ano_fabricacion = ano_fabricacion;
    this->capacidad = capacidad;
    this->peso_max_despegue = peso_max_despegue;
    this->aerolinea = aerolinea;
    this->estado = estado;
    this->siguiente = nullptr;
    this->anterior = nullptr;
}
nodoAviones::~nodoAviones()
{
}

#endif