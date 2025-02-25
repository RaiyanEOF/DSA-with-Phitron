#include <iostream>
using namespace std;
class Node {
public:
    int val;
    Node* next;
    Node* prev;
    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class myStack {
private:
    Node* head = NULL;
    Node* tail = NULL;
public:
    void push(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    int pop() {
        if (tail == NULL) return -1; // Stack is empty
        int value = tail->val;
        Node* deleteNode = tail;
        tail = tail->prev;
        if (tail) tail->next = NULL;
        else head = NULL; // Stack becomes empty
        delete deleteNode;
        return value;
    }
    int top() {
        return (tail != NULL) ? tail->val : -1;
    }
    bool empty() {
        return head == NULL;
    }
};
class myQueue {
private:
    Node* head = NULL;
    Node* tail = NULL;
public:
    void push(int val) {
        Node* newNode = new Node(val);
        if (head == NULL) {
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    int pop() {
        if (head == NULL) return -1; // Queue is empty
        int value = head->val;
        Node* deleteNode = head;
        head = head->next;
        if (head) head->prev = NULL;
        else tail = NULL; // Queue becomes empty
        delete deleteNode;
        return value;
    }
    int front() {
        return (head != NULL) ? head->val : -1;
    }
    bool empty() {
        return head == NULL;
    }
};
int main() {
    int N, M;
    cin >> N >> M;
    myStack stk;
    myQueue q;
    for (int i = 0; i < N; i++) {
        int val;
        cin >> val;
        stk.push(val);
    }
    for (int i = 0; i < M; i++) {
        int val;
        cin >> val;
        q.push(val);
    }
    if (N != M) {
        cout << "NO" << endl;
        return 0;
    }
    while (!stk.empty() && !q.empty()) {
        if (stk.pop() != q.pop()) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
