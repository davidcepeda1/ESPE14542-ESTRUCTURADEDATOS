#ifndef COLA_H
#define COLA_H

#include <iostream>
#include <memory>

template <typename T>
class Cola {
public:
    Cola();
    ~Cola();
    void enqueue(T dato);
    void dequeue();
    T front() const;
    bool isEmpty() const;
    void mostrarCola() const;

private:
    struct Nodo {
        T dato;
        std::unique_ptr<Nodo> siguiente;
        Nodo(T d) : dato(d), siguiente(nullptr) {}
    };
    std::unique_ptr<Nodo> cabeza;
    Nodo* cola;

    void mostrarColaRec(const Nodo* nodo) const;
};

#endif // COLA_H
