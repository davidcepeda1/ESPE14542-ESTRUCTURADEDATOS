#include <iostream>

struct NodoArbol {
    int dato;
    NodoArbol* izquierda;
    NodoArbol* derecha;
};

// Función para recorrer un árbol binario en preorden utilizando recursividad y pila
void recorrerPreorden(NodoArbol* raiz) {
    if (raiz == nullptr) return;
    
    std::cout << raiz->dato << " ";
    recorrerPreorden(raiz->izquierda);
    recorrerPreorden(raiz->derecha);
}

int main() {
    // Supongamos que tenemos un árbol binario de ejemplo
    NodoArbol* raiz = new NodoArbol{1,
                                    new NodoArbol{2, nullptr, nullptr},
                                    new NodoArbol{3, nullptr, nullptr}};
    
    // Recorrido en preorden utilizando una pila implícita por la recursividad
    recorrerPreorden(raiz);
    std::cout << std::endl;

    return 0;
}
