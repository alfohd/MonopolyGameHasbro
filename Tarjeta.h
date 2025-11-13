#ifndef TARJETA_H
#define TARJETA_H

#include <iostream>
#include <string>
using namespace std;


class Tarjeta {
private:
    string tipo;         // "Casualidad" o "Arca Comunal"
    string descripcion;  // Texto que aparece en la tarjeta
    string accion;       // "cobrar", "pagar", "mover", "carcel_libre", etc.
    int valor;           // Valor asociado a la acción (positivo o negativo)

public:
    // Constructor
    Tarjeta(string tipo, string descripcion, string accion, int valor = 0);

    // Destructor
    ~Tarjeta();

    // Mostrar la información completa de la tarjeta
    void mostrar() const;

    // Getters
    string getTipo() const;
    string getDescripcion() const;
    string getAccion() const;
    int getValor() const;
};

#endif
