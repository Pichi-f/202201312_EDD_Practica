#include <iostream>
#include "json.hpp"
#include <fstream>
#include <cstring>
#include "listaCircularAviones.h"
#include "nodoAviones.h"

listaCircularAviones *avionesDisponibles = new listaCircularAviones();
listaCircularAviones *avionesEnMantenimiento = new listaCircularAviones();

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
    cout << "Carga de pasajeros" << endl;
}

void cargaMovimientos(){
    cout << "Carga de movimientos" << endl;
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
            cout << "Aviones cargados" << endl;
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
            cout << "Aviones disponibles";
            avionesDisponibles->mostrar();
            cout << "Aviones en mantenimiento";
            avionesEnMantenimiento->mostrar();
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