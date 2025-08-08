#include<iostream>
#include<bits/stdc++.h>
using namespace std;


class Node{
    public:
    int data;
    Node * next;

    Node(int value){
        data= value;
        next=nullptr;
    }
};

int countLL(Node*&head){
    Node* temp=head;
    int cnt=0;
    while(temp != nullptr){
        cnt++;
        temp=temp->next;
    }

    return cnt;
}

void display(Node*&head){
    Node *temp=head;
    while(temp!=nullptr){
        cout<< temp->data <<" -> ";
        temp=temp->next;
    }

    cout<< " NULL";
}

int main(){
    Node* head= new Node(0);
    head->next= new Node(1);
    head->next->next= new Node(2);
    head->next->next->next= new Node(3);
    head->next->next->next->next= new Node(4);
    head->next->next->next->next->next= new Node(5);
    cout<< "The list is:" <<endl;
    display(head);

    cout<< endl << "The length of LL is: ";
    cout<< countLL(head);

    return 0;
}
