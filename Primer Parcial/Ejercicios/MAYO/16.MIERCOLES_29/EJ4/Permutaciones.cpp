#include "Permutaciones.h"
#include <iostream>

Permutaciones::Permutaciones(const std::vector<int>& elementos) {
    this->elementos = elementos;
}

void Permutaciones::generarPermutaciones() {
    std::vector<bool> usado(elementos.size(), false);
    std::vector<int> actual;

    generarPermutacionesRec(actual, usado);
}

void Permutaciones::generarPermutacionesRec(std::vector<int>& actual, std::vector<bool>& usado) {
    if (actual.size() == elementos.size()) {
        permutaciones.push_back(actual);
        return;
    }

    for (size_t i = 0; i < elementos.size(); ++i) {
        if (!usado[i]) {
            usado[i] = true;
            actual.push_back(elementos[i]);
            generarPermutacionesRec(actual, usado);
            actual.pop_back();
            usado[i] = false;
        }
    }
}

void Permutaciones::imprimirPermutaciones() {
    for (const auto& perm : permutaciones) {
        std::cout << "[ ";
        for (int num : perm) {
            std::cout << num << " ";
        }
        std::cout << "]" << std::endl;
    }
}
