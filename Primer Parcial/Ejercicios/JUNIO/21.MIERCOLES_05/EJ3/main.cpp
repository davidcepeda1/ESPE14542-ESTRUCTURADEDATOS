#include <iostream>

struct NodoArbol {
    int dato;
    NodoArbol* izquierda;
    NodoArbol* derecha;
};

// Función para contar los nodos hoja en un árbol binario
int contarNodosHoja(NodoArbol* raiz) {
    if (raiz == nullptr) return 0;
    if (raiz->izquierda == nullptr && raiz->derecha == nullptr) return 1;
    return contarNodosHoja(raiz->izquierda) + contarNodosHoja(raiz->derecha);
}

// Función para crear un nuevo nodo del árbol binario
NodoArbol* crearNodo(int dato) {
    NodoArbol* nuevo = new NodoArbol();
    nuevo->dato = dato;
    nuevo->izquierda = nullptr;
    nuevo->derecha = nullptr;
    return nuevo;
}

int main() {
    // Construcción de un árbol binario de ejemplo
    NodoArbol* raiz = crearNodo(1);
    raiz->izquierda = crearNodo(2);
    raiz->derecha = crearNodo(3);
    raiz->izquierda->izquierda = crearNodo(4);
    raiz->izquierda->derecha = crearNodo(5);

    // Calcular y mostrar el número de nodos hoja
    int nodosHoja = contarNodosHoja(raiz);
    std::cout << "El numero de nodos hoja en el arbol es: " << nodosHoja << std::endl;

    // Liberar memoria al finalizar
    // (Implementación opcional dependiendo de la gestión de memoria requerida)

    return 0;
}
