#include <iostream>
#include "ListaCircular.h"

template <typename T>
ListaCircular<T>::ListaCircular() : cabeza(nullptr) {}

template <typename T>
ListaCircular<T>::~ListaCircular() {
    if (cabeza) {
        Nodo<T>* current = cabeza;
        Nodo<T>* next;
        do {
            next = current->siguiente;
            delete current;
            current = next;
        } while (current != cabeza);
    }
}

template <typename T>
void ListaCircular<T>::insertarAlInicio(T dato) {
    Nodo<T>* nuevoNodo = new Nodo<T>(dato);
    if (!cabeza) {
        cabeza = nuevoNodo;
        nuevoNodo->siguiente = cabeza;
    } else {
        Nodo<T>* temp = cabeza;
        while (temp->siguiente != cabeza) {
            temp = temp->siguiente;
        }
        nuevoNodo->siguiente = cabeza;
        temp->siguiente = nuevoNodo;
        cabeza = nuevoNodo;
    }
}

template <typename T>
void ListaCircular<T>::insertarAlFinal(T dato) {
    if (!cabeza) {
        insertarAlInicio(dato);
    } else {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        Nodo<T>* temp = cabeza;
        while (temp->siguiente != cabeza) {
            temp = temp->siguiente;
        }
        temp->siguiente = nuevoNodo;
        nuevoNodo->siguiente = cabeza;
    }
}

template <typename T>
void ListaCircular<T>::insertarEnPosicion(T dato, int posicion) {
    if (posicion == 0) {
        insertarAlInicio(dato);
    } else {
        Nodo<T>* nuevoNodo = new Nodo<T>(dato);
        Nodo<T>* temp = cabeza;
        for (int i = 0; temp->siguiente != cabeza && i < posicion - 1; ++i) {
            temp = temp->siguiente;
        }
        nuevoNodo->siguiente = temp->siguiente;
        temp->siguiente = nuevoNodo;
    }
}

template <typename T>
void ListaCircular<T>::eliminarNodo(T key) {
    bool found = false;
    cabeza = eliminarNodoRec(cabeza, key, found);
    if (!found) {
        std::cout << "Nodo con dato " << key << " no encontrado en la lista.\n";
    }
}

template <typename T>
Nodo<T>* ListaCircular<T>::eliminarNodoRec(Nodo<T>* nodo, T key, bool& found) {
    if (!nodo) {
        return nullptr;
    }

    Nodo<T>* current = nodo;
    Nodo<T>* previous = nullptr;

    do {
        if (current->dato == key) {
            found = true;
            if (current == cabeza && current->siguiente == cabeza) {
                delete current;
                return nullptr;
            }
            if (current == cabeza) {
                previous = cabeza;
                while (previous->siguiente != cabeza) {
                    previous = previous->siguiente;
                }
                cabeza = cabeza->siguiente;
                previous->siguiente = cabeza;
                delete current;
                return cabeza;
            }
            if (current->siguiente == cabeza) {
                previous->siguiente = cabeza;
            } else {
                previous->siguiente = current->siguiente;
            }
            delete current;
            return nodo;
        }
        previous = current;
        current = current->siguiente;
    } while (current != cabeza);

    return nodo;
}

template <typename T>
void ListaCircular<T>::eliminarDesdePosicion(int posicion) {
    cabeza = eliminarDesdePosicionRec(cabeza, posicion, 0);
}

template <typename T>
Nodo<T>* ListaCircular<T>::eliminarDesdePosicionRec(Nodo<T>* nodo, int posicion, int contador) {
    if (!nodo || contador > posicion) {
        return nodo;
    }

    if (contador == posicion) {
        if (nodo == cabeza && nodo->siguiente == cabeza) {
            delete nodo;
            return nullptr;
        }
        Nodo<T>* current = nodo;
        Nodo<T>* previous = nullptr;
        while (current->siguiente != nodo) {
            previous = current;
            current = current->siguiente;
        }
        if (nodo == cabeza) {
            cabeza = nodo->siguiente;
            previous->siguiente = cabeza;
        } else {
            previous->siguiente = nodo->siguiente;
        }
        delete nodo;
        return cabeza;
    }

    nodo->siguiente = eliminarDesdePosicionRec(nodo->siguiente, posicion, contador + 1);
    return nodo;
}

template <typename T>
void ListaCircular<T>::recorrerLista() {
    if (cabeza) {
        recorrerListaRec(cabeza, cabeza);
        std::cout << " (vuelve a cabeza)\n";
    }
}

template <typename T>
void ListaCircular<T>::recorrerListaRec(Nodo<T>* nodo, Nodo<T>* stop) {
    if (nodo->siguiente != stop) {
        std::cout << nodo->dato << " -> ";
        recorrerListaRec(nodo->siguiente, stop);
    } else {
        std::cout << nodo->dato;
    }
}

template <typename T>
bool ListaCircular<T>::buscarNodo(T key) {
    return buscarNodoRec(cabeza, key);
}

template <typename T>
bool ListaCircular<T>::buscarNodoRec(Nodo<T>* nodo, T key) {
    if (!nodo) {
        return false;
    }

    Nodo<T>* current = nodo;

    do {
        if (current->dato == key) {
            return true;
        }
        current = current->siguiente;
    } while (current != nodo);

    return false;
}

// Explicit template instantiation
template class ListaCircular<int>;
