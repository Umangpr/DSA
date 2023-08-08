Node* kreverse(Node* head, int k){
    if(head == NULL)
        return NULL;
    
    //step 1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev;
    
    int count = 0;


    while(curr !=NULL && count < k ){
        next = curr->next;
        curr->next = prev;
        prev  =  curr;
        curr = next;
        count++;
    }

    //step2: Recursion sambhal lega
    if(next!= Null){
        head->next = kreverse(next, k );
    }

    //step3: return head of reversed list
    return prev;
}