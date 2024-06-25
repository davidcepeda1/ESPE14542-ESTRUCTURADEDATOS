#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    Nodo* siguiente;
    Nodo* anterior;
};

class Deque {
private:
    Nodo* frente;
    Nodo* final;

public:
    Deque() : frente(nullptr), final(nullptr) {}

    ~Deque() {
        while (!estaVacia()) {
            desencolarFrente();
        }
    }

    void encolarFrente(int valor) {
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->valor = valor;
        nuevoNodo->siguiente = frente;
        nuevoNodo->anterior = nullptr;
        if (estaVacia()) {
            final = nuevoNodo;
        } else {
            frente->anterior = nuevoNodo;
        }
        frente = nuevoNodo;
    }

    void encolarFinal(int valor) {
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->valor = valor;
        nuevoNodo->siguiente = nullptr;
        nuevoNodo->anterior = final;
        if (estaVacia()) {
            frente = nuevoNodo;
        } else {
            final->siguiente = nuevoNodo;
        }
        final = nuevoNodo;
    }

    void desencolarFrente() {
        if (estaVacia()) {
            cout << "Deque vacio" << endl;
            return;
        }
        Nodo* temp = frente;
        frente = frente->siguiente;
        if (frente == nullptr) {
            final = nullptr;
        } else {
            frente->anterior = nullptr;
        }
        delete temp;
    }

    void desencolarFinal() {
        if (estaVacia()) {
            cout << "Deque vacio" << endl;
            return;
        }
        Nodo* temp = final;
        final = final->anterior;
        if (final == nullptr) {
            frente = nullptr;
        } else {
            final->siguiente = nullptr;
        }
        delete temp;
    }

    int obtenerFrente() {
        if (estaVacia()) {
            cout << "Deque vacio" << endl;
            return -1;
        }
        return frente->valor;
    }

    int obtenerFinal() {
        if (estaVacia()) {
            cout << "Deque vacio" << endl;
            return -1;
        }
        return final->valor;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    Deque deque;
    deque.encolarFrente(10);
    deque.encolarFinal(20);
    deque.encolarFrente(30);

    cout << "Elemento al frente: " << deque.obtenerFrente() << endl;
    cout << "Elemento al final: " << deque.obtenerFinal() << endl;

    deque.desencolarFrente();
    cout << "Elemento al frente despues de desencolar por el frente: " << deque.obtenerFrente() << endl;

    deque.desencolarFinal();
    cout << "Elemento al final despues de desencolar por el final: " << deque.obtenerFinal() << endl;

    return 0;
}
