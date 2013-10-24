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
    int minDepth(TreeNode *root) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        if(!root)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        
        if(left == 0)
            return right+1;
        if(right == 0)
            return left+1;
        return 1 + min(left, right);
    }
};
