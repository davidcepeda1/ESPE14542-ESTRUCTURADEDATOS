#include <iostream>
#include <cmath>

using namespace std;

bool esPalindromo(int numero, int divisor) {
    if (numero == 0) {
        return true;
    }
    int primerDigito = numero / divisor;
    int ultimoDigito = numero % 10;
    if (primerDigito != ultimoDigito) {
        return false;
    }
    return esPalindromo((numero % divisor) / 10, divisor / 100);
}

int main() {
    int numero;
    cout << "Introduce un numero: ";
    cin >> numero;

    if (numero < 0) {
        cout << "Introduce un numero positivo." << endl;
        return 1;
    }

    int divisor = pow(10, (int)log10(numero));

    bool resultado = esPalindromo(numero, divisor);
    if (resultado) {
        cout << "El número es palindromo." << endl;
    } else {
        cout << "El número no es palindromo." << endl;
    }

    return 0;
}
