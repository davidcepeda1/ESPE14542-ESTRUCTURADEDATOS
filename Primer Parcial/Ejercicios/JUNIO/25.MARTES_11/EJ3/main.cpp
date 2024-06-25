#include <iostream>
#include <string>
using namespace std;

struct Solicitud {
    int id;
    string descripcion;
    Solicitud* siguiente;
};

class ColaSolicitudes {
private:
    Solicitud* frente;
    Solicitud* final;

public:
    ColaSolicitudes() : frente(nullptr), final(nullptr) {}

    ~ColaSolicitudes() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(int id, string descripcion) {
        Solicitud* nuevaSolicitud = new Solicitud();
        nuevaSolicitud->id = id;
        nuevaSolicitud->descripcion = descripcion;
        nuevaSolicitud->siguiente = nullptr;
        if (final) {
            final->siguiente = nuevaSolicitud;
        } else {
            frente = nuevaSolicitud;
        }
        final = nuevaSolicitud;
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return;
        }
        Solicitud* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    Solicitud obtenerFrente() {
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
    ColaSolicitudes cola;
    cola.encolar(1, "Solicitud de acceso");
    cola.encolar(2, "Solicitud de cambio de contraseña");
    cola.encolar(3, "Solicitud de soporte tecnico");

    cout << "Solicitud del frente: " << cola.obtenerFrente().descripcion << endl;

    cola.desencolar();
    cout << "Solicitud del frente despues de desencolar: " << cola.obtenerFrente().descripcion << endl;

    return 0;
}
