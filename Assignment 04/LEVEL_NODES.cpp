#include <bits/stdc++.h>
using namespace std;
class TreeNode {
    public:
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
TreeNode* buildTree(vector<int>& values) {
    if (values.empty() || values[0] == -1) return NULL;    
    queue<TreeNode*> q;
    TreeNode* root = new TreeNode(values[0]);
    q.push(root);   
    int i = 1;
    while (!q.empty() && i < values.size()) {
        TreeNode* current = q.front();
        q.pop();       
        if (values[i] != -1) {
            current->left = new TreeNode(values[i]);
            q.push(current->left);
        }
        i++;       
        if (i < values.size() && values[i] != -1) {
            current->right = new TreeNode(values[i]);
            q.push(current->right);
        }
        i++;
    }
    return root;
}
void printLevel(TreeNode* root, int X) {
    if (!root) {
        cout << "Invalid" << endl;
        return;
    }   
    queue<TreeNode*> q;
    q.push(root);
    int level = 0;    
    while (!q.empty()) {
        int levelSize = q.size();       
        if (level == X) {
            for (int i = 0; i < levelSize; i++) {
                TreeNode* current = q.front();
                q.pop();
                cout << current->val << " ";
            }
            cout << endl;
            return;
        }        
        for (int i = 0; i < levelSize; i++) {
            TreeNode* current = q.front();
            q.pop();            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }      
        level++;
    }   
    cout << "Invalid" << endl;
}
int main() {
    vector<int> values;
    int val;
    while (cin >> val) {
        values.push_back(val);
    }   
    int X = values.back(); 
    values.pop_back();    
    TreeNode* root = buildTree(values);
    printLevel(root, X);   
    return 0;
}
