#include <bits/stdc++.h>
using namespace std;
bool customComparator(const pair<string, int>& a, const pair<string, int>& b){
    if(a.first == b.first){
        return a.second > b.second; 
    }
    return a.first < b.first; 
}
int main(){
    int N; 
   cin >> N;
    vector<pair<string, int>> A(N);
    for(int i = 0; i < N; i++){
        cin >> A[i].first >> A[i].second;
    }
    sort(A.begin(), A.end(), customComparator);
    for(auto it = A.begin(); it != A.end(); ++it){
    cout << it->first << " " << it->second << endl;
      }
    return 0;
}
