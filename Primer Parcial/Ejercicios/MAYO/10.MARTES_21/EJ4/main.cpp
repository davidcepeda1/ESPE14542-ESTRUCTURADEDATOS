#include <iostream>
#include <memory>
#include <functional>

using namespace std; 

template <typename T>
T calcularPromedio(T* array, size_t size) {
    T suma = 0;
    for (size_t i = 0; i < size; ++i)
        suma += array[i];
    return suma / size;
}

int main() {
    size_t size;
    cout << "Ingrese el tamano del array: ";
    cin >> size;

    auto array = std::make_unique<int[]>(size);
    cout << "Ingrese los elementos del array:\n";
    for (size_t i = 0; i < size; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> array[i];
    }

    auto promedio = calcularPromedio(array.get(), size);
    std::cout << "El promedio es: " << promedio << std::endl;

    return 0;
}
