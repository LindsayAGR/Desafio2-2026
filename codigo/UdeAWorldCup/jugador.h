#ifndef JUGADOR_H
#define JUGADOR_H

#include <string>
using namespace std;

class Jugador {
private:
    string nombre;
    string apellido;
    int numero;

    int goles;
    int tarjetasAmarillas;
    int tarjetasRojas;
    int faltas;
    int minutosJugados;

public:
    Jugador();
    Jugador(string nombre, string apellido, int numero);

    void registrarGol();
    void recibirAmarilla();
    void recibirRoja();
    void cometerFalta();
    void sumarMinutos(int minutos);

    string getNombre() const;
    string getApellido() const;
    int getNumero() const;
    int getGoles() const;
};

#endif // JUGADOR_H
