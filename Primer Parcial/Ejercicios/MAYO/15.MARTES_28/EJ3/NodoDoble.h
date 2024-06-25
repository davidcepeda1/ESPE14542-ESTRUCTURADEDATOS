#ifndef NODODOBLE_H
#define NODODOBLE_H

template <typename T>
class NodoDoble {
public:
    T dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;

    NodoDoble(T d) : dato(d), siguiente(nullptr), anterior(nullptr) {}
};

#endif // NODODOBLE_H
