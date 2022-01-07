class Solution {
public:
    int height(TreeNode* root, int value, int &parent, int depth) {
        if(!root) return 0;
        if(root->val == value) return depth;
        parent = root->val;
        int left = height(root->left, value, parent, depth + 1);
        if(left) return left;
        parent = root->val;
        return height(root->right, value, parent, depth + 1);
    }
    
    bool isCousins(TreeNode* root, int x, int y) {
        if(!root) return false;
        if(root->val == x or root->val == y) return false;
        int parentX = -1;
        int hx = height(root, x, parentX, 0);
        int parentY = -1;
        int hy = height(root, y, parentY, 0);
        if(hx == hy and parentY != parentX) return true;
        return false;
    }
};