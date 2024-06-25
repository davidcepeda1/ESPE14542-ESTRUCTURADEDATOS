#pragma once
#include "Nodo.h"
#include <iostream>

template<typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    void insertar(T dato) {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        nuevoNodo->setSiguiente(cabeza);
        cabeza = nuevoNodo;
    }

    bool existe(T dato) {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            if (actual->getDato() == dato) {
                return true;
            }
            actual = actual->getSiguiente();
        }
        return false;
    }

    Nodo<T>* getCabeza() const {
        return cabeza;
    }

    ~ListaEnlazada() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* siguiente = actual->getSiguiente();
            delete actual;
            actual = siguiente;
        }
    }
};
