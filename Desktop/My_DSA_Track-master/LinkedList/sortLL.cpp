#include <iostream>
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

// Function to print the linked list
void display(Node* head) {
    while (head) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "NULL\n";
}

// Function to find the middle of the list
Node* getMiddle(Node* head) {
    if (!head || !head->next) return head;

    Node* slow = head;
    Node* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to merge two sorted linked lists
Node* merge(Node* left, Node* right) {
    Node* dummy = new Node(-1);
    Node* temp = dummy;

    while (left && right) {
        if (left->data < right->data) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    if (left) temp->next = left;
    if (right) temp->next = right;

    return dummy->next;
}

// Merge sort function
Node* mergeSort(Node* head) {
    if (!head || !head->next) return head;

    Node* mid = getMiddle(head);
    Node* rightHead = mid->next;
    mid->next = nullptr;

    Node* left = mergeSort(head);
    Node* right = mergeSort(rightHead);

    return merge(left, right);
}

// Helper function to insert at tail
void insertAtTail(Node*& head, Node*& tail, int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        tail = newNode;
    }
}

// ---------- MAIN ----------
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;

    insertAtTail(head, tail, 4);
    insertAtTail(head, tail, 2);
    insertAtTail(head, tail, 1);
    insertAtTail(head, tail, 5);
    insertAtTail(head, tail, 3);

    cout << "Original List: ";
    display(head);

    head = mergeSort(head);

    cout << "Sorted List:   ";
    display(head);

    return 0;
}
