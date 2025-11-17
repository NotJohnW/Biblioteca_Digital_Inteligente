#include "Libro.h"
#include <vector>
using namespace std;

void seleccion(vector<Libro>& libros) {
    for (int i = 0; i < libros.size(); i++) {
        int minIndex = i;
        for (int j = i + 1; j < libros.size(); j++) {
            if (libros[j].getAutor() < libros[minIndex].getAutor()) {
                minIndex = j;
            }
        }
        swap(libros[i], libros[minIndex]);
    }
}