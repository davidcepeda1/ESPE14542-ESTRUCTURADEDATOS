#include <iostream>

using namespace std;

int longitudCadena(const char* str) {
    if (*str == '\0') {
        return 0;
    }
    return 1 + longitudCadena(str + 1);
}

int main() {
    char str[100];
    cout << "Introduce una cadena: ";
    cin >> str;

    int longitud = longitudCadena(str);
    cout << "La longitud de la cadena es: " << longitud << endl;

    return 0;
}