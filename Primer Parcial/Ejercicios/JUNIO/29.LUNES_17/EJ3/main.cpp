#include <iostream>
#include <string>
using namespace std;

struct ProcesoImpresion {
    string nombreDocumento;
    int numPaginas;
    string prioridad;
    ProcesoImpresion* siguiente;
};

class ColaImpresion {
private:
    ProcesoImpresion* frente;
    ProcesoImpresion* final;

public:
    ColaImpresion() : frente(nullptr), final(nullptr) {}

    ~ColaImpresion() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(string nombreDocumento, int numPaginas, string prioridad) {
        ProcesoImpresion* nuevoProceso = new ProcesoImpresion();
        nuevoProceso->nombreDocumento = nombreDocumento;
        nuevoProceso->numPaginas = numPaginas;
        nuevoProceso->prioridad = prioridad;
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
            cout << "Cola vacía" << endl;
            return;
        }
        ProcesoImpresion* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    ProcesoImpresion obtenerFrente() {
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
    ColaImpresion cola;
    cola.encolar("Documento1", 5, "alta");
    cola.encolar("Documento2", 3, "media");
    cola.encolar("Documento3", 8, "baja");

    cout << "Proceso de impresion al frente: Documento '" << cola.obtenerFrente().nombreDocumento << "', Paginas = " << cola.obtenerFrente().numPaginas << ", Prioridad = " << cola.obtenerFrente().prioridad << endl;

    cola.desencolar();
    cout << "Proceso de impresion al frente despues de desencolar: Documento '" << cola.obtenerFrente().nombreDocumento << "', Paginas = " << cola.obtenerFrente().numPaginas << ", Prioridad = " << cola.obtenerFrente().prioridad << endl;

    return 0;
}
