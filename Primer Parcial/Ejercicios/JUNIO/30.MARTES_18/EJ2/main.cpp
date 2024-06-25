#include <iostream>
#include <functional>
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

    int calcularTamano(function<int(int)> funcion) {
        Nodo<T>* temp = frente;
        int tamano = 0;
        while (temp) {
            tamano += funcion(temp->dato);
            temp = temp->siguiente;
        }
        return tamano;
    }
};

int main() {
    Cola<int> cola;
    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);

    auto contar = [](int) {
        return 1;
    };

    cout << "Tamaño de la cola: " << cola.calcularTamano(contar) << endl;

    return 0;
}
