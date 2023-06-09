#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
using namespace std;

int main() {
    srand(time(0));

    int opcion;
    do {
        cout << "=== Menu ===" << endl << endl;
        cout << "1. Modo un jugador" << endl;
        cout << "2. Modo dos jugadores" << endl;
        cout << "3. Puntuacion maxima" << endl;
        cout << "4. Salir" << endl << endl;
        cout << "Ingrese una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                jugarModoUnJugador();
                break;
            case 2:
                ///Modo dos jugadores
                break;
            case 3:
                /// funcionalidad de puntuacion maxima
                break;
            case 4:
                cout << "¡Game Over!" << endl;
                break;
            default:
                cout << "Opcion no valida. Por favor, ingrese una opcion valida." << endl;
        }
        cout << endl;
    } while (opcion != 4);

    return 0;
}
