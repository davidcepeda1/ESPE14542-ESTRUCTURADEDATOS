#include <iostream>
#include "listaSimple.h"

int main() {
    ListaSimpleEliminar lista;
    
    lista.insertarInicio(3);
    lista.insertarInicio(2);
    lista.insertarFinal(4);
    lista.insertarFinal(5);

    std::cout << "Lista Simple: ";
    lista.imprimirLista();
    
    lista.eliminar(3);
    std::cout << "Lista Simple después de eliminar 3: ";
    lista.imprimirLista();

    return 0;
}
