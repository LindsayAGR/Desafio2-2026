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
void Torneo::clasificarEquipos() {

    vector<Equipo*> primeros;
    vector<Equipo*> segundos;
    vector<Equipo*> terceros;

    // sacar 123
    for (int i = 0; i < cantidadGrupos; i++) {

        vector<Equipo*> ordenados = grupos[i].getEquiposOrdenados();

        primeros.push_back(ordenados[0]);
        segundos.push_back(ordenados[1]);
        terceros.push_back(ordenados[2]);
    }

    //ordenar terceros
    for (int i = 0; i < terceros.size() - 1; i++) {
        for (int j = i + 1; j < terceros.size(); j++) {

            int pts_i = terceros[i]->getPuntos();
            int pts_j = terceros[j]->getPuntos();

            int dg_i = terceros[i]->getGF() - terceros[i]->getGC();
            int dg_j = terceros[j]->getGF() - terceros[j]->getGC();

            if (
                pts_j > pts_i ||
                (pts_j == pts_i && dg_j > dg_i) ||
                (pts_j == pts_i && dg_j == dg_i &&
                 terceros[j]->getGF() > terceros[i]->getGF())
                ) {
                Equipo* temp = terceros[i];
                terceros[i] = terceros[j];
                terceros[j] = temp;
            }
        }
    }

    // seleccionar los 8 mejores terceros
    vector<Equipo*> mejoresTerceros;

    for (int i = 0; i < 8 && i < terceros.size(); i++) {
        mejoresTerceros.push_back(terceros[i]);
    }



    cout << "\n--------- CLASIFICADOS--------\n";

    cout << "\nPrimeros de grupo:\n";
    for (int i = 0; i < primeros.size(); i++) {
        cout << primeros[i]->getNombrePais() << endl;
    }

    cout << "\nSegundos de grupo:\n";
    for (int i = 0; i < segundos.size(); i++) {
        cout << segundos[i]->getNombrePais() << endl;
    }

    cout << "\nMejores terceros:\n";
    for (int i = 0; i < mejoresTerceros.size(); i++) {
        cout << mejoresTerceros[i]->getNombrePais()
        << " (PTS: " << mejoresTerceros[i]->getPuntos() << ")\n";
    }

    cout << "\n  CRUCES\n";

    // primeros vs mejores terceros
    cout << "\nPrimeros vs Mejores Terceros:\n";

    for (int i = 0; i < primeros.size() && i < mejoresTerceros.size(); i++) {
        cout << primeros[i]->getNombrePais()
        << " vs "
        << mejoresTerceros[i]->getNombrePais()
        << endl;
    }

    // segundos entre sí
    cout << "\nSegundos entre si:\n";

    for (int i = 0; i < segundos.size(); i += 2) {

        if (i + 1 < segundos.size()) {
            cout << segundos[i]->getNombrePais()
            << " vs "
            << segundos[i + 1]->getNombrePais()
            << endl;
        }
    }
}
