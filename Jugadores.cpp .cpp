#include "Jugadores.h"


Jugador::Jugador(string nombre)
    : nombre(nombre), posicion(0), dinero(1500), enCarcel(false) {}


string Jugador::getNombre() const { return nombre; }
int Jugador::getPosicion() const { return posicion; }
int Jugador::getDinero() const { return dinero; }
bool Jugador::estaEnCarcel() const { return enCarcel; }


void Jugador::mover(Tablero& tablero, int pasos) {
    if (enCarcel) {
        cout << nombre << " está en la cárcel y no puede moverse este turno.\n";
        return;
    }

    int nuevaPosicion = tablero.moverJugador(posicion, pasos);
    if (nuevaPosicion < posicion) {
        cout << nombre << " pasó por la Salida (GO) y recibe $200.\n";
        dinero += 200;
    }

    posicion = nuevaPosicion;

    Casilla* casillaActual = tablero.obtenerCasilla(posicion);
    cout << nombre << " cayó en la casilla: " << casillaActual->nombre
         << " (" << casillaActual->tipo << ")\n";

    if (casillaActual->nombre == "Ve a la Cárcel") {
        irACarcel(10);  
    }
}

void Jugador::modificarDinero(int cantidad) {
    dinero += cantidad;
    if (dinero < 0) {
        cout << nombre << " está en bancarrota 💸\n";
    }
}

void Jugador::irACarcel(int posicionCarcel) {
    posicion = posicionCarcel;
    enCarcel = true;
    cout << nombre << " ha sido enviado a la cárcel 🚔\n";
}

void Jugador::salirDeCarcel() {
    enCarcel = false;
    cout << nombre << " ha salido de la cárcel 🎉\n";
}

void Jugador::mostrarInfo() const {
    cout << "Jugador: " << nombre
         << " | Dinero: $" << dinero
         << " | Posición: " << posicion
         << (enCarcel ? " (En cárcel)" : "") << "\n";
}
