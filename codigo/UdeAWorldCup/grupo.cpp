#include "Grupo.h"
#include <iostream>
#include "Grupo.h"
#include <iostream>

using namespace std;
// CONSTRUCTORES

Grupo::Grupo() {
    nombre = "";

    cantidadEquipos = 4;
    equipos = new Equipo*[cantidadEquipos];

    cantidadPartidos = 6;
    partidos = new Partido[cantidadPartidos];
}

Grupo::Grupo(string nombre) {
    this->nombre = nombre;

    cantidadEquipos = 4;
    equipos = new Equipo*[cantidadEquipos];

    cantidadPartidos = 6;
    partidos = new Partido[cantidadPartidos];
}


// DESTRUCTOR
Grupo::~Grupo() {

}

// MÉTODOS

// Agregar equipo al grupo
void Grupo::agregarEquipo(Equipo* equipo, int posicion) {
    equipos[posicion] = equipo;
}

// Generar todos los partidos (todos contra todos)
void Grupo::generarPartidos() {
    int idx = 0;

    for (int i = 0; i < cantidadEquipos; i++) {
        for (int j = i + 1; j < cantidadEquipos; j++) {
            partidos[idx++] = Partido(
                equipos[i],
                equipos[j],
                "fecha",
                "sede"
                );
        }
    }
}

void Grupo::simularPartidos() {
    for (int i = 0; i < cantidadPartidos; i++) {
        partidos[i].simularPartido();
    }
}



void Grupo::mostrarTabla() {


    // ordenar por puntos, diferencia de gol y goles a favor
    for (int i = 0; i < cantidadEquipos - 1; i++) {
        for (int j = i + 1; j < cantidadEquipos; j++) {

            int dg_i = equipos[i]->getGF() - equipos[i]->getGC();
            int dg_j = equipos[j]->getGF() - equipos[j]->getGC();

            if (
                equipos[j]->getPuntos() > equipos[i]->getPuntos() ||
                (equipos[j]->getPuntos() == equipos[i]->getPuntos() && dg_j > dg_i) ||
                (equipos[j]->getPuntos() == equipos[i]->getPuntos() && dg_j == dg_i &&
                 equipos[j]->getGF() > equipos[i]->getGF())
                ) {
                Equipo* temp = equipos[i];
                equipos[i] = equipos[j];
                equipos[j] = temp;
            }
        }
    }
    cout << "\nTabla de posiciones:\n";
    cout << "Equipo\tPJ\tPG\tPE\tPP\tGF\tGC\tPTS\n";

    for (int i = 0; i < cantidadEquipos; i++) {
        cout << equipos[i]->getNombrePais() << "\t"
             << equipos[i]->getPJ() << "\t"
             << equipos[i]->getPG() << "\t"
             << equipos[i]->getPE() << "\t"
             << equipos[i]->getPP() << "\t"
             << equipos[i]->getGF() << "\t"
             << equipos[i]->getGC() << "\t"
             << equipos[i]->getPuntos()
             << endl;
    }
}

vector<Equipo*> Grupo::getEquiposOrdenados() {

    for (int i = 0; i < cantidadEquipos - 1; i++) {
        for (int j = i + 1; j < cantidadEquipos; j++) {

            int dg_i = equipos[i]->getGF() - equipos[i]->getGC();
            int dg_j = equipos[j]->getGF() - equipos[j]->getGC();

            if (
                equipos[j]->getPuntos() > equipos[i]->getPuntos() ||
                (equipos[j]->getPuntos() == equipos[i]->getPuntos() && dg_j > dg_i) ||
                (equipos[j]->getPuntos() == equipos[i]->getPuntos() && dg_j == dg_i &&
                 equipos[j]->getGF() > equipos[i]->getGF())
                ) {
                Equipo* temp = equipos[i];
                equipos[i] = equipos[j];
                equipos[j] = temp;
            }
        }
    }

    vector<Equipo*> resultado;

    for (int i = 0; i < cantidadEquipos; i++) {
        resultado.push_back(equipos[i]);
    }

    return resultado;
}


void Grupo::mostrarGrupo() {
    cout << "Grupo " << nombre << endl;

    for (int i = 0; i < cantidadEquipos; i++) {
        cout << equipos[i]->getNombrePais() << endl;
    }

    cout << "\nResultados:\n";

    for (int i = 0; i < cantidadPartidos; i++) {
        partidos[i].mostrarResultado();
    }


    mostrarTabla();
}

void Grupo::setNombre(string nombre) {
    this->nombre = nombre;
}
