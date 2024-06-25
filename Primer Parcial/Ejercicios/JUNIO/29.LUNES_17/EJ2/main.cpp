#include <iostream>
#include <string>
using namespace std;

struct Libro {
    string titulo;
    string autor;
    int numPaginas;
    Libro* siguiente;
};

class Biblioteca {
private:
    Libro* cabeza;

public:
    Biblioteca() : cabeza(nullptr) {}

    ~Biblioteca() {
        while (cabeza) {
            Libro* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    void insertarInicio(string titulo, string autor, int numPaginas) {
        Libro* nuevoLibro = new Libro();
        nuevoLibro->titulo = titulo;
        nuevoLibro->autor = autor;
        nuevoLibro->numPaginas = numPaginas;
        nuevoLibro->siguiente = cabeza;
        cabeza = nuevoLibro;
    }

    void insertarFinal(string titulo, string autor, int numPaginas) {
        Libro* nuevoLibro = new Libro();
        nuevoLibro->titulo = titulo;
        nuevoLibro->autor = autor;
        nuevoLibro->numPaginas = numPaginas;
        nuevoLibro->siguiente = nullptr;
        if (!cabeza) {
            cabeza = nuevoLibro;
        } else {
            Libro* temp = cabeza;
            while (temp->siguiente) {
                temp = temp->siguiente;
            }
            temp->siguiente = nuevoLibro;
        }
    }

    void eliminarInicio() {
        if (!cabeza) {
            cout << "Lista vacía" << endl;
            return;
        }
        Libro* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }

    void eliminarFinal() {
        if (!cabeza) {
            cout << "Lista vacía" << endl;
            return;
        }
        if (!cabeza->siguiente) {
            delete cabeza;
            cabeza = nullptr;
            return;
        }
        Libro* temp = cabeza;
        while (temp->siguiente->siguiente) {
            temp = temp->siguiente;
        }
        delete temp->siguiente;
        temp->siguiente = nullptr;
    }

    void mostrarLista() {
        Libro* temp = cabeza;
        while (temp) {
            cout << "Titulo: " << temp->titulo << ", Autor: " << temp->autor << ", Paginas: " << temp->numPaginas << endl;
            temp = temp->siguiente;
        }
    }
};

int main() {
    Biblioteca biblioteca;
    biblioteca.insertarFinal("El Señor de los Anillos", "J.R.R. Tolkien", 1200);
    biblioteca.insertarFinal("Cien años de soledad", "Gabriel Garcia Marquez", 400);

    cout << "Lista de libros:" << endl;
    biblioteca.mostrarLista();

    return 0;
}
