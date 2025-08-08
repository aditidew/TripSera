#include <iostream>
using namespace std;

#define MAX 1000

int queue[MAX];
int front = -1;
int rear = -1;

// Function to add (enqueue) an element
void enqueue(int x) {
    if (rear >= MAX - 1) {
        cout << "Queue Overflow\n";
        return;
    }
    if (front == -1) front = 0;  // First element
    queue[++rear] = x;
    cout << x << " enqueued into queue\n";
}

// Function to remove (dequeue) an element
int dequeue() {
    if (front == -1 || front > rear) {
        cout << "Queue Underflow\n";
        return -1;
    }
    int x = queue[front++];
    cout << x << " dequeued from queue\n";
    return x;
}

// Function to see the front element
int peek() {
    if (front == -1 || front > rear) {
        cout << "Queue is Empty\n";
        return -1;
    }
    return queue[front];
}

// Function to check if the queue is empty
bool isEmpty() {
    return (front == -1 || front > rear);
}

// Function to display queue elements
void display() {
    if (isEmpty()) {
        cout << "Queue is empty\n";
        return;
    }
    cout << "Queue elements (front to rear): ";
    for (int i = front; i <= rear; i++) {
        cout << queue[i] << " ";
    }
    cout << endl;
}

// Driver code
int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);

    display();  // Display current queue

    cout << "Front element is: " << peek() << endl;

    dequeue();
    display();  // Display after dequeue

    dequeue();
    dequeue();
    dequeue();  // This will cause underflow

    if (isEmpty())
        cout << "Queue is empty\n";
    else
        cout << "Queue is not empty\n";

    return 0;
}
