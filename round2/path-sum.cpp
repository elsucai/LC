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
    bool hasPathSum(TreeNode *root, int sum) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        
		if(!root)
			return false;
		if(!root->left && !root->right)
			return root->val == sum;
		
		bool tmp = false;
		if(root->left){
			tmp = tmp || hasPathSum(root->left, sum-root->val);
		}
		if(tmp)
			return true;
		if(root->right)
			return hasPathSum(root->right, sum-root->val);
    }
};