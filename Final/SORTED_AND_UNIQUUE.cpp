#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; 
    cin >> T;
    while (T--) {
        int N; 
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        set<int> unique_sorted(arr.begin(), arr.end());
        for(auto it = unique_sorted.begin(); it != unique_sorted.end(); ++it){
            if(it != unique_sorted.begin()){ 
                cout << " ";
            }
            cout << *it;
        }
        cout << endl;
    }
    return 0;
}
