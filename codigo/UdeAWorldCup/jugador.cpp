#include "Jugador.h"

// Constructor vacío
Jugador::Jugador() {
    nombre = "";
    apellido = "";
    numero = 0;
    goles = 0;
    tarjetasAmarillas = 0;
    tarjetasRojas = 0;
    faltas = 0;
    minutosJugados = 0;
}

// Constructor con datos
Jugador::Jugador(string nombre, string apellido, int numero) {
    this->nombre = nombre;
    this->apellido = apellido;
    this->numero = numero;

    goles = 0;
    tarjetasAmarillas = 0;
    tarjetasRojas = 0;
    faltas = 0;
    minutosJugados = 0;
}

// Métodos
void Jugador::registrarGol() {
    goles++;
}

void Jugador::recibirAmarilla() {
    tarjetasAmarillas++;
}

void Jugador::recibirRoja() {
    tarjetasRojas++;
}

void Jugador::cometerFalta() {
    faltas++;
}

void Jugador::sumarMinutos(int minutos) {
    minutosJugados += minutos;
}

// Getters
string Jugador::getNombre() const { return nombre; }
string Jugador::getApellido() const { return apellido; }
int Jugador::getNumero() const { return numero; }
int Jugador::getGoles() const { return goles; }
