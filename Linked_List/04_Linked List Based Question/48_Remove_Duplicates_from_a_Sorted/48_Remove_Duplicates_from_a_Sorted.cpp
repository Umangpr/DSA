#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        // Constructor
        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

void InsertAtHead(Node* &head, int d){
    //Create a new node
    Node* temp = new Node(d);
    temp->data = d;
    temp->next = head;
    head = temp;
}

void InsertAtTail(Node* &tail, int d){
    Node* temp = new Node(d);
    tail -> next = temp;
    tail = tail -> next;
}

void InsertAtPosition(Node* &tail,Node* &head, int position, int d){
    // nth position pr node insert krna  to (n-1) position tk travers kro

    Node* temp = head;
    int count = 1;

    if(position == 1){
        InsertAtHead(head, d);
        return;
    }

    while(count < position-1){
        temp = temp ->next;
        count ++;
    }
    
    if(temp->next == NULL){
        InsertAtTail(tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp ->next; 
    temp -> next = nodeToInsert;

}


void print(Node* &head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data<<"  ";
        temp = temp ->next;
    }
    cout << endl;
}

Node* uniqueSortedList(Node* head){
    //empty list
    if(head == NULL){
        return NULL;
    }

    //non empty list
    Node* curr = head;

    while(curr != NULL){
        if((curr ->next != NULL) && curr->data == curr->next->data){
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete(nodeToDelete);
            curr->next =next_next;
        }

        //not equal
        else{
            curr= curr->next;
        }
    }
    return head;
}

int main(){
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 ->next <<endl;

    Node* head = node1;
    Node* tail = node1;

    InsertAtHead(head, 10);

    print(head);

    InsertAtHead(head, 9);
    print(head);

    InsertAtTail(tail, 11);
    print(head);
    InsertAtTail(tail,11);
    print(head);

    // InsertAtPosition(tail,head, 6,420);
    // print(head);

    cout<< "Head " << head->data << endl;
    cout<< "Tail " << tail->data << endl;

    uniqueSortedList(head);
    print(head);


    return 0;
}