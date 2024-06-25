#include <iostream>
#include "ListaSimple.h"

ListaEnlazada::ListaEnlazada() : cabeza(nullptr) {}

ListaEnlazada::~ListaEnlazada() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        Nodo* siguiente = actual->siguiente;
        delete actual;
        actual = siguiente;
    }
}

void ListaEnlazada::insertarAlInicio(int dato) {
    Nodo* nuevoNodo = new Nodo(dato);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

void ListaEnlazada::insertarAlFinal(int dato) {
    Nodo* nuevoNodo = new Nodo(dato);
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
        return;
    }
    Nodo* ultimo = cabeza;
    while (ultimo->siguiente != nullptr) {
        ultimo = ultimo->siguiente;
    }
    ultimo->siguiente = nuevoNodo;
}

void ListaEnlazada::eliminarNodo(int key) {
    Nodo* temp = cabeza;
    Nodo* prev = nullptr;

    if (temp != nullptr && temp->dato == key) {
        cabeza = temp->siguiente;
        delete temp;
        return;
    }

    while (temp != nullptr && temp->dato != key) {
        prev = temp;
        temp = temp->siguiente;
    }

    if (temp == nullptr) return;

    prev->siguiente = temp->siguiente;
    delete temp;
}

void ListaEnlazada::recorrerLista() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " -> ";
        actual = actual->siguiente;
    }
    std::cout << "None" << std::endl;
}
