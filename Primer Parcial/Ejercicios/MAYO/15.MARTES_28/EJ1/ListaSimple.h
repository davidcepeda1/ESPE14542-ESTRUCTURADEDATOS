#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include "Nodo.h"

class ListaEnlazada {
public:
    ListaEnlazada();
    ~ListaEnlazada();
    void insertarAlInicio(int dato);
    void insertarAlFinal(int dato);
    void eliminarNodo(int key);
    void recorrerLista();

private:
    Nodo* cabeza;
};

#endif // LISTAENLAZADA_H
