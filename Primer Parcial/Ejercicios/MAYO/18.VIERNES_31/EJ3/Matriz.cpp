#include "Matriz.h"
#include <iostream>

// Constructor
MultiplicacionMatrices::MultiplicacionMatrices(int filasA, int colsA, int filasB, int colsB) {
    this->filasA = filasA;
    this->colsA = colsA;
    this->filasB = filasB;
    this->colsB = colsB;

    matrizA = new int*[filasA];
    for (int i = 0; i < filasA; ++i) {
        matrizA[i] = new int[colsA];
    }

    matrizB = new int*[filasB];
    for (int i = 0; i < filasB; ++i) {
        matrizB[i] = new int[colsB];
    }

    resultado = new int*[filasA];
    for (int i = 0; i < filasA; ++i) {
        resultado[i] = new int[colsB];
        for (int j = 0; j < colsB; ++j) {
            resultado[i][j] = 0;
        }
    }
}

// Destructor
MultiplicacionMatrices::~MultiplicacionMatrices() {
    for (int i = 0; i < filasA; ++i) {
        delete[] matrizA[i];
        delete[] resultado[i];
    }
    delete[] matrizA;
    delete[] resultado;

    for (int i = 0; i < filasB; ++i) {
        delete[] matrizB[i];
    }
    delete[] matrizB;
}

// Inicializa la matriz A
void MultiplicacionMatrices::inicializarMatrizA(int** matriz) {
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < colsA; ++j) {
            matrizA[i][j] = matriz[i][j];
        }
    }
}

// Inicializa la matriz B
void MultiplicacionMatrices::inicializarMatrizB(int** matriz) {
    for (int i = 0; i < filasB; ++i) {
        for (int j = 0; j < colsB; ++j) {
            matrizB[i][j] = matriz[i][j];
        }
    }
}

// Método para multiplicar las matrices utilizando recursión
int** MultiplicacionMatrices::multiplicar() {
    multiplicarRecursivo(0, 0, 0);
    return resultado;
}

// Método recursivo para multiplicar las matrices
void MultiplicacionMatrices::multiplicarRecursivo(int i, int j, int k) {
    if (i < filasA) {
        if (j < colsB) {
            if (k < colsA) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
                multiplicarRecursivo(i, j, k + 1);
            } else {
                multiplicarRecursivo(i, j + 1, 0);
            }
        } else {
            multiplicarRecursivo(i + 1, 0, 0);
        }
    }
}

// Método para imprimir el resultado de la multiplicación
void MultiplicacionMatrices::imprimirResultado() {
    for (int i = 0; i < filasA; ++i) {
        for (int j = 0; j < colsB; ++j) {
            std::cout << resultado[i][j] << " ";
        }
        std::cout << std::endl;
    }
}
