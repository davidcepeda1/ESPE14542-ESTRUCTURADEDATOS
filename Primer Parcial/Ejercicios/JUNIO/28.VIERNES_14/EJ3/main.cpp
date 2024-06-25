#include <iostream>
#include <string>
using namespace std;

struct PaqueteRed {
    int id;
    int tamanoBytes;
    string direccionDestino;
    PaqueteRed* siguiente;
};

class ColaPaquetes {
private:
    PaqueteRed* frente;
    PaqueteRed* final;

public:
    ColaPaquetes() : frente(nullptr), final(nullptr) {}

    ~ColaPaquetes() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(int id, int tamanoBytes, string direccionDestino) {
        PaqueteRed* nuevoPaquete = new PaqueteRed();
        nuevoPaquete->id = id;
        nuevoPaquete->tamanoBytes = tamanoBytes;
        nuevoPaquete->direccionDestino = direccionDestino;
        nuevoPaquete->siguiente = nullptr;
        if (final) {
            final->siguiente = nuevoPaquete;
        } else {
            frente = nuevoPaquete;
        }
        final = nuevoPaquete;
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return;
        }
        PaqueteRed* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    PaqueteRed obtenerFrente() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return { -1, -1, "", nullptr };
        }
        return *frente;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaPaquetes cola;
    cola.encolar(1, 1024, "192.168.0.1");
    cola.encolar(2, 512, "192.168.0.2");
    cola.encolar(3, 2048, "192.168.0.3");

    cout << "Paquete al frente: ID = " << cola.obtenerFrente().id << ", Tamaño = " << cola.obtenerFrente().tamanoBytes << " bytes, Direccion = " << cola.obtenerFrente().direccionDestino << endl;

    cola.desencolar();
    cout << "Paquete al frente despues de desencolar: ID = " << cola.obtenerFrente().id << ", Tamaño = " << cola.obtenerFrente().tamanoBytes << " bytes, Direccion = " << cola.obtenerFrente().direccionDestino << endl;

    return 0;
}
