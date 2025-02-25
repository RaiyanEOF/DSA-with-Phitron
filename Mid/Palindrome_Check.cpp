#include <bits/stdc++.h>
using namespace std;
class Node{
public:
    int value;
    Node* prev;
    Node* next;
    Node(int value){
        this->value = value;
        prev = NULL;
        next = NULL;
    }
};
class myDoublyList{
public:
    Node* head;
    Node* tail;
    myDoublyList(){
        head = NULL;
        tail = NULL;
    }
    bool isPalindrome(){
        if(!head || !head->next){
            return true; 
        }
        Node* left = head;
        Node* right = tail;
        while(left != right && left->prev != right){
            if(left->value != right->value){
                return false;
            }
            left = left->next;
            right = right->prev;
        }
        return true;
    }
};
int main(){
    myDoublyList now;
    int value;
    while(cin >> value && value != -1){
        Node* newNode = new Node(value);
        if(!now.head){
            now.head = newNode;
            now.tail = newNode;
        } 
        else{
            now.tail->next = newNode;
            newNode->prev = now.tail;
            now.tail = newNode;
        }
    }
    if(now.isPalindrome()){
        cout << "YES" << endl;
    } 
    else{
        cout << "NO" << endl;
    }
    return 0;
}
