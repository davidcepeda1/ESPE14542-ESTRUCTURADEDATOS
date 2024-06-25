#include <iostream>
#include <functional>

using namespace std;

// Función recursiva para búsqueda binaria utilizando lambdas y templates
template <typename T>
int busquedaBinaria(T* arr, int inicio, int fin, T valor) {
    // Definir la lambda para la búsqueda binaria
    function<int(T*, int, int, T)> busquedaRecursiva = [&](T* arr, int inicio, int fin, T valor) -> int {
        if (inicio > fin) {
            return -1;
        }
        int medio = inicio + (fin - inicio) / 2;
        if (arr[medio] == valor) {
            return medio;
        }
        if (arr[medio] > valor) {
            return busquedaRecursiva(arr, inicio, medio - 1, valor);
        }
        return busquedaRecursiva(arr, medio + 1, fin, valor);
    };

    return busquedaRecursiva(arr, inicio, fin, valor);
}

int main() {
    int n;
    cout << "Introduce el numero de elementos: ";
    cin >> n;

    // Crear array dinámico
    int* arr = new int[n];
    cout << "Introduce los elementos (ordenados):\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int valor;
    cout << "Introduce el valor a buscar: ";
    cin >> valor;

    int resultado = busquedaBinaria(arr, 0, n - 1, valor);
    if (resultado != -1) {
        cout << "El valor se encuentra en el índice: " << resultado << endl;
    } else {
        cout << "El valor no se encuentra en el array." << endl;
    }

    // Liberar memoria dinámica
    delete[] arr;

    return 0;
}
