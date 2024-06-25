#include <iostream>
#include <stack>
using namespace std;

bool esOperador(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}

bool esValida(string expr) {
    stack<char> *pila = new stack<char>;
    bool ultimoFueOperador = true; // El inicio no puede ser un operador
    for (char c : expr) {
        if (isalnum(c)) {
            ultimoFueOperador = false;
        } else if (esOperador(c)) {
            if (ultimoFueOperador) return false; // Dos operadores seguidos no son válidos
            ultimoFueOperador = true;
        } else if (c == '(') {
            pila->push(c);
            ultimoFueOperador = true;
        } else if (c == ')') {
            if (pila->empty() || ultimoFueOperador) return false;
            pila->pop();
            ultimoFueOperador = false;
        } else {
            return false; // Carácter no válido
        }
    }
    bool resultado = pila->empty() && !ultimoFueOperador;
    delete pila;
    return resultado;
}

int main() {
    string expr = "(a+b)*c-(d+e)";
    cout << "La expresion \"" << expr << "\" es ";
    if (esValida(expr)) cout << "valida." << endl;
    else cout << "invalida." << endl;
    return 0;
}
