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

    void recorrer(function<void(T)> funcion) {
        Nodo<T>* temp = cima;
        while (temp) {
            funcion(temp->dato);
            temp = temp->siguiente;
        }
    }
};

int main() {
    Pila<int> pila;
    pila.apilar(10);
    pila.apilar(20);
    pila.apilar(30);

    auto imprimir = [](int valor) {
        cout << valor << " ";
    };

    cout << "Elementos en la pila: ";
    pila.recorrer(imprimir);
    cout << endl;

    return 0;
}
