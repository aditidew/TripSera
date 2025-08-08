#include <bits/stdc++.h>
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

void reverseList(Node* &head){
    Node* curr=head;
    Node*prev= nullptr;
    Node*front;

    while(curr!=nullptr){
        front= curr->next;
        curr->next=prev;
        prev=curr;
        curr=front;
    }
    head=prev;
}

void display(Node* &head) {
    while (head != nullptr) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    // Creating a sample linked list: 1 -> 2 -> 3 -> 4 -> 5 ->6
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    head->next->next->next->next->next = new Node(6);

    reverseList(head);
    cout<< "The reversed list is: ";
    display(head);
    return 0;
}
