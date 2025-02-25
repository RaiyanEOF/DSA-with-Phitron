#include <bits/stdc++.h>
using namespace std;
int main(){
    list<int> myList;
    int value;
    while(cin >> value && value!=-1){
        myList.push_back(value);
    }
    myList.sort();
    myList.unique();
    for(int val : myList){ 
        cout << val << " ";
    }
    return 0;
}
