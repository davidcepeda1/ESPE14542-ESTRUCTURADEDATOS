#include "Potencia.h"
#include <iostream>

int main() {
    Potencia pot;
    double base;
    int exponente;

    std::cout << "Ingrese la base: ";
    std::cin >> base;
    std::cout << "Ingrese el exponente: ";
    std::cin >> exponente;

    double resultado = pot.calcular(base, exponente);
    std::cout << base << " elevado a " << exponente << " es " << resultado << std::endl;

    return 0;
}
