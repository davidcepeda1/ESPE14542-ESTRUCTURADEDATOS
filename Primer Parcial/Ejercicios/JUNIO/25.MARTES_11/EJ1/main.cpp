#include <iostream>
#include <stack>
using namespace std;

struct Nodo {
    char dato;
    Nodo* siguiente;
};

class Cola {
private:
    Nodo* frente;
    Nodo* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    ~Cola() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(char valor) {
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->dato = valor;
        nuevoNodo->siguiente = nullptr;
        if (final) {
            final->siguiente = nuevoNodo;
        } else {
            frente = nuevoNodo;
        }
        final = nuevoNodo;
    }

    void desencolar() {
        if (estaVacia()) {
            return;
        }
        Nodo* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    char obtenerFrente() {
        if (estaVacia()) {
            return '\0';
        }
        return frente->dato;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

bool esPalindromo(const string& cadena) {
    Cola cola;
    stack<char> pila;

    for (char c : cadena) {
        if (isalnum(c)) {
            char charLower = tolower(c);
            cola.encolar(charLower);
            pila.push(charLower);
        }
    }

    while (!cola.estaVacia()) {
        if (cola.obtenerFrente() != pila.top()) {
            return false;
        }
        cola.desencolar();
        pila.pop();
    }
    return true;
}

int main() {
    string cadena;
    cout << "Introduce una cadena: ";
    cin >> cadena;

    if (esPalindromo(cadena)) {
        cout << "La cadena es un palindromo." << endl;
    } else {
        cout << "La cadena no es un palindromo." << endl;
    }

    return 0;
}
