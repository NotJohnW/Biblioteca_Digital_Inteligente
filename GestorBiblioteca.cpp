#include "GestorBiblioteca.h"
#include <fstream>
#include <iostream>

void GestorBiblioteca::agregarLibro(Libro libro) {
    libros.push_back(libro);
}

vector<Libro>& GestorBiblioteca::getLibros() {
    return libros;
}

void GestorBiblioteca::listarLibros() const {
    for (const auto& l : libros)
        l.mostrar();
}

void GestorBiblioteca::cargarDesdeArchivo(string nombre) {
    ifstream archivo(nombre);
    if (!archivo.is_open()) return;

    string t, a, g, i;
    int an;

    while (getline(archivo, t)) {
        getline(archivo, a);
        archivo >> an;
        archivo.ignore();
        getline(archivo, g);
        getline(archivo, i);
        libros.emplace_back(t, a, an, g, i);
    }

    archivo.close();
}

void GestorBiblioteca::guardarEnArchivo(string nombre) const {
    ofstream archivo(nombre);

    for (const auto& l : libros) {
        archivo << l.getTitulo() << "\n"
                << l.getAutor() << "\n"
                << l.getAnio() << "\n"
                << l.getGenero() << "\n"
                << l.getISBN() << "\n";
    }

    archivo.close();
}
