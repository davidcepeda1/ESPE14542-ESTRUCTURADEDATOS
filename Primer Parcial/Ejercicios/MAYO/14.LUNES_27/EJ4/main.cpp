#include <iostream>
#include "listaDoble.h"

int main(){
    ListaDobleConcatenar lista1;
    ListaDobleConcatenar lista2;

    lista1.insertarInicio(3);
    lista1.insertarInicio(2);
    lista2.insertarFinal(4);
    lista2.insertarFinal(5);

    std::cout << "Lista Doble 1: ";
    lista1.imprimirLista();
    std::cout << "Lista Doble 2: ";
}