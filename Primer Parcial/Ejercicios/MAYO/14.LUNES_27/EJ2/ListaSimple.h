#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaSimpleEliminar {
public:
    ListaSimpleEliminar();
    ~ListaSimpleEliminar();
    void insertarInicio(int valor);
    void insertarFinal(int valor);
    void imprimirLista();
    void eliminar(int valor);
private:
    Nodo* cabeza;
};

#endif // LISTA_SIMPLE_ELIMINAR_H
