#include <iostream>
#include <functional>
using namespace std;

template<typename T>
struct Nodo {
    T dato;
    Nodo* siguiente;
};

template<typename T>
class Pila {
private:
    Nodo<T>* cima;

public:
    Pila() : cima(nullptr) {}

    ~Pila() {
        while (!estaVacia()) {
            desapilar();
        }
    }

    void apilar(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>();
        nuevoNodo->dato = valor;
        nuevoNodo->siguiente = cima;
        cima = nuevoNodo;
    }

    void desapilar() {
        if (estaVacia()) {
            cout << "Pila vacía" << endl;
            return;
        }
        Nodo<T>* temp = cima;
        cima = cima->siguiente;
        delete temp;
    }

    T obtenerCima() {
        if (estaVacia()) {
            throw runtime_error("Pila vacía");
        }
        return cima->dato;
    }

    bool estaVacia() {
        return cima == nullptr;
    }

    void realizarOperacion(function<void(T&)> operacion) {
        Nodo<T>* temp = cima;
        while (temp) {
            operacion(temp->dato);
            temp = temp->siguiente;
        }
    }
};

int main() {
    Pila<int> pila;
    pila.apilar(10);
    pila.apilar(20);
    pila.apilar(30);
    pila.apilar(40);

    auto duplicar = [](int& valor) {
        valor *= 2;
    };

    cout << "Elementos de la pila antes de duplicar: ";
    while (!pila.estaVacia()) {
        cout << pila.obtenerCima() << " ";
        pila.desapilar();
    }
    cout << endl;

    pila.apilar(10);
    pila.apilar(20);
    pila.apilar(30);
    pila.apilar(40);

    pila.realizarOperacion(duplicar);

    cout << "Elementos de la pila despues de duplicar: ";
    while (!pila.estaVacia()) {
        cout << pila.obtenerCima() << " ";
        pila.desapilar();
    }
    cout << endl;

    return 0;
}
