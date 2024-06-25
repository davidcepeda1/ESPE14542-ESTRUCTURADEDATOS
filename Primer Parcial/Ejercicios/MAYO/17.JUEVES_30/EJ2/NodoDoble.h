#pragma once

template<typename T>
class NodoDoble {
public:
    T dato;
    NodoDoble<T>* siguiente;
    NodoDoble<T>* anterior;

    NodoDoble(T dato) : dato(dato), siguiente(nullptr), anterior(nullptr) {}
};
