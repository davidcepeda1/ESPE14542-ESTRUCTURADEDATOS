#include <iostream>
#include <stack>
using namespace std;

class PilaMin {
    stack<int> *pila;
    stack<int> *minPila;
public:
    PilaMin() {
        pila = new stack<int>;
        minPila = new stack<int>;
    }
    ~PilaMin() {
        delete pila;
        delete minPila;
    }
    void push(int x) {
        pila->push(x);
        if (minPila->empty() || x <= minPila->top()) {
            minPila->push(x);
        }
    }
    void pop() {
        if (pila->top() == minPila->top()) {
            minPila->pop();
        }
        pila->pop();
    }
    int getMin() {
        return minPila->top();
    }
};

int main() {
    PilaMin* pila = new PilaMin();
    pila->push(3);
    pila->push(5);
    cout << "Minimo actual: " << pila->getMin() << endl;
    pila->push(2);
    pila->push(1);
    cout << "Minimo actual: " << pila->getMin() << endl;
    pila->pop();
    cout << "Minimo actual: " << pila->getMin() << endl;
    pila->pop();
    cout << "Minimo actual: " << pila->getMin() << endl;
    delete pila;
    return 0;
}
