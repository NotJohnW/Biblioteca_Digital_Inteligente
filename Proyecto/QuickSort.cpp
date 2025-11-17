#include "Libro.h"
#include <vector>
using namespace std;

int particion(vector<Libro>& libros, int low, int high) {
    string pivot = libros[high].getISBN();
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (libros[j].getISBN() < pivot) {
            i++;
            swap(libros[i], libros[j]);
        }
    }
    swap(libros[i + 1], libros[high]);
    return i + 1;
}

void quickSort(vector<Libro>& libros, int low, int high) {
    if (low < high) {
        int pi = particion(libros, low, high);
        quickSort(libros, low, pi - 1);
        quickSort(libros, pi + 1, high);
    }
}