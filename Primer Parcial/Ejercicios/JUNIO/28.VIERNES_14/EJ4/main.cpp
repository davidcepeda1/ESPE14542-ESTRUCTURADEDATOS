#include <iostream>
#include <string>
using namespace std;

struct Mensaje {
    string remitente;
    string destinatario;
    string contenido;
    Mensaje* siguiente;
};

class ColaMensajes {
private:
    Mensaje* frente;
    Mensaje* final;

public:
    ColaMensajes() : frente(nullptr), final(nullptr) {}

    ~ColaMensajes() {
        while (!estaVacia()) {
            desencolar();
        }
    }

    void encolar(string remitente, string destinatario, string contenido) {
        Mensaje* nuevoMensaje = new Mensaje();
        nuevoMensaje->remitente = remitente;
        nuevoMensaje->destinatario = destinatario;
        nuevoMensaje->contenido = contenido;
        nuevoMensaje->siguiente = nullptr;
        if (final) {
            final->siguiente = nuevoMensaje;
        } else {
            frente = nuevoMensaje;
        }
        final = nuevoMensaje;
    }

    void desencolar() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return;
        }
        Mensaje* temp = frente;
        frente = frente->siguiente;
        if (!frente) {
            final = nullptr;
        }
        delete temp;
    }

    Mensaje obtenerFrente() {
        if (estaVacia()) {
            cout << "Cola vacia" << endl;
            return { "", "", "", nullptr };
        }
        return *frente;
    }

    bool estaVacia() {
        return frente == nullptr;
    }
};

int main() {
    ColaMensajes cola;
    cola.encolar("Usuario1", "Usuario2", "Hola, ¿como estas?");
    cola.encolar("Usuario2", "Usuario1", "Hola, todo bien, gracias.");

    cout << "Mensaje al frente: De " << cola.obtenerFrente().remitente << " para " << cola.obtenerFrente().destinatario << ": " << cola.obtenerFrente().contenido << endl;

    cola.desencolar();
    cout << "Mensaje al frente despues de desencolar: De " << cola.obtenerFrente().remitente << " para " << cola.obtenerFrente().destinatario << ": " << cola.obtenerFrente().contenido << endl;

    return 0;
}
