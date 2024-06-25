#include "TorresHanoi.h"
#include <iostream>

int main() {
    int numDiscos;
    std::cout << "Ingrese el numero de discos: ";
    std::cin >> numDiscos;

    TorresHanoi hanoi(numDiscos);
    std::cout << "Solucion de Torres de Hanoi para " << numDiscos << " discos:" << std::endl;
    hanoi.resolver();

    return 0;
}
