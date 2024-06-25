#include <iostream>
#include "listaDoble.h"

int main() {
    ListaDoble lista;
    
    lista.insertarInicio(3);
    lista.insertarInicio(2);
    lista.insertarFinal(4);
    lista.insertarFinal(5);

    std::cout << "Lista Simple: ";
    lista.imprimirLista();

    return 0;
}
