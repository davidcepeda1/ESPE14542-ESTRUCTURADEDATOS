#include "Modulo.h"

int Modulo::calcularModulo(int a, int b) {
    if (b == 0) {
        return -1;
    }
    return a % b;
}
