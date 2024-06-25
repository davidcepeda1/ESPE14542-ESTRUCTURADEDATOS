#ifndef LISTADOBLE_H
#define LISTADOBLE_H

#include "NodoDoble.h"
#include <functional>

template <typename T>
class ListaDoble {
public:
    ListaDoble();
    ~ListaDoble();
    void insertarAlInicio(T dato);
    void insertarAlFinal(T dato);
    void eliminarNodo(T key);
    void recorrerLista();
    void recorrerListaReversa();
    bool buscarNodo(T key);

private:
    NodoDoble<T>* cabeza;
    NodoDoble<T>* cola;

    void insertarAlFinalRec(NodoDoble<T>* nodo, T dato);
    NodoDoble<T>* eliminarNodoRec(NodoDoble<T>* nodo, T key, bool& found);
    void recorrerListaRec(NodoDoble<T>* nodo);
    void recorrerListaReversaRec(NodoDoble<T>* nodo);
    bool buscarNodoRec(NodoDoble<T>* nodo, T key);
};

#endif // LISTADOBLE_H
