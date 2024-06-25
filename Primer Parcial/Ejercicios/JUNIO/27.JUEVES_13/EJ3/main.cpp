#include <iostream>
#include <string>
using namespace std;

struct Pedido {
    int id;
    string producto;
    int cantidad;
    Pedido* siguiente;
};

class ColaPedidos {
private:
    Pedido* frente;
    Pedido* final;

public:
    ColaPedidos() : frente(nullptr), final(nullptr) {}

    ~ColaPedidos() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(int id, string producto, int cantidad) {
        Pedido* nuevoPedido = new Pedido();
        nuevoPedido->id = id;
        nuevoPedido->producto = producto;
        nuevoPedido->cantidad = cantidad;
        nuevoPedido->siguiente = nullptr;
        if (final) {
            final->siguiente = nuevoPedido;
        } else {
            frente = nuevoPedido;
        }
        final = nuevoPedido;
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return;
        }
        Pedido* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    Pedido obtenerFrente() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return { -1, "", -1 };
        }
        return *frente;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaPedidos cola;
    cola.encolar(1, "Laptop", 2);
    cola.encolar(2, "Mouse", 5);
    cola.encolar(3, "Teclado", 3);

    cout << "Pedido al frente: ID = " << cola.obtenerFrente().id << ", Producto = " << cola.obtenerFrente().producto << ", Cantidad = " << cola.obtenerFrente().cantidad << endl;

    cola.desencolar();
    cout << "Pedido al frente despues de desencolar: ID = " << cola.obtenerFrente().id << ", Producto = " << cola.obtenerFrente().producto << ", Cantidad = " << cola.obtenerFrente().cantidad << endl;

    return 0;
}
