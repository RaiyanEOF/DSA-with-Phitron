#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int value;       
    Node* next;      
    Node* prev;      
    Node(int val){
        value = val;
        next = NULL;
        prev = NULL;
    }
};
class myDoublyList{
public:
    Node* head;  
    Node* tail;  
    int size;    
    myDoublyList(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    bool insertAt(int index, int value){
        if(index < 0 || index > size){
            return false;
        }
        Node* newNode = new Node(value);
        if(index == 0){ 
            newNode->next = head;
            if(head){
                head->prev = newNode;
            }
            head = newNode;
            if(size == 0){ 
                tail = newNode;
            }
        } 
        else if(index == size){ 
            newNode->prev = tail;
            if(tail){
                tail->next = newNode;
            }
            tail = newNode;
        } 
        else{ 
            Node* temp = head;
            for(int i = 0; i < index - 1; ++i){ 
                temp = temp->next;
            }
            newNode->next = temp->next;
            newNode->prev = temp;
            temp->next->prev = newNode;
            temp->next = newNode;
        }
        size++;
        return true;
    }
    void printLeftToRight(){
        cout << "L -> ";
        Node* current = head;
        while(current){
            cout << current->value << " ";
            current = current->next;
        }
        cout << endl;
    }
    void printRightToLeft(){
        cout << "R -> ";
        Node* current = tail;
        while(current){
            cout << current->value << " ";
            current = current->prev;
        }
        cout << endl;
    }
};
int main(){
    int Q;
    cin >> Q;
    myDoublyList dll; 
    while (Q--){
        int index, value;
        cin >> index >> value;
        if(dll.insertAt(index, value)){
            dll.printLeftToRight();
            dll.printRightToLeft();
        } 
        else{
            cout << "Invalid" << endl;
        }
    }
    return 0;
}
