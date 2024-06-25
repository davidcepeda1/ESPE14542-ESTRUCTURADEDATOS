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

    bool buscar(function<bool(T)> condicion) {
        Nodo<T>* temp = cabeza;
        while (temp) {
            if (condicion(temp->dato)) {
                return true;
            }
            temp = temp->siguiente;
        }
        return false;
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
    lista.insertarInicio(10);
    lista.insertarInicio(20);
    lista.insertarInicio(30);

    auto esIgualA20 = [](int valor) {
        return valor == 20;
    };

    if (lista.buscar(esIgualA20)) {
        cout << "El valor 20 se encuentra en la lista." << endl;
    } else {
        cout << "El valor 20 no se encuentra en la lista." << endl;
    }

    return 0;
}
