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

    T sumarElementos() {
        T suma = 0;
        Nodo<T>* temp = cima;

        while (temp) {
            suma += temp->dato;
            temp = temp->siguiente;
        }

        return suma;
    }
};

int main() {
    Pila<int> pila;
    pila.apilar(1);
    pila.apilar(2);
    pila.apilar(3);
    pila.apilar(4);

    cout << "Suma de los elementos de la pila: " << pila.sumarElementos() << endl;

    return 0;
}
