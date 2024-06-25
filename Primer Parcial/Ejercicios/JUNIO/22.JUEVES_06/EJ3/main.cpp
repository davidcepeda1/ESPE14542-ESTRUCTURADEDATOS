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

    void copyStack(Stack& destination) {
        copyStackRecursive(destination, top);
    }

private:
    void copyStackRecursive(Stack& destination, Node* node) {
        if (node == nullptr) {
            return;
        }
        copyStackRecursive(destination, node->next);
        destination.push(node->data);
    }
};

int main() {
    Stack stack1;
    stack1.push(10);
    stack1.push(20);
    stack1.push(30);

    Stack stack2;
    stack1.copyStack(stack2);

    cout << "Elements in copied stack: ";
    while (!stack2.isEmpty()) {
        cout << stack2.getTop() << " ";
        stack2.pop();
    }
    cout << endl;

    return 0;
}
