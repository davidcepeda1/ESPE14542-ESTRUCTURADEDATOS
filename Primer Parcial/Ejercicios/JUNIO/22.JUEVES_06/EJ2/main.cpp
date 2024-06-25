#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    void push(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
    }

    void pop() {
        if (isEmpty()) {
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    bool isEmpty() {
        return top == nullptr;
    }

    int getTop() {
        if (isEmpty()) {
            return -1;
        }
        return top->data;
    }

    int sumElements() {
        return sumElementsRecursive(top);
    }

private:
    int sumElementsRecursive(Node* node) {
        if (node == nullptr) {
            return 0;
        }
        return node->data + sumElementsRecursive(node->next);
    }
};

int main() {
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "Suma de elementos: " << stack.sumElements() << endl;

    return 0;
}
