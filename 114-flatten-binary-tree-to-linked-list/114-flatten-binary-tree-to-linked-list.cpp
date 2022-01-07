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
    void flatten(TreeNode* root) {
        if(!root) return;
        
        TreeNode *tempL = root->left;
        TreeNode *tempR = root->right;
        
        root->left = nullptr;
        
        flatten(tempL);
        flatten(tempR);
        
        root->right = tempL;
        TreeNode *current = root;
        while(current->right) current = current->right;
        current->right = tempR;
    }
};