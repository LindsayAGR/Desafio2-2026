#ifndef TORNEO_H
#define TORNEO_H

#include "Equipo.h"

// FORWARD DECLARATION
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

    void crearEquipos();
    void crearGrupos();
    void asignarEquiposAGrupos();
    void simularTorneo();
    void mostrarTorneo();
};

#endif
