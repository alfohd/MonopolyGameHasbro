#ifndef JUGADORES_H
#define JUGADORES_H

#include <string>
#include <iostream>
#include "Tablero.h"
using namespace std;

/**
 * @brief Representa a un jugador del juego Monopoly.
 */
class Jugador {
private:
    string nombre;        
    int posicion;         
    int dinero;           
    bool enCarcel;        

public:
    /**
     * @brief Constructor del jugador.
     * @param nombre Nombre del jugador.
     * @pre Ninguna.
     * @post Se crea un jugador con $1500, en posición 0 (Salida).
     */
    Jugador(string nombre);

    /**
     * @brief Obtiene el nombre del jugador.
     * @return Nombre del jugador.
     */
    string getNombre() const;

    /**
     * @brief Devuelve la posición actual del jugador.
     * @return Índice de la casilla actual.
     */
    int getPosicion() const;

    /**
     * @brief Devuelve el dinero actual del jugador.
     * @return Cantidad de dinero.
     */
    int getDinero() const;

    /**
     * @brief Verifica si el jugador está en la cárcel.
     * @return true si está en la cárcel, false en caso contrario.
     */
    bool estaEnCarcel() const;

    /**
     * @brief Mueve al jugador en el tablero según el número de pasos.
     * @param tablero Referencia al tablero.
     * @param pasos Cantidad de casillas que debe avanzar.
     * @pre El tablero debe estar inicializado.
     * @post Actualiza la posición del jugador (circularmente).
     */
    void mover(Tablero& tablero, int pasos);

    /**
     * @brief Modifica el dinero del jugador.
     * @param cantidad Cantidad a sumar (puede ser negativa).
     * @pre Ninguna.
     * @post Actualiza el saldo del jugador.
     */
    void modificarDinero(int cantidad);

    /**
     * @brief Envía al jugador a la cárcel.
     * @param posicionCarcel Posición de la casilla "Cárcel".
     * @pre posición válida.
     * @post Cambia el estado del jugador a "en cárcel".
     */
    void irACarcel(int posicionCarcel);

    /**
     * @brief Libera al jugador de la cárcel.
     * @pre El jugador debe estar en cárcel.
     * @post Cambia el estado del jugador a "libre".
     */
    void salirDeCarcel();

    /**
     * @brief Muestra información general del jugador.
     */
    void mostrarInfo() const;
};

#endif
