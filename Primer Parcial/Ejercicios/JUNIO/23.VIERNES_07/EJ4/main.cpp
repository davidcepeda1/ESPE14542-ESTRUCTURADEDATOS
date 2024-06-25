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
            return;
        }
        Nodo* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    bool estaVacia() {
        return frente == nullptr;
    }

    int contarElementos() {
        return contarElementosRecursivo(frente);
    }

private:
    int contarElementosRecursivo(Nodo* nodo) {
        if (nodo == nullptr) {
            return 0;
        }
        return 1 + contarElementosRecursivo(nodo->siguiente);
    }
};

int main() {
    Cola cola;
    cola.encolar(10);
    cola.encolar(20);
    cola.encolar(30);

    cout << "Numero de elementos en la cola: " << cola.contarElementos() << endl;

    return 0;
}
