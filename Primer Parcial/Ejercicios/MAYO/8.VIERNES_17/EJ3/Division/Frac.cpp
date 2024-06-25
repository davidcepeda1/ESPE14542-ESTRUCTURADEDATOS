#include <iostream>
#include "Frac.h"

using namespace std;

void Frac::in() {
    cout << "Ingrese el numerador: ";
    cin >> a;
    cout << "Ingrese el denominador: ";
    cin >> b;
}

// Sobrecarga del operador *
Frac Frac::operator*(const Frac &obj) {
    Frac temporal;
    temporal.a = a * obj.a;
    temporal.b = b * obj.b;
    return temporal;
}
// Sobrecarga del operador /
Frac Frac::operator/(const Frac &obj) {
    Frac temporal;
    temporal.a = a * obj.b;
    temporal.b = b * obj.a;
    return temporal;
}

void Frac::out() {
    cout << "Resultado: " << a << "/" << b << endl;
}
