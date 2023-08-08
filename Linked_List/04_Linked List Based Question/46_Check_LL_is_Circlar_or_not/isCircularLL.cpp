#include <iostream>
using namespace std;

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
// Node class for 