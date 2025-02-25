#include <bits/stdc++.h>
using namespace std;
int main()
{
    int Q;
    cin >> Q;
    queue<string> line;
    while (Q--){
        int count;
        cin >> count;

        if(count == 0){
            string name;
            cin >> name;
            line.push(name);
        } 
        else if(count == 1){
            if(!line.empty()){
                cout << line.front() << endl;
                line.pop();
            } 
            else{
                cout << "Invalid" << endl;
            }
        }
    }
    return 0;
}
