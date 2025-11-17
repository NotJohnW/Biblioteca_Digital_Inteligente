#ifndef LIBRO_H
#define LIBRO_H

#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int anio;
    string genero;
    string isbn;

public:
    Libro();
    Libro(string, string, int, string, string);

    string getTitulo() const;
    string getAutor() const;
    int getAnio() const;
    string getGenero() const;
    string getISBN() const;

    void mostrar() const;
};

#endif