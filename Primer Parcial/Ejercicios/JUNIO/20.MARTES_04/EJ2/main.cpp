#include <iostream>
#include <stack>
using namespace std;

string postfijoAInfijo(const string& postfijo) {
    stack<string> *pila = new stack<string>;
    for (char c : postfijo) {
        if (isalnum(c)) {
            pila->push(string(1, c));
        } else {
            string op1 = pila->top(); pila->pop();
            string op2 = pila->top(); pila->pop();
            string expr = "(" + op2 + c + op1 + ")";
            pila->push(expr);
        }
    }
    string resultado = pila->top();
    delete pila;
    return resultado;
}

int main() {
    string postfijo = "ab+c*d-e^fgh*+^i-";
    cout << "Expresion infija: " << postfijoAInfijo(postfijo) << endl;
    return 0;
}
