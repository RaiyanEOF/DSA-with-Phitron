#include <bits/stdc++.h>
using namespace std;
bool IsItEmpty(const string &s){
    stack<char> st;
    for(char c : s){
        if(!st.empty() && ((st.top() == '0' && c == '1') || (st.top() == '1' && c == '0'))){
            st.pop(); 
        } else {
            st.push(c); 
        }
    }
    return st.empty();
}
int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        cin >> s;
        if(IsItEmpty(s)){
            cout << "YES" << endl;
        } 
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
