#ifndef JUGADORES_H
#define JUGADORES_H

#include <string>
#include <iostream>
#include "Tablero.h"
using namespace std;


class Jugador {
private:
    string nombre;        
    int posicion;         
    int dinero;           
    bool enCarcel;        

public:
    
    Jugador(string nombre);

    
    string getNombre() const;

    
    int getPosicion() const;

   
    int getDinero() const;

    
    bool estaEnCarcel() const;

   
    void mover(Tablero& tablero, int pasos);

   
    void modificarDinero(int cantidad);

    
    void irACarcel(int posicionCarcel);

  
    void salirDeCarcel();

    void mostrarInfo() const;
};

#endif
