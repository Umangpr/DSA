#include<iostream>
#include<map>
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


void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data<<"  ";
        temp = temp ->next;
    }
    cout << endl;
}
bool detectLoop(Node* head){
    if(head == NULL){
        return false;
    }

    map<Node* , bool> visited;

    Node* temp = head;

    while(temp != NULL){
        if(visited[temp] == true){
            cout<< "Loop is presented at "<<temp->data<<endl;
            return true;
        }
        visited[temp] = true;
        temp = temp->next;
    }
    return false;
}

int main(){
    Node* node1 = new Node(10);
    cout << node1 -> data << endl;
    cout << node1 ->next <<endl;

    Node* head = node1;
    Node* tail = node1;

    InsertAtHead(head, 5);

    print(head);

    InsertAtHead(head, 252);
    print(head);

    InsertAtTail(tail, 89);
    print(head);
    InsertAtTail(tail,42);
    print(head);

    InsertAtPosition(tail,head, 6,420);
    print(head);

    tail-> next = head-> next->next->next;

    cout<< "Head " << head->data << endl;
    cout<< "Tail " << tail->data << endl;

    if(detectLoop(head)==true){
        cout << "Loop is present. "<<endl;
    }else{
        cout<< "Loop is not presented. "<< endl;
    }

    return 0;
}