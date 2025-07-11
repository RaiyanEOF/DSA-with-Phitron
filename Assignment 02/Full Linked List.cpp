#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};
void insert_at_head(Node* &head, Node* &tail, int val) {
    Node* newnode = new Node(val);
    if(head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        newnode->next = head;
        head = newnode;
    }
}
void insert_at_tail(Node* &head, Node* &tail, int val) {
    Node* newnode = new Node(val);
    if(head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        tail->next = newnode;
        tail = newnode;
    }
}
void insert_at_any_pos(Node* &head, Node* &tail, int index, int val) {
    if(index == 0) {
        insert_at_head(head, tail, val);
        return;
    }
    Node* temp = head;
    for(int i = 0; i < index - 1; i++) {
        if(temp == NULL) return;
        temp = temp->next;
    }
    if(temp == NULL) return;
    if(temp == tail) {
        insert_at_tail(head, tail, val);
        return;
    }
    Node* newnode = new Node(val);
    newnode->next = temp->next;
    temp->next = newnode;
}
void delete_at_head(Node* &head, Node* &tail) {
    if(head == NULL) return;
    Node* deleteNode = head;
    head = head->next;
    if(head == NULL) tail = NULL;
    delete deleteNode;
}
void delete_at_tail(Node* &head, Node* &tail) {
    if(head == NULL) return;
    if(head == tail) {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    Node* temp = head;
    while(temp->next != tail) {
        temp = temp->next;
    }
    delete tail;
    tail = temp;
    tail->next = NULL;
}
void delete_at_any_pos(Node* &head, Node* &tail, int index) {
    if(head == NULL) return;
    if(index == 0) {
        delete_at_head(head, tail);
        return;
    }
    Node* temp = head;
    for(int i = 0; i < index - 1; i++) {
        if(temp == NULL || temp->next == NULL) return;
        temp = temp->next;
    }
    if(temp->next == NULL) return;
    if(temp->next == tail) {
        delete_at_tail(head, tail);
        return;
    }
    Node* deleteNode = temp->next;
    temp->next = temp->next->next;
    delete deleteNode;
}
void reverse_linked_list(Node*& head, Node*& tail, Node* temp) {
    if (temp->next == NULL){
        head = temp;
        return;
    }
    reverse_linked_list(head, tail, temp->next);
    temp->next->next = temp;
    temp->next = NULL;
    tail = temp;
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
int main(){
    Node* head = NULL;
    Node* tail = NULL;
    cout << "Menu:\n";
    cout << "1. Insert at head\n";
    cout << "2. Insert at tail\n";
    cout << "3. Insert at any position\n";
    cout << "4. Delete at head\n";
    cout << "5. Delete at tail\n";
    cout << "6. Delete at any position\n";
    cout << "7. Reverse list\n";
    cout << "8. Print linked list\n";
    cout << "0. Exit\n";
    int t;
    cin >> t;
    while(t--){
        int choice;
        cout << "Enter choice: ";
        cin >> choice;
        if(choice == 0) break;
        if(choice == 1){
            int val;
            cout << "Enter value: ";
            cin >> val;
            insert_at_head(head, tail, val);
        } 
        else if(choice == 2){
            int val;
            cout << "Enter value: ";
            cin >> val;
            insert_at_tail(head, tail, val);
        } 
        else if(choice == 3){
            int index, val;
            cout << "Enter index and value: ";
            cin >> index >> val;
            insert_at_any_pos(head, tail, index, val);
        } 
        else if(choice == 4){
            delete_at_head(head, tail);
        } 
        else if(choice == 5){
            delete_at_tail(head, tail);
        } 
        else if(choice == 6){
            int index;
            cout << "Enter index: ";
            cin >> index;
            delete_at_any_pos(head, tail, index);
        } 
        else if(choice == 7){
            reverse_linked_list(head,tail,head);
        }
        else if(choice == 8){
            print_linked_list(head);
        }
    }
    return 0;
}
