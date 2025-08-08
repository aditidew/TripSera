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

Node* reverseLL(Node* head){
    if(head== nullptr || head->next== nullptr){
        return head;
    }
    Node* newhead= reverseLL(head->next);
    Node * front =head->next;
    front->next= head;
    head->next= nullptr;

    return newhead;
}
bool isPalindrome(Node* head) {
    if (head == NULL || head->next == NULL) {
        
         // It's a palindrome by definition
        return true; 
    }
    Node* slow = head;
    Node* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        
        // Move slow pointer one step at a time
        slow = slow->next;  
        
        fast = fast->next->next;  
    }
    Node* newHead = reverseLL(slow->next);
    
    // Pointer to the first half
    Node* first = head;  
    Node* second = newHead; 
    while (second != NULL) {
   
        if (first->data != second->data) {
            reverseLL(newHead);  

            return false;
        }
        first = first->next; 
        second = second->next;  
    }
    reverseLL(newHead);  

    return true;  
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
    append(head, tail, 10);

    cout << "Original Linked List: ";
    display(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    display(head);

    return 0;
}
