#pragma once
#include "NodoDoble.h"
#include <functional>

template<typename T>
class ListaCircularDoble {
private:
    NodoDoble<T>* cabeza;

public:
    ListaCircularDoble() : cabeza(nullptr) {}

    ~ListaCircularDoble() {
        if (cabeza) {
            NodoDoble<T>* temp = cabeza->siguiente;
            while (temp != cabeza) {
                NodoDoble<T>* siguiente = temp->siguiente;
                delete temp;
                temp = siguiente;
            }
            delete cabeza;
        }
    }

    void insertar(T dato) {
        NodoDoble<T>* nuevo = new NodoDoble<T>(dato);
        if (!cabeza) {
            cabeza = nuevo;
            cabeza->siguiente = cabeza;
            cabeza->anterior = cabeza;
        } else {
            nuevo->siguiente = cabeza;
            nuevo->anterior = cabeza->anterior;
            cabeza->anterior->siguiente = nuevo;
            cabeza->anterior = nuevo;
        }
    }

    void recorrer(std::function<void(T)> callback) {
        NodoDoble<T>* temp = cabeza;
        do {
            callback(temp->dato);
            temp = temp->siguiente;
        } while (temp != cabeza);
    }

    void imprimirInverso(NodoDoble<T>* nodo) {
    if (nodo != cabeza) {
        imprimirInverso(nodo->anterior);
        std::cout << nodo->dato << " ";
    }
}

void imprimirInverso() {
    if (cabeza) {
        imprimirInverso(cabeza->anterior);
        std::cout << cabeza->dato << " ";
    }
    std::cout << std::endl;
}

void eliminar(T dato) {
    if (cabeza) {
        NodoDoble<T>* temp = cabeza;
        do {
            if (temp->dato == dato) {
                if (temp == cabeza) {
                    cabeza = cabeza->siguiente;
                }
                temp->anterior->siguiente = temp->siguiente;
                temp->siguiente->anterior = temp->anterior;
                delete temp;
                return;
            }
            temp = temp->siguiente;
        } while (temp != cabeza);
    }
}

};
