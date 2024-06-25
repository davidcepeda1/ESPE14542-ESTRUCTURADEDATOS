#include <iostream>
using namespace std;

class Pila {
    int tope;
    int capacidad;
    int *arr;

public:
    Pila(int capacidad);
    ~Pila();
    bool push(int x);
    int pop();
    int peek();
    bool isEmpty();
};

Pila::Pila(int capacidad) {
    this->capacidad = capacidad;
    arr = new int[capacidad];
    tope = -1;
}

Pila::~Pila() {
    delete[] arr;
}

bool Pila::push(int x) {
    if (tope >= (capacidad - 1)) {
        cout << "Desbordamiento de pila\n";
        return false;
    }
    else {
        arr[++tope] = x;
        cout << x << " agregado a la pila\n";
        return true;
    }
}

int Pila::pop() {
    if (tope < 0) {
        cout << "Subdesbordamiento de pila\n";
        return 0;
    }
    else {
        int x = arr[tope--];
        return x;
    }
}

int Pila::peek() {
    if (tope < 0) {
        cout << "La pila está vacía\n";
        return 0;
    }
    else {
        int x = arr[tope];
        return x;
    }
}

bool Pila::isEmpty() {
    return (tope < 0);
}

int main() {
    Pila pila(100);
    pila.push(10);
    pila.push(20);
    pila.push(30);
    cout << pila.pop() << " sacado de la pila\n";
    return 0;
}
