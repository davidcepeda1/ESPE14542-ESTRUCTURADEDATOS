#include "listaSimple.h"
#include <iostream>

ListaSimpleEliminar::ListaSimpleEliminar() : cabeza(nullptr) {}

ListaSimpleEliminar::~ListaSimpleEliminar() {
    while (cabeza != nullptr) {
        Nodo* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void ListaSimpleEliminar::insertarInicio(int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = cabeza;
    cabeza = nuevo;
}

void ListaSimpleEliminar::insertarFinal(int valor) {
    Nodo* nuevo = new Nodo;
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;
    if (cabeza == nullptr) {
        cabeza = nuevo;
    } else {
        Nodo* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
    }
}

void ListaSimpleEliminar::imprimirLista() {
    Nodo* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

void ListaSimpleEliminar::eliminar(int valor) {
    Nodo* actual = cabeza;
    Nodo* anterior = nullptr;

    while (actual != nullptr && actual->dato != valor) {
        anterior = actual;
        actual = actual->siguiente;
    }

    if (actual == nullptr) {
        std::cout << "El valor " << valor << " no está en la lista." << std::endl;
        return;
    }

    if (anterior == nullptr) {
        cabeza = actual->siguiente;
    } else {
        anterior->siguiente = actual->siguiente;
    }

    delete actual;
}
