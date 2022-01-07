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
    bool path(TreeNode* root, int target, int sum) {
        if(!root) return false;
        sum += root->val;
        if(!root->left and !root->right and sum == target) return true;
        return path(root->left, target, sum) or path(root->right, target, sum);
    }
    
    bool hasPathSum(TreeNode* root, int targetSum) {
        return path(root, targetSum, 0);
    }
};