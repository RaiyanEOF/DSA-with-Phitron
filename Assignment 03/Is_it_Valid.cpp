#include <bits/stdc++.h>
using namespace std;
bool isValidString(const string& s) {
    stack<char> st;
    for(char c : s){
        if(!st.empty() && ((c == '0' && st.top() == '1') || (c == '1' && st.top() == '0'))){
            st.pop(); 
        } 
        else{
            st.push(c); 
        }
    }
    return st.empty(); 
}
int main(){
    int T;
    cin >> T;
    while (T--){
        string S;
        cin >> S;
        if(isValidString(S)){
            cout << "YES" << endl;
        } 
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
