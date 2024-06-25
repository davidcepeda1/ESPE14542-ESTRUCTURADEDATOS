#include <iostream>
#include <stack>
using namespace std;

class Cola {
    stack<int> *pila1;
    stack<int> *pila2;
public:
    Cola() {
        pila1 = new stack<int>;
        pila2 = new stack<int>;
    }
    ~Cola() {
        delete pila1;
        delete pila2;
    }
    void encolar(int x) {
        pila1->push(x);
    }
    int desencolar() {
        if (pila2->empty()) {
            while (!pila1->empty()) {
                pila2->push(pila1->top());
                pila1->pop();
            }
        }
        if (pila2->empty()) {
            cout << "Cola vacía" << endl;
            return -1;
        }
        int x = pila2->top();
        pila2->pop();
        return x;
    }
};

int main() {
    Cola *cola = new Cola();
    cola->encolar(1);
    cola->encolar(2);
    cola->encolar(3);
    cout << "Elemento desencolado: " << cola->desencolar() << endl;
    cout << "Elemento desencolado: " << cola->desencolar() << endl;
    delete cola;
    return 0;
}
