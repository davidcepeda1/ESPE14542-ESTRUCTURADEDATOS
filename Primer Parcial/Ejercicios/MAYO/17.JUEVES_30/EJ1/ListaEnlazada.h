#pragma once
#include "Nodo.h"
#include <functional>

template<typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    ~ListaEnlazada() {
        while (cabeza) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    void insertar(T dato) {
        Nodo<T>* nuevo = new Nodo<T>(dato);
        nuevo->siguiente = cabeza;
        cabeza = nuevo;
    }

    void recorrer(std::function<void(T)> callback) {
        Nodo<T>* temp = cabeza;
        while (temp) {
            callback(temp->dato);
            temp = temp->siguiente;
        }
    }

    // Función recursiva para imprimir la lista en orden inverso
    void imprimirInverso(Nodo<T>* nodo) {
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
