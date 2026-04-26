#include <iostream>
#include <cstdlib>
#include <ctime>

#include "Torneo.h"

using namespace std;

int main() {

    // Inicializar números aleatorios
    srand(time(0));

    cout << "=====================================\n";
    cout << "   SIMULADOR DE MUNDIAL DE FUTBOL   \n";
    cout << "=====================================\n\n";

    // CAMBIA ESTO SEGÚN NECESITES
    // Pruebas: (8, 2)
    // Final:   (48, 12)
    int cantEquipos = 8;
    int cantGrupos = 2;

    // Crear torneo
    Torneo torneo(cantEquipos, cantGrupos);

    cout << "Cargando equipos desde archivo...\n";
    torneo.crearEquipos();

    cout << "Creando grupos...\n";
    torneo.crearGrupos();

    cout << "Asignando equipos a grupos...\n";
    torneo.asignarEquiposAGrupos();

    cout << "Simulando partidos...\n\n";
    torneo.simularTorneo();

    cout << "=========== RESULTADOS ===========\n\n";
    torneo.mostrarTorneo();

    cout << "=====================================\n";
    cout << "        FIN DE LA SIMULACION        \n";
    cout << "=====================================\n";

    return 0;
}
