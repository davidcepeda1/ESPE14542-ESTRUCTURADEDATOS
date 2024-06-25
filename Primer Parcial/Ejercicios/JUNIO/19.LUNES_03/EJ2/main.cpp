#include <iostream>
#include <stack>
using namespace std;

void invertirCadena(string &cadena) {
    stack<char> *pila = new stack<char>;
    for (char c : cadena) {
        pila->push(c);
    }

    for (int i = 0; i < cadena.length(); i++) {
        cadena[i] = pila->top();
        pila->pop();
    }
    delete pila;
}

int main() {
    string cadena = "Estructura de Datos";
    invertirCadena(cadena);
    cout << "Cadena invertida: " << cadena << endl;
    return 0;
}
