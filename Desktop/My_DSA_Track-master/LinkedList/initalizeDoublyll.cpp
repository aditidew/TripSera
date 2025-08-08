#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newnode = new Node;
    newnode->data = value;
    newnode->prev = nullptr;
    newnode->next = nullptr;
    return newnode;
}

// Append using both head and tail references
void append(Node*& head, Node*& tail, int value) {
    Node* newnode = createNode(value);
    if (head == nullptr) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

// Insert at the beginning
void insertAtFirst(Node*& head, Node*& tail, int value) {
    Node* newnode = createNode(value);
    newnode->next = head;
    if (head == nullptr) {
        head = tail = newnode;
    } else {
        head->prev = newnode;
        head = newnode;
    }
}

void insertAtTail(Node*& head, Node*& tail, int value) {
    Node* newnode = createNode(value);
    if (head == nullptr) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        newnode->prev = tail;
        tail = newnode;
    }
}

void insertInBetween(Node*& head, Node*& tail, int k, int value) {
    if (k <= 1) {
        insertAtFirst(head, tail, value);
        return;
    }

    Node* temp = head;
    int cnt = 1;

    while (temp != nullptr && cnt < k - 1) {
        temp = temp->next;
        cnt++;
    }

    if (temp == nullptr || temp == tail) {
        insertAtTail(head, tail, value);
        return;
    }

    Node* newnode = createNode(value);
    Node* front = temp->next;

    temp->next = newnode;
    newnode->prev = temp;
    newnode->next = front;
    front->prev = newnode;
}


void deleteHead(Node* &head, Node* &tail){
    Node* temp= head;
    if(head== nullptr) return;

    if(head==tail){
        delete head;
        head= tail = nullptr;
        return;
    }

    head= head->next;
    head->prev= nullptr;
    temp->next= nullptr;
    delete temp;
}

void deletetail(Node* &head, Node* &tail){
    if(head== nullptr) return;

    if(head==tail){
        delete head;
        head = tail = nullptr;
        return;
    }

    Node* temp = tail;
    tail=tail->prev;
    tail->next= nullptr;
    temp->prev= nullptr;
    delete temp;
}

void deleteInBetween(Node* &head, Node* &tail, int k) {
    if (head == nullptr || k <= 0) return;

    if (head == tail && k == 1) {
        delete head;
        head = tail = nullptr;
    } else {
        Node* temp = head;
        int cnt = 1;

        while (temp != nullptr) {
            if (cnt == k) break;
            temp = temp->next;
            cnt++;
        }

        if (temp == nullptr) return; // k is out of range

        if (temp == head) {
            head = head->next;
            head->prev = nullptr;
            delete temp;
        } else if (temp == tail) {
            tail = tail->prev;
            tail->next = nullptr;
            delete temp;
        } else {
            Node* back = temp->prev;
            Node* front = temp->next;
            back->next = front;
            front->prev = back;
            delete temp;
        }
    }
}


void reverseList(Node*& head, Node*& tail) {
    if (head == nullptr || head == tail) return;

    Node* current = head;
    Node* temp = nullptr;

    while (current != nullptr) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    temp = head;
    head = tail;
    tail = temp;
}


// Display the list forward
void displayForward(Node* head) {
    Node* temp = head;
    cout << "Forward: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Display the list backward
void displayBackward(Node* tail) {
    Node* temp = tail;
    cout << "Backward: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->prev;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int k = 2;

    append(head, tail, 10);
    append(head, tail, 20);
    append(head, tail, 30);

    displayForward(head);
    displayBackward(tail);

    cout << "\nInserting 5 at the beginning:\n";
    insertAtFirst(head, tail, 5);
    displayForward(head);

    cout << "\nDeleting node at position " << k << ":\n";
    deleteInBetween(head, tail, k);
    displayForward(head);
    

    insertAtTail(head, tail, 40);
    displayForward(head);


   cout << "\nInserting 25 at position 3:\n";
   insertInBetween(head, tail, 3, 25);
   displayForward(head);
    
cout<< "\n Reversed List \n";
    reverseList(head, tail);
    displayForward(head);

    return 0;
}
