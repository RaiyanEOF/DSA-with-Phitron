#include <bits/stdc++.h>
using namespace std;
int main() {
    int Q;
    cin >> Q;  
    list<int> myList;  
    while (Q--) {
        int X, V;
        cin >> X >> V;  
        if (X == 0) {  
            myList.push_front(V);
        } 
        else if (X == 1) {  
            myList.push_back(V);
        }
        else if(X == 2){
            if(V >= 0 && V < myList.size()){
                auto it = myList.begin();
                advance(it, V);
                myList.erase(it);
            }
        }
        cout << "L -> ";
        for (auto it = myList.begin(); it != myList.end(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
        cout << "R -> ";
        for (auto it = myList.rbegin(); it != myList.rend(); ++it) {
            cout << *it << " ";
        }
        cout << endl;
    }

    return 0;
}
