#include <iostream>
#include <stack>
#include <string>

struct Contacto {
    std::string nombre;
    std::string telefono;
};

// Función recursiva para buscar un contacto en la agenda
bool buscarContacto(std::stack<Contacto>& pila, const std::string& nombre) {
    if (pila.empty()) {
        return false;
    }

    Contacto contacto = pila.top();
    pila.pop();

    if (contacto.nombre == nombre) {
        std::cout << "Contacto encontrado - Nombre: " << contacto.nombre << ", Telefono: " << contacto.telefono << std::endl;
        return true;
    }

    bool encontrado = buscarContacto(pila, nombre);
    pila.push(contacto); // Restaurar el contacto a la pila original
    return encontrado;
}

// Función para imprimir todos los contactos en la agenda
void imprimirAgenda(std::stack<Contacto>& pila) {
    std::stack<Contacto> aux;

    std::cout << "Agenda de Contactos:" << std::endl;
    while (!pila.empty()) {
        Contacto contacto = pila.top();
        pila.pop();
        std::cout << "Nombre: " << contacto.nombre << ", Telefono: " << contacto.telefono << std::endl;
        aux.push(contacto);
    }

    // Restaurar los contactos a la pila original
    while (!aux.empty()) {
        pila.push(aux.top());
        aux.pop();
    }
}

int main() {
    std::stack<Contacto> agenda;

    // Insertar contactos en la agenda
    agenda.push({"Juan", "1234567890"});
    agenda.push({"Maria", "654321780"});
    agenda.push({"Pedro", "9876541485"});

    imprimirAgenda(agenda);

    // Buscar un contacto por nombre
    std::string nombreABuscar = "Maria";
    if (!buscarContacto(agenda, nombreABuscar)) {
        std::cout << "Contacto no encontrado en la agenda." << std::endl;
    }

    return 0;
}
