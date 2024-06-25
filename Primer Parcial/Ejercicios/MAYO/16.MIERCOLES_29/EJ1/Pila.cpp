#include "Pila.h"

template <typename T>
Pila<T>::Pila() : cabeza(nullptr) {}

template <typename T>
Pila<T>::~Pila() {}

template <typename T>
void Pila<T>::push(T dato) {
    auto nuevoNodo = std::make_unique<Nodo>(dato);
    nuevoNodo->siguiente = std::move(cabeza);
    cabeza = std::move(nuevoNodo);
}

template <typename T>
void Pila<T>::pop() {
    if (cabeza) {
        cabeza = std::move(cabeza->siguiente);
    } else {
        std::cout << "La pila está vacía.\n";
    }
}

template <typename T>
T Pila<T>::top() const {
    if (cabeza) {
        return cabeza->dato;
    } else {
        throw std::runtime_error("La pila está vacía");
    }
}

template <typename T>
bool Pila<T>::isEmpty() const {
    return cabeza == nullptr;
}

template <typename T>
void Pila<T>::mostrarPila() const {
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
template class Pila<int>;
