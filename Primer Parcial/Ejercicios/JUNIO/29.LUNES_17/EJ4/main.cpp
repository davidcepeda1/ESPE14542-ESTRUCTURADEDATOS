#include <iostream>
#include <stack>
#include <cctype>
#include <string>
#include <map>
using namespace std;

int prioridadOperador(char operador) {
    if (operador == '+' || operador == '-') {
        return 1;
    } else if (operador == '*' || operador == '/') {
        return 2;
    }
    return 0;
}

int evaluarExpresion(const string& expresion) {
    stack<int> valores;
    stack<char> operadores;

    map<char, int> precedencia;
    precedencia['+'] = 1;
    precedencia['-'] = 1;
    precedencia['*'] = 2;
    precedencia['/'] = 2;

    for (size_t i = 0; i < expresion.size(); ++i) {
        if (isdigit(expresion[i])) {
            int numero = 0;
            while (i < expresion.size() && isdigit(expresion[i])) {
                numero = numero * 10 + (expresion[i] - '0');
                ++i;
            }
            --i; // Retrocedemos el índice una posición
            valores.push(numero);
        } else if (expresion[i] == '(') {
            operadores.push('(');
        } else if (expresion[i] == ')') {
            while (!operadores.empty() && operadores.top() != '(') {
                char operador = operadores.top();
                operadores.pop();
                int a = valores.top();
                valores.pop();
                int b = valores.top();
                valores.pop();
                switch (operador) {
                    case '+': valores.push(b + a); break;
                    case '-': valores.push(b - a); break;
                    case '*': valores.push(b * a); break;
                    case '/': valores.push(b / a); break;
                }
            }
            operadores.pop(); // Eliminamos el '(' de la pila de operadores
        } else if (expresion[i] == '+' || expresion[i] == '-' || expresion[i] == '*' || expresion[i] == '/') {
            while (!operadores.empty() && precedencia[operadores.top()] >= precedencia[expresion[i]]) {
                char operador = operadores.top();
                operadores.pop();
                int a = valores.top();
                valores.pop();
                int b = valores.top();
                valores.pop();
                switch (operador) {
                    case '+': valores.push(b + a); break;
                    case '-': valores.push(b - a); break;
                    case '*': valores.push(b * a); break;
                    case '/': valores.push(b / a); break;
                }
            }
            operadores.push(expresion[i]);
        }
    }

    while (!operadores.empty()) {
        char operador = operadores.top();
        operadores.pop();
        int a = valores.top();
        valores.pop();
        int b = valores.top();
        valores.pop();
        switch (operador) {
            case '+': valores.push(b + a); break;
            case '-': valores.push(b - a); break;
            case '*': valores.push(b * a); break;
            case '/': valores.push(b / a); break;
        }
    }

    return valores.top();
}

int main() {
    string expresion = "3 + 4 * (2 - 1)";
    int resultado = evaluarExpresion(expresion);
    cout << "Resultado de la expresion '" << expresion << "' es: " << resultado << endl;

    return 0;
}
