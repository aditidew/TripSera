#include <iostream>
using namespace std;

// Define a node of the queue
struct Node {
    int data;
    Node* next;
};

Node* front = nullptr;
Node* rear = nullptr;

// Enqueue operation
void enqueue(int x) {
    Node* newNode = new Node();
    if (!newNode) {
        cout << "Heap Overflow\n";
        return;
    }
    newNode->data = x;
    newNode->next = nullptr;

    if (rear == nullptr) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << x << " enqueued into queue\n";
}

// Dequeue operation
int dequeue() {
    if (front == nullptr) {
        cout << "Queue Underflow\n";
        return -1;
    }
    Node* temp = front;
    int val = front->data;
    front = front->next;

    if (front == nullptr)  // If queue became empty
        rear = nullptr;

    delete temp;
    cout << val << " dequeued from queue\n";
    return val;
}

// Peek operation
int peek() {
    if (front == nullptr) {
        cout << "Queue is empty\n";
        return -1;
    }
    return front->data;
}

// Check if queue is empty
bool isEmpty() {
    return (front == nullptr);
}

// Display queue elements
void display() {
    if (front == nullptr) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements (front to rear): ";
    Node* temp = front;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Driver code
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();  // Show queue

    cout << "Front element is: " << peek() << endl;

    dequeue();
    display();  // Show after dequeue

    dequeue();
    dequeue();
    dequeue();  // Underflow

    if (isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";

    return 0;
}
