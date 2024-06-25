#include <iostream>
#include <string>

using namespace std;

int main() {
    int a, b, c;
    cout << "Ingresa los tres lados del triangulo (separados por espacios): ";
    cin >> a >> b >> c;

    auto classifyTriangle = [](int x, int y, int z) {
        if (x <= 0 || y <= 0 || z <= 0) return "Lados invalidos.";
        
        switch ((x == y) + (y == z) + (x == z)) {
            case 3:
                return "El triangulo es equilatero.";
            case 1:
                return "El triangulo es isosceles.";
            default:
                return "El triangulo es escaleno.";
        }
    };

    string result = classifyTriangle(a, b, c);
    cout << result << endl;

    return 0;
}
