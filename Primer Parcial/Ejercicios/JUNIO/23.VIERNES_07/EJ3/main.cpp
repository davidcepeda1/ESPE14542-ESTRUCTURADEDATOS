#include <iostream>
using namespace std;

struct Nodo {
    int dato;
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
        nuevoNodo->dato = valor;
        nuevoNodo->prioridad = prioridad;
        nuevoNodo->siguiente = nullptr;

        if (!frente || prioridad < frente->prioridad) {
            nuevoNodo->siguiente = frente;
            frente = nuevoNodo;
        } else {
            Nodo* temp = frente;
            while (temp->siguiente && temp->siguiente->prioridad <= prioridad) {
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
        return frente->dato;
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

    cout << "El elemento del frente es: " << cola.obtenerFrente() << endl;

    cola.desencolar();
    cout << "El elemento del frente despues de desencolar es: " << cola.obtenerFrente() << endl;

    return 0;
}
