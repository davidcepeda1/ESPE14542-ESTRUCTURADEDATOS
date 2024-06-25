#include <iostream>
#include "ListaEnlazada.h"

int main() {
    ListaEnlazada<int> lista;

    // Insertar elementos en la lista
    lista.insertar(10);
    lista.insertar(20);
    lista.insertar(30);
    lista.insertar(40);

    // Recorrer e imprimir la lista usando una función lambda
    lista.recorrer([](int dato) {
        std::cout << dato << " ";
    });
    std::cout << std::endl;

    // Imprimir la lista en orden inverso usando recursión
    lista.imprimirInverso();

    return 0;
}
