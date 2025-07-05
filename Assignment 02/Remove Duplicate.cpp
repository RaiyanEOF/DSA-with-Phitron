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
void print_linked_list(Node* head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->val;
        if(temp->next != NULL) cout << " ";
        temp = temp->next;
    }
    cout << endl;
}
void remove_duplicate(Node* &head){
    Node* i = head;
    while(i != NULL){
        Node* prev = i;
        Node* curr = i->next;
        while(curr != NULL){
            if(curr->val == i->val){
                prev->next = curr->next;
                delete curr;
                curr = prev->next;
            }
            else{
                prev = curr;
                curr = curr->next;
            }
        }
        i = i->next;
    }
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
    remove_duplicate(head);
    print_linked_list(head);
    return 0;
}
