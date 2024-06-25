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
};

struct Persona {
    string nombre;
    int edad;

    Persona(string nom, int ed) : nombre(nom), edad(ed) {}
};

int main() {
    auto comparadorPorEdad = [](Persona a, Persona b) {
        return a.edad < b.edad; // Mayor prioridad al mayor valor
    };

    ColaPrioritaria<Persona> cola(comparadorPorEdad);

    cola.encolar(Persona("Juan", 30));
    cola.encolar(Persona("María", 25));
    cola.encolar(Persona("Pedro", 35));

    cout << "Persona de mayor edad en la cola: " << cola.obtenerFrente().nombre << endl;

    cola.desencolar();
    cout << "Siguiente persona de mayor edad en la cola: " << cola.obtenerFrente().nombre << endl;

    return 0;
}
