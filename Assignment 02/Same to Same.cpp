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
bool same_same(Node* head1,Node* head2){
    while(head1 != NULL && head2 != NULL){
        if(head1->val != head2->val) return false;
        head1 = head1->next;
        head2 = head2->next;
    }
    return head1 == NULL && head2 == NULL;
}
int main(){
    Node* head1 = NULL;
    Node* tail1 = NULL;
    while(true){
        int val1;
        cin >> val1;
        if(val1==-1) break;
        insert_at_tail(head1,tail1,val1);
    }
    Node* head2 = NULL;
    Node* tail2 = NULL;
    while(true){
        int val2;
        cin >> val2;
        if(val2 == -1) break;
        insert_at_tail(head2,tail2,val2);
    }
    if(same_same(head1,head2)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
