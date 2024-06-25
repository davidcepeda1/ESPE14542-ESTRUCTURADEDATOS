#include "Fibonacci.h"

// Constructor
Fibonacci::Fibonacci() {
    resultado = new long long;
}

// Destructor
Fibonacci::~Fibonacci() {
    delete resultado;
}

// Método recursivo para calcular el n-ésimo número de Fibonacci
long long Fibonacci::calcular(int n) {
    if (n <= 1) {
        *resultado = n;
    } else {
        *resultado = calcular(n - 1) + calcular(n - 2);
    }
    return *resultado;
}
