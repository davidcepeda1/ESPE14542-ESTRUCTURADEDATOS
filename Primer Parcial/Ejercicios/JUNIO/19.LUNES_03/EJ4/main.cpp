#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

int prioridad(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

string infijoAPostfijo(const string& infijo) {
    stack<char> *pila = new stack<char>;
    string postfijo;
    for (char c : infijo) {
        if (isalnum(c)) {
            postfijo += c;
        }
        else if (c == '(') {
            pila->push(c);
        }
        else if (c == ')') {
            while (!pila->empty() && pila->top() != '(') {
                postfijo += pila->top();
                pila->pop();
            }
            if (!pila->empty() && pila->top() == '(') {
                pila->pop();
            }
        }
        else {
            while (!pila->empty() && prioridad(pila->top()) >= prioridad(c)) {
                postfijo += pila->top();
                pila->pop();
            }
            pila->push(c);
        }
    }
    while (!pila->empty()) {
        postfijo += pila->top();
        pila->pop();
    }
    delete pila;
    return postfijo;
}

int main() {
    string infijo = "a+b*(c^d-e)^(f+g*h)-i";
    cout << "Expresion postfija: " << infijoAPostfijo(infijo) << endl;
    return 0;
}
