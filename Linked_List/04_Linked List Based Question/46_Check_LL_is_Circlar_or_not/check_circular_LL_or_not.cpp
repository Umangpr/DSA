#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int d){
            this->data = d;
            this->next = NULL;
        }
};

void insertIntoHead(Node* &head, int d){
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout<< temp->data << " ";
        temp = temp->next;
    }
}

bool isCircularLL(Node* head){
    //empty list
    if(head == NULL){
        return false;
    }
    Node* temp = head->next;
    while(temp != NULL && temp != head){
        temp = temp->next;
    }

    if(temp == head){
        return true;
    }
    return false;
}



int main(){
    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = head;

    insertIntoHead(head,20);
    insertIntoHead(head,30);
    insertIntoHead(head,40);
    insertIntoHead(head,50);
    insertIntoHead(head,60);
    insertIntoHead(head,70);
    insertIntoHead(head,80);
    insertIntoHead(head,90);
    insertIntoHead(head,100);
    insertIntoHead(head,120);
    insertIntoHead(head,140);
    print(head);
    cout<< endl;
    if(isCircularLL(head)){
        cout << "Linked List is circular in nature." << endl;  
    }else{
        cout << "Linked List is not circular in nature." << endl;  
    }
    cout<< endl;
    cout<< head->data;
    return 0;
}