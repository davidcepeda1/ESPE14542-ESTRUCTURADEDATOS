#include <iostream>
#include <functional>
#include <queue>
#include <vector>
using namespace std;

template<typename T>
class ColaPrioritaria {
private:
    priority_queue<T, vector<T>, function<bool(T, T)>> cola;

public:
    ColaPrioritaria(function<bool(T, T)> comparador) : cola(comparador) {}

    void encolar(T valor) {
        cola.push(valor);
    }

    void desencolar() {
        if (cola.empty()) {
            cout << "Cola vacía" << endl;
            return;
        }
        cola.pop();
    }

    T obtenerFrente() {
        if (cola.empty()) {
            throw runtime_error("Cola vacía");
        }
        return cola.top();
    }

    bool estaVacia() {
        return cola.empty();
    }

    void modificarPrioridades(function<void(T&)> modificar) {
        vector<T> elementos;
        while (!estaVacia()) {
            T elem = obtenerFrente();
            modificar(elem);
            elementos.push_back(elem);
            desencolar();
        }

        for (T& elem : elementos) {
            encolar(elem);
        }
    }
};

struct Tarea {
    string descripcion;
    int prioridad;

    Tarea(string desc, int prio) : descripcion(desc), prioridad(prio) {}

    bool operator<(const Tarea& otra) const {
        return prioridad < otra.prioridad;
    }
};

int main() {
    auto comparador = [](Tarea a, Tarea b) {
        return a.prioridad < b.prioridad; // Mayor prioridad al mayor valor
    };

    ColaPrioritaria<Tarea> cola(comparador);

    cola.encolar(Tarea("Hacer la compra", 2));
    cola.encolar(Tarea("Estudiar para el examen", 5));
    cola.encolar(Tarea("Pasear al perro", 1));

    cout << "Tarea de mayor prioridad: " << cola.obtenerFrente().descripcion << endl;

    auto aumentarPrioridad = [](Tarea& tarea) {
        tarea.prioridad += 1;
    };

    cola.modificarPrioridades(aumentarPrioridad);

    cout << "Tarea de mayor prioridad despues de aumentar las prioridades: " << cola.obtenerFrente().descripcion << endl;

    return 0;
}
