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

    void eliminarPorCondicion(function<bool(T)> condicion) {
        Nodo<T>* actual = cabeza;
        Nodo<T>* anterior = nullptr;

        while (actual) {
            if (condicion(actual->dato)) {
                if (anterior) {
                    anterior->siguiente = actual->siguiente;
                } else {
                    cabeza = actual->siguiente;
                }
                Nodo<T>* temp = actual;
                actual = actual->siguiente;
                delete temp;
            } else {
                anterior = actual;
                actual = actual->siguiente;
            }
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
    lista.insertarInicio(10);
    lista.insertarInicio(20);
    lista.insertarInicio(30);
    lista.insertarInicio(40);

    auto esMenorQue30 = [](int valor) {
        return valor < 30;
    };

    lista.eliminarPorCondicion(esMenorQue30);
    cout << "Lista despues de eliminar elementos menores que 30: ";
    lista.mostrarLista();

    return 0;
}
