/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool helper(TreeNode* root, int& pre){
        if(!root)
            return true;
        if(!helper(root->left, pre))
            return false;
        if(pre >= root->val)
            return false;
        pre = root->val;
        return helper(root->right, pre);
    }
    
    bool isValidBST(TreeNode *root) {
        // IMPORTANT: Please reset any member data you declared, as
        // the same Solution instance will be reused for each test case.
        int pre = INT_MIN;
        return helper(root, pre);
    }
};