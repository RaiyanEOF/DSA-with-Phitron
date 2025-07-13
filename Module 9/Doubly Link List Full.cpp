#include<bits/stdc++.h>
using namespace std;
class Node{
    public :
    Node* next;
    Node* prev;
    int val;
    Node(int val){
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void insert_at_head(Node* &head, Node* &tail,int val){
    Node* newNode = new Node(val);
    if(head==NULL){
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insert_at_any_pos(Node* &head, Node* &tail, int idx, int val) {
    if(idx == 0){
        insert_at_head(head, tail, val);
        return;  
    }
    Node* temp = head;
    int i = 0;
    while (temp != NULL && i < idx - 1){
        temp = temp->next;
        i++;
    }
    if(temp == NULL || temp->next == NULL){
        insert_at_tail(head, tail, val);
        return;
    }
    Node* newNode = new Node(val);
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
void delete_at_head(Node* &head,Node* &tail){
    if(head==NULL){
        return;
    }
    Node* deleteNode = head;
    if(head->next==NULL){
        head = NULL;
        tail = NULL;
    }
    else{
        head = head->next;
        head->prev = NULL;
    }
    delete deleteNode;
}
void delete_at_tail(Node* &head, Node* &tail){
    if(head==NULL){
        return;
    }
    Node* deleteNode = tail;
    if(head==tail){
        head = NULL;
        tail = NULL;
    }
    else{
        tail = tail->prev;
        tail->next = NULL;
    }
    delete deleteNode;
}
void delete_at_any_pos(Node* &head,Node* &tail,int idx){
    if(head==NULL){
        return;
    }
    if(idx==0){
        delete_at_head(head,tail);
        return;
    }
    Node* temp = head;
    for(int i=1;i<idx;i++){
        if(temp == NULL) return;
        temp = temp->next;
    }
    if(temp==NULL || temp->next==NULL){
        delete_at_tail(head,tail);
        return;
    }
    else{
    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    temp->next->prev = temp;
    }
    delete deleteNode;
}
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    while(true){
        int val;
        cin >> val;
        if(val==-1) break;
        insert_at_tail(head,tail,val);
    }
    return 0;
}
