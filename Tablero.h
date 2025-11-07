#ifndef TABLERO_H
#define TABLERO_H

#include <string>
#include <iostream>
using namespace std;


struct Casilla {
    int id;                  // Identificador único (0 a 39)
    string nombre;           // Nombre de la casilla (ej: "Avenida Mediterráneo")
    string tipo;             // Tipo (Propiedad, Tarjeta, Especial, etc.)
    Casilla* siguiente;      // Puntero a la siguiente casilla (lista circular)

    // Constructor
    Casilla(int idCasilla, string nom, string t)
        : id(idCasilla), nombre(nom), tipo(t), siguiente(nullptr) {}
};


class Tablero {
private:
    Casilla* inicio;     // Puntero a la primera casilla (GO)
    int numCasillas;     // Debe ser siempre 40

public:
    // Constructor
    Tablero();

    // Destructor
    ~Tablero();

    // Agregar una nueva casilla al tablero
    void agregarCasilla(string nombre, string tipo);

    // Mostrar todas las casillas del tablero
    void mostrarTablero() const;

    // Inicializa las 40 casillas del tablero (Monopoly estándar)
    void inicializar();

    // Mover jugador desde una posición actual
    int moverJugador(int posicionActual, int pasos) const;

    // Obtener una casilla por índice
    Casilla* obtenerCasilla(int indice) const;
};

#endif
