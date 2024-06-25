#include <iostream>
using namespace std;

struct Proceso {
    int id;
    int prioridad;
    int tiempoCPU;
    Proceso* siguiente;
};

class ColaProcesos {
private:
    Proceso* frente;
    Proceso* final;

public:
    ColaProcesos() : frente(nullptr), final(nullptr) {}

    ~ColaProcesos() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(int id, int prioridad, int tiempoCPU) {
        Proceso* nuevoProceso = new Proceso();
        nuevoProceso->id = id;
        nuevoProceso->prioridad = prioridad;
        nuevoProceso->tiempoCPU = tiempoCPU;
        nuevoProceso->siguiente = nullptr;
        if (final) {
            final->siguiente = nuevoProceso;
        } else {
            frente = nuevoProceso;
        }
        final = nuevoProceso;
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return;
        }
        Proceso* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    Proceso obtenerFrente() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return { -1, -1, -1, nullptr };
        }
        return *frente;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaProcesos cola;
    cola.encolar(1, 1, 10);
    cola.encolar(2, 2, 5);
    cola.encolar(3, 1, 8);

    cout << "Proceso al frente: ID = " << cola.obtenerFrente().id << ", Prioridad = " << cola.obtenerFrente().prioridad << ", Tiempo CPU = " << cola.obtenerFrente().tiempoCPU << endl;

    cola.desencolar();
    cout << "Proceso al frente despues de desencolar: ID = " << cola.obtenerFrente().id << ", Prioridad = " << cola.obtenerFrente().prioridad << ", Tiempo CPU = " << cola.obtenerFrente().tiempoCPU << endl;

    return 0;
}
