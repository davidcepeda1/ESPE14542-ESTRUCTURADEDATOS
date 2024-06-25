#pragma once
#include "NodoCircular.h"
#include <functional>

template<typename T>
class ListaCircularSimple {
private:
    NodoCircular<T>* cabeza;

public:
    ListaCircularSimple() : cabeza(nullptr) {}

    ~ListaCircularSimple() {
        if (cabeza) {
            NodoCircular<T>* temp = cabeza->siguiente;
            while (temp != cabeza) {
                NodoCircular<T>* siguiente = temp->siguiente;
                delete temp;
                temp = siguiente;
            }
            delete cabeza;
        }
    }

    void insertar(T dato) {
        NodoCircular<T>* nuevo = new NodoCircular<T>(dato);
        if (!cabeza) {
            cabeza = nuevo;
            cabeza->siguiente = cabeza;
        } else {
            nuevo->siguiente = cabeza->siguiente;
            cabeza->siguiente = nuevo;
        }
    }

    void recorrer(std::function<void(T)> callback) {
        NodoCircular<T>* temp = cabeza;
        do {
            callback(temp->dato);
            temp = temp->siguiente;
        } while (temp != cabeza);
    }

    void imprimirInverso(NodoCircular<T>* nodo) {
        if (nodo != cabeza) {
            imprimirInverso(nodo->siguiente);
            std::cout << nodo->dato << " ";
        }
    }

    void imprimirInverso() {
        if (cabeza) {
            imprimirInverso(cabeza->siguiente);
            std::cout << cabeza->dato << " ";
        }
        std::cout << std::endl;
    }
};
