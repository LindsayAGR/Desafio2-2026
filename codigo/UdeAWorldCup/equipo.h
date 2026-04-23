#ifndef EQUIPO_H
#define EQUIPO_H

#include <string>
#include "Jugador.h"
using namespace std;

class Equipo {
private:
    string nombrePais;
    string confederacion;
    int ranking;

    int golesFavor;
    int golesContra;
    int partidosGanados;
    int partidosEmpatados;
    int partidosPerdidos;

    Jugador* jugadores;
    int cantidadJugadores;

public:
    // Constructores
    Equipo();
    Equipo(string nombrePais, string confederacion, int ranking);

    // Destructor
    ~Equipo();

    // Métodos
    void crearJugadores();
    void mostrarEquipo();


    void sumarVictoria();
    void sumarEmpate();
    void sumarDerrota();
    void sumarGoles(int favor, int contra);

    int getPuntos() const;

    int getPG() const;
    int getPE() const;
    int getPP() const;
    int getGF() const;
    int getGC() const;
    int getPJ() const;



    // Getters
    string getNombrePais() const;
    string getConfederacion() const;
    int getRanking() const;
    Jugador* getJugadores() const;

    //SETTERS
    void setGolesFavor(int gf);
    void setGolesContra(int gc);
    void setPartidosGanados(int pg);
    void setPartidosEmpatados(int pe);
    void setPartidosPerdidos(int pp);
};

#endif // EQUIPO_H
