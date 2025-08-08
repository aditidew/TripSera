#include <iostream>
using namespace std;

// Define a node of the stack
struct Node {
    int data;
    Node* next;
};

Node* top = nullptr;  // Initially stack is empty

// Push operation
void push(int x) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Heap Overflow\n";
        return;
    }
    newNode->data = x;
    newNode->next = top;
    top = newNode;
    cout << x << " pushed into stack\n";
}

// Pop operation
int pop() {
    if (top == nullptr) {
        cout << "Stack Underflow\n";
        return -1;
    }
    Node* temp = top;
    int popped = top->data;
    top = top->next;
    delete temp;
    cout << popped << " popped from stack\n";
    return popped;
}

// Peek operation
int peek() {
    if (top == nullptr) {
        cout << "Stack is empty\n";
        return -1;
    }
    return top->data;
}

// Check if stack is empty
bool isEmpty() {
    return (top == nullptr);
}

// Display stack elements
void display() {
    if (top == nullptr) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements (top to bottom): ";
    Node* temp = top;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code
int main() {
    push(10);
    push(20);
    push(30);

    display();  // Show stack

    cout << "Top element is: " << peek() << endl;

    pop();
    display();  // Show after pop

    pop();
    pop();
    pop();  // Underflow

    if (isEmpty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";

    return 0;
}
