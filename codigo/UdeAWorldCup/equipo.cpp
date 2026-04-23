#include "Equipo.h"
#include <iostream>

using namespace std;

// Constructor vacío
Equipo::Equipo() {
    nombrePais = "";
    confederacion = "";
    ranking = 0;

    golesFavor = 0;
    golesContra = 0;
    partidosGanados = 0;
    partidosEmpatados = 0;
    partidosPerdidos = 0;

    cantidadJugadores = 26;
    jugadores = new Jugador[cantidadJugadores];

    crearJugadores();
}

// Constructor principal
Equipo::Equipo(string nombrePais, string confederacion, int ranking) {
    this->nombrePais = nombrePais;
    this->confederacion = confederacion;
    this->ranking = ranking;

    golesFavor = 0;
    golesContra = 0;
    partidosGanados = 0;
    partidosEmpatados = 0;
    partidosPerdidos = 0;

    cantidadJugadores = 26;
    jugadores = new Jugador[cantidadJugadores];

    crearJugadores();
}


//  DESTRUCTOR
Equipo::~Equipo() {
    delete[] jugadores;
}


// MÉTODOS

// Crear jugadores automáticamente
void Equipo::crearJugadores() {
    for (int i = 0; i < cantidadJugadores; i++) {
        jugadores[i] = Jugador(
            "nombre" + to_string(i + 1),
            "apellido" + to_string(i + 1),
            i + 1
            );
    }
}

//  Actualizar estadísticas
void Equipo::sumarVictoria() { partidosGanados++; }
void Equipo::sumarEmpate() { partidosEmpatados++; }
void Equipo::sumarDerrota() { partidosPerdidos++; }

void Equipo::sumarGoles(int favor, int contra) {
    golesFavor += favor;
    golesContra += contra;
}

// Puntos
int Equipo::getPuntos() const {
    return partidosGanados * 3 + partidosEmpatados;
}

//  GETTERS


string Equipo::getNombrePais() const { return nombrePais; }
string Equipo::getConfederacion() const { return confederacion; }
int Equipo::getRanking() const { return ranking; }
Jugador* Equipo::getJugadores() const { return jugadores; }

int Equipo::getPG() const { return partidosGanados; }
int Equipo::getPE() const { return partidosEmpatados; }
int Equipo::getPP() const { return partidosPerdidos; }
int Equipo::getGF() const { return golesFavor; }
int Equipo::getGC() const { return golesContra; }

int Equipo::getPJ() const {
    return partidosGanados + partidosEmpatados + partidosPerdidos;
}


// SETTERS (archivo CSV)
void Equipo::setGolesFavor(int gf) { golesFavor = gf; }
void Equipo::setGolesContra(int gc) { golesContra = gc; }
void Equipo::setPartidosGanados(int pg) { partidosGanados = pg; }
void Equipo::setPartidosEmpatados(int pe) { partidosEmpatados = pe; }
void Equipo::setPartidosPerdidos(int pp) { partidosPerdidos = pp; }
