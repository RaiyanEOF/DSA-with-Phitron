#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int value;
    Node* next;
    Node(int val){
        value = val;
        next = NULL;
    }
};
class LinkedList{
public:
    Node* head;
    Node* tail;
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void insert_at_head(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
        if(tail == NULL){ 
            tail = head;
        }
    }
    void insert_at_tail(int val){
        Node* newNode = new Node(val);
        if(head == NULL){ 
            head = newNode;
            tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }
    void delete_at_any_pos(int idx){
        if(head == nullptr) return; 
        if(idx == 0){ 
            Node* temp = head;
            head = head->next;
            if(head == NULL){ 
                tail = NULL;
            }
            delete temp;
            return;
        }
        Node* temp = head;
        for(int i = 1; i < idx; ++i){
            if(temp->next == NULL) return; 
            temp = temp->next;
        }
        if(temp->next == NULL) return; 
        Node* deleteNode = temp->next;
        temp->next = temp->next->next;
        if(deleteNode == tail){ 
            tail = temp;
        }
        delete deleteNode;
    }
    void print_list(){
        Node* temp = head;
        if(temp == NULL){
            cout << endl;
            return;
        }
        while(temp != NULL){
            cout << temp->value;
            if(temp->next != NULL){
                cout << " ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
};
int main(){
    int Q;
    cin >> Q;
    LinkedList list;
    for(int i = 0; i < Q; ++i){
        int X, V;
        cin >> X >> V;
        if(X == 0){
            list.insert_at_head(V); 
        } 
        else if(X == 1){
            list.insert_at_tail(V); 
        } 
        else if(X == 2){
            list.delete_at_any_pos(V); 
        }
        list.print_list();
    }
    return 0;
}
