#include <iostream>
#include <stack>
using namespace std;

template<typename T>
struct Nodo {
    T dato;
    Nodo* siguiente;
};

template<typename T>
class Cola {
private:
    Nodo<T>* frente;
    Nodo<T>* final;

public:
    Cola() : frente(nullptr), final(nullptr) {}

    ~Cola() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>();
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
        Nodo<T>* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    T obtenerFrente() {
        if (estaVacia()) {
            throw runtime_error("Cola vacía");
        }
        return frente->dato;
    }

    bool estaVacia() {
        return frente == nullptr;
    }

    void revertir() {
        stack<T> pila;
        while (!estaVacia()) {
            pila.push(obtenerFrente());
            desencolar();
        }
        while (!pila.empty()) {
            encolar(pila.top());
            pila.pop();
        }
    }

    void mostrarCola() {
        Nodo<T>* temp = frente;
        while (temp) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }
};

int main() {
    Cola<int> cola;
    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);
    cola.encolar(4);

    cout << "Cola antes de revertir: ";
    cola.mostrarCola();

    cola.revertir();

    cout << "Cola despues de revertir: ";
    cola.mostrarCola();

    return 0;
}
