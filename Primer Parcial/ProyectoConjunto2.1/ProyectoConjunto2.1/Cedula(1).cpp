#include "Cedula.h"
#include <stdexcept>

Cedula::Cedula() : numero("") {}

bool Cedula::validarCedula(const std::string& cedula) {
    // Validar que la cédula tenga 10 dígitos
    if (cedula.length() != 10) {
        return false;
    }

    // Verificar que todos los caracteres sean dígitos
    for (char c : cedula) {
        if (!isdigit(c)) {
            return false;
        }
    }

    // Algoritmo para verificar la validez de la cédula ecuatoriana
    int coeficientes[] = {2, 1, 2, 1, 2, 1, 2, 1, 2};
    int suma = 0;
    int digitoVerificador = std::stoi(cedula.substr(9, 1));

    for (int i = 0; i < 9; ++i) {
        int valor = (cedula[i] - '0') * coeficientes[i];
        if (valor >= 10) {
            valor -= 9;
        }
        suma += valor;
    }

    int residuo = suma % 10;
    int resultado;
    if (residuo == 0) {
        resultado = 0;
    } else {
        resultado = 10 - residuo;
    }

    return resultado == digitoVerificador;
}

void Cedula::setNumero(const std::string& num) {
    if (!validarCedula(num)) {
        throw std::invalid_argument("La cédula ingresada no es válida.");
    }
    numero = num;
}

std::string Cedula::getNumero() const {
    return numero;
}
