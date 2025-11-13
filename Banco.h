#ifndef BANCO_H
#define BANCO_H

#include <iostream>
#include <string>
#include "Jugadores.h"  
#include "Tablero.h"

using namespace std;


class Banco {
private:
    int dineroDisponible; ///< Dinero que tiene el banco (opcionalmente limitado)

public:
   
    Banco(int dineroInicial = 100000);

  
    void pagarJugador(Jugador& jugador, int cantidad);

    
    void cobrarJugador(Jugador& jugador, int cantidad);

   
    void venderPropiedad(Jugador& jugador, Casilla* casilla, int precio);

    
    void mostrarEstado() const;
};

#endif
