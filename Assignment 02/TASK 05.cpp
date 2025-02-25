#include <bits/stdc++.h>
using namespace std;
class Node {
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
    LinkedList(){
        head = NULL;
    }
    void insert_at_tail(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
        } 
        else{
            Node* temp = head;
            while (temp->next != NULL){
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    void remove_duplicates(){
        Node* current = head;
        while(current != NULL){
            Node* runner = current;
            while(runner->next != NULL){
                if(runner->next->value == current->value){
                    Node* duplicate = runner->next;
                    runner->next = runner->next->next;
                    delete duplicate;
                } 
                else{
                    runner = runner->next;
                }
            }
            current = current->next;
        }
    }
    void print_list(){
        Node* temp = head;
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
    LinkedList list;
    int val;
    while(cin >> val && val != -1){
        list.insert_at_tail(val);
    }
    list.remove_duplicates();
    list.print_list();
    return 0;
}
