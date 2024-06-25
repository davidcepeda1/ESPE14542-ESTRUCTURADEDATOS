#include <iostream>

// Plantilla de función para calcular la potencia de un número
template <typename T>
T potencia(T base, int exponente) {
    T resultado = 1;
    for (int i = 0; i < exponente; ++i) {
        resultado *= base;
    }
    return resultado;
}

int main() {
    // Declarar la base y el exponente como variables
    // Utilizar un tipo de dato específico (por ejemplo, double) para T
    double base;
    int exponente;

    // Pedir al usuario que ingrese la base
    std::cout << "Ingrese la base: ";
    std::cin >> base;

    // Pedir al usuario que ingrese el exponente (entero positivo)
    std::cout << "Ingrese el exponente (entero positivo): ";
    std::cin >> exponente;

    // Validar que el exponente sea un entero positivo
    if (exponente < 0) {
        std::cerr << "El exponente debe ser un entero positivo." << std::endl;
        return 1;  // Salir del programa con error
    }

    // Calcular y mostrar el resultado de la potencia
    std::cout << base << "^" << exponente << " = " << potencia(base, exponente) << std::endl;

    return 0;
}
