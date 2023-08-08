#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(int d ){
            this->data = d;
            this->next = this->prev = NULL;
        }

        // Destructor
        ~Node(){
            int value = this->data;
            //memory free
            if(this->next != NULL){
                delete next;
                this->next = NULL;
            }
            cout << "Memory is free for node with data "<< value <<endl;
        }
};


//traversing a linked list
void print(Node* head){
    Node* temp = head;

    while(temp != NULL){
        cout << temp->data << " ";
        temp = temp ->next;
    }
    cout<<endl;
}

// gives length of Linked List
int getLength(Node* head){
    Node* temp = head;
    int len=0;

    while(temp != NULL){
        len++;
        temp = temp ->next;
    }
    return len;
}

void insertAtHead(Node* &head,Node* &tail, int d){
    if (head == NULL)
    {
        Node* temp =new Node(d);
        head = temp;
    }

    else{
        Node* temp = new Node(d);
        temp->next  = head;
        head->prev = temp;
        head = temp; 
    }
    
}

void insertAtTail( Node* &head,Node* &tail, int d ){
    if(tail == NULL){
        Node* temp = new Node(d);
        tail=temp;
    }
    else{
        Node* temp = new Node(d);
        temp-> prev = tail->next;
        tail->next = temp;
        tail = tail->next;
    }

}

void insertAtPosition ( Node* &head, Node* &tail,int position, int d ){

    if(position == 1){
        insertAtHead(head,tail, d);
        return;
    }

    Node* temp = head;
    int count = 1;

    while(count < position-1){
        temp = temp ->next;
        count++;
    }

    if(temp->next == NULL){
        insertAtTail(head, tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp ->next -> prev = nodeToInsert;
    temp-> next = nodeToInsert;
    nodeToInsert ->prev = temp;
}

void deleteNode( Node* &head, int position){
    if(position==1){
        Node* temp = head;
        temp->next ->prev = NULL;
        head = temp-> next;
        temp -> next =NULL;

        delete temp;
    }
    else{
        //deleting any middle  node or last node
        Node* curr=head;
        Node* prev = NULL;

        int count = 1;
        while(count < position){
            prev = curr;
            curr = curr->next;
            count++;
        }
        curr ->prev = NULL;
        prev -> next = curr -> next;
        curr -> next = NULL;

        delete curr;
    }

}

int main(){
    Node* node1 = new Node(25);
    Node* head = node1; 
    Node* tail = node1;

    print(head);


    insertAtHead(head,tail, 23);
    print(head);
    //cout << getLength(head)<<endl;

    insertAtTail(head,tail, 72);
    insertAtTail(head, tail, 82);
    insertAtTail(head, tail, 92);
    print(head);

    // cout<< "Head -> " << head->data<< endl;
    // cout<< "Tail -> " << tail->data<< endl;

    insertAtPosition( head,tail, 6, 420);
    print(head);

    deleteNode(head, 2);
    print(head);
    cout<< "Head -> " << head->data<< endl;
    cout<< "Tail -> " << tail->data<< endl;


    // delete(head);
    // print(head);
    return 0;
}