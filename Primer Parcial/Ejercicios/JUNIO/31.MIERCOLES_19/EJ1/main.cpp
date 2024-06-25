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

    int contarCumpleCondicion(function<bool(T)> condicion) {
        Nodo<T>* temp = frente;
        int contador = 0;
        while (temp) {
            if (condicion(temp->dato)) {
                contador++;
            }
            temp = temp->siguiente;
        }
        return contador;
    }
};

int main() {
    Cola<int> cola;
    cola.encolar(1);
    cola.encolar(2);
    cola.encolar(3);
    cola.encolar(4);

    auto esPar = [](int valor) {
        return valor % 2 == 0;
    };

    cout << "Cantidad de numeros pares en la cola: " << cola.contarCumpleCondicion(esPar) << endl;

    return 0;
}
