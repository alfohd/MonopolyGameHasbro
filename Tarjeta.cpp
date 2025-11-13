#include "Tarjeta.h"

Tarjeta::Tarjeta(string tipo, string descripcion, string accion, int valor) {
    this->tipo = tipo;
    this->descripcion = descripcion;
    this->accion = accion;
    this->valor = valor;
}

Tarjeta::~Tarjeta() {
    // No se necesita liberar nada
}

void Tarjeta::mostrar() const {
    cout << "-------------------------------------\n";
    cout << "Tipo: " << tipo << endl;
    cout << "Descripción: " << descripcion << endl;
    cout << "Acción: " << accion << endl;
    cout << "Valor: " << valor << endl;
    cout << "-------------------------------------\n";
}

string Tarjeta::getTipo() const {
    return tipo;
}

string Tarjeta::getDescripcion() const {
    return descripcion;
}

string Tarjeta::getAccion() const {
    return accion;
}

int Tarjeta::getValor() const {
    return valor;
}
