#ifndef PERMUTACIONES_H
#define PERMUTACIONES_H

#include <vector>

class Permutaciones {
public:
    Permutaciones(const std::vector<int>& elementos);
    void generarPermutaciones();
    void imprimirPermutaciones();

private:
    std::vector<int> elementos;
    std::vector<std::vector<int>> permutaciones;
    void generarPermutacionesRec(std::vector<int>& actual, std::vector<bool>& usado);
};

#endif // PERMUTACIONES_H
