#include "Cedula.h"
#include <stdexcept>
#include <iostream>
#include <conio.h> // Para getch()
#include <algorithm>

Cedula::Cedula() : numero("") {}

void Cedula::setNumero() {
    std::string num = ingresar("Ingrese cedula ecuatoriana (10 digitos)");
    if (num.size() != 10 || !std::all_of(num.begin(), num.end(), ::isdigit)) {
        throw std::invalid_argument("La cédula debe tener 10 dígitos numéricos.");
    }
    numero = num;
}

std::string Cedula::getNumero() const {
    return numero;
}

bool Cedula::validarCedula() const {
    std::string cedula = this->numero; // Obtener la cédula del objeto actual
    int verif[9], num, i;
    auto char2int = [](char c) { return (int)c - '0'; };

    if (cedula.length() != 10) {
        std::cout << "Longitud invalida. " << std::endl;
        return false;
    }
    
    for (i = 0; i <= 8; i++) {
        if (i % 2 == 0) {
            verif[i] = char2int(cedula.at(i)) * 2;
            if (verif[i] >= 10) {
                verif[i] = verif[i] - 9;
            }
        } else {
            verif[i] = char2int(cedula.at(i)) * 1;
            if (verif[i] >= 10) {
                verif[i] = verif[i] - 9;
            }
        }
    }

    int suma = 0;
    for (i = 0; i <= 8; i++) {
        suma = suma + verif[i];
    }

    num = 10 - (suma % 10);
    if (num == 10) num = 0; // Si el resultado es 10, el dígito verificador debe ser 0

    if (char2int(cedula.at(9)) == num) {
        std::cout << "Cedula valida." << std::endl;
        return true;
    } else {
        std::cout << "Error en el digito verificador" << std::endl;
        return false;
    }
}

std::string Cedula::ingresar(const std::string& msj) {
    char dato[25];
    char c;
    int i = 0;
    std::cout << msj << " : ";
    while ((c = getch()) != 13) { // 13 es el código ASCII de Enter
        if (c >= '0' && c <= '9') {
            dato[i++] = c;
            std::cout << c;
        }
    }
    dato[i] = '\0';
    std::cout << std::endl;
    return std::string(dato);
}
