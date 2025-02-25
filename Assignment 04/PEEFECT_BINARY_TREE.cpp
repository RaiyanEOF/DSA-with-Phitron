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
int getDepth(TreeNode* root) {
    if (!root) return 0;
    return 1 + max(getDepth(root->left), getDepth(root->right));
}
int countNodes(TreeNode* root) {
    if (!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}
bool isPerfectBinaryTree(TreeNode* root) {
    if (!root) return true;    
    int depth = getDepth(root);
    int nodeCount = countNodes(root);   
    return nodeCount == (1 << depth) - 1; 
}
int main() {
    vector<int> values;
    int val;
    while (cin >> val) {
        values.push_back(val);
    }   
    TreeNode* root = buildTree(values);
    cout << (isPerfectBinaryTree(root) ? "YES" : "NO") << endl;   
    return 0;
}
