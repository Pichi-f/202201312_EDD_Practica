#include <iostream>
#include "json.hpp"
#include <fstream>
#include <sstream>
#include <string>
#include <cctype>
#include <thread>
#include <cstdlib>
#include <windows.h>
#include "listaCircularAviones.h"
#include "nodoAviones.h"
#include "colaPasajeros.h"
#include "nodoPasajeros.h"
#include "pilaEquipaje.h"

listaCircularAviones *avionesDisponibles = new listaCircularAviones();
listaCircularAviones *avionesEnMantenimiento = new listaCircularAviones();
colaPasajeros *pasajeros = new colaPasajeros();
pilaEquipaje *pila = new pilaEquipaje();


using namespace std;
using json = nlohmann::json;

void menuPrincipal(){
    cout << "Menu Principal" << endl;
    cout << "1. Carga de aviones" << endl;
    cout << "2. Carga de pasajeros" << endl;
    cout << "3. Carga de movimientos" << endl;
    cout << "4. Consultar pasajero" << endl;
    cout << "5. Visualizar reportes" << endl;
    cout << "6. Salir" << endl;
}

void cargaAviones(){
    ifstream archivo("aviones.json");

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    json j;
    archivo >> j;

    for(const auto & item : j){
        string vuelo = item["vuelo"];
        string numero_de_registro = item["numero_de_registro"];
        string modelo = item["modelo"];
        string fabricante = item["fabricante"];
        int ano_fabricacion = item["ano_fabricacion"];
        int capacidad = item["capacidad"];
        int peso_max_despegue = item["peso_max_despegue"];
        string aerolinea = item["aerolinea"];
        string estado = item["estado"];

        if(estado == "Disponible" || estado == "disponible"){
            avionesDisponibles->insertar(vuelo, numero_de_registro, modelo, fabricante, ano_fabricacion, capacidad, peso_max_despegue, aerolinea, estado);
        }else{
            avionesEnMantenimiento->insertar(vuelo, numero_de_registro, modelo, fabricante, ano_fabricacion, capacidad, peso_max_despegue, aerolinea, estado);
        }
    
    }
}

void cargaPasajeros(){
    ifstream archivo("pasajeros.json");

    if (!archivo.is_open())
    {
        cout << "No se pudo abrir el archivo" << endl;
        return;
    }
    json j;
    archivo >> j;

    for(const auto & item : j){
        string nombre = item["nombre"];
        string nacionalidad = item["nacionalidad"];
        string numero_de_pasaporte = item["numero_de_pasaporte"];
        string vuelo = item["vuelo"];
        string asiento = item["asiento"];
        string destino = item["destino"];
        string origen = item["origen"];
        int equipaje_facturado = item["equipaje_facturado"];

        pasajeros->insertar(nombre, nacionalidad, numero_de_pasaporte, vuelo, asiento, destino, origen, equipaje_facturado);
    }
}

void comparacion(const std::string& palabra) {
    std::string comando, estado, registro;
    std::stringstream ss(palabra);
    std::getline(ss, comando, ',');
    std::getline(ss, estado, ',');
    std::getline(ss, registro, ',');

    if (estado == "INGRESO") {
        nodoAviones* avion = avionesDisponibles->cambiarEstado(estado, registro);
        if (avion) { // Verificar que avion no es nulo
            avion->estado = "Mantenimiento";
            avionesEnMantenimiento->insertar(avion->vuelo, avion->numero_de_registro, avion->modelo, avion->fabricante, avion->ano_fabricacion, avion->capacidad, avion->peso_max_despegue, avion->aerolinea, avion->estado);
        }
    } else if (estado == "SALIDA") {
        nodoAviones* avion = avionesEnMantenimiento->cambiarEstado(estado, registro);
        if (avion) { // Verificar que avion no es nulo
            avion->estado = "Disponible";
            avionesDisponibles->insertar(avion->vuelo, avion->numero_de_registro, avion->modelo, avion->fabricante, avion->ano_fabricacion, avion->capacidad, avion->peso_max_despegue, avion->aerolinea, avion->estado);
        }
    }
}

void cargaMovimientos() {
    std::ifstream archivo("movimientos.txt");
    if (!archivo.is_open()) {
        std::cout << "No se pudo abrir el archivo" << std::endl;
        return;
    }
    std::string str((std::istreambuf_iterator<char>(archivo)), std::istreambuf_iterator<char>());
    archivo.close();

    std::stringstream ss(str);
    std::string token;
    while (std::getline(ss, token, ';')) {
        std::transform(token.begin(), token.end(), token.begin(), ::toupper);
        token.erase(std::remove_if(token.begin(), token.end(), ::isspace), token.end());
        std::istringstream iss(token);
        std::string palabra;
        while (iss >> palabra) {
            if (palabra == "INGRESOEQUIPAJES") {
                nodoPasajeros* pasajero = pasajeros->pasajeroRegistrado();
                if (pasajero) { // Verificar que pasajero no es nulo
                    pila->insertarNodoPila(pasajero);
                }
            } else {
                comparacion(palabra);
            }
        }
    }
}

void consultarPasajero(){
    cout << "Consultar pasajero" << endl;
}

void visualizarReportes(){
    cout << "Visualizar reportes" << endl;
}

void salir(){
    cout << "Salir" << endl;
}

int main() {
    int opcion;
    do
    {
        menuPrincipal();
        cout << "Ingrese una opcion: ";
        cin >> opcion;
        switch (opcion)
        {
        case 1:
            cargaAviones();
            cout <<""<<endl;
            cout << "Aviones cargados" << endl;
            cout <<""<<endl;
            break;
        case 2:
            cargaPasajeros();
            break;
        case 3:
            cargaMovimientos();
            break;
        case 4:
            consultarPasajero();
            break;
        case 5:
            avionesDisponibles->graficar("avionesDisponibles");
            Sleep(1000);
            avionesEnMantenimiento->graficar("avionesEnMantenimiento");
            Sleep(1000);
            pasajeros->graficar("pasajeros");
            break;
        case 6:
            salir();
            break;
        default:
            cout << "Opcion no valida" << endl;
            break;
        }
    } while (opcion != 6);
    
    return 0;
}