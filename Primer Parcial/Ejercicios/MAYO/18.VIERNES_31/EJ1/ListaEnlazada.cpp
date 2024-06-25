#include "ListaEnlazada.h"
#include <iostream>

// Constructor
ListaEnlazada::ListaEnlazada() {
    cabeza = nullptr;
}

// Destructor
ListaEnlazada::~ListaEnlazada() {
    Nodo* actual = cabeza;
    Nodo* siguiente;
    while (actual != nullptr) {
        siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

// Método para insertar un nuevo valor en la lista
void ListaEnlazada::insertar(int valor) {
    Nodo* nuevoNodo = new Nodo();
    nuevoNodo->dato = valor;
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

// Método para invertir la lista utilizando recursión
void ListaEnlazada::invertir() {
    cabeza = invertirRecursivo(cabeza);
}

// Método recursivo para invertir la lista
Nodo* ListaEnlazada::invertirRecursivo(Nodo* nodo) {
    if (nodo == nullptr || nodo->siguiente == nullptr) {
        return nodo;
    }
    Nodo* nuevoNodo = invertirRecursivo(nodo->siguiente);
    nodo->siguiente->siguiente = nodo;
    nodo->siguiente = nullptr;
    return nuevoNodo;
}

// Método para imprimir la lista
void ListaEnlazada::imprimir() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}
