#ifndef LISTAENLAZADA_H
#define LISTAENLAZADA_H

#include "Nodo.h"
#include <functional>

template <typename T>
class ListaEnlazada {
public:
    ListaEnlazada();
    ~ListaEnlazada();
    void insertarAlInicio(T dato);
    void insertarAlFinal(T dato);
    void eliminarNodo(T key);
    void recorrerLista();
    bool buscarNodo(T key);

private:
    Nodo<T>* cabeza;

    void insertarAlFinalRec(Nodo<T>* nodo, T dato);
    Nodo<T>* eliminarNodoRec(Nodo<T>* nodo, T key, bool& found);
    void recorrerListaRec(Nodo<T>* nodo);
    bool buscarNodoRec(Nodo<T>* nodo, T key);
};

#endif // LISTAENLAZADA_H
