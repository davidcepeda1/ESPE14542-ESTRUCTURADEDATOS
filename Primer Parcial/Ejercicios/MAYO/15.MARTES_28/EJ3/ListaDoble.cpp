#include <iostream>
#include "ListaDoble.h"

template <typename T>
ListaDoble<T>::ListaDoble() : cabeza(nullptr), cola(nullptr) {}

template <typename T>
ListaDoble<T>::~ListaDoble() {
    auto eliminarNodos = [](NodoDoble<T>* nodo, auto& self) -> void {
        if (nodo != nullptr) {
            self(nodo->siguiente, self);
            delete nodo;
        }
    };
    eliminarNodos(cabeza, eliminarNodos);
}

template <typename T>
void ListaDoble<T>::insertarAlInicio(T dato) {
    NodoDoble<T>* nuevoNodo = new NodoDoble<T>(dato);
    if (cabeza == nullptr) {
        cabeza = cola = nuevoNodo;
    } else {
        nuevoNodo->siguiente = cabeza;
        cabeza->anterior = nuevoNodo;
        cabeza = nuevoNodo;
    }
}

template <typename T>
void ListaDoble<T>::insertarAlFinal(T dato) {
    NodoDoble<T>* nuevoNodo = new NodoDoble<T>(dato);
    if (cola == nullptr) {
        cabeza = cola = nuevoNodo;
    } else {
        cola->siguiente = nuevoNodo;
        nuevoNodo->anterior = cola;
        cola = nuevoNodo;
    }
}

template <typename T>
void ListaDoble<T>::eliminarNodo(T key) {
    bool found = false;
    cabeza = eliminarNodoRec(cabeza, key, found);
    if (!found) {
        std::cout << "Nodo con dato " << key << " no encontrado en la lista.\n";
    }
}

template <typename T>
NodoDoble<T>* ListaDoble<T>::eliminarNodoRec(NodoDoble<T>* nodo, T key, bool& found) {
    if (nodo == nullptr) {
        return nullptr;
    }
    if (nodo->dato == key) {
        found = true;
        if (nodo->anterior) nodo->anterior->siguiente = nodo->siguiente;
        if (nodo->siguiente) nodo->siguiente->anterior = nodo->anterior;
        if (nodo == cabeza) cabeza = nodo->siguiente;
        if (nodo == cola) cola = nodo->anterior;
        delete nodo;
        return found ? nullptr : nodo;
    }
    nodo->siguiente = eliminarNodoRec(nodo->siguiente, key, found);
    return nodo;
}

template <typename T>
void ListaDoble<T>::recorrerLista() {
    recorrerListaRec(cabeza);
    std::cout << "None" << std::endl;
}

template <typename T>
void ListaDoble<T>::recorrerListaRec(NodoDoble<T>* nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->dato << " -> ";
        recorrerListaRec(nodo->siguiente);
    }
}

template <typename T>
void ListaDoble<T>::recorrerListaReversa() {
    recorrerListaReversaRec(cola);
    std::cout << "None" << std::endl;
}

template <typename T>
void ListaDoble<T>::recorrerListaReversaRec(NodoDoble<T>* nodo) {
    if (nodo != nullptr) {
        std::cout << nodo->dato << " -> ";
        recorrerListaReversaRec(nodo->anterior);
    }
}

template <typename T>
bool ListaDoble<T>::buscarNodo(T key) {
    return buscarNodoRec(cabeza, key);
}

template <typename T>
bool ListaDoble<T>::buscarNodoRec(NodoDoble<T>* nodo, T key) {
    if (nodo == nullptr) {
        return false;
    }
    if (nodo->dato == key) {
        return true;
    }
    return buscarNodoRec(nodo->siguiente, key);
}

// Explicit template instantiation
template class ListaDoble<int>;
