#pragma once
#include <iostream>


using namespace std;

template<typename T>
class Nodo{
private:
    T per;
    Nodo<T>* siguiente;
public:
Nodo(T persona): per(persona), siguiente(nullptr){}

T getPer() {
    return per;
}

Nodo<T>* getSiguiente() {
    return siguiente;
}

void setSiguiente(Nodo<T>* nodo) {
    siguiente = nodo;
}
};