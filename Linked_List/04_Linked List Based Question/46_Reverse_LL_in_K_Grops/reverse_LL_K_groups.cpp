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

Node* kReverse(Node* &head,int k){
    //base case
    if(head == NULL){
        return NULL;
    }

    //step1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;

    int count = 0;
    while(curr != NULL && count < k ){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        count++;
    }

    //step2: recursion dekh lega aage ka 
    if(next != NULL){
        head->next = kReverse(next,k);
    }

    //step3: return head of reversed list
    head = prev;
    return prev;
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
    print(kReverse(head,4));
    cout<< endl;
    cout<< endl;

    print(head);
    cout<< endl;
    return 0;
}