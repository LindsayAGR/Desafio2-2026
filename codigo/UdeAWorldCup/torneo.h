#ifndef TORNEO_H
#define TORNEO_H

#include "Equipo.h"
#include <vector>
using namespace std;


class Grupo;

class Torneo {
private:
    Equipo* equipos;
    int cantidadEquipos;

    Grupo* grupos;
    int cantidadGrupos;

public:

    Torneo(int cantEquipos, int cantGrupos);
    ~Torneo();

    // FASE DE GRUPOS
    void crearEquipos();
    void crearGrupos();
    void asignarEquiposAGrupos();
    void simularTorneo();
    void mostrarTorneo();


    void clasificarEquipos();
};

#endif
