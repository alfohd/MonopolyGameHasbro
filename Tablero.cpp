#include "Tablero.h"

/**
 * @brief Constructor del TAD Tablero.
 * @pre Ninguna.
 * @post Se crea un tablero vacío, sin casillas.
 */
Tablero::Tablero() {
    inicio = nullptr;
    numCasillas = 0;
}

/**
 * @brief Destructor del TAD Tablero.
 * @pre El tablero puede tener 0 o más casillas.
 * @post Se libera toda la memoria dinámica usada por las casillas.
 */
Tablero::~Tablero() {
    if (inicio != nullptr) {
        Casilla* actual = inicio;
        Casilla* siguiente;
        do {
            siguiente = actual->siguiente;
            delete actual;
            actual = siguiente;
        } while (actual != inicio);
        inicio = nullptr;
    }
}

/**
 * @brief Agrega una nueva casilla al tablero circular.
 * @param nombre Nombre de la casilla.
 * @param tipo Tipo de casilla (Propiedad, Tarjeta, Especial, etc.)
 * @pre nombre y tipo deben ser cadenas válidas.
 * @post Se agrega una nueva casilla al final del tablero circular.
 */
void Tablero::agregarCasilla(string nombre, string tipo) {
    Casilla* nueva = new Casilla(numCasillas, nombre, tipo);

    if (inicio == nullptr) {
        inicio = nueva;
        nueva->siguiente = inicio;
    } else {
        Casilla* temp = inicio;
        while (temp->siguiente != inicio) {
            temp = temp->siguiente;
        }
        temp->siguiente = nueva;
        nueva->siguiente = inicio;
    }

    numCasillas++;
}

/**
 * @brief Inicializa las 40 casillas del tablero estándar del Monopoly.
 * @pre El tablero debe estar vacío.
 * @post El tablero tiene 40 casillas conectadas circularmente.
 */
void Tablero::inicializar() {
    agregarCasilla("Salida (GO)", "Especial");
    agregarCasilla("Avenida Mediterráneo", "Propiedad");
    agregarCasilla("Arca Comunal", "Tarjeta");
    agregarCasilla("Avenida Báltica", "Propiedad");
    agregarCasilla("Impuesto sobre ingresos", "Especial");
    agregarCasilla("Ferrocarril Reading", "Propiedad");
    agregarCasilla("Avenida Oriental", "Propiedad");
    agregarCasilla("Casualidad", "Tarjeta");
    agregarCasilla("Avenida Vermont", "Propiedad");
    agregarCasilla("Avenida Connecticut", "Propiedad");
    agregarCasilla("Cárcel / Solo de visita", "Especial");
    agregarCasilla("Plaza San Carlos", "Propiedad");
    agregarCasilla("Compañía Eléctrica", "Propiedad");
    agregarCasilla("Avenida de los Estados", "Propiedad");
    agregarCasilla("Ferrocarril Pennsylvania", "Propiedad");
    agregarCasilla("Avenida San James", "Propiedad");
    agregarCasilla("Arca Comunal", "Tarjeta");
    agregarCasilla("Avenida Tennessee", "Propiedad");
    agregarCasilla("Avenida Nueva York", "Propiedad");
    agregarCasilla("Estacionamiento libre", "Especial");
    agregarCasilla("Avenida Kentucky", "Propiedad");
    agregarCasilla("Casualidad", "Tarjeta");
    agregarCasilla("Avenida Indiana", "Propiedad");
    agregarCasilla("Avenida Illinois", "Propiedad");
    agregarCasilla("Ferrocarril B&O", "Propiedad");
    agregarCasilla("Avenida Atlántico", "Propiedad");
    agregarCasilla("Avenida Ventnor", "Propiedad");
    agregarCasilla("Compañía de Agua", "Propiedad");
    agregarCasilla("Jardines Marvin", "Propiedad");
    agregarCasilla("Ve a la Cárcel", "Especial");
    agregarCasilla("Avenida Pacífico", "Propiedad");
    agregarCasilla("Avenida Carolina del Norte", "Propiedad");
    agregarCasilla("Arca Comunal", "Tarjeta");
    agregarCasilla("Avenida Pensilvania", "Propiedad");
    agregarCasilla("Ferrocarril Short Line", "Propiedad");
    agregarCasilla("Casualidad", "Tarjeta");
    agregarCasilla("Plaza del Parque", "Propiedad");
    agregarCasilla("Impuesto de lujo", "Especial");
    agregarCasilla("Paseo del Muelle", "Propiedad");
    agregarCasilla("Regreso a Salida", "Especial");


   

    Casilla* temp = inicio;
    while (temp->siguiente != inicio) {
        temp = temp->siguiente;
    }
    temp->siguiente = inicio;
}

/**
 * @brief Muestra todas las casillas del tablero en orden.
 * @pre El tablero debe estar inicializado.
 * @post Muestra en consola las 40 casillas con su id, nombre y tipo.
 */
void Tablero::mostrarTablero() const {
    if (inicio == nullptr) {
        cout << "El tablero está vacío.\n";
        return;
    }

    Casilla* actual = inicio;
    do {
        cout << actual->id << " - " << actual->nombre << " (" << actual->tipo << ")\n";
        actual = actual->siguiente;
    } while (actual != inicio);
}

/**
 * @brief Mueve un jugador en el tablero circular.
 * @param posicionActual Posición actual del jugador (0 a 39).
 * @param pasos Cantidad de pasos a avanzar.
 * @return Nueva posición (0 a 39).
 * @pre El tablero debe tener 40 casillas.
 * @post Devuelve la posición final del jugador considerando el ciclo.
 */
int Tablero::moverJugador(int posicionActual, int pasos) const {
    if (numCasillas == 0) return -1;
    return (posicionActual + pasos) % numCasillas;
}

/**
 * @brief Devuelve el puntero a la casilla correspondiente al índice.
 * @param indice Índice de la casilla (0–39).
 * @return Puntero a la casilla o nullptr si no existe.
 * @pre indice >= 0 y < numCasillas.
 * @post Devuelve la dirección de memoria de la casilla solicitada.
 */
Casilla* Tablero::obtenerCasilla(int indice) const {
    if (indice < 0 || indice >= numCasillas) return nullptr;

    Casilla* actual = inicio;
    for (int i = 0; i < indice; ++i) {
        actual = actual->siguiente;
    }
    return actual;
}







