#include <bits/stdc++.h>
using namespace std;
int main() {
    int T; 
    cin >> T;
    cin.ignore(); 
    while (T--){
        string S;
        getline(cin, S); 
        unordered_map<string, int> word_count; 
        stringstream ss(S);
       string word;
        string most_frequent_word;
        int max_count = 0;
        while(ss >> word){
            word_count[word]++; 
            if(word_count[word] > max_count ||(word_count[word] == max_count && most_frequent_word.empty())){
                most_frequent_word = word;
                max_count = word_count[word];
            }
        }
        cout << most_frequent_word << " " << max_count << endl;
    }

    return 0;
}
