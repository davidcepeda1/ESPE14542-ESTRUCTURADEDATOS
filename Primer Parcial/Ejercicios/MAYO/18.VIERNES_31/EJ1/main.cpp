#include "ListaEnlazada.h"
#include <iostream>

int main() {
    ListaEnlazada lista;
    int n, valor;

    std::cout << "Ingrese el numero de elementos de la lista: ";
    std::cin >> n;

    std::cout << "Ingrese los elementos de la lista:" << std::endl;
    for (int i = 0; i < n; ++i) {
        std::cin >> valor;
        lista.insertar(valor);
    }

    std::cout << "Lista original: ";
    lista.imprimir();

    lista.invertir();

    std::cout << "Lista invertida: ";
    lista.imprimir();

    return 0;
}
