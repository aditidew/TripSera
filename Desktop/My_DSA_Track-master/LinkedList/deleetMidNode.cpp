#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

void deleteMid(Node*& head) {
    if (head == nullptr || head->next == nullptr) {
        delete head;
        head = nullptr;
        return;
    }

    Node* slow = head;
    Node* fast = head;
    fast=fast->next->next;
    

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    slow->next = slow->next->next;
    
}

void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    cout << "Original Linked List:\n";
    display(head);

    deleteMid(head);

    cout << "Linked List After Deleting Middle Node:\n";
    display(head);

    return 0;
}
