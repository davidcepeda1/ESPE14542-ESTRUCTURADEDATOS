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

    void modificarPorCondicion(function<void(T&)> modificar) {
        Nodo<T>* temp = cabeza;
        while (temp) {
            modificar(temp->dato);
            temp = temp->siguiente;
        }
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
    lista.insertarInicio(5);
    lista.insertarInicio(10);
    lista.insertarInicio(15);
    lista.insertarInicio(20);

    auto multiplicarPorDos = [](int& valor) {
        valor *= 2;
    };

    cout << "Lista antes de modificar: ";
    lista.mostrarLista();

    lista.modificarPorCondicion(multiplicarPorDos);

    cout << "Lista despues de multiplicar los elementos por dos: ";
    lista.mostrarLista();

    return 0;
}
