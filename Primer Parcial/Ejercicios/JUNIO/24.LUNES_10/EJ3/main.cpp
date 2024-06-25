#include <iostream>
#include <string>
using namespace std;

struct Cliente {
    int id;
    string nombre;
    Cliente* siguiente;
};

class ColaClientes {
private:
    Cliente* frente;
    Cliente* final;

public:
    ColaClientes() : frente(nullptr), final(nullptr) {}

    ~ColaClientes() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(int id, string nombre) {
        Cliente* nuevoCliente = new Cliente();
        nuevoCliente->id = id;
        nuevoCliente->nombre = nombre;
        nuevoCliente->siguiente = nullptr;
        if (final) {
            final->siguiente = nuevoCliente;
        } else {
            frente = nuevoCliente;
        }
        final = nuevoCliente;
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return;
        }
        Cliente* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    Cliente obtenerFrente() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return { -1, "" };
        }
        return *frente;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaClientes cola;
    cola.encolar(1, "Juan");
    cola.encolar(2, "Ana");
    cola.encolar(3, "Pedro");

    cout << "El cliente del frente es: " << cola.obtenerFrente().nombre << endl;

    cola.desencolar();
    cout << "El cliente del frente despues de desencolar es: " << cola.obtenerFrente().nombre << endl;

    return 0;
}
