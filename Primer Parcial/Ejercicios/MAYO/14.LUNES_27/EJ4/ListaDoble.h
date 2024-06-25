#ifndef LISTA_DOBLE_CONCATENAR_H
#define LISTA_DOBLE_CONCATENAR_H

struct NodoDoble {
    int dato;
    NodoDoble* siguiente;
    NodoDoble* anterior;
};

class ListaDobleConcatenar {
public:
    ListaDobleConcatenar();
    ~ListaDobleConcatenar();
    void insertarInicio(int valor);
    void insertarFinal(int valor);
    void imprimirLista();
    void concatenar(ListaDobleConcatenar& otra);
private:
    NodoDoble* cabeza;
};

#endif // LISTA_DOBLE_CONCATENAR_H
