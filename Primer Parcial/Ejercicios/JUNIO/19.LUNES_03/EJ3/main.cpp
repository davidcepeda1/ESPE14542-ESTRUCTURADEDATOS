#include <iostream>
#include <stack>
using namespace std;

bool estanBalanceados(string expr) {
    stack<char> *pila = new stack<char>;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            pila->push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (pila->empty())
                return false;
            char tope = pila->top();
            if ((c == ')' && tope == '(') ||
                (c == '}' && tope == '{') ||
                (c == ']' && tope == '[')) {
                pila->pop();
            } else {
                return false;
            }
        }
    }
    bool balanceados = pila->empty();
    delete pila;
    return balanceados;
}

int main() {
    string expr = "{[(a+b)*(c+d)]}";
    if (estanBalanceados(expr)) {
        cout << "Los parentesis estan balanceados\n";
    } else {
        cout << "Los parentesis no estan balanceados\n";
    }
    return 0;
}
