#include <bits/stdc++.h>
using namespace std;
class Node {
public:
    string website;
    Node* next;
    Node* prev;
    Node(string addr){
        website = addr;
        next = NULL;
        prev = NULL;
    }
};
class myDoublyList{
public:
    Node* head;
    Node* tail;
    Node* current;
    myDoublyList(){
        head = NULL;
        tail = NULL;
        current = NULL;
    }
    void append(string addr){
        Node* newNode = new Node(addr);
        if(!head){
            head = newNode;
            tail = newNode;
        } 
        else{
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    Node* find(string addr){
        Node* temp = head;
        while(temp){
            if(temp->website == addr){
                return temp;
            }
            temp = temp->next;
        }
        return NULL;
    }
    string moveNext(){
        if(current && current->next){
            current = current->next;
            return current->website;
        }
        return "Not Available";
    }
    string movePrev(){
        if(current && current->prev){
            current = current->prev;
            return current->website;
        }
        return "Not Available";
    }
    string getCurrentAddress(){
        if(current){
            return current->website;
        } 
        else{
            return "Not Available";
        }
    }
};
int main(){
   myDoublyList dll;
    string address;
    while(cin >> address && address != "end"){
        dll.append(address);
    }
    dll.current = dll.head;
    int Q;
    cin >> Q;
    cin.ignore(); 
    string command;
    while (Q--){
        getline(cin, command);
        if(command.length()>6 && command[0] == 'v' && command[1] == 'i' &&
            command[2] == 's' && command[3] == 'i' && command[4] == 't' && command[5] == ' '){
            string target = "";
            for(size_t i=6;i<command.length();++i){
                target += command[i];
            }
            Node* node = dll.find(target);
            if (node){
                dll.current = node;
                cout << dll.getCurrentAddress() << endl;
            } 
            else{
                cout << "Not Available" << endl;
            }
        } 
        else if(command == "next"){
            cout << dll.moveNext() << endl;
        } 
        else if(command == "prev"){
            cout << dll.movePrev() << endl;
        }
    }
    return 0;
}
