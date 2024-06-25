#include "Matriz.h"
#include <iostream>

int main() {
    int filasA, colsA, filasB, colsB;

    std::cout << "Ingrese el numero de filas de la matriz A: ";
    std::cin >> filasA;
    std::cout << "Ingrese el numero de columnas de la matriz A (y filas de la matriz B): ";
    std::cin >> colsA;
    std::cout << "Ingrese el numero de columnas de la matriz B: ";
    std::cin >> colsB;

    filasB = colsA; // Para que la multiplicación sea válida

    int** matrizA = new int*[filasA];
    for (int i = 0; i < filasA; ++i) {
        matrizA[i] = new int[colsA];
    }

    int** matrizB = new int*[filasB];
    for (int i = 0; i < filasB; ++i) {
        matrizB[i] = new int[colsB];
    }

    std::cout << "Ingrese los elementos de la matriz A:" << std::endl;
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            std::cin >> matrizA[i][j];
        }
    }

    std::cout << "Ingrese los elementos de la matriz B:" << std::endl;
    for (int i = 0; i < filasB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            std::cin >> matrizB[i][j];
        }
    }

    MultiplicacionMatrices mult(filasA, colsA, filasB, colsB);
    mult.inicializarMatrizA(matrizA);
    mult.inicializarMatrizB(matrizB);

    std::cout << "El resultado de la multiplicación de matrices es:" << std::endl;
    mult.multiplicar();
    mult.imprimirResultado();

    for (int i = 0; i < filasA; ++i) {
        delete[] matrizA[i];
    }
    delete[] matrizA;

    for (int i = 0; i < filasB; ++i) {
        delete[] matrizB[i];
    }
    delete[] matrizB;

    return 0;
}
