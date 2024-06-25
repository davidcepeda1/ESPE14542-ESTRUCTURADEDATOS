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

    int encontrarMaximo() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return -1;
        }
        return encontrarMaximoRecursivo(frente, frente->dato);
    }

private:
    int encontrarMaximoRecursivo(Nodo* nodo, int maximo) {
        if (nodo == nullptr) {
            return maximo;
        }
        if (nodo->dato > maximo) {
            maximo = nodo->dato;
        }
        return encontrarMaximoRecursivo(nodo->siguiente, maximo);
    }
};

int main() {
    Cola cola;
    cola.encolar(10);
    cola.encolar(20);
    cola.encolar(30);

    cout << "El valor maximo en la cola es: " << cola.encontrarMaximo() << endl;

    return 0;
}
