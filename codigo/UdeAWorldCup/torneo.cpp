#include "Torneo.h"
#include "Grupo.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

Torneo::Torneo(int cantEquipos, int cantGrupos) {
    cantidadEquipos = cantEquipos;
    cantidadGrupos = cantGrupos;

    equipos = new Equipo[cantidadEquipos];
    grupos = new Grupo[cantidadGrupos];
}

Torneo::~Torneo() {

}

void Torneo::crearEquipos() {
    ifstream archivo("selecciones_clasificadas_mundial.csv");
    if (!archivo.is_open()) {
        cout << "Error abriendo el archivo\n";
        return;
    }

    string linea;
    getline(archivo, linea);
    getline(archivo, linea); // encabezado

    int i = 0;

    while (getline(archivo, linea) && i < cantidadEquipos) {

        char sep = (linea.find(';') != string::npos) ? ';' : ',';

        stringstream ss(linea);

        string rankingStr, pais, dt, federacion, confederacion;
        string gf, gc, pg, pe, pp;

        getline(ss, rankingStr, sep);
        getline(ss, pais, sep);
        getline(ss, dt, sep);
        getline(ss, federacion, sep);
        getline(ss, confederacion, sep);
        getline(ss, gf, sep);
        getline(ss, gc, sep);
        getline(ss, pg, sep);
        getline(ss, pe, sep);
        getline(ss, pp, sep);

        int ranking = stoi(rankingStr);

        equipos[i] = Equipo(pais, confederacion, ranking);

        //  cargar datos reales
        equipos[i].setGolesFavor(0);
        equipos[i].setGolesContra(0);
        equipos[i].setPartidosGanados(0);
        equipos[i].setPartidosEmpatados(0);
        equipos[i].setPartidosPerdidos(0);

        i++;
    }

    archivo.close();
}

void Torneo::crearGrupos() {
    for (int i = 0; i < cantidadGrupos; i++) {
        grupos[i].setNombre(string(1, 'A' + i));
    }
}

void Torneo::asignarEquiposAGrupos() {
    int idx = 0;

    for (int i = 0; i < cantidadGrupos; i++) {
        for (int j = 0; j < 4; j++) {
            grupos[i].agregarEquipo(&equipos[idx++], j);
        }
        grupos[i].generarPartidos();
    }
}

void Torneo::simularTorneo() {
    for (int i = 0; i < cantidadGrupos; i++) {
        grupos[i].simularPartidos();
    }
}

void Torneo::mostrarTorneo() {
    for (int i = 0; i < cantidadGrupos; i++) {
        grupos[i].mostrarGrupo();
        cout << "------------------\n";
    }
}
