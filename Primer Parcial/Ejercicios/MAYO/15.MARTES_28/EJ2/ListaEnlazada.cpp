#include <iostream>
#include "ListaEnlazada.h"

template <typename T>
ListaEnlazada<T>::ListaEnlazada() : cabeza(nullptr) {}

template <typename T>
ListaEnlazada<T>::~ListaEnlazada() {
    auto eliminarNodos = [](Nodo<T>* nodo, auto& self) -> void {
        if (nodo != nullptr) {
            self(nodo->siguiente, self);
            delete nodo;
        }
    };
    eliminarNodos(cabeza, eliminarNodos);
}

template <typename T>
void ListaEnlazada<T>::insertarAlInicio(T dato) {
    Nodo<T>* nuevoNodo = new Nodo<T>(dato);
    nuevoNodo->siguiente = cabeza;
    cabeza = nuevoNodo;
}

template <typename T>
void ListaEnlazada<T>::insertarAlFinal(T dato) {
    if (cabeza == nullptr) {
        cabeza = new Nodo<T>(dato);
    } else {
        insertarAlFinalRec(cabeza, dato);
    }
}

template <typename T>
void ListaEnlazada<T>::insertarAlFinalRec(Nodo<T>* nodo, T dato) {
    if (nodo->siguiente == nullptr) {
        nodo->siguiente = new Nodo<T>(dato);
    } else {
        insertarAlFinalRec(nodo->siguiente, dato);
    }
}

template <typename T>
void ListaEnlazada<T>::eliminarNodo(T key) {
    bool found = false;
    cabeza = eliminarNodoRec(cabeza, key, found);
    if (!found) {
        std::cout << "Nodo con dato " << key << " no encontrado en la lista.\n";
    }
}

template <typename T>
Nodo<T>* ListaEnlazada<T>::eliminarNodoRec(Nodo<T>* nodo, T key, bool& found) {
    if (nodo == nullptr) {
        return nullptr;
    }
    if (nodo->dato == key) {
        found = true;
        Nodo<T>* temp = nodo->siguiente;
        delete nodo;
        return temp;
    }
    nodo->siguiente = eliminarNodoRec(nodo->siguiente, key, found);
    return nodo;
}

template <typename T>
void ListaEnlazada<T>::recorrerLista() {
    recorrerListaRec(cabeza);
    std::cout << "None" << std::endl;
}

template <typename T>
void ListaEnlazada<T>::recorrerListaRec(Nodo<T>* nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->dato << " -> ";
        recorrerListaRec(nodo->siguiente);
    }
}

template <typename T>
bool ListaEnlazada<T>::buscarNodo(T key) {
    return buscarNodoRec(cabeza, key);
}

template <typename T>
bool ListaEnlazada<T>::buscarNodoRec(Nodo<T>* nodo, T key) {
    if (nodo == nullptr) {
        return false;
    }
    if (nodo->dato == key) {
        return true;
    }
    return buscarNodoRec(nodo->siguiente, key);
}

// Explicit template instantiation
template class ListaEnlazada<int>;
