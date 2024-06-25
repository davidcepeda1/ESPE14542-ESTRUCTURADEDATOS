#include "listaDoble.h"
#include <iostream>

ListaDobleConcatenar::ListaDobleConcatenar() : cabeza(nullptr) {}

ListaDobleConcatenar::~ListaDobleConcatenar() {
    while (cabeza != nullptr) {
        NodoDoble* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void ListaDobleConcatenar::insertarInicio(int valor) {
    NodoDoble* nuevo = new NodoDoble;
    nuevo->dato = valor;
    nuevo->anterior = nullptr;
    nuevo->siguiente = cabeza;
    if (cabeza != nullptr) {
        cabeza->anterior = nuevo;
    }
    cabeza = nuevo;
}

void ListaDobleConcatenar::insertarFinal(int valor) {
    NodoDoble* nuevo = new NodoDoble;
    nuevo->dato = valor;
    nuevo->siguiente = nullptr;
    if (cabeza == nullptr) {
        nuevo->anterior = nullptr;
        cabeza = nuevo;
    } else {
        NodoDoble* actual = cabeza;
        while (actual->siguiente != nullptr) {
            actual = actual->siguiente;
        }
        actual->siguiente = nuevo;
        nuevo->anterior = actual;
    }
}

void ListaDobleConcatenar::imprimirLista() {
    NodoDoble* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

void ListaDobleConcatenar::concatenar(ListaDobleConcatenar& otra) {
    if (otra.cabeza == nullptr) {
        return;
    }
    if (cabeza == nullptr) {
        cabeza = otra.cabeza;
        otra.cabeza = nullptr;
        return;
    }
    NodoDoble* actual = cabeza;
    while (actual->siguiente != nullptr) {
        actual = actual->siguiente;
    }
    actual->siguiente = otra.cabeza;
    otra.cabeza->anterior = actual;
    otra.cabeza = nullptr;
}
