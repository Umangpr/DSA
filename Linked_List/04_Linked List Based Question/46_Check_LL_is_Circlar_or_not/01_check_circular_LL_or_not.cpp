#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int d) : data(d), next(nullptr) {}

    // Destructor
    ~Node() {
        int value = this->data;
        if (this->next != nullptr) {
            delete next;
            next = nullptr;
        }

        cout << "Memory is freed for node with data " << value << endl;
    }
};

void insertNode(Node*& tail, int d) {
    if (tail == nullptr) {
        Node* newNode = new Node(d);
        tail = newNode;
        newNode->next = newNode;
    } else {
        Node* newNode = new Node(d);
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }
}

void print(Node* tail) {
    if (tail == nullptr) {
        cout << "Circular linked list is empty." << endl;
        return;
    }

    Node* temp = tail->next;
    cout << tail->data << " ";

    while (temp != tail) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
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

int main() {
    Node* tail = nullptr;

    // Empty list - insert element
    insertNode(tail, 3);
    insertNode(tail,32 );
    insertNode(tail, 32);
    insertNode(tail, 23);
    insertNode(tail, 52);
    insertNode(tail, 78);
    insertNode(tail, 45);
    insertNode(tail, 120);
    insertNode(tail, 74);
    insertNode(tail, 89);
    insertNode(tail, 51);
    insertNode(tail,41);
    insertNode(tail, 783);
    insertNode(tail, 45);
    insertNode(tail, 459);
    insertNode(tail, 879);
    insertNode(tail, 788);

    print(tail);
    cout<<endl;
    cout<<endl;

    
    cout<<isCircularLL(tail)<<endl;

    return 0;
}
