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
    int count = 0;
    unordered_map<int,int> dict;
    
    void solve(TreeNode* root, int targetSum, int sum) {
        if(!root)
            return;
        sum += root->val;
        if(sum == targetSum) count++;
        count += dict[sum - targetSum];
        dict[sum]++;
        solve(root->left, targetSum, sum);
        solve(root->right, targetSum, sum);
        
        dict[sum]--;
    }
    
    int pathSum(TreeNode* root, int targetSum) {
        solve(root, targetSum, 0);
        return count;
    }
};