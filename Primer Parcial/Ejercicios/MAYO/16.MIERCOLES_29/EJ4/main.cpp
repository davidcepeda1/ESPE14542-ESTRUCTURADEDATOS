#include "Permutaciones.h"
#include <iostream>
#include <vector>

int main() {
    std::vector<int> elementos = {1, 2, 3};
    Permutaciones perm(elementos);
    
    std::cout << "Generando permutaciones de {1, 2, 3}:" << std::endl;
    perm.generarPermutaciones();
    perm.imprimirPermutaciones();

    return 0;
}
