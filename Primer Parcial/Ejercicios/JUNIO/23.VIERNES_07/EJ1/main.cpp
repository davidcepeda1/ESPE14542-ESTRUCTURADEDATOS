#include <iostream>
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
            cout << "Cola vacía" << endl;
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
            cout << "Cola vacía" << endl;
            return -1;
        }
        return frente->dato;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    Cola cola;
    cola.encolar(10);
    cola.encolar(20);
    cola.encolar(30);

    cout << "El elemento del frente es: " << cola.obtenerFrente() << endl;

    cola.desencolar();
    cout << "El elemento del frente despues de desencolar es: " << cola.obtenerFrente() << endl;

    return 0;
}
