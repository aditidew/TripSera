#include<iostream>
using namespace std;

class node{
public:
    int data;
    node * next;

    node(int value){
        data = value;
        next = nullptr;
    }
};

void display(node* &head){
    node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

node* detectLoop(node* &head){
    node* slow = head;
    node* fast = head;

    if (head == nullptr || head->next == nullptr) 
        return nullptr;

    while (fast != nullptr && fast->next != nullptr){
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast){
            // Loop detected
            slow = head;
            while (slow != fast){
                slow = slow->next;
                fast = fast->next;
            }
            return slow; // Starting node of loop
        }
    }

    return nullptr; // No loop
}

int main() {
    node* head = new node(1);
    node* second = new node(2);
    node* third = new node(3);
    node* fourth = new node(4);
    node* fifth = new node(5);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // Create loop
    fifth->next = third;

    node* startNode = detectLoop(head);

    if (startNode != nullptr) {
        cout << "Loop detected starting at node with value: " << startNode->data << endl;
    } else {
        cout << "No loop detected." << endl;
        display(head); // Safe to display if no loop
    }

    // ⚠️ Don't delete nodes unless loop is removed

    return 0;
}
