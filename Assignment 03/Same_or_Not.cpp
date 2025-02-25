#include <bits/stdc++.h>
using namespace std;
int main()
{
    int N, M;
    cin >> N >> M;

    stack<int> myStack;
    queue<int> q;
    for (int i = 0; i < N; ++i) {
        int value;
        cin >> value;
        myStack.push(value);
    }
    for (int i = 0; i < M; ++i) {
        int value;
        cin >> value;
        q.push(value);
    }
    if (N != M) {
        cout << "NO" << endl;
        return 0;
    }
    while (!myStack.empty() && !q.empty()) {
        if (myStack.top() != q.front()) {
            cout << "NO" << endl;
            return 0;
        }
        myStack.pop();
        q.pop();
    }
    cout << "YES" << endl;
    return 0;
}
