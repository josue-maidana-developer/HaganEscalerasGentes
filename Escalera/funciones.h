#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <string>
using namespace std;

void jugarModoUnJugador();
void lanzarDados(int dados[], int cantidadDados);
void mostrarDados(int dados[], int cantidadDados);
int calcularPuntuacion(int dados[]);
string obtenerNombreCombinacion(int puntuacion);
void mostrarCombinacionGanadora(const string & nombreCombinacion, int puntaje);


#endif // FUNCIONES_H_INCLUDED
