#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
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
vector<int> getLeafNodes(TreeNode* root) {
    if (!root) return {};    
    queue<TreeNode*> q;
    q.push(root);
    vector<int> leafNodes;  
    while (!q.empty()) {
        TreeNode* current = q.front();
        q.pop();
        if (!current->left && !current->right) {
            leafNodes.push_back(current->val);
        }       
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }    
    sort(leafNodes.rbegin(), leafNodes.rend()); // Sort in descending order
    return leafNodes;
}
int main() {
    vector<int> values;
    int val;
    while (cin >> val) {
        values.push_back(val);
    }    
    TreeNode* root = buildTree(values);
    vector<int> leafNodes = getLeafNodes(root);
    
    for (int num : leafNodes) {
        cout << num << " ";
    }
    cout << endl;    
    return 0;
}
