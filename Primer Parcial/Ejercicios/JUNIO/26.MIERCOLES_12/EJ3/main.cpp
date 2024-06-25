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

    void invertirCola() {
        if (estaVacia()) {
            return;
        }
        stack<char> pila;
        while (!estaVacia()) {
            pila.push(obtenerFrente());
            desencolar();
        }
        while (!pila.empty()) {
            encolar(pila.top());
            pila.pop();
        }
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

int main() {
    Cola cola;
    cola.encolar('A');
    cola.encolar('B');
    cola.encolar('C');

    cout << "Cola original: ";
    while (!cola.estaVacia()) {
        cout << cola.obtenerFrente() << " ";
        cola.desencolar();
    }
    cout << endl;

    cola.encolar('A');
    cola.encolar('B');
    cola.encolar('C');
    cola.invertirCola();

    cout << "Cola invertida: ";
    while (!cola.estaVacia()) {
        cout << cola.obtenerFrente() << " ";
        cola.desencolar();
    }
    cout << endl;

    return 0;
}
