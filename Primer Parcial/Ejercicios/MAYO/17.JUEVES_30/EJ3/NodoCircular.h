#pragma once

template<typename T>
class NodoCircular {
public:
    T dato;
    NodoCircular<T>* siguiente;

    NodoCircular(T dato) : dato(dato), siguiente(nullptr) {}
};
