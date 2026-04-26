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

    amarillas1 = amarillas2 = 0;
    rojas1 = rojas2 = 0;


    double alpha = 0.6;
    double beta = 0.4;
    double mu = 1.35;

    // evitar ceros (por eso +1)
    double GFA = equipo1->getGF() + 1;
    double GCB = equipo2->getGC() + 1;

    double GFB = equipo2->getGF() + 1;
    double GCA = equipo1->getGC() + 1;

    // lambdas (goles esperados)
    double lambda1 = alpha * GFA + beta * GCB + mu;
    double lambda2 = alpha * GFB + beta * GCA + mu;

    // convertir a goles reales (aproximación)
    golesEquipo1 = rand() % ((int)lambda1 + 1);
    golesEquipo2 = rand() % ((int)lambda2 + 1);


    Jugador* j1 = equipo1->getJugadores();
    Jugador* j2 = equipo2->getJugadores();

    // ===== GOLES A JUGADORES =====
    for (int i = 0; i < golesEquipo1; i++) {
        j1[rand() % 26].registrarGol();
    }

    for (int i = 0; i < golesEquipo2; i++) {
        j2[rand() % 26].registrarGol();
    }

    // ===== MINUTOS =====
    for (int i = 0; i < 26; i++) {
        j1[i].sumarMinutos(90);
        j2[i].sumarMinutos(90);
    }

    // ===== FALTAS =====
    for (int i = 0; i < 5; i++) {
        j1[rand() % 26].cometerFalta();
        j2[rand() % 26].cometerFalta();
    }

    // ===== TARJETAS AMARILLAS =====
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

    // ===== TARJETAS ROJAS =====
    if (rand() % 100 < 10) {
        j1[rand() % 26].recibirRoja();
        rojas1++;
    }

    if (rand() % 100 < 10) {
        j2[rand() % 26].recibirRoja();
        rojas2++;
    }

    // ===== ESTADÍSTICAS DE EQUIPO =====
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
