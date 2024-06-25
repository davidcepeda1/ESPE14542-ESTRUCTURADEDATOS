#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

#include "Nodo.h"
#include <functional>

template <typename T>
class ListaCircular {
public:
    ListaCircular();
    ~ListaCircular();
    void insertarAlInicio(T dato);
    void insertarAlFinal(T dato);
    void insertarEnPosicion(T dato, int posicion);
    void eliminarNodo(T key);
    void eliminarDesdePosicion(int posicion);
    void recorrerLista();
    bool buscarNodo(T key);

private:
    Nodo<T>* cabeza;

    void insertarAlFinalRec(Nodo<T>* nodo, T dato);
    Nodo<T>* eliminarNodoRec(Nodo<T>* nodo, T key, bool& found);
    Nodo<T>* eliminarDesdePosicionRec(Nodo<T>* nodo, int posicion, int contador);
    void recorrerListaRec(Nodo<T>* nodo, Nodo<T>* stop);
    bool buscarNodoRec(Nodo<T>* nodo, T key);
};

#endif // LISTACIRCULAR_H
