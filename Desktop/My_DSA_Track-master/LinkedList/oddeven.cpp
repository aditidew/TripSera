#include<iostream>
#include<bits/stdc++.h>
using namespace std;

class node{
    public:
    int data;
    node * next;

    node(int value){
        data=value;
        next=nullptr;
    }
};

void display(node* head){
    node* temp= head;
    while(temp!=nullptr){
        cout << temp->data << " -> ";
        temp=temp->next;
    }
    cout << " NULL "<<endl;
}

void oddEven(node * head){
    node*evenhead= head->next;
    node* odd= head;
    node *even= head->next;

    while (even != nullptr && even->next != nullptr) {
         odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        even = even->next;
    }
    odd->next= evenhead;
}

int main(){
    node* head= new node(10);
    head->next = new node(20);
    head->next->next = new node(30);
    head->next->next->next = new node(40);
    head->next->next->next->next = new node(50);


    display(head);

    oddEven(head);
    display(head);
    return 0;
}