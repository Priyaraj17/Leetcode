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
    bool solve(TreeNode *a, TreeNode *b) {
        if(!a and !b) return true;
        if(!a or !b) return false;
        if(a->val != b->val) return false;
        return solve(a->left, b->right) and solve(a->right, b->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return solve(root->left, root->right);
    }
};