#include <iostream>
#include <string>
using namespace std;

struct Documento {
    string nombre;
    int paginas;
    string prioridad;
    Documento* siguiente;
};

class ColaDocumentos {
private:
    Documento* frente;
    Documento* final;

public:
    ColaDocumentos() : frente(nullptr), final(nullptr) {}

    ~ColaDocumentos() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(string nombre, int paginas, string prioridad) {
        Documento* nuevoDocumento = new Documento();
        nuevoDocumento->nombre = nombre;
        nuevoDocumento->paginas = paginas;
        nuevoDocumento->prioridad = prioridad;
        nuevoDocumento->siguiente = nullptr;
        if (final) {
            final->siguiente = nuevoDocumento;
        } else {
            frente = nuevoDocumento;
        }
        final = nuevoDocumento;
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacía" << endl;
            return;
        }
        Documento* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    Documento obtenerFrente() {
        if (estaVacia()) {
            cout << "Cola vacía" << endl;
            return { "", -1, "", nullptr };
        }
        return *frente;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaDocumentos cola;
    cola.encolar("Documento1", 5, "alta");
    cola.encolar("Documento2", 3, "media");
    cola.encolar("Documento3", 8, "baja");

    cout << "Documento al frente: " << cola.obtenerFrente().nombre << ", Paginas = " << cola.obtenerFrente().paginas << ", Prioridad = " << cola.obtenerFrente().prioridad << endl;

    cola.desencolar();
    cout << "Documento al frente despues de desencolar: " << cola.obtenerFrente().nombre << ", Paginas = " << cola.obtenerFrente().paginas << ", Prioridad = " << cola.obtenerFrente().prioridad << endl;

    return 0;
}
