#include <iostream>
#include <string>
#include <functional>

using namespace std;

template <typename T>
T concatenar(T a, T b) {
    auto concat = [](T x, T y) { return x + y; };
    return concat(a, b);
}

int main() {
    string cadena1, cadena2;
    cout << "Introduce la primera cadena: ";
    cin >> cadena1;
    cout << "Introduce la segunda cadena: ";
    cin >> cadena2;

    string resultado = concatenar(cadena1, cadena2);
    cout << "La cadena concatenada es: " << resultado << endl;

    return 0;
}
