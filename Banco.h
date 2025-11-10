#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <string>
#include "Jugadores.h"  
#include "Tablero.h"

using namespace std;

/**
 * @brief Representa el Banco en el juego Monopoly.
 * 
 * El Banco controla las transacciones de dinero, la compra de propiedades
 * y los pagos por pasar por la salida o caer en impuestos.
 */
class Banco {
private:
    int dineroDisponible; ///< Dinero que tiene el banco (opcionalmente limitado)

public:
    /**
     * @brief Constructor del Banco.
     * @param dineroInicial Monto inicial del banco (por defecto 100000).
     * @post El banco queda listo para operar con el dinero indicado.
     */
    Banco(int dineroInicial = 100000);

    /**
     * @brief Paga dinero a un jugador (por ejemplo, al pasar por la salida).
     * @param jugador Jugador que recibe el dinero.
     * @param cantidad Monto a pagar.
     */
    void pagarJugador(Jugador& jugador, int cantidad);

    /**
     * @brief Cobra dinero a un jugador (impuestos, multas, propiedades).
     * @param jugador Jugador que paga.
     * @param cantidad Monto a cobrar.
     */
    void cobrarJugador(Jugador& jugador, int cantidad);

    /**
     * @brief Vende una propiedad a un jugador.
     * @param jugador Jugador que compra.
     * @param casilla Casilla que representa la propiedad.
     * @param precio Precio de la propiedad.
     * @post Si el jugador tiene dinero suficiente, se le descuenta el valor y se marca como propietario.
     */
    void venderPropiedad(Jugador& jugador, Casilla* casilla, int precio);

    /**
     * @brief Muestra el estado actual del banco.
     */
    void mostrarEstado() const;
};

#endif
