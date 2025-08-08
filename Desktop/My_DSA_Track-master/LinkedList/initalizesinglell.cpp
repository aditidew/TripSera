#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newnode = new Node;
    newnode->data = value;
    newnode->next = nullptr;
    return newnode;
}

// Append using both head and tail references
void append(Node*& head, Node*& tail, int value) {
    Node* newnode = createNode(value);
    if (head== nullptr) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

// Display the list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    append(head, tail, 10);
    append(head, tail, 20);
    append(head, tail, 30);

    display(head);

    return 0;
}
