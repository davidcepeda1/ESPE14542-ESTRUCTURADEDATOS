#include <iostream>
#include "ListaCircularDoble.h"

// Función estática para el recorrido dinámico
template<typename T>
void recorridoDinamico(T dato) {
    std::cout << dato << " ";
}

// Definimos un tipo de puntero a función para el recorrido dinámico
template<typename T>
using FuncionRecorrido = void (*)(T);


int main() {
    ListaCircularDoble<int> lista;

    // Insertar elementos en la lista
    lista.insertar(10);
    lista.insertar(20);
    lista.insertar(30);
    lista.insertar(40);

    // Definimos una función de recorrido dinámica
    FuncionRecorrido<int> recorrido = recorridoDinamico<int>;

    // Recorrer e imprimir la lista usando la función de recorrido dinámica
    lista.recorrer(recorrido);
    std::cout << std::endl;

    // Imprimir la lista en orden inverso usando recursión
    lista.imprimirInverso();

    std::cout << "Before deletion:" << std::endl;
    lista.recorrer([](int dato) {
        std::cout << dato << " ";
    });
    
    lista.eliminar(20); // Remove the element with value 20
    
    std::cout << "\nAfter deletion:" << std::endl;
    lista.recorrer([](int dato) {
        std::cout << dato << " ";
    });
    
    return 0;
}
