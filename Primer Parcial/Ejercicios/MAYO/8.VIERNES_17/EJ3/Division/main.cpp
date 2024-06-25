#include <iostream>
#include "Frac.h"

using namespace std;

int main() {
    Frac F1, F2, result;
    char operation;

    system("cls");

    cout << "Ingresar la primera fraccion: " << endl;
    F1.in();

    cout << "Ingresar la segunda fraccion: " << endl;
    F2.in();

    cout << "Ingrese la operación (* o /): ";
    cin >> operation;

    if (operation == '*') {
        result = F1 * F2;
    } else if (operation == '/') {
        result = F1 / F2;
    } else {
        cout << "Operación no válida." << endl;
        return 1;
    }

    result.out();

    return 0;
}
