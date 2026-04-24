#ifndef PARTIDO_H
#define PARTIDO_H

#include "Equipo.h"
#include <string>
using namespace std;

class Partido {
private:
    Equipo* equipo1;
    Equipo* equipo2;

    int golesEquipo1;
    int golesEquipo2;

    string fecha;
    string sede;

public:
    Partido();
    Partido(Equipo* eq1, Equipo* eq2, string fecha, string sede);

    void simularPartido();
    void mostrarResultado();


    int getGolesEquipo1() const;
    int getGolesEquipo2() const;
};

#endif // PARTIDO_H
