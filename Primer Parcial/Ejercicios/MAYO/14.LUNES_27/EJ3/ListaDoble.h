#ifndef LISTA_DOBLE_H
#define LISTA_DOBLE_H

struct NodoDoble {
    int dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;
};

class ListaDoble {
public:
    ListaDoble();
    ~ListaDoble();
    void insertarInicio(int valor);
    void insertarFinal(int valor);
    void imprimirLista();
    void imprimirListaReversa();
private:
    NodoDoble* cabeza;
};

#endif // LISTA_DOBLE_H
