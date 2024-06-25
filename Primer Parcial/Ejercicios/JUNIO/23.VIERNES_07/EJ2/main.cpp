#include <iostream>
#include <stack>
using namespace std;

struct Nodo {
    int dato;
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

    void encolar(int valor) {
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

    int obtenerFrente() {
        if (estaVacia()) {
            return -1;
        }
        return frente->dato;
    }

    bool estaVacia() {
        return frente == nullptr;
    }

    void invertir() {
        stack<int> pilaAux;
        while (!estaVacia()) {
            pilaAux.push(obtenerFrente());
            desencolar();
        }
        while (!pilaAux.empty()) {
            encolar(pilaAux.top());
            pilaAux.pop();
        }
    }
};

int main() {
    Cola cola;
    cola.encolar(10);
    cola.encolar(20);
    cola.encolar(30);

    cout << "Cola original: ";
    while (!cola.estaVacia()) {
        cout << cola.obtenerFrente() << " ";
        cola.desencolar();
    }
    cout << endl;

    cola.encolar(10);
    cola.encolar(20);
    cola.encolar(30);
    cola.invertir();

    cout << "Cola invertida: ";
    while (!cola.estaVacia()) {
        cout << cola.obtenerFrente() << " ";
        cola.desencolar();
    }
    cout << endl;

    return 0;
}
