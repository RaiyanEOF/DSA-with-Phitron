#include <bits/stdc++.h>
using namespace std;
int main(){
    int N;
    cin >> N; 
    multiset<int> ms;
    for (int i=0;i<N;i++){
        int x;
        cin >> x;
        ms.insert(x);
    }
    int Q;
    cin >> Q;
    while (Q--){
        int command;
        cin >> command;
        if(command == 0){
            int X;
            cin >> X;
            ms.insert(X);
            cout << *ms.begin() << endl; 
        } 
        else if(command == 1){
            if(ms.empty()){
                cout << "Empty" << endl;
            } 
            else{
                cout << *ms.begin() << endl; 
            }
        } 
        else if(command == 2){
            if(ms.empty()){
                cout << "Empty" << endl;
            } 
            else{
                ms.erase(ms.begin()); 
                if(ms.empty()){
                    cout << "Empty" << endl;
                } 
                else{
                    cout << *ms.begin() << endl; 
                }
            }
        }
    }
    return 0;
}
