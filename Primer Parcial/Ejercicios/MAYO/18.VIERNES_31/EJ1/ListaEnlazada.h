#ifndef LISTA_ENLAZADA_H
#define LISTA_ENLAZADA_H

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ListaEnlazada {
public:
    ListaEnlazada();
    ~ListaEnlazada();
    void insertar(int valor);
    void invertir();
    void imprimir();

private:
    Nodo* cabeza;
    Nodo* invertirRecursivo(Nodo* nodo);
};

#endif // LISTA_ENLAZADA_H
