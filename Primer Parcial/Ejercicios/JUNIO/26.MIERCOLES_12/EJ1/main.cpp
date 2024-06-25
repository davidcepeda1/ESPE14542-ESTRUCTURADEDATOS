#include <iostream>
using namespace std;

struct Nodo {
    int valor;
    int prioridad;
    Nodo* siguiente;
};

class ColaPrioridad {
private:
    Nodo* frente;

public:
    ColaPrioridad() : frente(nullptr) {}

    ~ColaPrioridad() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(int valor, int prioridad) {
        Nodo* nuevoNodo = new Nodo();
        nuevoNodo->valor = valor;
        nuevoNodo->prioridad = prioridad;
        nuevoNodo->siguiente = nullptr;

        if (estaVacia() || frente->prioridad > prioridad) {
            nuevoNodo->siguiente = frente;
            frente = nuevoNodo;
        } else {
            Nodo* temp = frente;
            while (temp->siguiente != nullptr && temp->siguiente->prioridad <= prioridad) {
                temp = temp->siguiente;
            }
            nuevoNodo->siguiente = temp->siguiente;
            temp->siguiente = nuevoNodo;
        }
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return;
        }
        Nodo* temp = frente;
        frente = frente->siguiente;
        delete temp;
    }

    int obtenerFrente() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return -1;
        }
        return frente->valor;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaPrioridad cola;
    cola.encolar(10, 2);
    cola.encolar(20, 1);
    cola.encolar(30, 3);

    cout << "Elemento con mayor prioridad: " << cola.obtenerFrente() << endl;

    cola.desencolar();
    cout << "Elemento con mayor prioridad despues de desencolar: " << cola.obtenerFrente() << endl;

    return 0;
}
