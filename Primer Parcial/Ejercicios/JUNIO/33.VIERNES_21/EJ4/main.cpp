#include <iostream>
#include <functional>
#include <unordered_set>
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

    void eliminarDuplicados() {
        if (!cabeza) return;

        unordered_set<T> vistos;
        Nodo<T>* actual = cabeza;
        Nodo<T>* anterior = nullptr;

        while (actual) {
            if (vistos.find(actual->dato) != vistos.end()) {
                anterior->siguiente = actual->siguiente;
                delete actual;
            } else {
                vistos.insert(actual->dato);
                anterior = actual;
            }
            actual = anterior->siguiente;
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
    lista.insertarInicio(1);
    lista.insertarInicio(2);
    lista.insertarInicio(2);
    lista.insertarInicio(3);
    lista.insertarInicio(4);
    lista.insertarInicio(4);
    lista.insertarInicio(5);

    cout << "Lista antes de eliminar duplicados: ";
    lista.mostrarLista();

    lista.eliminarDuplicados();

    cout << "Lista despues de eliminar duplicados: ";
    lista.mostrarLista();

    return 0;
}
