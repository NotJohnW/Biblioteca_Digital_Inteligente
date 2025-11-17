#ifndef GESTOR_BIBLIOTECA_H
#define GESTOR_BIBLIOTECA_H

#include "Libro.h"
#include <vector>
using namespace std;

class GestorBiblioteca {
private:
    vector<Libro> libros;

public:
    void agregarLibro(Libro);
    void cargarDesdeArchivo(string nombre);
    void guardarEnArchivo(string nombre) const;
    void listarLibros() const;
    vector<Libro>& getLibros();
};

#endif
