#include <iostream>
#include <string>
using namespace std;

struct Paciente {
    string nombre;
    int edad;
    string problema;
    Paciente* siguiente;
};

class ColaPacientes {
private:
    Paciente* frente;
    Paciente* final;

public:
    ColaPacientes() : frente(nullptr), final(nullptr) {}

    ~ColaPacientes() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(string nombre, int edad, string problema) {
        Paciente* nuevoPaciente = new Paciente();
        nuevoPaciente->nombre = nombre;
        nuevoPaciente->edad = edad;
        nuevoPaciente->problema = problema;
        nuevoPaciente->siguiente = nullptr;
        if (final) {
            final->siguiente = nuevoPaciente;
        } else {
            frente = nuevoPaciente;
        }
        final = nuevoPaciente;
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacía" << endl;
            return;
        }
        Paciente* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    Paciente obtenerFrente() {
        if (estaVacia()) {
            cout << "Cola vacía" << endl;
            return { "", -1, "" };
        }
        return *frente;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaPacientes cola;
    cola.encolar("Juan Perez", 45, "Dolor de cabeza");
    cola.encolar("Ana Gomez", 30, "Fiebre");
    cola.encolar("Carlos Ruiz", 25, "Fractura");

    cout << "Paciente al frente: " << cola.obtenerFrente().nombre << ", Edad: " << cola.obtenerFrente().edad << ", Problema: " << cola.obtenerFrente().problema << endl;

    cola.desencolar();
    cout << "Paciente al frente despues de desencolar: " << cola.obtenerFrente().nombre << ", Edad: " << cola.obtenerFrente().edad << ", Problema: " << cola.obtenerFrente().problema << endl;

    return 0;
}
