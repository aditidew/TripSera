#include<iostream>
using namespace std;

class node {
public:
    int data;
    node* next;

    node(int value) {
        data = value;
        next = nullptr;
    }
};

void display(node* &head) {
    node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node* reverseByK(node*& head, int k) {
    // Check if we have at least k nodes to reverse
    node* temp = head;
    int cnt = 0;
    while (cnt < k && temp != nullptr) {
        temp = temp->next;
        cnt++;
    }

    if (cnt < k) return head;

    // Reverse k nodes
    node* prev = nullptr;
    node* curr = head;
    node* front = nullptr;
    int i = 0;
    while (curr != nullptr && i < k) {
        front = curr->next;
        curr->next = prev;
        prev = curr;
        curr = front;
        i++;
    }

    // Recursive call for remaining list
    if (curr != nullptr) {
        head->next = reverseByK(curr, k);
    }

    return prev;
}

int main() {
    node* head = new node(1);
    head->next = new node(2);
    head->next->next = new node(3);
    head->next->next->next = new node(4);
    head->next->next->next->next = new node(5);

    int k = 2;
    head = reverseByK(head, k); // capture new head
    display(head);

    return 0;
}
