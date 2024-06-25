#include <iostream>
#include <string>
using namespace std;

struct Cliente {
    string nombre;
    string transaccion;
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

    void encolar(string nombre, string transaccion) {
        Cliente* nuevoCliente = new Cliente();
        nuevoCliente->nombre = nombre;
        nuevoCliente->transaccion = transaccion;
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
            return { "", "" };
        }
        return *frente;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaClientes cola;
    cola.encolar("Ana Gomez", "Retiro");
    cola.encolar("Carlos Ruiz", "Consulta");

    cout << "Cliente al frente: " << cola.obtenerFrente().nombre << ", Transaccion: " << cola.obtenerFrente().transaccion << endl;

    cola.desencolar();
    cout << "Cliente al frente despues de desencolar: " << cola.obtenerFrente().nombre << ", Transaccion: " << cola.obtenerFrente().transaccion << endl;

    return 0;
}

