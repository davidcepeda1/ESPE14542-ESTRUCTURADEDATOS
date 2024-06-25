#include <iostream>
#include <cstdlib> // para usar system()
#include "Pila.h"
#include "Cola.h"

// Función para limpiar la pantalla
void limpiarPantalla() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void mostrarMenu() {
    std::cout << "\nOpciones:\n";
    std::cout << "1. Push en la pila\n";
    std::cout << "2. Pop de la pila\n";
    std::cout << "3. Mostrar pila\n";
    std::cout << "4. Enqueue en la cola\n";
    std::cout << "5. Dequeue de la cola\n";
    std::cout << "6. Mostrar cola\n";
    std::cout << "7. Salir\n";
    std::cout << "Elige una opción: ";
}

void pausarPantalla() {
    std::cout << "\nPresiona Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

int main() {
    Pila<int> pila;
    Cola<int> cola;
    int opcion, dato;

    do {
        limpiarPantalla();
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore(); // Ignorar el salto de línea que queda en el buffer

        switch(opcion) {
            case 1:
                limpiarPantalla();
                std::cout << "Ingrese el dato a push en la pila: ";
                std::cin >> dato;
                pila.push(dato);
                pausarPantalla();
                break;
            case 2:
                limpiarPantalla();
                pila.pop();
                pausarPantalla();
                break;
            case 3:
                limpiarPantalla();
                std::cout << "La pila es: ";
                pila.mostrarPila();
                pausarPantalla();
                break;
            case 4:
                limpiarPantalla();
                std::cout << "Ingrese el dato a enqueue en la cola: ";
                std::cin >> dato;
                cola.enqueue(dato);
                pausarPantalla();
                break;
            case 5:
                limpiarPantalla();
                cola.dequeue();
                pausarPantalla();
                break;
            case 6:
                limpiarPantalla();
                std::cout << "La cola es: ";
                cola.mostrarCola();
                pausarPantalla();
                break;
            case 7:
                limpiarPantalla();
                std::cout << "Saliendo...\n";
                break;
            default:
                limpiarPantalla();
                std::cout << "Opción no válida, intente nuevamente.\n";
                pausarPantalla();
        }
    } while (opcion != 7);

    return 0;
}
