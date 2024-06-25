#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T, typename Func>
void aplicarOperacion(vector<T>& vec, Func func) {
    // Utilizamos la función transform para aplicar la función Lambda a cada elemento del vector
    transform(vec.begin(), vec.end(), vec.begin(), func);
}
   
int main() {
    // Creamos un vector de enteros
    vector<int> numeros = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Definimos una función Lambda que multiplica cada número por 2
    auto funcionDoble = [](int x) { return x * 2; };

    // Definimos una función Lambda que multiplica cada número por 3
    auto funcionTriple = [](int x) { return x * 3; };

    // Aplicamos nuestro template aplicarOperacion con la función Lambda como argumento
    aplicarOperacion(numeros, funcionDoble);
    // Imprimimos el vector resultante
    cout << "Tabla del 2: ";
    for (const auto& num : numeros) {
        cout << num << " ";
    }
    cout <<endl;

    aplicarOperacion(numeros, funcionTriple);

    // Imprimimos el vector resultante
    cout << "Tabla del 3: ";
    for (const auto& num : numeros) {
        cout << num << " ";
    }
    cout <<endl;
    return 0;
}
