#include <iostream>
#include <memory>
#include <algorithm>
#include <functional>

using namespace std;

template <typename T>
void ordenar(T* array, size_t size, function<bool(T, T)> criterio) {
    sort(array, array + size, criterio);
}

int main() {
    size_t size;
    cout << "Ingrese el tamano: ";
    cin >> size;

    auto array = std::make_unique<int[]>(size);
    cout << "Ingrese los elementos:\n";
    for (size_t i = 0; i < size; ++i) {
        cout << "Elemento " << i + 1 << ": ";
        cin >> array[i];
    }
       
    ordenar<int>(array.get(), size, [](int a, int b) { return a < b; });

    cout << "Elementos ordenados:\n";
    for (size_t i = 0; i < size; ++i) {
        cout << array[i] << ' ';
    }
    cout << std::endl;

    return 0;
}
