#include "Libro.h"
#include <vector>
using namespace std;

int busquedaBinaria(const vector<Libro>& libros, string titulo) {
    int izquierda = 0, derecha = libros.size() - 1;

    while (izquierda <= derecha) {
        int medio = (izquierda + derecha) / 2;

        if (libros[medio].getTitulo() == titulo)
            return medio;

        if (libros[medio].getTitulo() < titulo)
            izquierda = medio + 1;
        else
            derecha = medio - 1;
    }

    return -1;
}
