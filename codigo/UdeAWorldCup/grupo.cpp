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

// Simular partidos
void Grupo::simularPartidos() {
    for (int i = 0; i < cantidadPartidos; i++) {
        partidos[i].simularPartido();
    }
}


//  TABLA DE POSICIONES

void Grupo::mostrarTabla() {

    //  ordenar por puntos (mayor a menor)
    for (int i = 0; i < cantidadEquipos - 1; i++) {
        for (int j = i + 1; j < cantidadEquipos; j++) {
            if (equipos[j]->getPuntos() > equipos[i]->getPuntos()) {
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

//  MOSTRAR GRUPO

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
