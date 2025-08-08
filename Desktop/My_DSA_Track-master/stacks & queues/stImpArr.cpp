#include <iostream>
using namespace std;

#define MAX 1000

int stack[MAX];  // stack array
int top = -1;    // initially stack is empty

// Function to add an element to the stack
void push(int x) {
    if (top >= MAX - 1) {
        cout << "Stack Overflow\n";
        return;
    }
    top+=1;
    stack[top] = x;
    cout << x << " pushed into stack\n";
}

// Function to remove an element from the stack
int pop() {
    if (top < 0) {
        cout << "Stack Underflow\n";
        return -1;  // return an invalid value
    }
    int x = stack[top];
    top-=1;
    cout << x << " popped from stack\n";
    return x;
}

// Function to see the top element
int topMost() {
    if (top < 0) {
        cout << "Stack is Empty\n";
        return -1;
    }
    return stack[top];
}

// Function to check if the stack is empty
bool isEmpty() {
    return (top < 0);
}

// Function to display stack elements
void display() {
    if (top < 0) {
        cout << "Stack is empty\n";
        return;
    }
    cout << "Stack elements (top to bottom): ";
    for (int i = top; i >= 0; i--) {
        cout << stack[i] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    push(10);
    push(20);
    push(30);

    display();  // Display current stack

    cout << "Top element is: " << topMost() << endl;

    pop();
    display();  // Display after pop

    pop();
    pop();
    pop();  // This will cause underflow

    if (isEmpty())
        cout << "Stack is empty\n";
    else
        cout << "Stack is not empty\n";

    return 0;
}
