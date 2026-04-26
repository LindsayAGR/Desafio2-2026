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

    amarillas1 = amarillas2 = 0;
    rojas1 = rojas2 = 0;
}

// Simulación del partido
void Partido::simularPartido() {

    // goles aleatorios
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

    // minutos jugados
    for (int i = 0; i < 26; i++) {
        j1[i].sumarMinutos(90);
        j2[i].sumarMinutos(90);
    }

    // faltas
    for (int i = 0; i < 5; i++) {
        j1[rand() % 26].cometerFalta();
        j2[rand() % 26].cometerFalta();
    }

    // tarjetas amarillas
    for (int i = 0; i < 3; i++) {
        if (rand() % 100 < 50) {
            j1[rand() % 26].recibirAmarilla();
            amarillas1++;
        }

        if (rand() % 100 < 50) {
            j2[rand() % 26].recibirAmarilla();
            amarillas2++;
        }
    }
    // tarjetas rojas
    if (rand() % 100 < 10) {
        j1[rand() % 26].recibirRoja();
        rojas1++;
    }

    if (rand() % 100 < 10) {
        j2[rand() % 26].recibirRoja();
        rojas2++;
    }
    // actualizar estadísticas del equipo
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
         << equipo2->getNombrePais()
         << " | Amarillas: " << amarillas1 << "-" << amarillas2
         << " | Rojas: " << rojas1 << "-" << rojas2
         << endl;
}

//  GETTERS
int Partido::getGolesEquipo1() const {
    return golesEquipo1;
}

int Partido::getGolesEquipo2() const {
    return golesEquipo2;
}
