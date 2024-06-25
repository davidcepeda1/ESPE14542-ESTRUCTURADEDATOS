#include <iostream>
#include <string>
using namespace std;

struct Reserva {
    string nombre;
    int cantidadEntradas;
    Reserva* siguiente;
};

class ColaReservas {
private:
    Reserva* frente;
    Reserva* final;

public:
    ColaReservas() : frente(nullptr), final(nullptr) {}

    ~ColaReservas() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(string nombre, int cantidadEntradas) {
        Reserva* nuevaReserva = new Reserva();
        nuevaReserva->nombre = nombre;
        nuevaReserva->cantidadEntradas = cantidadEntradas;
        nuevaReserva->siguiente = nullptr;
        if (final) {
            final->siguiente = nuevaReserva;
        } else {
            frente = nuevaReserva;
        }
        final = nuevaReserva;
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return;
        }
        Reserva* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    Reserva obtenerFrente() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return { "", -1 };
        }
        return *frente;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaReservas cola;
    cola.encolar("Juan Perez", 2);
    cola.encolar("Ana Gomez", 4);
    cola.encolar("Carlos Ruiz", 1);

    cout << "Reserva del frente: " << cola.obtenerFrente().nombre << ", Entradas: " << cola.obtenerFrente().cantidadEntradas << endl;

    cola.desencolar();
    cout << "Reserva del frente despues de desencolar: " << cola.obtenerFrente().nombre << ", Entradas: " << cola.obtenerFrente().cantidadEntradas << endl;

    return 0;
}
