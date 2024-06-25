#include <iostream>
#include <functional>

using namespace std;

int main() {
    int n, valor;
    cout << "Introduce el numero de elementos: ";
    cin >> n;

    // Crear array dinámico
    int* arr = new int[n];
    cout << "Introduce los elementos:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Introduce el valor para comparar: ";
    cin >> valor;

    // Lambda para contar elementos mayores que un valor dado
    auto contar_mayores = [valor](int* arr, int size) {
        int count = 0;
        for (int i = 0; i < size; ++i) {
            if (arr[i] > valor) {
                ++count;
            }
        }
        return count;
    };

    int resultado = contar_mayores(arr, n);
    cout << "El numero de elementos mayores que " << valor << " es: " << resultado << endl;

    // Liberar memoria dinámica
    delete[] arr;

    return 0;
}
