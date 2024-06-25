#include "Cedula.h"
#include <stdexcept>
#include <algorithm>
#include <conio.h> // Para getch
#include <cstdlib> // Para malloc y free

Cedula::Cedula() : numero("") {}

void Cedula::setNumero(const std::string& num) {
    if (num.size() != 10 || !std::all_of(num.begin(), num.end(), ::isdigit)) {
        throw std::invalid_argument("La cédula debe tener 10 dígitos numéricos.");
    }
    numero = num;
}

std::string Cedula::getNumero() const {
    return numero;
}

void Cedula::ingresarCedula() {
    char dato[11]; // Espacio para 10 dígitos + terminador null
    char c;
    int i = 0;

    std::cout << "Ingrese cedula ecuatoriana (10 digitos): ";
    while (i < 10 && (c = getch()) != 13) {
        if (c >= '0' && c <= '9') {
            dato[i++] = c;
            std::cout << c;
        }
    }

    if (i == 10) {
        dato[i] = '\0';
        std::cout << std::endl;
        setNumero(dato);
    } else {
        std::cout << "\nError: Debe ingresar exactamente 10 dígitos.\n";
    }
}
