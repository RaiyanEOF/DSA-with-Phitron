#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val = val;
        this->next = NULL;
    }
};
void insert_at_tail(Node* &head, Node* &tail,int val){
    Node* newnode = new Node(val);
    if(head==NULL){
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}
void insert_at_head(Node* &head,Node* &tail,int val){
    Node* newnode = new Node(val);
    if(head==NULL){
        head = newnode;
        tail = newnode;
    }
    else{
    newnode->next = head;
    head = newnode;
    }
}
void delete_at_any_pos(Node* &head,Node* &tail,int index){
    if(head==NULL) return;
    if(index==0){
        Node* deleteNode = head;
        head = head->next;
        if(head==NULL) tail = NULL;
        delete deleteNode;
        return;
    }
    Node* temp = head;
    for(int i=0;i<index-1;i++){
        if(temp == NULL || temp->next == NULL) return;
        temp = temp->next;
    }
    if(temp->next == NULL) return;
    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    if(temp->next==NULL) tail = temp;
    delete deleteNode;
}
void print_linked_list(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout << temp->val;
        if(temp->next != NULL) cout << " ";
        temp = temp->next;
    }
}
int main(){
    int q;
    cin >> q;
        Node* head = NULL;
        Node* tail = NULL;
    while(q--){
        int x,v;
        cin >> x >> v;
        if(x==0){
            insert_at_head(head,tail,v);
        }
        else if(x==1){
            insert_at_tail(head,tail,v);
        }
        else{
            delete_at_any_pos(head,tail,v);
        }
        print_linked_list(head);
        cout << endl;
    }
    return 0;
}
