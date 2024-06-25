#include "TorresHanoi.h"
#include <iostream>

// Constructor: inicializa el número de discos
TorresHanoi::TorresHanoi(int numDiscos) {
    this->numDiscos = numDiscos;
}

// Función recursiva para mover los discos
void TorresHanoi::moverDisco(int n, char origen, char destino, char auxiliar) {
    if (n == 1) {
        std::cout << "Mover disco 1 desde " << origen << " a " << destino << std::endl;
        return;
    }
    // Mover n-1 discos de origen a auxiliar, usando destino como auxiliar
    moverDisco(n - 1, origen, auxiliar, destino);
    // Mover disco n de origen a destino
    std::cout << "Mover disco " << n << " desde " << origen << " a " << destino << std::endl;
    // Mover n-1 discos de auxiliar a destino, usando origen como auxiliar
    moverDisco(n - 1, auxiliar, destino, origen);
}

// Función para resolver el problema de Torres de Hanoi
void TorresHanoi::resolver() {
    moverDisco(numDiscos, 'A', 'C', 'B');
}
