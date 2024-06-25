#include <iostream>
using namespace std;

struct Nodo {
    int dato;
    Nodo* siguiente;
};

class ColaCircular {
private:
    Nodo* frente;
    Nodo* final;

public:
    ColaCircular() : frente(nullptr), final(nullptr) {}

    ~ColaCircular() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(int valor) {
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->dato = valor;
        if (estaVacia()) {
            frente = nuevoNodo;
            final = nuevoNodo;
            nuevoNodo->siguiente = frente;
        } else {
            final->siguiente = nuevoNodo;
            final = nuevoNodo;
            final->siguiente = frente;
        }
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return;
        }
        Nodo* temp = frente;
        if (frente == final) {
            frente = nullptr;
            final = nullptr;
        } else {
            frente = frente->siguiente;
            final->siguiente = frente;
        }
        delete temp;
    }

    int obtenerFrente() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return -1;
        }
        return frente->dato;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaCircular cola;
    cola.encolar(10);
    cola.encolar(20);
    cola.encolar(30);

    cout << "El elemento del frente es: " << cola.obtenerFrente() << endl;

    cola.desencolar();
    cout << "El elemento del frente despues de desencolar es: " << cola.obtenerFrente() << endl;

    return 0;
}
