#include <iostream>
#include "calculadora.h"
#include "Modulo.h"

using namespace std;

int main() {
    Calculadora* calculadora = new Modulo();

    int a, b;

    cout << "Ingrese el primer numero: ";
    cin >> a;

    cout << "Ingrese el segundo numero: ";
    cin >> b;

    int resultado = calculadora->calcularModulo(a, b);
    cout << "El modulo es: " << resultado << std::endl;

    delete calculadora;

    return 0;
}
