#include <iostream>
#include <cstdlib> // para usar system()
#include "ListaDoble.h"

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
    std::cout << "1. Insertar al inicio\n";
    std::cout << "2. Insertar al final\n";
    std::cout << "3. Eliminar nodo\n";
    std::cout << "4. Mostrar lista\n";
    std::cout << "5. Mostrar lista en reversa\n";
    std::cout << "6. Salir\n";
    std::cout << "Elige una opción: ";
}

void pausarPantalla() {
    std::cout << "\nPresiona Enter para continuar...";
    std::cin.ignore();
    std::cin.get();
}

int main() {
    ListaDoble<int> lista;
    int opcion, dato;

    do {
        limpiarPantalla();
        mostrarMenu();
        std::cin >> opcion;
        std::cin.ignore(); // Ignorar el salto de línea que queda en el buffer

        switch(opcion) {
            case 1:
                limpiarPantalla();
                std::cout << "Ingrese el dato a insertar al inicio: ";
                std::cin >> dato;
                lista.insertarAlInicio(dato);
                pausarPantalla();
                break;
            case 2:
                limpiarPantalla();
                std::cout << "Ingrese el dato a insertar al final: ";
                std::cin >> dato;
                lista.insertarAlFinal(dato);
                pausarPantalla();
                break;
            case 3:
                limpiarPantalla();
                std::cout << "Ingrese el dato del nodo a eliminar: ";
                std::cin >> dato;
                if (lista.buscarNodo(dato)) {
                    lista.eliminarNodo(dato);
                    std::cout << "Nodo con dato " << dato << " eliminado.\n";
                } else {
                    std::cout << "Nodo con dato " << dato << " no encontrado en la lista.\n";
                }
                pausarPantalla();
                break;
            case 4:
                limpiarPantalla();
                std::cout << "La lista enlazada es: ";
                lista.recorrerLista();
                pausarPantalla();
                break;
            case 5:
                limpiarPantalla();
                std::cout << "La lista enlazada en reversa es: ";
                lista.recorrerListaReversa();
                pausarPantalla();
                break;
            case 6:
                limpiarPantalla();
                std::cout << "Saliendo...\n";
                break;
            default:
                limpiarPantalla();
                std::cout << "Opción no válida, intente nuevamente.\n";
                pausarPantalla();
        }
    } while (opcion != 6);

    return 0;
}
