#include "Libro.h"
#include <vector>
using namespace std;

void burbuja(vector<Libro>& libros) {
    for (int i = 0; i < libros.size(); i++) {
        for (int j = 0; j < libros.size() - 1; j++) {
            if (libros[j].getTitulo() > libros[j + 1].getTitulo()) {
                swap(libros[j], libros[j + 1]);
            }
        }
    }
}