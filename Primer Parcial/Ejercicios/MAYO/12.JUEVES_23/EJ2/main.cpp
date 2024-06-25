#include <iostream>
#include <vector>
#include <functional>

using namespace std;

int main() {
    int n;
    cout << "Introduce el número de elementos: ";
    cin >> n;

    // Crear vector dinámico
    vector<int> vec(n);
    cout << "Introduce los elementos:\n";
    for (int i = 0; i < n; ++i) {
        cout<<"Elemento "<<i+1<<": ";
        cin >> vec[i];
    }

    // Lambda para calcular el promedio de los elementos
    auto promedio = [](vector<int>& vec) {
        int sum = 0;
        for (int x : vec) {
            sum += x;
        }
        return static_cast<double>(sum) / vec.size();
    };

    double resultado = promedio(vec);
    cout << "El promedio de los elementos es: " << resultado << endl;

    return 0;
}
