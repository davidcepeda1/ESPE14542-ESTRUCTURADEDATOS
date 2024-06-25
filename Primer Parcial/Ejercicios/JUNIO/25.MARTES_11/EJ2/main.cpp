#include <iostream>
#include <string>
using namespace std;

struct Documento {
    string nombre;
    int paginas;
    Documento* siguiente;
};

class ColaImpresion {
private:
    Documento* frente;
    Documento* final;

public:
    ColaImpresion() : frente(nullptr), final(nullptr) {}

    ~ColaImpresion() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(string nombre, int paginas) {
        Documento* nuevoDoc = new Documento();
        nuevoDoc->nombre = nombre;
        nuevoDoc->paginas = paginas;
        nuevoDoc->siguiente = nullptr;
        if (final) {
            final->siguiente = nuevoDoc;
        } else {
            frente = nuevoDoc;
        }
        final = nuevoDoc;
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
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
    ColaImpresion cola;
    cola.encolar("Documento1", 10);
    cola.encolar("Documento2", 20);
    cola.encolar("Documento3", 30);

    cout << "Documento del frente: " << cola.obtenerFrente().nombre << ", Paginas: " << cola.obtenerFrente().paginas << endl;

    cola.desencolar();
    cout << "Documento del frente despues de desencolar: " << cola.obtenerFrente().nombre << ", Paginas: " << cola.obtenerFrente().paginas << endl;

    return 0;
}
