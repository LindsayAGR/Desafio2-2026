#ifndef GRUPO_H
#define GRUPO_H

#include "Equipo.h"
#include "Partido.h"
#include <string>
#include <vector>
using namespace std;

class Grupo {
private:
    string nombre;

    Equipo** equipos;   // punteros (NO copia)
    int cantidadEquipos;

    Partido* partidos;
    int cantidadPartidos;

public:
    // Constructores
    Grupo();
    Grupo(string nombre);

    // Destructor
    ~Grupo();

    // Métodos
    void agregarEquipo(Equipo* equipo, int posicion);
    void generarPartidos();
    void simularPartidos();
    void mostrarGrupo();
    void setNombre(string nombre);
    void mostrarTabla();


    vector<Equipo*> getEquiposOrdenados();
};


#endif // GRUPO_H
