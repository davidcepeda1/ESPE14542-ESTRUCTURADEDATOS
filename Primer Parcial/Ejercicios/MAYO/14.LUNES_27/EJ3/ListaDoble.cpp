#include "listaDoble.h"
#include <iostream>

ListaDoble::ListaDoble() : cabeza(nullptr) {}

ListaDoble::~ListaDoble() {
    while (cabeza != nullptr) {
        NodoDoble* temp = cabeza;
        cabeza = cabeza->siguiente;
        delete temp;
    }
}

void ListaDoble::insertarInicio(int valor) {
    NodoDoble* nuevo = new NodoDoble;
    nuevo->dato = valor;
    nuevo->anterior = nullptr;
    nuevo->siguiente = cabeza;
    if (cabeza != nullptr) {
        cabeza->anterior = nuevo;
    }
    cabeza = nuevo;
}

void ListaDoble::insertarFinal(int valor) {
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

void ListaDoble::imprimirLista() {
    NodoDoble* actual = cabeza;
    while (actual != nullptr) {
        std::cout << actual->dato << " ";
        actual = actual->siguiente;
    }
    std::cout << std::endl;
}

void ListaDoble::imprimirListaReversa() {
    NodoDoble* actual = cabeza;
    while (actual->siguiente != nullptr) {
        actual;
    }
}