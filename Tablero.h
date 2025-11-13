#ifndef TABLERO_H
#define TABLERO_H

#include <string>
#include <iostream>
#include <fstream>   
#include <sstream>   
using namespace std;


struct Casilla {
    int id;                  
    string nombre;           
    string tipo;             
    Casilla* siguiente;      


    Casilla(int idCasilla, string nom, string t)
        : id(idCasilla), nombre(nom), tipo(t), siguiente(nullptr) {}
};


class Tablero {
private:
    Casilla* inicio;     
    int numCasillas;     

public:
   
    Tablero();

   
    ~Tablero();

  
    void agregarCasilla(string nombre, string tipo);

   
    void cargarDesdeArchivo(const string& nombreArchivo);

   
    void mostrarTablero() const;

   
    void inicializar();

    
    int moverJugador(int posicionActual, int pasos) const;

    
    Casilla* obtenerCasilla(int indice) const;
};

#endif
