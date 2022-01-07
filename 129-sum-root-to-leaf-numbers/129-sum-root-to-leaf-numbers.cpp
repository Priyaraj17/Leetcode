/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int ans = 0;
    void solve(TreeNode *root, string str) {
        if(!root)    
            return ;
        string s = to_string(root->val);
        if(!root->left and !root->right) {
            s = str + s;
            ans += stoi(s);
        }
        solve(root->left, str + s);
        solve(root->right, str + s);
    }
    
    int sumNumbers(TreeNode* root) {
        solve(root, "");
        return ans;
    }
};