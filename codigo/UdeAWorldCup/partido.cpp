#include "Partido.h"
#include <iostream>
#include <cstdlib>

using namespace std;

// Constructor vacío
Partido::Partido() {
    equipo1 = nullptr;
    equipo2 = nullptr;
    golesEquipo1 = 0;
    golesEquipo2 = 0;
}

// Constructor principal
Partido::Partido(Equipo* eq1, Equipo* eq2, string fecha, string sede) {
    equipo1 = eq1;
    equipo2 = eq2;
    this->fecha = fecha;
    this->sede = sede;

    golesEquipo1 = 0;
    golesEquipo2 = 0;
}

// Simulación simple
void Partido::simularPartido() {
    golesEquipo1 = rand() % 5;
    golesEquipo2 = rand() % 5;

    Jugador* j1 = equipo1->getJugadores();
    Jugador* j2 = equipo2->getJugadores();

    // registrar goles en jugadores
    for (int i = 0; i < golesEquipo1; i++) {
        j1[rand() % 26].registrarGol();
    }

    for (int i = 0; i < golesEquipo2; i++) {
        j2[rand() % 26].registrarGol();
    }


    // ACTUALIZAR ESTADÍSTICAS

    equipo1->sumarGoles(golesEquipo1, golesEquipo2);
    equipo2->sumarGoles(golesEquipo2, golesEquipo1);

    if (golesEquipo1 > golesEquipo2) {
        equipo1->sumarVictoria();
        equipo2->sumarDerrota();
    }
    else if (golesEquipo1 < golesEquipo2) {
        equipo2->sumarVictoria();
        equipo1->sumarDerrota();
    }
    else {
        equipo1->sumarEmpate();
        equipo2->sumarEmpate();
    }
}

// Mostrar
void Partido::mostrarResultado() {
    cout << equipo1->getNombrePais() << " "
         << golesEquipo1 << " - "
         << golesEquipo2 << " "
         << equipo2->getNombrePais() << endl;
}

//  GETTERS
int Partido::getGolesEquipo1() const {
    return golesEquipo1;
}

int Partido::getGolesEquipo2() const {
    return golesEquipo2;
}
