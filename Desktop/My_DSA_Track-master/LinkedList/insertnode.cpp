#include<bits/stdc++.h>
using namespace std;


struct node{
    int data;
     struct node *next;
};

node * createnode(int value){
    node* newnode= new node;
    newnode->data= value;
    newnode->next= nullptr;
    return newnode;
}


void append(node* &head, node* &tail, int value){
     node* newnode= createnode(value);
     if(head==nullptr){
        head= tail= newnode;
     }

     else{
        tail->next= newnode;
        tail=newnode;
     }
    }


void display(node* head){
    node*temp=head;
    while(temp!=nullptr){
        cout<< temp->data <<" -> ";
        temp=temp->next;
    }
    cout << "NULL" << endl;
}

void insertAtBeginning(node* &head, node* &tail, int value) {
    node* newnode = createnode(value);
    newnode->next = head;
    head = newnode;

    // If the list was previously empty
    if (tail == nullptr) {
        tail = newnode;
    }
}

void insertAtEnd(node* &head, node* &tail, int value) {
    node* newnode = createnode(value);
    tail->next = newnode;
    tail = newnode;

    // If the list was previously empty
    if (tail == nullptr) {
        tail = newnode;
    }
}


void insertAtPosition(node* &head, node* &tail, int value, int k) {
    node* newnode = createnode(value);

    // Case 1: Insert at the beginning or when list is empty
    if (k <= 1 || head == nullptr) {
        newnode->next = head;
        head = newnode;
        if (tail == nullptr) tail = newnode;
        return;
    }

    node* temp = head;
    int cnt = 1;

    // Traverse to (k-1)th node or last node if k is beyond length
    while (temp->next != nullptr && cnt < k - 1) {
        temp = temp->next;
        cnt++;
    }

    // Insert after (k-1)th node
    newnode->next = temp->next;
    temp->next = newnode;

    // Update tail if inserted at the end
    if (newnode->next == nullptr) {
        tail = newnode;
    }
}




int main() {
    node* head = nullptr;
    node* tail = nullptr;
    int k=2;
    int el=500;
    int value=100;

    append(head, tail, 200);
    append(head, tail, 300);
    append(head, tail, 400);
    cout<< "Initial LL: ";
    display(head);


    insertAtBeginning(head, tail, value);
    cout<< "After inserting "<< value << " at first position: ";
    display(head);


    insertAtEnd(head, tail, el);
    cout<< "After inserting "<< el << " at last position: ";
    display(head);



    insertAtPosition(head, tail, 335,4);
    cout<< "After inserting 335" << " at k position: ";
    display(head);
}



    