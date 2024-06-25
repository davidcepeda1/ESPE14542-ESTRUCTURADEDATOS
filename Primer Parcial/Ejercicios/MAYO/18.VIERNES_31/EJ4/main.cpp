#include "Fibonacci.h"
#include <iostream>

int main() {
    Fibonacci fib;
    int numero;

    std::cout << "Ingrese un numero para calcular el n-esimo numero de Fibonacci: ";
    std::cin >> numero;

    long long resultado = fib.calcular(numero);
    std::cout << "El " << numero << "-esimo numero de Fibonacci es " << resultado << std::endl;

    return 0;
}
