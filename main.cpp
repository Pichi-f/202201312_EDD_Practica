#include <iostream>

using namespace std;

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
    cout << "Carga de aviones" << endl;
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
            visualizarReportes();
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