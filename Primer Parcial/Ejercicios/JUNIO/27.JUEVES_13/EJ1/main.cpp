#include <iostream>
using namespace std;

struct Nodo {
    int valor;
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
        nuevoNodo->valor = valor;
        if (estaVacia()) {
            frente = final = nuevoNodo;
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
            frente = final = nullptr;
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
        return frente->valor;
    }

    int obtenerFinal() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return -1;
        }
        return final->valor;
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

    cout << "Elemento al frente: " << cola.obtenerFrente() << endl;
    cout << "Elemento al final: " << cola.obtenerFinal() << endl;

    cola.desencolar();
    cout << "Elemento al frente despues de desencolar: " << cola.obtenerFrente() << endl;
    cout << "Elemento al final despues de desencolar: " << cola.obtenerFinal() << endl;

    return 0;
}
