#pragma once

template<typename T>
class Nodo {
private:
    T dato;
    Nodo<T>* siguiente;

public:
    Nodo(T dato) : dato(dato), siguiente(nullptr) {}

    T getDato() {
        return dato;
    }

    Nodo<T>* getSiguiente() {
        return siguiente;
    }

    void setSiguiente(Nodo<T>* nodo) {
        siguiente = nodo;
    }
};
