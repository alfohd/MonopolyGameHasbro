#include "Banco.h"

Banco::Banco(int dineroInicial) : dineroDisponible(dineroInicial) {}

/**
 * @brief El banco entrega dinero a un jugador.
 */
void Banco::pagarJugador(Jugador& jugador, int cantidad) {
    if (dineroDisponible >= cantidad) {
        dineroDisponible -= cantidad;
        jugador.modificarDinero(cantidad);
        cout << "El banco pagó $" << cantidad << " a " << jugador.getNombre() << ".\n";
    } else {
        cout << "⚠️ El banco no tiene suficiente dinero para pagar.\n";
    }
}

/**
 * @brief El banco cobra dinero a un jugador.
 */
void Banco::cobrarJugador(Jugador& jugador, int cantidad) {
    jugador.modificarDinero(-cantidad);
    dineroDisponible += cantidad;
    cout << "🏦 El banco cobró $" << cantidad << " a " << jugador.getNombre() << ".\n";
}

/**
 * @brief Vende una propiedad del tablero a un jugador.
 */
void Banco::venderPropiedad(Jugador& jugador, Casilla* casilla, int precio) {
    if (casilla == nullptr) {
        cout << " Error: la casilla no existe.\n";
        return;
    }

    if (casilla->tipo != "Propiedad") {
        cout << "❌ " << casilla->nombre << " no es una propiedad comprable.\n";
        return;
    }

    if (jugador.getDinero() < precio) {
        cout << "💸 " << jugador.getNombre() << " no tiene suficiente dinero para comprar " << casilla->nombre << ".\n";
        return;
    }

    
    jugador.modificarDinero(-precio);
    dineroDisponible += precio;

    cout << "🏠 " << jugador.getNombre() << " compró " << casilla->nombre 
         << " por $" << precio << ".\n";
}

/**
 * @brief Muestra el dinero actual del banco.
 */
void Banco::mostrarEstado() const {
    cout << "Dinero disponible en el banco: $" << dineroDisponible << "\n";
}
