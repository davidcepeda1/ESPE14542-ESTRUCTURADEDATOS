#include <iostream>
#include <list>

template <typename T>
class Iterador {
private:
    T* datos;
    size_t tamano;
    size_t posicion_actual;

public:
    Iterador(T* datos, size_t tamano) : datos(datos), tamano(tamano), posicion_actual(0) {}

    void avanzar() {
        ++posicion_actual;
    }

    void retroceder() {
        --posicion_actual;
    }

    T& obtener() {
        return datos[posicion_actual];
    }

    bool fin() const {
        return posicion_actual >= tamano;
    }
};

int main() {
    int* arreglo = new int[5]{1, 2, 3, 4, 5};
    Iterador<int> iteradorArr(arreglo, 5);

    while (!iteradorArr.fin()) {
        std::cout << iteradorArr.obtener() << " ";
        iteradorArr.avanzar();
    }
    std::cout << std::endl;

    delete[] arreglo;

    std::list<double> lista = {1.1, 2.2, 3.3, 4.4, 5.5};
    Iterador<double> iteradorLista(&lista.front(), lista.size());

    while (!iteradorLista.fin()) {
        std::cout << iteradorLista.obtener() << " ";
        iteradorLista.avanzar();
    }
    std::cout << std::endl;

    return 0;
}
