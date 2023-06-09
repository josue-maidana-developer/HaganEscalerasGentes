#include <iostream>
#include <cstdlib>
#include <ctime>
#include "funciones.h"
using namespace std;

void jugarModoUnJugador() {
    string nombre;
    cout << "Ingrese su nombre y apellido: ";
    cin.ignore();
    getline(cin, nombre);

    int puntuacionTotal = 0;
    int rondasGanadas = 0;

    while (puntuacionTotal < 500) {
        cout << "Presione 1 para lanzar los dados, o 0 para salir: ";
        int opcion;
        cin >> opcion;

        if (opcion == 0) {
            break;
        }

        int dados[6];
        lanzarDados(dados, 6);
        mostrarDados(dados, 6);

        int puntuacion = calcularPuntuacion(dados);
        string nombreCombinacion = obtenerNombreCombinacion(puntuacion);
        mostrarCombinacionGanadora(nombreCombinacion, puntuacion);

        puntuacionTotal += puntuacion;

        rondasGanadas++;
    }

    cout << "¡" << nombre << " gano la partida!" << endl;
    cout << "Rondas ganadas: " << rondasGanadas << endl;
    cout << "Puntuacion total: " << puntuacionTotal << " puntos." << endl;
}

void lanzarDados(int dados[], int cantidadDados) {
    for (int i = 0; i < cantidadDados; i++) {
        dados[i] = 1 + rand() % 6;
    }
}

void mostrarDados(int dados[], int cantidadDados) {
    cout << "Dados lanzados: ";
    for (int i = 0; i < cantidadDados; i++) {
        cout << dados[i] << " ";
    }
    cout << endl;
}

int calcularPuntuacion(int dados[]) {
    int puntuacion = 0;

    /// Verificar si se obtiene un Sexteto X (6 dados iguales excepto 6)
    bool sexteto = true;
    for (int i = 0; i < 6; i++) {
        if (dados[i] != 6) {
            sexteto = false;
            break;
        }
    }
    if (sexteto) {
        puntuacion = 0; /// Pierde todos los puntos de la ronda
        return puntuacion;
    }

    /// Verificar si se obtiene una Escalera
    bool escalera = true;
    for (int i = 0; i < 6; i++) {
        if (dados[i] != i + 1) {
            escalera = false;
            break;
        }
    }
    if (escalera) {
        cout << "¡Escalera! Ganaste la partida en esta ronda." << endl;
        puntuacion = 500; /// Puntuacion maxima, gana la partida
        return puntuacion;
    }

for (int i = 1; i <= 5; i++) {
    int count = 0;
    for (int j = 0; j < 6; j++) {
        if (dados[j] == i) {
            count++;
        }
    }
    if (count >= 6) {
        puntuacion = i * 50;
        return puntuacion;
    }
}

    /// Verificar si se obtiene un Trio
    for (int i = 1; i <= 6; i++) {
        int count = 0;
        for (int j = 0; j < 6; j++) {
            if (dados[j] == i) {
                count++;
            }
        }
        if (count >= 3) {
            puntuacion = i * 10;
            return puntuacion;
        }
    }

    /// Si no se obtiene ninguna combinacion ganadora, calcular la suma de los valores de los dados
    for (int i = 0; i < 6; i++) {
        puntuacion += dados[i];
    }

    return puntuacion;
}

string obtenerNombreCombinacion(int puntuacion) {
    string nombreCombinacion;

    if (puntuacion == 0) {
        nombreCombinacion = "Sexteto 6";
    } else if (puntuacion == 500) {
        nombreCombinacion = "Escalera";
    } else if (puntuacion >= 50 && puntuacion <= 250) {
        int numero = puntuacion / 50;
        nombreCombinacion = "Sexteto " + to_string(numero);
    } else if (puntuacion >= 10 && puntuacion <= 40) {
        int numero = puntuacion / 10;
        nombreCombinacion = "Trio " + to_string(numero) + "++";
    } else {
        nombreCombinacion = "Suma de dados";
    }

    return nombreCombinacion;
}

void mostrarCombinacionGanadora(const string & nombreCombinacion, int puntaje) {
    cout << "¡" << nombreCombinacion << "! Puntuacion obtenida: " << puntaje << " puntos." << endl;
}
