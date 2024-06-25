#include <iostream>

using namespace std;

// Función recursiva para calcular el factorial
void factorial(int n, int* resultado) {
    if (n == 0 || n == 1) {
        *resultado = 1;
        return;
    }
    int temp;
    factorial(n - 1, &temp);
    *resultado = n * temp;
}

int main() {
    int n;
    cout << "Introduce un numero: ";
    cin >> n;

    int* resultado = new int;
    factorial(n, resultado);
    cout << "El factorial de " << n << " es: " << *resultado << endl;

    // Liberar memoria dinámica
    delete resultado;

    return 0;
}
