#include "Libro.h"
#include <vector>
using namespace std;

int busquedaLineal(const vector<Libro>& libros, string titulo) {
    for (int i = 0; i < libros.size(); i++) {
        if (libros[i].getTitulo() == titulo)
            return i;
    }
    return -1;
}
