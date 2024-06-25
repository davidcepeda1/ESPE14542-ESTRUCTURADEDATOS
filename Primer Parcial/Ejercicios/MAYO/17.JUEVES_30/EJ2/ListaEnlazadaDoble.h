#pragma once
#include "NodoDoble.h"
#include <functional>

template<typename T>
class ListaEnlazadaDoble {
private:
    NodoDoble<T>* cabeza;

public:
    ListaEnlazadaDoble() : cabeza(nullptr) {}

    ~ListaEnlazadaDoble() {
        while (cabeza) {
            NodoDoble<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    void insertar(T dato) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(dato);
        nuevo->siguiente = cabeza;
        if (cabeza) cabeza->anterior = nuevo;
        cabeza = nuevo;
    }

    void recorrer(std::function<void(T)> callback) {
        NodoDoble<T>* temp = cabeza;
        while (temp) {
            callback(temp->dato);
            temp = temp->siguiente;
        }
    }

    void imprimirInverso(NodoDoble<T>* nodo) {
        if (nodo) {
            imprimirInverso(nodo->siguiente);
            std::cout << nodo->dato << " ";
        }
    }

    void imprimirInverso() {
        imprimirInverso(cabeza);
        std::cout << std::endl;
    }
};
