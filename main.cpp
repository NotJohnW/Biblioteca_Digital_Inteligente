#include <iostream>
#include "GestorBiblioteca.h"

using namespace std;

// Declaración de algoritmos
int busquedaLineal(const vector<Libro>&, string);
int busquedaBinaria(const vector<Libro>&, string);
void burbuja(vector<Libro>&);
void seleccion(vector<Libro>&);
void quickSort(vector<Libro>&, int, int);

int main() {
    GestorBiblioteca gestor;
    gestor.cargarDesdeArchivo("datos.txt");

    int opcion;
    do {
        cout << "\n=== Biblioteca Digital ===\n";
        cout << "1. Listar libros\n";
        cout << "2. Agregar libro\n";
        cout << "3. Buscar (Lineal)\n";
        cout << "4. Buscar (Binaria)\n";
        cout << "5. Ordenar (Burbuja)\n";
        cout << "6. Ordenar (Seleccion)\n";
        cout << "7. Ordenar (QuickSort)\n";
        cout << "0. Salir\n";
        cout << "Opción: ";
        cin >> opcion;
        cin.ignore();

        if (opcion == 1) gestor.listarLibros();

        else if (opcion == 2) {
            string t, a, g, i;
            int an;

            cout << "Título: "; getline(cin, t);
            cout << "Autor: "; getline(cin, a);
            cout << "Año: "; cin >> an; cin.ignore();
            cout << "Género: "; getline(cin, g);
            cout << "ISBN: "; getline(cin, i);

            gestor.agregarLibro(Libro(t, a, an, g, i));
        }

        else if (opcion == 3) {
            string t;
            cout << "Título a buscar: "; getline(cin, t);
            int pos = busquedaLineal(gestor.getLibros(), t);
            if (pos != -1) gestor.getLibros()[pos].mostrar();
            else cout << "No encontrado.\n";
        }

        else if (opcion == 4) {
            string t;
            cout << "Título a buscar (requiere lista ordenada): ";
            getline(cin, t);
            int pos = busquedaBinaria(gestor.getLibros(), t);
            if (pos != -1) gestor.getLibros()[pos].mostrar();
            else cout << "No encontrado.\n";
        }

        else if (opcion == 5) {
            burbuja(gestor.getLibros());
            cout << "Ordenado por título (Burbuja).\n";
        }

        else if (opcion == 6) {
            seleccion(gestor.getLibros());
            cout << "Ordenado por autor (Seleccion).\n";
        }

        else if (opcion == 7) {
            quickSort(gestor.getLibros(), 0, gestor.getLibros().size() - 1);
            cout << "Ordenado por ISBN (QuickSort).\n";
        }

    } while (opcion != 0);

    gestor.guardarEnArchivo("datos.txt");

    return 0;
}
