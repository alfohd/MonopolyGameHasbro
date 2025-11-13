#include "Tablero.h"
#include <fstream>   // para leer archivos
#include <sstream>   // para dividir cada línea

Tablero::Tablero() { // el constructor fue creado para darle inicio a nuestro tablero vacio y que sea consistente
    inicio = nullptr;
    numCasillas = 0;
}

Tablero::~Tablero() {
    if (inicio != nullptr) {
        Casilla* actual = inicio; // la casilla declara el actual apuntando al primer nodo y este actual lo usaremos para recorrer la lista circular
        Casilla* siguiente; // declaramos un apuntador que usaremos como auxiliar para el actual
        do { // iniciamos el ciclo del do while para procesar el primer nodo antes de iniciar el proceso 
            siguiente = actual->siguiente; // accede al siguiente nodo antes de liberar el actual y evitar que se borre los siguientes nodos, como vimos en clase el caso del TMP
            delete actual; // libera memoria del actual para guardar espacio para el heap 
            actual = siguiente; // actual es igual a siguiente ya que creamos siguiente para que se guarde el proceso del apuntador actual
        } while (actual != inicio); // esto lo repite hasta volver al nodo inicial 
        inicio = nullptr; // por seguridad 
    }
}

void Tablero::agregarCasilla(string nombre, string tipo) {
    Casilla* nueva = new Casilla(numCasillas, nombre, tipo); // creamos un objeto new llamado casilla y nueva obtiene la direccion de memoria 

    if (inicio == nullptr) {
        inicio = nueva; // apunta a la nueva casilla que seria la primera 
        nueva->siguiente = inicio; // por ser circular, la única casilla apunta a sí misma.
    } else {
        Casilla* temp = inicio; // será un cursor para encontrar el último nodo.
        while (temp->siguiente != inicio) { // recorre la lista hasta el nodo cuyo siguiente vuelve a inicio
            temp = temp->siguiente; 
        }
        temp->siguiente = nueva; // enlaza el último nodo al nuevo.
        nueva->siguiente = inicio; // nuevo apunta de vuelta al inicio (manteniendo la circularidad).
    }

    numCasillas++; // incremeta el contador de casillas 
}


void Tablero::cargarDesdeArchivo(const string& nombreArchivo) {  // método que lee las casillas desde un archivo de texto.
    ifstream archivo(nombreArchivo); 
    if (!archivo.is_open()) { // comprueba apertura; si falla, muestra error y sale.
        cerr << "Error: no se pudo abrir el archivo " << nombreArchivo << endl; // muestra error y sale 
        return;
    }

    string linea; // comprueba apertura; si falla, muestra error y sale.
    while (getline(archivo, linea)) { // lee línea por línea hasta EOF. getline descarta el carácter de nueva línea. (eso quiere decir que lee hasta la ultima linea del archivo )
        stringstream ss(linea); // crea un stream en memoria con la línea para dividir por comas.
        string idStr, nombre, tipo; // variables temporales para las partes.

        getline(ss, idStr, ','); // lee hasta la primera coma
        getline(ss, nombre, ','); // la siguiente coma
        getline(ss, tipo, ','); // la siguiente coma

        
        if (!nombre.empty() && nombre[0] == ' ') nombre.erase(0, 1); // elimina un posible espacio inicial del nombre
        if (!tipo.empty() && tipo[0] == ' ') tipo.erase(0, 1); // elimina un espacio si existe 

        agregarCasilla(nombre, tipo); // crea y enlaza la casilla con nombre y tipo. El id será numCasillas antes del incremento
    }

    archivo.close(); // cierra archivo 
    cout << "Tablero cargado desde " << nombreArchivo << " con " << numCasillas << " casillas.\n";
}

void Tablero::mostrarTablero() const { 
    if (inicio == nullptr) {
        cout << "El tablero está vacío.\n"; // si esta vacio se sale
        return;
    }
 
    Casilla* actual = inicio; // comienza la casilla actual en el inicio
    do {
        cout << actual->id << " - " << actual->nombre << " (" << actual->tipo << ")\n";
        actual = actual->siguiente; // despues la actual se mueve a la siguiente hasta llegar al inicio y lo muestra
    } while (actual != inicio); // cilco para que esto funcione
}

int Tablero::moverJugador(int posicionActual, int pasos) const { // metodo const para no modificar nada
    if (numCasillas == 0) return -1; // protección si tablero vacío.
    return (posicionActual + pasos) % numCasillas; // aritmética modular para moverse circularmente.
}

Casilla* Tablero::obtenerCasilla(int indice) const { // devuelve puntero a la casilla en posición indice.
    if (indice < 0 || indice >= numCasillas) return nullptr; // valida rango 

    Casilla* actual = inicio; // cursor
    for (int i = 0; i < indice; ++i) { // avanza indice veces desde inicio.
        actual = actual->siguiente; // devuelve la dirección del nodo.
    }
    return actual;
}
