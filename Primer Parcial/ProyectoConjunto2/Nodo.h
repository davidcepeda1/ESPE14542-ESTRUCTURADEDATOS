#pragma once

template <class T>
class Nodo {
public:
    T data;
    Nodo<T>* next;

    Nodo(T dato) : data(dato), next(nullptr) {}
};
