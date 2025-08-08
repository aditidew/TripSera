#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to create a new node
Node* createNode(int value) {
    Node* newnode = new Node;
    newnode->data = value;
    newnode->next = nullptr;
    return newnode;
}

// Append a node to the end of the list
void append(Node*& head, Node*& tail, int value) {
    Node* newnode = createNode(value);
    if (head == nullptr) {
        head = tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}

// Display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Delete the last (tail) node
void deleteTail(Node*& head, Node*& tail) {
    if (head == nullptr) {
        // List is empty
        return;
    }

    if (head == tail) {
        // Only one node in the list
        delete head;
        head = tail = nullptr;
        return;
    }

    // Traverse to the second last node
    Node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }

    delete tail;
    tail = temp;
    tail->next = nullptr;
}


void deleteAtK(Node* head, int k){
    if(head== nullptr) return;
    // if( k==1){
    //     Node* temp=head;
    //     head=head->next;
    //     free(temp);
        


    // }
    Node* temp=head;
    int cnt=0; 
    Node* prev= nullptr;
    while(temp!=nullptr){
        cnt++;
       
        if(cnt==k){
            prev->next= prev->next->next;
            free(temp);
            break;

        }
        prev=temp;
        temp=temp->next;
    }
}

void deleteEL(Node* head, int el){
    if(head== nullptr) return;
    if( head->data==el){
        Node* temp=head;
        head=head->next;
        free(temp);
        


    }
    Node* temp=head;
    Node* prev= nullptr;
    while(temp!=nullptr){
        if(temp->data==el){
            prev->next= prev->next->next;
            free(temp);
            break;

        }
        prev=temp;
        temp=temp->next;
    }
}



void deleteHead(Node * &head, Node* &tail){
    if(head== nullptr) return;

    if(head==tail){
        delete head;
        head= nullptr;
        return;
    }

    Node* temp=head;
    head= head->next;
    delete temp;



}
// Main function to demonstrate usage


int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int k=2;
    int el=30;

    append(head, tail, 10);
    append(head, tail, 20);
    append(head, tail, 30);
    append(head, tail, 40);

    cout << "Initial list: ";
    display(head);

    // Delete last node
    deleteTail(head, tail);
    cout << "After deleting tail: ";
    display(head);

    // deleteHead(head, tail);
    // cout << "After deleting head ";
    // display(head);

    // deleteAtK(head, k);
    // cout << "After deleting at "<< k <<"th position \n" ;
    // display(head);

    deleteEL(head, el);
    cout << "After deleting the element "<< el <<"\n" ;
    display(head);
    return 0;
}


