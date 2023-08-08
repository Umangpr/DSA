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

Node* floydDetectLoop(Node* head) {

    if(head == NULL)
        return NULL;

    Node* slow = head;
    Node* fast = head;

    while(slow != NULL && fast !=NULL) {
        
        fast = fast -> next;
        if(fast != NULL) {
            fast = fast -> next;
        }

        slow = slow -> next;

        if(slow == fast) {
            cout<< "both slow and fast presented at Node: " << slow->data<<endl;
            return slow;
        }
    }

    return NULL;

}

Node* getStartingNode(Node* head) {

    if(head == NULL) 
        return NULL;

    Node* intersection = floydDetectLoop(head);
    
    if(intersection == NULL)
        return NULL;
    
    Node* slow = head;

    while(slow != intersection) {
        slow = slow -> next;
        intersection = intersection -> next;
    }  

    return slow;

}

Node *removeLoop(Node *head)
{
    if( head == NULL)
        return NULL;

    Node* startOfLoop = getStartingNode(head);
    
    if(startOfLoop == NULL)
        return head;
    
    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop) {
        temp = temp -> next;
    } 

    temp -> next = NULL;
    return head;
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

    tail->next = head->next;

    cout<< "Head " << head->data << endl;
    cout<< "Tail " << tail->data << endl;

    if(floydDetectLoop(head) == NULL){
        cout<< "Loop is not present"<<endl;
    }
    else{
        cout<< "Loop is  present"<<endl;
    }

    Node* abc = getStartingNode(head);
    cout<<"Loop start at: " <<abc->data<<endl; 

    removeLoop(head);

    if(floydDetectLoop(head) == NULL){
        cout<< "Loop is not present"<<endl;
    }
    else{
        cout<< "Loop is  present"<<endl;
    }
    return 0;
}