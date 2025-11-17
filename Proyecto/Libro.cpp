#include "Libro.h"
#include <iostream>

Libro::Libro() {}

Libro::Libro(string t, string a, int an, string g, string i)
    : titulo(t), autor(a), anio(an), genero(g), isbn(i) {}

string Libro::getTitulo() const { return titulo; }
string Libro::getAutor() const { return autor; }
int Libro::getAnio() const { return anio; }
string Libro::getGenero() const { return genero; }
string Libro::getISBN() const { return isbn; }

void Libro::mostrar() const {
    cout << "Título: " << titulo << "\nAutor: " << autor
         << "\nAño: " << anio << "\nGénero: " << genero
         << "\nISBN: " << isbn << "\n\n";
}