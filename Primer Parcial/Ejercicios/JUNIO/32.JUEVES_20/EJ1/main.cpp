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

    void filtrar(function<bool(T)> condicion) {
        Nodo<T>* temp = cima;
        Pila<T> pilaFiltrada;

        while (temp) {
            if (condicion(temp->dato)) {
                pilaFiltrada.apilar(temp->dato);
            }
            temp = temp->siguiente;
        }

        while (!pilaFiltrada.estaVacia()) {
            this->apilar(pilaFiltrada.obtenerCima());
            pilaFiltrada.desapilar();
        }
    }

    void mostrarPila() {
        Nodo<T>* temp = cima;
        while (temp) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }
};

int main() {
    Pila<int> pila;
    pila.apilar(10);
    pila.apilar(15);
    pila.apilar(20);
    pila.apilar(25);

    auto esMayorQue15 = [](int valor) {
        return valor > 15;
    };

    cout << "Pila antes de filtrar: ";
    pila.mostrarPila();

    pila.filtrar(esMayorQue15);

    cout << "Pila despues de filtrar elementos mayores que 15: ";
    pila.mostrarPila();

    return 0;
}
