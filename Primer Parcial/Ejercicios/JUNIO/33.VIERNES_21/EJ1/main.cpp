#include <iostream>
#include <functional>
using namespace std;

template<typename T>
struct Nodo {
    T dato;
    Nodo* siguiente;
};

template<typename T>
class ListaEnlazada {
private:
    Nodo<T>* cabeza;

public:
    ListaEnlazada() : cabeza(nullptr) {}

    ~ListaEnlazada() {
        while (cabeza) {
            Nodo<T>* temp = cabeza;
            cabeza = cabeza->siguiente;
            delete temp;
        }
    }

    void insertarInicio(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>();
        nuevoNodo->dato = valor;
        nuevoNodo->siguiente = cabeza;
        cabeza = nuevoNodo;
    }

    T encontrarMaximo(function<bool(T, T)> comparador) {
        if (!cabeza) {
            throw runtime_error("Lista vacía");
        }

        Nodo<T>* temp = cabeza;
        T maximo = temp->dato;
        temp = temp->siguiente;

        while (temp) {
            if (comparador(temp->dato, maximo)) {
                maximo = temp->dato;
            }
            temp = temp->siguiente;
        }

        return maximo;
    }

    void mostrarLista() {
        Nodo<T>* temp = cabeza;
        while (temp) {
            cout << temp->dato << " ";
            temp = temp->siguiente;
        }
        cout << endl;
    }
};

int main() {
    ListaEnlazada<int> lista;
    lista.insertarInicio(3);
    lista.insertarInicio(1);
    lista.insertarInicio(4);
    lista.insertarInicio(2);

    auto comparador = [](int a, int b) {
        return a > b;
    };

    cout << "Elemento maximo en la lista: " << lista.encontrarMaximo(comparador) << endl;

    return 0;
}
