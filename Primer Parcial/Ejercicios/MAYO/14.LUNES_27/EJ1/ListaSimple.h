#ifndef LISTA_SIMPLE_H
#define LISTA_SIMPLE_H

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaSimple {
public:
    ListaSimple();
    ~ListaSimple();
    void insertarInicio(int valor);
    void insertarFinal(int valor);
    void imprimirLista();
private:
    Nodo* cabeza;
};

#endif // LISTA_SIMPLE_H
