#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int aplicarOperacion(int a, int b, char operador) {
    switch (operador) {
        case '+': return a + b;
        case '-': return a - b;
        case '*': return a * b;
        case '/': return a / b; // Suponiendo división entera para simplicidad
        default: return 0;
    }
}

int evaluarExpresion(const string& expresion) {
    stack<int> pila;

    for (int i = 0; i < expresion.length(); ++i) {
        if (isdigit(expresion[i])) {
            int numero = 0;
            while (i < expresion.length() && isdigit(expresion[i])) {
                numero = numero * 10 + (expresion[i] - '0');
                ++i;
            }
            --i; // Retrocedemos el índice una posición
            pila.push(numero);
        } else if (esOperador(expresion[i])) {
            int b = pila.top();
            pila.pop();
            int a = pila.top();
            pila.pop();
            int resultado = aplicarOperacion(a, b, expresion[i]);
            pila.push(resultado);
        }
    }

    return pila.top();
}

int main() {
    string expresion = "3*4+5-2/1";
    int resultado = evaluarExpresion(expresion);
    cout << "Resultado de la expresion '" << expresion << "' es: " << resultado << endl;

    return 0;
}
