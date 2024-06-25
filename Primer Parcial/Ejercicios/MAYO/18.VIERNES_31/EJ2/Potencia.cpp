#include "Potencia.h"

// Constructor
Potencia::Potencia() {
    resultado = new double;
}

// Destructor
Potencia::~Potencia() {
    delete resultado;
}

// Método recursivo para calcular la potencia
double Potencia::calcular(double base, int exponente) {
    if (exponente == 0) {
        *resultado = 1;
    } else if (exponente > 0) {
        *resultado = base * calcular(base, exponente - 1);
    } else {
        *resultado = 1 / calcular(base, -exponente);
    }
    return *resultado;
}
