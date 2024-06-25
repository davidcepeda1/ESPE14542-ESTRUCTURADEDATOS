#include <iostream>
using namespace std;

struct Tarea {
    int id;
    int prioridad;
    Tarea* siguiente;
};

class ColaTareas {
private:
    Tarea* frente;
    Tarea* final;

public:
    ColaTareas() : frente(nullptr), final(nullptr) {}

    ~ColaTareas() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(int id, int prioridad) {
        Tarea* nuevaTarea = new Tarea();
        nuevaTarea->id = id;
        nuevaTarea->prioridad = prioridad;
        nuevaTarea->siguiente = nullptr;
        if (final) {
            final->siguiente = nuevaTarea;
        } else {
            frente = nuevaTarea;
        }
        final = nuevaTarea;
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return;
        }
        Tarea* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    Tarea obtenerFrente() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return { -1, -1 };
        }
        return *frente;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaTareas cola;
    cola.encolar(1, 5);
    cola.encolar(2, 3);
    cola.encolar(3, 1);

    cout << "Tarea del frente: ID = " << cola.obtenerFrente().id << ", Prioridad = " << cola.obtenerFrente().prioridad << endl;

    cola.desencolar();
    cout << "Tarea del frente despues de desencolar: ID = " << cola.obtenerFrente().id << ", Prioridad = " << cola.obtenerFrente().prioridad << endl;

    return 0;
}
