#include "Tablero.h"

int main() {
    Tablero tablero;
    tablero.inicializar();

    cout << "=== TABLERO DE MONOPOLY ===" << endl;
    tablero.mostrarTablero();

    return 0;
}
