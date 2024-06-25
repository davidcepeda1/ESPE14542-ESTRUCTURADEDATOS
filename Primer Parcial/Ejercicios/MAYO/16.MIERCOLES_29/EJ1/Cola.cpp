#include "Cola.h"

template <typename T>
Cola<T>::Cola() : cabeza(nullptr), cola(nullptr) {}

template <typename T>
Cola<T>::~Cola() {}

template <typename T>
void Cola<T>::enqueue(T dato) {
    auto nuevoNodo = std::make_unique<Nodo>(dato);
    Nodo* nuevoNodoPtr = nuevoNodo.get();
    if (cola) {
        cola->siguiente = std::move(nuevoNodo);
    } else {
        cabeza = std::move(nuevoNodo);
    }
    cola = nuevoNodoPtr;
}

template <typename T>
void Cola<T>::dequeue() {
    if (cabeza) {
        cabeza = std::move(cabeza->siguiente);
        if (!cabeza) {
            cola = nullptr;
        }
    } else {
        std::cout << "La cola está vacía.\n";
    }
}

template <typename T>
T Cola<T>::front() const {
    if (cabeza) {
        return cabeza->dato;
    } else {
        throw std::runtime_error("La cola está vacía");
    }
}

template <typename T>
bool Cola<T>::isEmpty() const {
    return cabeza == nullptr;
}

template <typename T>
void Cola<T>::mostrarCola() const {
    auto mostrarRec = [](const Nodo* nodo, const auto& mostrarRec) -> void {
        if (nodo) {
            std::cout << nodo->dato << " -> ";
            mostrarRec(nodo->siguiente.get(), mostrarRec);
        }
    };
    mostrarRec(cabeza.get(), mostrarRec);
    std::cout << "NULL\n";
}

// Explicit template instantiation
template class Cola<int>;
