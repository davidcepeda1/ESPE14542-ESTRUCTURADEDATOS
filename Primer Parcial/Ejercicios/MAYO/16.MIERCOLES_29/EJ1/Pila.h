#ifndef PILA_H
#define PILA_H

#include <iostream>
#include <memory>

template <typename T>
class Pila {
public:
    Pila();
    ~Pila();
    void push(T dato);
    void pop();
    T top() const;
    bool isEmpty() const;
    void mostrarPila() const;

private:
    struct Nodo {
        T dato;
        std::unique_ptr<Nodo> siguiente;
        Nodo(T d) : dato(d), siguiente(nullptr) {}
    };
    std::unique_ptr<Nodo> cabeza;

    void mostrarPilaRec(const Nodo* nodo) const;
};

#endif // PILA_H
